package codejam.y2013.round1C;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("inputs/1C/A.in"));
		PrintWriter output = new PrintWriter("inputs/1C/A.out");

		String out;
		int N = input.nextInt();
		for(int c = 1; c <= N; c++) {
			String name = input.next();
			int n = input.nextInt();
			out = "Case #" + c + ": " + solve(name, n);
			output.println(out);
			System.out.println(out);
		}
		input.close();
		output.close();
	}
	
	private static int solve(String name, int n) {
		if(name.length() < n) return 0;
		ArrayList<Integer> ind = new ArrayList<Integer>();
		ArrayList<Integer> d = new ArrayList<Integer>();
		ArrayList<Integer> l = new ArrayList<Integer>();
		String temp;
		int last = 0;
		for(int i = 0; i < name.length()-n+1; i++) {
			temp = name.substring(i, i+n);
			if(isConstant(temp)) {
				if(i != 0) {
					if(i-last <= n-1) {
						d.add(i-last);
					} else {
						d.add(-1);						
					}
				} else {
					d.add(-1);
				}
				l.add(last);
				ind.add(i);
				last = i;
			}
		}
		
		int sum = 0;
		int len = name.length();
		for(int i = 0; i < ind.size(); i++) {
			last = l.get(i);
			int c = ind.get(i);
			if(i == 0) last = -1;
			sum += (c+1-last-1)*(len-n-c+1);
		}
		
		return sum;
	}
/*	
	if(d.get(i) == -1) {
		sum += (i*(len-n-i))+ 1;
		if(i == 0) sum += len-n;
		if(len-n-i == 0) sum += i;
	} else {
		
	}
*/
	
	private static boolean isConstant(String str) {
		for(int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				return false;
			}
		}
		return true;
	}
	
}

