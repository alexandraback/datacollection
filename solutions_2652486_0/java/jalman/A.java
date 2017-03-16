import java.io.*;
import java.util.*;
import java.math.BigInteger;


public class A{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int T = Integer.parseInt(br.readLine());
		String dc = br.readLine();


		int N=3;
		int M=5;
		int K=7;
		int R=100;



		int[][][][] p = new int[M+1][M+1][M+1][M*M*M+2];

		for(int a = 2; a <= M; a++) for(int b = 2; b <= M; b++) for(int c = 2; c <= M; c++) {
			p[a][b][c][1]++;
			p[a][b][c][a]++;
			p[a][b][c][b]++;
			p[a][b][c][c]++;
			p[a][b][c][a*b]++;
			p[a][b][c][a*c]++;
			p[a][b][c][b*c]++;
			p[a][b][c][a*b*c]++;
		}

		pw.println("Case #1:");


		for(int i = 1; i <= R; i++) {

			String[] s = br.readLine().split(" ");
			int[] vals = new int[K];
			for(int q = 0; q < K; q++)
				vals[q] = Integer.parseInt(s[q]);


			int best = 0;
			int ba = 0;
			int bb = 0;
			int bc = 0;

			for(int a = 2; a <= M; a++) for(int b = 2; b <= M; b++) for(int c = 2; c <= M; c++) {
				int cur = 1;

				for(int q = 0; q < K; q++) {
					cur *= p[a][b][c][vals[q]];
				}


				System.out.println(a + " " + b + " " + c + "  " + cur);
				if(cur > best) {
					best = cur;
					ba = a;
					bb = b;
					bc = c;
				}
			}


			pw.println(ba + "" + bb + "" + bc);

		}


		pw.flush();
		pw.close();
	}

}