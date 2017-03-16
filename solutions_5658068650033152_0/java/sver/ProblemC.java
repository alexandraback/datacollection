import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class ProblemC {
	
	private static long[] squares;

	public static void main(String[] args) throws Exception{
		fillSquares();
		Scanner scanner = new Scanner(new File("C-small-attempt2.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("out3.txt")));
		int cases = scanner.nextInt();
		for(int i = 0; i < cases; i++){
			
			String str = "Case #"+(i+1)+": ";
			str += numberStones(scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
			str += "\n";
			System.out.println(str);
			writer.write(str);
		}
		writer.flush();
		writer.close();
		scanner.close();
	}

	private static long numberStones(int n, int m, int k) {
		if(k <= 4)
			return 4;
		int core = (int)Math.sqrt(k);
		int current = k - core;
		return current;
	}

	private static void fillSquares() {
		squares = new long[1001];
		long current = 1;
		for(int i = 1; i < squares.length; i++){
			squares[i] += current;
			current += 2;
		}
	}
}
