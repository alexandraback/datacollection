package q1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Qa{
	static final int M = 14;
	static int[] min;
	public static void main(String args[]) throws FileNotFoundException{
		initMin();
		File fi = new File("A-large.in.txt");
		File fo = new File("AL.txt");
		Scanner s = new Scanner(fi);
		PrintWriter p = new PrintWriter(fo);
		int T = s.nextInt();
		for(int i=1;i<=T;i++){
			long n = s.nextLong();
			p.write("Case #" + i + ": " + turn(n) + "\n");
		}
		p.flush();
	}
	public static int initMin(){
		min = new int[M+1];
		min[0] = 0;
		min[1] = 0;
		min[2] = 29;
		int n = 29;
		for(int i=3;i<=M;i++){
			n += Math.pow(10, i/2) + Math.pow(10, (i+1)/2) - 1;
			min[i] = n;
		}
		return 0;
	}
	public static long turn(long n){
		if(n < 21){ return n; }
		if(n < 100){
			if(n % 10 == 0){ return 10+(n/10)+((n-1)%10); }
			return 10+(n/10)+(n%10);
		}
		String k = Long.toString(n);
		int l = k.length();
		int up = toI(k.substring(0, l/2));
		int dp = toI(k.substring(l/2));
		if(n == Math.pow(10, l-1)){ return min[l-1]; }
		if(dp == 0){ dp = (int)Math.pow(10, (l+1)/2); up--; }
		if(up == Math.pow(10, l/2-1)){ return min[l-1]+dp; }
		return min[l-1]+flip(up)+dp;
	}
	public static int toI(String s){
		return Integer.parseInt(s);
	}
	public static int flip(int n){
		int x = 0;
		while(n != 0){
			x *= 10;
			x += n % 10;
			n /= 10;
		}
		return x;
	}
}
