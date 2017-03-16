import java.io.*;
import java.math.*;
import java.util.*;

public class B{
	public static long[][] memo;
	public static long dp(long[] ai, int[] Ai, long[] bi, int[] Bi, int starta, int startb){
		if(starta >= ai.length)
			return 0;
		if(startb >= bi.length)
			return 0;
		//if(memo[starta][startb] > -1)
		//	return memo[starta][startb];
		
		long res = 0;
		if(Ai[starta] == Bi[startb]){
			res += Math.min(ai[starta], bi[startb]);
			//System.out.println("TOOK FROM " + starta + " " + startb + "     " + ai[starta] + " " + bi[startb]);
			ai[starta] -= res;
			bi[startb] -= res;
			int newstarta = starta;
			int newstartb = startb;
			if(ai[starta] == 0)
				newstarta = starta+1;
			if(bi[startb] == 0)
				newstartb = startb+1;
			long testc = dp(ai, Ai, bi, Bi, newstarta, newstartb);
			res += testc;
			//System.out.println("added " + res + " " + starta + " " + startb + "      " + "called " + newstarta + " " + newstartb + "     " + testc);
			ai[starta] += res - testc;
			bi[startb] += res - testc;
			
		} else{
			long testa = dp(ai, Ai, bi, Bi, starta+1, startb);
			long testb = dp(ai, Ai, bi, Bi, starta, startb+1);
			res = Math.max(testa, testb);
			//System.out.println("checking max of " + (starta) + " " + (startb) + "       "+ testa + " " + testb);
		}

		//System.out.println(starta + " " + startb + "     " + res);
		memo[starta][startb] = res;
		return res;
			


	}
	public static void main(String[] args) throws Exception{
		BufferedReader fin = new BufferedReader(new FileReader("Bin.txt"));
		PrintWriter fout = new PrintWriter(new FileWriter("Bout.txt"));

		String in = fin.readLine();
		int tt = Integer.parseInt(in);

		int t = 1;

		while(t <= tt){
			//System.out.println("asdf");
			in = fin.readLine();
			//System.out.println(in);
			String[] sp = in.split(" ");
			int n = Integer.parseInt(sp[0]);
			int m = Integer.parseInt(sp[1]);
			
			long[] ai = new long[n];
			int[] Ai = new int[n];
			long[] bi = new long[m];
			int[] Bi = new int[m];

			in = fin.readLine();
			sp = in.split(" ");
			for(int i = 0; i < n*2; i+=2){
				ai[i/2] = Long.parseLong(sp[i]);
			}
			for(int i = 1; i < n*2; i+=2){
				Ai[i/2] = Integer.parseInt(sp[i]);
			}

			in = fin.readLine();
			sp = in.split(" ");
			for(int i = 0; i < m*2; i+=2){
				bi[i/2] = Long.parseLong(sp[i]);
			}
			for(int i = 1; i < m*2; i+=2){
				Bi[i/2] = Integer.parseInt(sp[i]);
			}

			memo = new long[n][m];
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					memo[i][j] = -1;
				}
			}
			long res = dp(ai, Ai, bi, Bi, 0, 0);






			fout.println("Case #" + t + ": " + res);
			fout.flush();
			t++;
		}
	}
}