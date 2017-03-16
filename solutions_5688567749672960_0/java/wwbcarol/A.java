package carol.r1B15;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	static final String TYPE = "A";
	static String inputFile;
	static String outputFile;

	private static void Name(String s) {
		inputFile = s + ".in";
		outputFile = s + ".out";
	}

	public static void main(String[] args) throws FileNotFoundException {

		String root = "data/R1B2015";

		// Test
//		Name(TYPE + "-large");
//		Name(TYPE + "-test");
		Name("A-small-attempt1");

		
		Scanner in = new Scanner(new File(root, inputFile));
		PrintWriter out = new PrintWriter(new File(root, outputFile));
		
		int MAX_MIN = (int) Math.pow(10, 6);
		MAX_MIN++;
//		int MAX_MIN = 1001;
		int[] db = new int[MAX_MIN];
		
		for(int i = 0; i < MAX_MIN; i++){
			if(i<=10)db[i] = i;
			else{
				int re = reverse(i);
//				System.out.println(i + " " + re);
				if(i%10==0) db[i] = db[i-1] + 1;
				else if(re < i){
					db[i] = Math.min(db[re], db[i-1]) + 1;
				}
				else{
					db[i] = db[i-1] + 1;
				}
			}
//			System.out.println(i + " " + db[i]);
		}
		
		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			out.println("Case #" + (i + 1) + ": " + db[N]);
			
		}

		in.close();
		out.close();

	}
	
	public static int reverse(int x) {
	    int rev = 0;
	    while(x != 0){
	        rev = rev*10 + x%10;
	        x = x/10;
	    }
	 
	    return rev;
	}

}