import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class QB {

	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("B-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			int X = sc.nextInt();
			int Y = sc.nextInt();

			StringBuilder sb = new StringBuilder();
			int x = 0;
			int y = 0;
			int pogo = 1;
			while(x!=X) {
				if(X < 0) {
					if(x - pogo < X) {
						x += pogo;
						sb.append("E");
					} else {
						x -= pogo;
						sb.append("W");
					}
				} else {
					if(x + pogo > X) {
						x -= pogo;
						sb.append("W");
					} else {
						x += pogo;
						sb.append("E");
					}
				}
				pogo++;
			}
			while(y!=Y) {
				if(Y < 0) {
					if(y - pogo < Y) {
						y += pogo;
						sb.append("N");
					} else {
						y -= pogo;
						sb.append("S");
					}
				} else {
					if(y + pogo > Y) {
						y -= pogo;
						sb.append("S");
					} else {
						y += pogo;
						sb.append("N");
					}
				}
				pogo++;
			}
			pw.println("Case #" + caseNum + ": " + sb.toString());
		}

		pw.flush();
		pw.close();
		sc.close();
	}

	static long factorielle(int i) {
		long res = 1;
		for (int j = 1; j <= i; j++) {
			res *= j;
		}
		return res;
	}
}
