/**
 * 
 */
package google.codejam.fourteen.qua;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import google.codejam.tools.QuestionFile;

/**
 * @author ya
 * 
 */
public class D {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		QuestionFile file = new QuestionFile(
				A.class.getResourceAsStream("D-large.in"), "D-l.out");
		int queNum = file.getLength();
		int t = 0;
		try {
			for (t = 0; t < queNum; t++) {
				String line = file.getLine();
				Integer N = Integer.parseInt(line);
				List<Double> Nm = new ArrayList<Double>();
				List<Double> Km = new ArrayList<Double>();
				String[] nums = file.getLine().split(" ");
				for (int i = 0; i < N; i++) {
					Nm.add(Double.parseDouble(nums[i]));
				}
				nums = file.getLine().split(" ");
				for (int i = 0; i < N; i++) {
					Km.add(Double.parseDouble(nums[i]));
				}
				Collections.sort(Nm);
				Collections.sort(Km);

				int de = deceitful(Nm, Km, N);
				int war = war(Nm, Km, N);
				file.writeAns(t, de + " " + war);
			}
			file.end();
		} catch (Exception e) {
			System.out.println(t);
			e.printStackTrace();
		}
	}

	static int deceitful(List<Double> Km, List<Double> Nm, int N) {
		int count = 0;

		int i = 0;
		int j = 0;
		for (; i < N; i++) {
			for (; j < N;) {
				if (Nm.get(i) < Km.get(j)) {
					count++;
					j++;
					break;
				} else
					j++;
			}
		}

		return count;
	}

	static int war(List<Double> Nm, List<Double> Km, int N) {
		int count = 0;

		int i = 0;
		int j = 0;
		for (; i < N; i++) {
			for (; j < N;) {
				if (Nm.get(i) < Km.get(j)) {
					count++;
					j++;
					break;
				} else
					j++;
			}
		}

		return N - count;
	}
}
