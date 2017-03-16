import java.io.*;
import java.util.*;

public class something {
	
	public static boolean ev(char ch) {
	  return ((ch == 'a') || (ch == 'u') || (ch == 'e') || (ch == 'i') || (ch == 'o'));
	}
	
	public static void main(String args[]) throws IOException {
		Scanner in = new Scanner(new File("A-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		
		int t;
		String s;

		t = in.nextInt();
		s = in.nextLine();
		for (int _t = 1; _t <= t; _t++) {
			long last = 0;
			s = in.nextLine();
			int j = s.length() - 1;
		    long n = 0;
		    long ten = 1;
		    long ans = 0;
		    while (s.charAt(j) != ' ') {
		      n = n + ten * (s.charAt(j) - '0');
		      ten *= 10;
		      j--;
		    }
		    int cnt = 0;
		    for (int i = 0; i < j; i++) {
		      if (ev(s.charAt(i)))
		        cnt = 0;
		      else
		        cnt++;
		      long i1 = i + 1;
		      if (cnt >= n) {
		        ans += (i1 - n + 1 - last) * (j - i1 + 1);
		        last = i1 - n + 1;
		      }
		    }
		    out.println("Case #" + _t + ": " + ans);
		}


		in.close();
		out.close();
		
	}
	
}