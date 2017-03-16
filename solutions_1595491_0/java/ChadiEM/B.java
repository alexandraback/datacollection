import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Chadi
 */

class TestCase {
	int googlers;
	int surprises;
	int minScore;
	int[] scores;
	public TestCase() {

	}
	public int[] split(int sum, boolean surprise) {
		if (sum == 0) {
			return new int[]{0,0,0};
		}
		else if (sum == 1) {
			return new int[]{0,0,1};
		}
		int[] res = new int[3];
		if (surprise == false) {
			res[0] = sum/3;
			res[1] = (sum - res[0]) / 2;
			res[2] = sum - res[0] - res[1];
		}
		else {
			res[0] = (int)(Math.ceil(sum / 3.0)) + 1;
			res[1] = (sum - res[0]) / 2;
			res[2] = sum - res[0] - res[1];
		}
		Arrays.sort(res);
		while (res[2] - res[0] > 2) {
			res[0]++;
			res[2]--;
			Arrays.sort(res);
		}
		return res;
	}
	public int solve() {
		int count = 0;
		for (int i = 0; i < googlers; i++) {
			int[] curScores = split(scores[i], false);
			//System.out.println(i + "\t" + Arrays.toString(curScores));
			if (curScores[2] >= minScore) {
				count++;
			}
			else {
				if (surprises > 0) {
					//System.out.println("Using a surprise!");
					int[] curScoresBest = split(scores[i], true);
					//System.out.println(i + "\t" + Arrays.toString(curScoresBest));
					if (curScoresBest[2] >= minScore) {
						count++;
						surprises--;
					}
				}
			}
		}
		
		return count;
	}
}

public class B {
    public static void main(String[] args) throws FileNotFoundException, IOException {
		/* READ INPUT + DATA STRUCTURES */
		String input = "B-small-attempt1.in";
		//String input = "C-large.in";
		String output = input.replace(".in", ".out");
		File f = new File(input);
		Scanner sc = new Scanner(f);

		int T = Integer.parseInt(sc.nextLine());
		TestCase[] cases = new TestCase[T];
		for (int i = 0; i < T; i++) {
			cases[i] = new TestCase();

			/* Add inputs to this case */
			cases[i].googlers = sc.nextInt();
			cases[i].surprises = sc.nextInt();
			cases[i].minScore = sc.nextInt();
			
			cases[i].scores = new int[cases[i].googlers];
			for (int k = 0; k < cases[i].googlers; k++) {
				cases[i].scores[k] = sc.nextInt();
			}
			

			
		}
		/* END READ INPUT + DATA STRUCTURES */

		File out = new File(output);
		if (out.exists()) {
			out.delete();
		}
		PrintWriter pw = new PrintWriter(new FileOutputStream(out, true));

		for (int i = 0; i < T; i++) {
			System.out.println("Solving case: " + "#" + (i+1));
			String result = "Case #" + (i+1) + ": " + cases[i].solve();
			if (i <= T-2) { pw.println(result); }
			else { pw.print(result); }
		}
		pw.close();
    }
}