import java.io.*;
import java.util.*;
import java.math.BigInteger;


public class A{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int T = Integer.parseInt(br.readLine());

		for(int i = 1; i <= T; i++) {
			String[] s = br.readLine().split(" ");

			int E = Integer.parseInt(s[0]);
			int R = Integer.parseInt(s[1]);
			int N = Integer.parseInt(s[2]);

			long[] v = new long[N];
			long[] vals = new long[N];
			s = br.readLine().split(" ");
			for(int q = 0; q < N; q++) {
				v[q] = Long.parseLong(s[q]);
				vals[q] = v[q];
			}

			Arrays.sort(vals);

			boolean[] used = new boolean[N];

			Arrays.fill(used,false);

			long ret = 0;



			for(int j = N-1; j >= 0; j--) {
				int lastused = -1;
				int K = -1;

				for(int k = 0; k < N; k++){
					if(used[k]) {
						lastused = k;
					} else if (v[k] == vals[j]) {
						K = k;
						break;
					}
				}


				int nextused = -1;

				for(int k = K+1; k < N; k++){
					if(used[k]) {
						nextused = k;
						break;
					}
				}

				used[K] = true;
				long a = E;
				if(lastused != -1)
					a = Math.min(a,R*(K-lastused));
				//System.out.println(a + " --min");

				long b = E - R*(nextused-K);

				if(nextused != -1 && b > 0)
					a = a-b;

				a = Math.max(a,0);
				//System.out.println(a);


				ret += v[K]*a;
			}


			pw.println("Case #" + i + ": " + ret);
			//System.out.println("-----");
		}


		pw.flush();
		pw.close();
	}

}