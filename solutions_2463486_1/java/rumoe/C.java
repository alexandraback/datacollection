package qualification2013;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

@SuppressWarnings("unused")
class C {

	private boolean log = true;
	
	private static final String FILE_PATH 	= "src//qualification2013//";
	private static final String FILE_NAME 	= "C-large-1";
	
	private static final File INPUT_FILE 	= new File(FILE_PATH + FILE_NAME + ".in");
	private static final File OUTPUT_FILE 	= new File(FILE_PATH + FILE_NAME + ".out");
	
	private Scanner sc;
	private PrintWriter pw;
	
	private C() throws IOException {
		sc = new Scanner(INPUT_FILE);
		pw = new PrintWriter(OUTPUT_FILE);
				
		allFair = allFairAndSquare(1000_000_000_000_000L);	//limit for large1
		
		final int C = sc.nextInt();
		for (int i = 1; i <= C; i++) {
			write(String.format("Case #%d: ", i));
			solve();
			write("\n");
		}
		
		pw.flush();
		pw.close();
		sc.close();
		System.out.println("Done!");
	}
	
	private Long[] allFair;
	
	
	private Long[] allFairAndSquare(long high) {
		
		List<Long> l = new ArrayList<Long>();
		long max = (long) Math.sqrt(high);
		for (long i = 1; i < max; i++) {
			if (isPalim(i)) {
				long t = i*i;
				if (isPalim(t)) {
					l.add(t);
				}
			}
		}		
		return l.toArray(new Long[0]);	
	}
	
	private boolean isPalim(long l) {
		char[] c = Long.toString(l).toCharArray();		
		for (int i = 0; i < (c.length / 2); i++) {
			if (c[i] != c[c.length - 1 - i]) return false;
		}	
		return true;
	}
	
	
	private void solve() {
		long low = sc.nextLong();
		long high = sc.nextLong();
		
		int count = 0;
		for (long i : allFair) {
			if (low <= i && high >= i) count++;
		}
		write(count);
	}
	
	private void write(String s) {
		pw.write(s);
		if(log) System.out.print(s);
	}
	
	private void write(int i) 	{ write(Integer.toString(i)); }
	private void write(long i)  { write(Long.toString(i)); }
	
	public static void main(String[] args) {
		try {
			new C();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
