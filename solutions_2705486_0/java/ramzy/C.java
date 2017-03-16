package codejam.y2013.round1B;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class C {
	
	private static int[][] solved = new int[4000][4000];
	private static TreeSet<String> dic = new TreeSet<String>();
	
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new FileReader("/Users/ramzy/Desktop/garbled_email_dictionary.txt"));
		
		while(s.hasNext()) {
			String w = s.next();
			dic.add(w);
			for(int i = 0 ; i < w.length(); i++) {
				dic.add(w.substring(0,i) + "-" + w.substring(i+1,w.length()));
			}
			if(w.length() <= 5) continue;
			for(int i = 5 ; i < w.length(); i++) {
				for(int j = 0 ; j < i-5; j++) {
					dic.add(w.substring(0,j) + "-" + w.substring(j+1,i) + "-" + w.substring(i+1,w.length()));
				}
			}
		}
		System.out.println(dic.size());
		
		Scanner input = new Scanner(new FileReader("inputs/1B/C.in"));
		PrintWriter output = new PrintWriter("inputs/1B/C.out");

		String out;
		int N = input.nextInt();
		for(int c = 1; c <= N; c++) {
			String w = input.next();
			for(int i = 0; i < solved.length; i++) {
			    Arrays.fill(solved[i], -1);
			}
			out = "Case #" + c + ": " + solve(w, 0, 0);
			output.println(out);
			System.out.println(out);
		}
		input.close();
		output.close();
	}

	
	private static int solve(String w, int x, int y) {
		if(w.length()-1 == x) {
			if(dic.contains(String.valueOf(w.charAt(w.length()-1))))
				return 0;
			else 
				return 1;
		}
		
		if(x >= w.length()) return 0;
		
		if(solved[x][y] != -1)
			return solved[x][y];
	
		int min = 4000;
		for(int i2 = 1; i2 < 10; i2++) {
			if(x+i2+1 > w.length()) break;
			String w2 = w.substring(x, x+i2+1);
			
			if(dic.contains(w2)) {
				solved[i2+x+1][0] = solve(w, i2+x+1, 0);
				min = Math.min(min, solved[i2+x+1][0]);
				continue;
			}
			if(y >= w2.length()) continue;
			for(int i = y; i < w2.length(); i++) {
				if(dic.contains(w2.substring(0,i) + "-" + w.substring(i+1,w2.length()))) {
					solved[i2+x+1][Math.max(0, 5-w2.length()+i-1)] = solve(w, i2+x+1, Math.max(0, 5-w2.length()+i-1));
					min = Math.min(min, 1+solved[i2+x+1][Math.max(0, 5-w2.length()+i-1)]);
					continue;
				}
			}
			if(y+5 >= w2.length() || w2.length() >= 5) continue;
			for(int i = 5+y; i < w.length(); i++) {
				for(int j = y ; j < i-5; j++) {
					if(dic.contains(w.substring(0,j) + "-" + w.substring(j+1,i) + "-" + w.substring(i+1,w.length()))) {
						solved[i2+x+1][Math.max(0, 5-w2.length()+i-1)] = solve(w, i2+x+1, Math.max(0, 5-w2.length()+i-1));
						min = Math.min(min,2+solved[i2+x+1][Math.max(0, 5-w2.length()+i-1)]);
					}
				}
			}
		}
		return min;
	}
	
	
}