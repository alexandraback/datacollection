import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Fractiles {
	public static void main(String[] args) throws FileNotFoundException{
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(new File("src/D-large.in")))));
//		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    for (int i = 1; i <= t; i++){
	    	int k = in.nextInt();
	    	int c = in.nextInt();
	    	int s = in.nextInt();
	    	if (s >= (k + 1) / 2 && c > 1){
		    	System.out.print("Case #" + i + ":");
		    	long[] res = large(k, c, s);
		    	for(long re : res){
		    		System.out.print(" " + re);
		    	}
		    	System.out.println();
	    	} else if(c == 1 && s == k){
	    		System.out.print("Case #" + i + ":");
	    		for (int j = 1; j <= k; j ++){
	    			System.out.print(" " + j);
	    		}
	    		System.out.println();
	    	}
	    	else {
	    		System.out.println("Case #" + i + ": IMPOSSIBLE");
	    	}
	    }
		
	}
	public static long[] large(int K, int C, int S){
		int num = (K + 1) / 2;
		long[] res = new long[num];
		if (K == 1){
			res[0] = 1;
			return res;
		}
		long constant = (long) Math.pow(K, C - 1);
		int ceil = K;
		int count = 2;
		res[0] = 2;
		
		for (int i = 1; i < num; i ++){
			if (count + 2 <= K){
				res[i] = res[i - 1] + constant * 2 + 2;
				count += 2;
			}
			else{
				res[i] = res[i - 1] + constant * 2 + 1;
				count += 1;
			}
		}
		
		return res;
	}
	
	public static long[] small(int K, int C, int S){
		long[] res = new long[K];
		long constant = (long) Math.pow(K, C - 1);
		res[0] = 1;
		for (int i = 1; i < K; i ++){
			res[i] = res[i - 1] + constant;
		}
		return res;
	}
}
