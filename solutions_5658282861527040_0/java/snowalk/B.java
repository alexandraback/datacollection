/**
 * 
 */
package google.codejam.fourteen.oneB;

import google.codejam.tools.QuestionFile;

import java.io.IOException;

/**
 * @author ya
 * 
 */
public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		QuestionFile file = new QuestionFile(
				B.class.getResourceAsStream("B-small-attempt0.in"), "B.out");
		int queNum = file.getLength();
		try {
			for (int t = 0; t < queNum; t++) {
				String line = file.getLine();
				String[] strs = line.split(" ");

				int result = solve(Integer.parseInt(strs[0]),
						Integer.parseInt(strs[1]), Integer.parseInt(strs[2]));
				if (result == -1)
					file.writeAns(t, "Fegla Won");
				else
					file.writeAns(t, result);
			}
			file.end();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public static int solve(int A, int B, int K) {
		int count = 0;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				if ((i & j) < K)
					count++;
			}
		}
		return count;

	}

}
