package gcj2013.R1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemA {
	//public static final String input = "/tmp/ProblemA.sample.in";
	public static final String input = "/tmp/A-small-attempt1.in";
	//public static final String output = "/tmp/ProblemA.sample.out";
	public static final String output = "/tmp/ProblemA.small.out";

	public static void main(String[] args) throws IOException {
//		Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new FileReader(input));
		int testCase = sc.nextInt();
		
		for (int i=0; i<testCase; i++) {
			String name = sc.next();
			int n = sc.nextInt();
			
//			System.out.println("[" + name + "] : " + n);
			write("Case #" + (i+1) + ": " + solve(name, n) + "\n");
//			System.out.println();
		}
	}
	
	private static int solve(String name, int n) {
		int length = name.length();
		int value = 0;
		
		for (int i=0; i<=length-1; i++) {
			for (int j=i+1; j<=length; j++) {
				int count;
				CharSequence cs = name.subSequence(i, j);				
				count = countCons(cs);
//				System.out.print(cs + " : " + count);
				
				if (count >= n) {
//					System.out.println("!");
					value++;
				} else {
//					System.out.println();
				}
			}
		}
		
		return value;
	}
	
	private static int countCons(CharSequence cs) {		
		int count = 0;
		int length = cs.length();
		int tmp = 0;
		
		for (int i=0; i<length; i++) {
			switch(cs.charAt(i)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				if (count < tmp) count = tmp;
				tmp = 0;
				break;
			default :
				tmp++;	
			}
		}
		
		if (count < tmp) count = tmp;
		
		return count;
	}
	
	private static void write(String buf) {
		FileWriter fw;
		
		try {
			fw = new FileWriter(output, true);
			
			fw.write(buf);
			fw.flush();
		} catch(Exception e) {
			e.printStackTrace();
		}
		
	}
}
