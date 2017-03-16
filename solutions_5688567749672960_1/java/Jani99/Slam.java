import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class Slam {
	
	public static long pow10(int n) {
		long pow = 1;
		for (int i=0;i<n;++i) {
			pow *= 10;
		}
		return pow;
	}
	
	public static int digits10(long n) {
		int digits = 0;
		while (n>0) {
			++digits;
			n /= 10;
		}
		return digits;
	}
	
	public static long reversedPrefix(long n, int l) {
		return new Long(new StringBuffer(Long.toString(n).substring(0,l)).reverse().toString());
	}
	
	public static long suffix(long n, int l) {
		String s = Long.toString(n);
		return new Long(s.substring(s.length()-l,s.length()));
	}
	
	public static long reversed(long n) {
		return new Long(new StringBuffer(Long.toString(n)).reverse().toString());
	}
	
	public static long countTo(long n) {
		
		if (n <= 10) {
			return n;
		}
		
		if (n%10 == 0) {
			return countTo(n-1) + 1;
		}
		
		int l = digits10(n);
		
		long count1 = 0;
		if (l%2==0) {
			count1 = suffix(n,l/2);
		} else {
			count1 = suffix(n,l/2+1);
		}
		
		if (reversedPrefix(n,l/2) == 1) {
			++count1;
			return count1 + countTo(n-count1);
		}
		
		--count1;
		return count1 + 1 + countTo(reversed(n - count1));
	}

	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(new File(args[0]));
        File outFile = new File(args[1]);
        FileOutputStream os = new FileOutputStream(outFile);
        OutputStreamWriter osw = new OutputStreamWriter(os);
        Writer w = new BufferedWriter(osw);
		        
		int cases = sc.nextInt();

		for (int i=0; i<cases; ++i) {
			
			long N = sc.nextLong();
			
			w.write("Case #" + Integer.toString(i+1) + ": " + Long.toString(countTo(N)) + "\n");
		}

		w.close();
		sc.close();
	}

}
