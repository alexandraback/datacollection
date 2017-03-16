package year2013.round1a.b;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem {
	public static void main(String[] args) throws Exception{
		// GCJ共通 ここから
		String filename = "src/year2013/round1a/b/B-large";
		PrintWriter out = new PrintWriter(new File(filename + ".out"));
		Scanner scan = new Scanner(new File(filename + ".in"));
		final int T = scan.nextInt();
		StringBuilder ret = new StringBuilder();
		for (int i = 0; i < T; i++) {
			ret.append("Case #"+(i+1)+": ");
			// 問題文を読んでsolve()に渡す ここから
			int E = scan.nextInt();
			int R = scan.nextInt();
			int N = scan.nextInt();
			int[] v = new int[N];
			for(int j=0; j<N; j++){
				v[j] = scan.nextInt();
			}
			
			ret.append(solve(E,R,N,v));
			// 問題文を読んでsolve()に渡す ここまで
			ret.append("\n");
		}
		out.write(ret.substring(0, ret.length()-1));
		out.flush();
		// GCJ共通 ここまで
	}

	/*
	 * 方針
	 * v[i]において、v[i+1]>v[i]ならば「$最小限度」だけエネルギーを使う。
	 * 「$最小限度」とは、($現時点のエネルギー + R)-Eが正の数ならその値、0以下なら0
	 */
	static String solve(int E, int R, int N, int[] v){
		long tgain = 0L;
		int curE = E; //current energy
		for (int i = 0; i < N; i++) {
			if(i<N-1){
				//次に出てくる「自分より大きいv」のインデックス
				int index = -1;
				for(int j=i+1; j<N; j++){
					if(v[j]>v[i]){
						index=j;
						break;
					}
				}
				int use =0;
				if(index!=-1){
					use = (curE+R*(index-i))-E;
					if(use<=0) use=0;
					if(use>curE) use=curE;
				}else{
					//全部使う
					use=curE;
				}
				tgain+=use*v[i];
				curE=curE-use+R;
				if(curE > E) curE=E;
			}else{
				//最後は全部使う
				tgain+=curE*v[i];
			}
		}
		
		return String.valueOf(tgain);
	}
}
