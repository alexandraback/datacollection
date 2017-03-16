import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class A {

	Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
	static final String FILENAME = "A-small-attempt0";
//	static final String FILENAME = "A-small-practice";
	static final String IN = FILENAME + ".in";
	static final String OUT = FILENAME + ".out";
	PrintStream out;

	long pgcd(long a, long b) { 
		if (a < b) 
			return (pgcd(b, a));
		else if (b == 0) 
			return (a);
		else
			
			return (pgcd(b, a % b));

	} 
	private void solve() {
		String s = sc.next();
		String gen[] = s.split("/");
		long n= Long.valueOf(gen[0]);
		long d=Long.valueOf(gen[1]);
		long pgcd = pgcd(n,d);
		n=n/pgcd;
		d=d/pgcd;
		int i =0;
		while(i<62&&((d>>>i)&1)==0){
			i++;
		}
		if((d>>>i)==1&&d>>>(i+1)==0){
			i=0;
			while(i<62&&((d>>>i))>n){
				i++;
			}
			out.print(i);
		}else{
			out.print("Impossible");
		}
		
			
	}

	private void run() throws Exception {
		sc.useLocale(Locale.US);
		out = new PrintStream(new FileOutputStream(OUT));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sc.nextLine();
			out.print("Case #" + i + ": ");
			solve();
			out.println();
		}
		sc.close();
		out.close();
	}

	public static void main(String args[]) throws Exception {
		new A().run();
	}

}