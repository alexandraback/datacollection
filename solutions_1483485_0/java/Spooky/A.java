package qual2012;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class A {

	static BufferedReader in;
	static PrintWriter out;
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		//out = new PrintWriter(System.out);
		//in = new StreamTokenizer(new BufferedReader(new FileReader("a.in")));
		out = new PrintWriter(new FileWriter("a.out"));
		
		int n = Integer.valueOf(in.readLine());
		for (int i = 0; i < n; i++) {
			out.print("Case #" + (i+1) + ": ");
			String x = in.readLine();
			for (int j = 0; j < x.length(); j++) {
				if (x.charAt(j) != ' ') {
					out.print(map[x.charAt(j)-'a']);
				}
				else {
					out.print(' ');
				}
			}
			out.println();
		}
		
		out.flush();
	}
	
	static char[] map = {'y', 'h', 'e', 's', 'o', 'c', 'v', 
		'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r',
		'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'
	};
	
}



