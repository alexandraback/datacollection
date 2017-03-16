/**
 * 
 */
package google.codejam.fourteen.qua;

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
				A.class.getResourceAsStream("B-small-attempt0.in"), "B.out");
		int queNum = file.getLength();
		try {
			for (int t = 0; t < queNum; t++) {
				String line = file.getLine();
				String[] nums = line.split(" ");
				Double C = Double.parseDouble(nums[0]);
				Double F = Double.parseDouble(nums[1]);
				Double X = Double.parseDouble(nums[2]);

				Double result = solve(C, F, X);
				file.writeAns(t, result);
			}
			file.end();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	static Double solve(Double C, Double F, Double X) {
		Double time = 0.0;

		Double speed = 2.0;
		while (X / speed > C / speed + X / (speed + F)) {
			time += C / speed;
			speed += F;
		}
		time += X / speed;
		return time;
	}
}
