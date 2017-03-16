import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Scanner;

class Problem3 {
	
	public static final long N_MIN = 1;
	public static final long N_MAX = 100000000000000L;
	
	private long T;
	private ArrayList<Long> perfectNumbers;
	
	Problem3() {
		perfectNumbers = new ArrayList<Long>();
		
		for (long i = N_MIN; i <= Math.sqrt(N_MAX) + 1; ++i) {
			if (isFair(i) && isFair(i * i)) {
				perfectNumbers.add(i * i);
			}
		}		
	}
	
	private boolean isFair(long n) {
		String str = String.valueOf(n);
		return str.equals(new StringBuffer().append(str).reverse().toString());
	}
	
	public void solve(String in, String out) throws IOException {
		Scanner scanner = new Scanner(new File(in));
		Writer outFile = new FileWriter(out);
		
		T = scanner.nextLong();
		
		for (int i = 1; i <= T; ++i) {
			long A = scanner.nextLong();
			long B = scanner.nextLong();
			int nNumbers = getNInInterval(A, B);
			String str = "Case #"+i+": " + nNumbers+'\n';
			outFile.write(str);
			System.out.print(str);
		}
		
		outFile.flush();
		outFile.close();		
	}

	private int getNInInterval(long a, long b) {
		
		int min = 0;
		int max = perfectNumbers.size() - 1;
		for ( ; perfectNumbers.get(min) < a; ++min)
			;
		for ( ; perfectNumbers.get(max) > b; --max)
			;
		return (max - min + 1);
	}		
	
	public void print() {
		for (Long n : perfectNumbers) {
			System.out.println(n);
		}
	}
}

public class Launcher {

	public static void main(String[] args) {
		Problem3 problem3 = new Problem3();
		try {
			problem3.solve("C-small-attempt0.in.txt", "out");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
