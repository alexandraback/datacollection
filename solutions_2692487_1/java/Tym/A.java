package round1B;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;

public class A {

	String solve(Scanner in) throws IOException {
		int a = in.nextInt(), n = in.nextInt();
		int[] motes = new int[n];
		for(int i = 0; i < n; i++)
			motes[i] = in.nextInt();
		Arrays.sort(motes);
		
		
		return "" + min(motes, 0, a);
	}
	
	int min(int[] motes, int from, long a) {
		int n = motes.length;
		if(from >= n)
			return 0;
		
		if(motes[from] < a)
			return min(motes, from+1, a+motes[from]);
		
		if(a == 1)
			return n-from;
		
		return Math.min(n-from, 1+min(motes, from, 2*a-1));
	}
	
/*************************************************************************************************/
	
	public static void main(String[] args) throws IOException {
		for(File f : new File(".").listFiles())
			if(f.isFile() && f.getName().startsWith(A.class.getSimpleName() + "-")
					      && f.getName().endsWith(".in")) {
				
				Scanner in = new Scanner(new FileReader(f));
				PrintWriter out = new PrintWriter(new FileWriter(f.getName() + ".out"));
				
				long start = System.currentTimeMillis();
				int cases = in.nextInt(); in.nextLine();
				for(int caseno = 1; caseno <= cases; caseno++)
					out.printf("Case #%d: %s%n", caseno, new A().solve(in));
				System.out.printf("%s: %d ms%n", f.getName(), System.currentTimeMillis()-start);
				out.close();
			}
	}
}
