import java.io.*;
import java.util.*; 

//1:16
public class Round0BBruteForce {

	int cases;

	Map<short[], Integer> states;
	LinkedList<short[]> queue; 
	
	void addState(short[] state, int time, boolean sort) {
		if (sort)
			Arrays.sort(state);

		Integer current = states.get(state);
		if (current == null || current > time) {
			states.put(state,  time);
			queue.addLast(state);
		}
	}
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int n = 0; n < cases; n++) {
			states = new HashMap<short[], Integer>(100000);
			queue = new LinkedList<short[]>();
			
			int D = scanner.nextInt();
			short[] P= new short[D];
			for (int i = 0; i < D; i++)
				P[i] = scanner.nextByte();
			
			try {
				addState(P, 0, true);
				System.err.print("> ");
				for (int i = 0; i < P.length; i++)
					System.err.print(" " + P[i]);
				
				int result = 0;
				while (true) {
					short[] state = queue.pollFirst();
					int time = states.get(state);
					
					int nonZero = 0;				
					for (int i = 0; i < state.length; i++)
						if (state[i] > 1)
							nonZero++;
					if (nonZero == 0) {
						result = time + 1;
						break;
					}
					short[] eat = new short[nonZero];
					int j = 0;
					for (int i = 0; i < state.length; i++)
						if (state[i] > 1)
							eat[j++] = (short) (state[i] - 1);
					addState(eat, time + 1, false);
					
					int i = state.length - 1;
					for (short m = 1; m + m <= state[i]; m++) {
						short[] nState = new short[state.length + 1];
						for (int k = 0; k < state.length - 1; k++)
							nState[k] = state[k];
						nState[i] = m;
						nState[state.length] = (short) (state[i] - m);
						addState(nState, time + 1, true);
					}
				}
				System.err.println(" #" + queue.size());
				System.err.println("Case #" + (n + 1) + ": " + result);			
	
				out.println("Case #" + (n + 1) + ": " + result);
				System.gc();
			} catch (OutOfMemoryError ex) {
				states = null;
				queue = null;
				System.gc();
				System.err.println("Case #" + (n + 1) + ": ???");			
				out.println("Case #" + (n + 1) + ": ???");				
			}
		}
	}
	
	Round0BBruteForce() throws IOException {
		/*String sampleText = "1\r\n" + 
		"1\r\n" + 
		"12";*/ 
		/*String sampleText = "3\r\n" + 
				"1\r\n" + 
				"3\r\n" + 
				"4\r\n" + 
				"1 2 1 2\r\n" + 
				"1\r\n" + 
				"4";
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\B-small-attempt1.in"));
		PrintStream out = new PrintStream("out-B-small1.txt");
		
		
		/*
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\B-large.in"));
		PrintStream out = new PrintStream("out-B-large.txt");
		*/

		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round0BBruteForce();
	}	
	
}
