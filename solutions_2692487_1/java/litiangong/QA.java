import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class QA {

	public static void main(String[] args) {
		
		try {
		Scanner sc = new Scanner(new FileReader("f:\\aaa.in"));
        PrintWriter pw = new PrintWriter("f:/output.txt");		
        
	        int n = sc.nextInt();
	        sc.nextLine();
	        for (int c=0; c<n; c++) {
	            System.out.println("Test case " + (c+1) + "...");
	            pw.print("Case #" + (c+1) + ": ");
	            test(sc, pw);
	            pw.println();
	        }
	        pw.flush();
	        pw.close();
	        sc.close();  
	        System.out.println("done");
	        
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static void test(Scanner sc, PrintWriter pw) {
		
		int A = sc.nextInt();
		int n = sc.nextInt();
		sc.nextLine();
		int[] motes = new int[n];
		for(int i = 0;i<n;i++)
			motes[i] = sc.nextInt();
		
		Arrays.sort(motes);
		
		int count = loop(motes, A, 0, 0,n);		
		
		pw.print(count);
		
	}

	private static int loop(int[] motes, int curr, int i, int count,int max) {
		
		if(count>=max)
			return max;

		if(i == motes.length-1)
		{
			if(motes[i] >= curr)
				return count+1;
			else {
				return count;
			}
		}
		
		if(motes[i]>=curr)
		{
			return Math.min(loop(motes, curr+curr-1, i, count+1, max), count+motes.length-i);
		}
		else {
			return loop(motes, curr+motes[i], i+1, count, max);
		}
		
	}

}
