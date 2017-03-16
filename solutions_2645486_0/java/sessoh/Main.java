import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File("B.in")));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("B.out"))));

			int T = Integer.parseInt(br.readLine());
			for (int i = 0; i < T; i++) {
				String[] param = br.readLine().split(" ");
				int E = Integer.parseInt(param[0]);
				int R = Integer.parseInt(param[1]);
				int N = Integer.parseInt(param[2]);
				int[] v = new int[N];
				param = br.readLine().split(" ");
				for (int j = 0; j < N; j++) v[j] = Integer.parseInt(param[j]);
				pw.println("Case #"+(i+1)+": "+analyze(E, R, N, v));
			}
			
			pw.close();
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
	}
	
	private static long analyze(int E, int R, int N, int[] v) {
		long answer = 0;
		if (E <= R) {
			for (int i = 0; i < N; i++) answer += v[i] * E;
			return answer;
		}
		
		long[] table = new long[N];
		for (int i = 0; i < N; i++) table[i] = ((long)v[i]<<32)|i;
		Arrays.sort(table);
		
		int[] list = new int[N+1];
		for (int i = 0; i < N; i++) {
			int x = (int)(table[N-1-i]&0xffffffff);
			int y = (int)(table[N-1-i]>>32);
			if (list[x] == 0) {
				list[x] = E;
				int max = 0;
				int maxn = -1;
				int e = E-R;
				int f = R;
				int j = i-1;
				for (; j >= 0 && e > 0; j--) {
					if (list[j] > 0) { list[x] = f; e = 0; break; }
					if (max < v[j]) { max = v[j]; maxn = j; }
					list[j] = -1;
					e-=R; f+=R;
				}
				if (j < 0) { for (int k = 0; k < i; k++) list[k] = R; }
				else if (e < 0) { if (maxn >= 0) list[maxn] = -e; }
				
			} else if (list[x] < 0) {
				list[x] = 0;
			}
			
		}
		
		for (int i = 0; i < N; i++) answer += v[i] * Math.max(0, list[i]);
		return answer;
	}
}
