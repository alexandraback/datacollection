import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class ProblemC {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("C-small-1-attempt4.in"));
		FileWriter fstream = new FileWriter("C-small-1-attempt4.out");
		BufferedWriter out = new BufferedWriter(fstream);
		int R = 100, N = 3, M = 5, K = 7;
		in.nextLine();
		in.nextLine();
		out.write("Case #1:\n");
		for (int i = 0; i < R; i++) {
			String s = in.nextLine();
			String[] strs = s.split(" ");
			int[] prods = new int[K];
			for (int j = 0; j < K; j++) {
				prods[j] = Integer.valueOf(strs[j]);
			}
			String result = guess(prods);
			out.write(result + "\n");
		}
		out.close();
		in.close();
	}
	
	public static String guess(int[] prods) {
		boolean hasThree = false, hasFive = false, hasTwo = false, hasFour = true;
		for (int num : prods) {
			if (num % 3 == 0) {
				hasThree = true;
			}
			if (num % 5 == 0) {
				hasFive = true;
			}
			if (num % 4 == 0) {
				hasFour = true;
			}
			if (num == 2) {
				hasTwo = true;
			}
			if (num == 100) {
				return "554";
			} 
			if (num == 36) {
				return "334";
			}
			if (num == 80) {
				return "445";
			}
			if (num == 45) {
				return "335";
			}
			if (num == 75) {
				return "555";
			}
			if (num == 27) {
				return "333";
			}
			if (num == 64) {
				return "444";
			}
			if (num == 125) {
				return "555";
			}
			if (num == 48) {
				return "443";
			}
			if (num == 40) {
				return "245";
			}
			if (num == 30) {
				return "235";
			}
			if (num == 24) {
				return "234";
			}
			if (num == 32) {
				return "442";
			}
			if (num == 60) {
				return "345";
			}
			if (num == 15) {
				return "435";
			}
			if (num == 12) {
				return "234";
			}
		}
		return "";
	}
}
