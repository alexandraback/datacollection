import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class C {
	public static final String FILENAME = "C-small-1-attempt0";
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/"+FILENAME+".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"+FILENAME+".out"));
		Scanner s = new Scanner(in);
		int T = s.nextInt();
		for(int i = 1; i <= T; i++) {
			int R = s.nextInt();
			int N = s.nextInt();
			int M = s.nextInt();
			int K = s.nextInt();
			out.write("Case #"+i+":\n");
			for (int j = 0; j < R; j++) {
				int[] p = new int[K];
				for (int l = 0; l < K; l++) {
					p[l] = s.nextInt();
				}
				if(N == 3) {
					out.write(guess3(N, M, p)+"\n");
				}
			}
		}
		in.close();
		out.close();
	}
	private static String guess3(int N, int M, int[] p) {
		for (int a = 2; a <= M; a++) {
			for (int b = 2; b <= M; b++) {
				for (int c = 2; c <= M; c++) {
					boolean ok = true;
					for (int l = 0; l < p.length; l++) {
						if(
							p[l] != 1
							&& p[l] != a
							&& p[l] != b
							&& p[l] != c
							&& p[l] != a*b
							&& p[l] != a*c
							&& p[l] != b*c
							&& p[l] != a*b*c
						) {
							ok = false;
						}
					}
					if(ok) {
						return a + "" + b + "" + c;
					}
				}
			}
		}
		return "";
	}
}
