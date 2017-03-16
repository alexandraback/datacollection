package year2013.round1a.c;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem {
	static int N,M,K;
	public static void main(String[] args) throws Exception{
		// GCJ共通 ここから
		String filename = "src/year2013/round1a/c/C-small-1-attempt0";
		PrintWriter out = new PrintWriter(new File(filename + ".out"));
		Scanner scan = new Scanner(new File(filename + ".in"));
		final int T = scan.nextInt();
		final int R = scan.nextInt();
		N = scan.nextInt();
		M = scan.nextInt();
		K = scan.nextInt();
		StringBuilder ret = new StringBuilder();
		ret.append("Case #1:\n");
		for (int i = 0; i < R; i++) {
			int[] prod = new int[K];
			for(int j=0; j<K; j++){
				prod[j] = scan.nextInt();
			}
			ret.append(solve(prod));
			ret.append("\n");
		}
		out.write(ret.substring(0, ret.length()-1));
		out.flush();
		// GCJ共通 ここまで
	}
	
	static String solve(int[] prod){
		//small 1. たかだか64個*8の組み合わせ
		for(int a = 2; a<=5; a++){
			for(int b = 2; b<=5; b++){
				for(int c = 2; c<=5; c++){
					
					//a,b,cの積でprod[i]をすべて表せるか
					boolean can = true;
					for(int i=0; i<K; i++)
					if(!can(a,b,c, prod[i])){
						can=false;
					}
					if(can){
						return String.valueOf(a)+String.valueOf(b)+String.valueOf(c);
					}
				}
			}
		}
		
		return "111";
	}
	
	static boolean can(int a, int b, int c, int prod){
		//a,b,cの積でprod[i]を表せるか
		for(int use_a = 0; use_a<=1; use_a++)
			for(int use_b = 0; use_b<=1; use_b++)
				for(int use_c = 0; use_c<=1; use_c++){
					int temp = (use_a==1?a:1)*(use_b==1?b:1)*(use_c==1?c:1);
					if(temp==prod) return true;
				}
		return false;
	}
}
