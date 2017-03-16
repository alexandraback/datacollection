package gcj2013.round1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class A {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(args[0]));
				
		int T = scanner.nextInt();
		for(int t=0; t<T; t++) {
			System.out.println("Case #" + (t+1) + ": " +  solve(scanner));
		}
	}

	private static long solve(Scanner scanner) {
		long value = 0;
		
		String name = scanner.next();
		long L = name.length();
		long n = scanner.nextInt();
		
		Pattern p = Pattern.compile("[^aeiou]{" + n + ",}");
		Matcher m = p.matcher(name);
		
		long start = 0;
		while(m.find()) {
			long before = m.start()-start+1;
			long after = L-m.end()+1;
			long extra = m.end()-m.start()-n;
			value += before*after + (before+after)*extra + extra*(extra-1)/2;
			
			start = m.start()+1+extra;
		}
		
		return value;
	}
}
