import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class Energy {
	private static int nextIntLine(Scanner in) {
		return Integer.parseInt(in.nextLine());
	}

	public static void main(String[] args) throws FileNotFoundException {
		File f = new File("output.out");
		f.delete();
		PrintStream out = new PrintStream(f);
//		PrintStream out = System.out;

		Scanner in = new Scanner(new File("input2.in"));
		int numCases = nextIntLine(in);
//		for(;;)System.out.println("\""+in.nextLine()+"\"");
		for(int i = 0; i < numCases; ++i) {
			out.printf("Case #%d: %d\n", i+1, getAnswer(in));
		}
		
		out.close();
		in.close();
	}

	private static int getAnswer(Scanner in) {
		int maxEnergy = in.nextInt();
		int regen = in.nextInt();

		int things = in.nextInt();
		int[] values = new int[things];
		for(int i = 0; i < things; ++i) {
			values[i] = in.nextInt();
		}
		
		int res = 0;
		int curEn = maxEnergy;
		for(int i = 0; i < things; ++i) {
			int dist = findNextBigger(values, i) - i;

			int take;
			if(dist > 0) {
				take = dist*regen + curEn - maxEnergy;
				take = Math.max(0, take);
				take = Math.min(take, curEn);
			} else {
				take = curEn;
			}
			
//			System.out.printf("%d %d %d\n", curEn, dist, take);
			res += values[i] * take;
			curEn -= take;
			curEn += regen;
			curEn = Math.min(curEn, maxEnergy);
		}
		
		return res;
	}

	private static int findNextBigger(int[] values, int i) {
		for(int idx = i+1; idx < values.length; ++idx) {
			if(values[idx] > values[i]) return idx;
		}
		return -1;
	}
}
