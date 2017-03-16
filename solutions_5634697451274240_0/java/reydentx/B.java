import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	static Scanner scan;
	static PrintWriter writer;
	static Boolean[] A = new Boolean[100];
	public static void main(String[] args) {
		
		File file = new File("D://input.txt");
		File out = new File("D://out.txt");
		try {
			scan = new Scanner(file);
			writer = new PrintWriter(out);
			int t = scan.nextInt();
			for (int i = 1; i <= t; i++) {
				writer.print("Case #" + i + ": ");
				String s = scan.next();
				int n = s.length();
				char[] chars = s.toCharArray();
				for(int j=0; j<n; j++) {
					if(chars[j] == '-') {
						A[j] = false;
					} else if(chars[j] == '+') {
						A[j] = true;
					}
				}
				
				solve(n);
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			scan.close();
			writer.close();
		}
	}
	
	private static void solve(int n) {
		int ret = 0;
		
		int l;
		while((l = getLastFalse(n)) != -1) {
			int nFirstTrue = getNFirstTrue(n);
			if(nFirstTrue > 0) {
				ret++;
				changeAndReverse(nFirstTrue);
			}
			ret ++;
			changeAndReverse(l+1);
		}
		writer.println(ret);
	}
	
	private static void changeAndReverse(int n) {
		for(int i=0; i<n; i++) {
			A[i] = !A[i];
		}
		for(int i = 0; i < n/2; i++)
		{
		    boolean temp = A[i];
		    A[i] = A[n - i - 1];
		    A[n - i - 1] = temp;
		}
	}
	
	private static int getLastFalse(int n) {
		for(int i=n-1; i>=0; i--) {
			if(!A[i]) {
				return i;
			}
		}
		
		return -1;
	}
	
	private static int getNFirstTrue(int n) {
		for(int i=0; i<n; i++) {
			if(!A[i]) {
				return i;
			}
		}
		return n;
	}
}
