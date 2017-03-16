import java.io.*;
import java.util.*; 

/** 
 * @author Olaf Matyja olafmat@gmail.com 
 */
public class Round1CB {
	int cases;

	int typedLen;
	int keyboardLen;
	int targetLen;
	String keyboard;
	String target;
	LinkedHashMap<Integer, Double> space;
	LinkedHashMap<Integer, Double> nextSpace;
	
	class State {
		int score;
		int progress;
		
		public int code() {
			return score * targetLen + progress; 
		}
		
		public State() {			
		}
		
		public State(int code) {
			score = code / targetLen;
			progress = code % targetLen;
		}
	}

	void addState(State state, double prob) {
		Double existing = nextSpace.get(state.code());
		//System.out.println("ADD " + state.progress + " " +state.score + " " + prob + " " + existing + " " + nextSpace.size());
		if (existing != null) {
			nextSpace.remove(state);
			nextSpace.put(state.code(), prob + existing);
		} else
			nextSpace.put(state.code(), prob);
	}
	
	void typeCharacter() {
		nextSpace = new LinkedHashMap<Integer, Double>();
		for (Map.Entry<Integer, Double> entry: space.entrySet()) {
			State state = new State(entry.getKey());
			double prob = entry.getValue();
			/*System.err.println(keyboard);
			System.err.println(target);
			System.err.println(state.score);
			System.err.println(state.progress);
			System.err.println(prob);
			System.err.println("SPACE " + space.size());
			System.err.println("NSPACE " + nextSpace.size());*/
			
			State nextOk = new State();
			if (state.progress + 1 == targetLen) {
				nextOk.score = state.score + 1;
				nextOk.progress = 0;
				while (nextOk.progress <= state.progress &&
					target.substring(0, nextOk.progress + 1).equals(target.substring(state.progress - nextOk.progress, state.progress + 1))
				) {
					nextOk.progress++;
				}
			} else {
				nextOk.score = state.score;
				nextOk.progress = state.progress + 1;
			}
			
			int casesNext = 0;
			char nextTarget = target.charAt(state.progress);
			for (int n = 0; n < keyboardLen; n++) {
				char keyTyped = keyboard.charAt(n); 
				if (keyTyped == nextTarget)
					casesNext ++;
				else {
					boolean ok = false;
					for (int m = state.progress; m >= 0; m--) {
						if (target.substring(0, m).equals(target.substring(state.progress - (m - 1), state.progress + 1)) &&
								target.charAt(state.progress) == keyTyped) {
							State partial = new State();
							partial.score = state.score;
							partial.progress = m + 1;
							addState(partial, prob / keyboardLen);
							ok =true;
							break;
						}
					}
					if (!ok) {
						State partial = new State();
						partial.score = state.score;
						partial.progress = 0;
						addState(partial, prob / keyboardLen);						
					}
				}
			}
			if (casesNext > 0) {
				double nProb = prob * casesNext / keyboardLen;
				addState(nextOk, nProb);
			}
		}
		space = nextSpace;
	}
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int curCase = 0; curCase < cases; curCase++) {
			keyboardLen = scanner.nextInt();
			targetLen = scanner.nextInt();
			typedLen = scanner.nextInt();
			scanner.nextLine();
			keyboard = scanner.nextLine();
			target = scanner.nextLine();

			space = new LinkedHashMap<Integer, Double>();			
			State initial = new State();
			initial.progress = 0;
			initial.score = 0;
			space.put(initial.code(), 1.0);
			
			for (int n = 0; n < typedLen; n++) {
				typeCharacter();
			}
			
			int max = 0;
			double expected = 0;
			for (Map.Entry<Integer, Double> entry: space.entrySet()) {
				State state = new State(entry.getKey());
				double prob = entry.getValue();
				if (state.score > max)
					max = state.score;
				expected += state.score * prob;
				
				/*System.err.println(keyboard);
				System.err.println(target);
				System.err.println(state.score);
				System.err.println(state.progress);
				System.err.println(prob);
				System.err.println("SPACE " + space.size());
				System.err.println("NSPACE " + nextSpace.size());*/
			}
			
			double dob = max - expected;
			out.println("Case #" + (curCase + 1) + ": " + dob);
		}
	}
	
	Round1CB() throws IOException {
		/*String sampleText = "5\r\n" + 
				"7 6 6\r\n" + 
				"BANANAS\r\n" + 
				"MONKEY\r\n" + 
				"2 3 4\r\n" + 
				"AA\r\n" + 
				"AAA\r\n" + 
				"2 1 2\r\n" + 
				"AB\r\n" + 
				"B\r\n" + 
				"6 2 2\r\n" + 
				"GOOGLE\r\n" + 
				"GO\r\n" + 
				"26 11 100\r\n" + 
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ\r\n" + 
				"ROSENCRANTZ\r\n"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\B-small-attempt2.in"));
		PrintStream out = new PrintStream("out-B-small.txt");
		
		/*
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\B-large.in"));
		PrintStream out = new PrintStream("out-B-large.txt");
		*/

		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round1CB();
	}	
	
}
