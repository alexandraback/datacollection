package j2013.r1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

@SuppressWarnings("all")
public class B {

	private static final boolean LOG = true;
	private static final String FILE_NAME = "B-small-attempt0";	
	
	private final String relativePath;
	{
		String p = getClass().getPackage().getName();
		p = p.replace('.', '\\');
		relativePath = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private final Scanner sc;
	private PrintWriter pw;
	
	public B () throws FileNotFoundException {
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
	
	int x = 0;
	int y = 0;
	private void solve() {
		int X = sc.nextInt();
		int Y = sc.nextInt();

		int i = 1;
		while (X != x && i < 500) {
			if (X >= x + i) {
				addX(i);
			} else {
				addX(-i);
			}
			i++;
		}
		
		while (Y != y && i < 500) {
			if (Y >= y + i) {
				addY(i);
			} else {
				addY(-i);
			}
			i++;
		}
		x = 0;
		y = 0;
	}
	void addX(int i) {
		if (i > 0) {
			write("E");
		}else {
			write("W");
		}
		x += i;
	}
	void addY(int i) {
		if (i > 0) {
			write("N");
		}else {
			write("S");
		}
		y += i;
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
			new B();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}






















