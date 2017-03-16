package carol.r1B15;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	static final String TYPE = "A";
	static String inputFile;
	static String outputFile;
	public static int MAXLEN = 18;
	
	public static long val[];
	static{
		val = new long[MAXLEN];
		val[1] = 1;
		for (int i = 1; i < MAXLEN - 1; ++i){
			val[i + 1] = val[i] * 10;
		}
	}

	private static void Name(String s) {
		inputFile = s + ".in";
		outputFile = s + ".out";
	}

	public static void main(String[] args) throws FileNotFoundException {

		String root = "data/R1B2015";

		// Test
		Name(TYPE + "-large");
//		Name(TYPE + "-test");
//		Name("A-small-attempt1-long");

		
		Scanner in = new Scanner(new File(root, inputFile));
		PrintWriter out = new PrintWriter(new File(root, outputFile));
//		
////		int MAX_MIN = (int) Math.pow(10, 6);
////		MAX_MIN++;
//		int MAX_MIN = 101;
//		long[] db = new long[MAX_MIN];
//		
//		for(int i = 0; i < MAX_MIN; i++){
//			if(i<=10)db[i] = i;
//			else{
//				int re = reverse(i);
////				System.out.println(i + " " + re);
//				if(i%10==0) db[i] = db[i-1] + 1;
//				else if(re < i){
//					if(db[re] < db[i-1]){
//						System.out.println("----  " + i +" " + re);
//					}
//					db[i] = Math.min(db[re], db[i-1]) + 1;
//				}
//				else{
//					db[i] = db[i-1] + 1;
//				}
//			}
//			System.out.println(i + " " + db[i]);
//		}
		
		long T = in.nextLong();

		for (int i = 0; i < T; i++) {
			long N = in.nextLong();
			out.println("Case #" + (i + 1) + ": " + calculate(N));
			
		}

		in.close();
		out.close();

	}
	
	public static long calculate(long j){
		if (j <= 10) return j;
		String data = String.valueOf(j);
		int len = data.length();
		
		if (j == val[len]) return 1 + calculate(val[len] - 1);
		
		long ans = j - val[len] - 1;
		long tot = 0;
		for (int i = 0; i < len - 1; ++i){
			for (char c = '1'; c <= '9'; ++c){
				tot += val[i + 1];
				if (j < reverse(val[len] + tot)){
					tot -= val[i + 1];
					break;
				}
				ans = Math.min(ans, tot + j - reverse(val[len] + tot));
			}
		}
		
		return ans + calculate(val[len] - 1) + 2;
	}
	
	public static long reverse(long x) {
	    long rev = 0;
	    while(x != 0){
	        rev = rev*10 + x%10;
	        x = x/10;
	    }
	 
	    return rev;
	}

}