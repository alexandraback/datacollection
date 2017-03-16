import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Fractiles {
	public static void main(String[] args) throws FileNotFoundException{
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(new File("src/D-small-attempt0.in")))));
//		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    for (int i = 1; i <= t; i++){
	    	int k = in.nextInt();
	    	int c = in.nextInt();
	    	int s = in.nextInt();
	    	if (k == s){
		    	System.out.print("Case #" + i + ":");
		    	long[] res = small(k, c, s);
		    	for(long re : res){
		    		System.out.print(" " + re);
		    	}
		    	System.out.println();
	    	} else {
	    		System.out.println("Case #" + i + ": IMPOSSIBLE");
	    	}
	    }
		
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
