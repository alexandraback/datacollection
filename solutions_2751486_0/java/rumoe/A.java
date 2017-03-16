package j2013.r1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

@SuppressWarnings("all")
public class A {

	private static final boolean LOG = true;
	private static final String FILE_NAME = "test";	
	
	private final String relativePath;
	{
		String p = getClass().getPackage().getName();
		p = p.replace('.', '\\');
		relativePath = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private final Scanner sc;
	private PrintWriter pw;
	
	public A () throws FileNotFoundException {
		sc = new Scanner(new File(relativePath + ".in"));	
		pw = new PrintWriter(relativePath + ".out"); 
			
		int cases = sc.nextInt();	
		for (int i = 1; i <= cases; i++) {
			write("Case #" + i + ": ");
			solve();
			writeln();
		}	

		pw.close();
		System.out.println("\nDONE!");
	}
	
	private void solve() {
		String name = sc.next();
		int N = sc.nextInt();
		char[] chars = name.toCharArray();
		
		long rank = 0;
		int pos = 0;
		outer:
		for (int i = 0; i < chars.length - (N - 1) ; i++) {
			for (int j = 0; j < N; j++) {
				char c = chars[j+i];
				if (c == 'a' || c == 'e' || c=='i' || c == 'o' || c=='u'){
					i = j+i;
					continue outer;	
				}
			}
			
			rank += (chars.length - (N - 1) - i) * ((i+1) - pos);
			pos = i+1;
		}

		write(rank);
	}
	
	private void write(long l) {
		write(Long.toString(l));
	}
	private void write(int i) {
		write(Integer.toString(i));
	}
	
	private void write(char c) {
		write(Character.toString(c));
	}
	private void write(String s) {
		pw.write(s);
		if(LOG) System.out.print(s);
	}
	
	private void writeln() {
		write("\n");
	}
	
	public static void main(String[] args) {
		try {
			new A();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}






















