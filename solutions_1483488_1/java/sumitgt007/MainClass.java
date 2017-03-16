import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class MainClass {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("C-large.in"));
		PrintWriter out = new PrintWriter(new File("RecycledNumbers.out"));

		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			System.out.println("For case i: " + i);
			int A = sc.nextInt();
			int B = sc.nextInt();
			long count = 0;
			String s1 = "";
			for (int j = A; j <= B; j++) {
				s1 = "" + j;
				ArrayList<String> done = new ArrayList<String>();
				for (int k = 0; k < s1.length(); k++) {
					String tempS = s1;
					tempS = s1.substring(1) + s1.charAt(0);
					if (done.contains(tempS)) {
						continue;
					} else {
						s1 = tempS;
					}
					int temp = Integer.parseInt(s1);
					if ((temp < j) && (temp >= A) && (temp <= B)) {
						count++;
						done.add(s1);

					}

				}
			}
			out.println("Case #" + (i + 1) + ": " + count);
			System.out.println("**************");
		}
		out.close();

	}

}
