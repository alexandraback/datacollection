package codejam.qualification;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class D {

	private final static boolean SMALL = true;
	
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("src/D-" + (SMALL ? "small" : "big") + ".in"));
		PrintWriter output = new PrintWriter("src/D-" + (SMALL ? "small" : "big") + ".out");

		String out;
		int T = input.nextInt();
		for(int i = 1; i <= T; i++) {
			int N = input.nextInt();
			List<Float> naomi = new ArrayList<Float>(N);
			List<Float> ken = new ArrayList<Float>(N);
			for (int j = 0; j < N; j++) {
				naomi.add(input.nextFloat());
			}
			for (int j = 0; j < N; j++) {
				ken.add(input.nextFloat());
			}
			Collections.sort(naomi, Collections.reverseOrder());
			Collections.sort(ken, Collections.reverseOrder());
			out = "Case #" + i + ": " + solve1(new ArrayList<Float>(naomi), new ArrayList<Float>(ken)) + " " + solve2(new ArrayList<Float>(naomi), new ArrayList<Float>(ken));
			output.println(out);
			System.out.println(out);
		}
		input.close();
		output.close();
	}
	
	private static int solve1(List<Float> naomi, List<Float> ken) {
		int nums = 0;
		for (int i = ken.size() - 1, j = naomi.size() -1; i>=0 && j>=0;) {
			if(naomi.get(j) > ken.get(i)) {
				nums++;
				ken.remove(i);
				naomi.remove(j);
				i--;
				j--;
			} else {
				j--;
			}
		}
		
		return nums + solve2(naomi, ken);
	}

	private static int solve2(List<Float> naomi, List<Float> ken) {
		int result = 0;
		while(!naomi.isEmpty()) {
			if(naomi.get(0) < ken.get(0)) {
				naomi.remove(0);
				ken.remove(0);
			} else {
				naomi.remove(0);
				ken.remove(ken.size()-1);
				result++;
			}
		}
		return result;
	}

}
