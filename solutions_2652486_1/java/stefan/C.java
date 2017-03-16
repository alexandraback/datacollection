import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;


public class C {
	public static final String FILENAME = "C-small-2-attempt2";
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
				long[] p = new long[K];
				for (int l = 0; l < K; l++) {
					p[l] = s.nextLong();
				}
				if(N == 3) {
					out.write(guess3(N, M, p)+"\n");
				}
				else if(M == 8) {
					out.write(guess8(N, M, p)+"\n");
				}
				else {
					out.write("not supported\n");
				}
			}
		}
		in.close();
		out.close();
	}
	private static String guess3(int N, int M, long[] p) {
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
	
	private static String guess8(int N, int M, long[] p) {
		int[] pr = {2, 3, 5, 7};
		int[] ne = {0, 0, 0, 0};
		boolean drei = false, zwei = false;
		for (int i = 0; i < p.length; i++) {
			for (int j = 0; j < pr.length; j++) {
				long tmp = p[i];
				int t = 0;
				while(tmp % pr[j] == 0) {
					tmp /= pr[j];
					t++;
				}
				ne[j] = Math.max(ne[j], t);
			}
			drei = drei || p[i] == 3;
			zwei = zwei || p[i] == 3;
		}
		
		int[] ret = new int[N];
		int f = 0;
		//5
		while(ne[2] > 0) {
			ret[f] = 5;
			ne[2]--;
			f++;
		}
		//7
		while(ne[3] > 0) {
			ret[f] = 7;
			ne[3]--;
			f++;
		}
		int fest = f;
		
		//3
		while(ne[1] > 0) {
			ret[f] = 3;
			ne[1]--;
			f++;
		}
		while(f < N) {
			ret[f] = 2;
			ne[0]--;
			f++;
		}
		
		int min = fest + (drei ? 1 : 0);
		int max = N - 1 - (zwei ? 1 : 0);
		while(ne[0] > 0) {
			Random r = new Random();
			int i = min + r.nextInt(max - min + 1);
			if(ret[i] <= 4) {
				ret[i] *= 2;
				ne[0]--;
			}
		}
		
		String rets = "";
		for (int j = 0; j < ret.length; j++) {
			rets += ret[j];
		}
		return rets;
	}
}
