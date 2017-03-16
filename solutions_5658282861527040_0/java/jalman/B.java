import java.io.*;
import java.util.*;

public class B{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());

		for(int p = 0; p < N; p++) {
			String[] s = br.readLine().split(" ");

			int a = Integer.parseInt(s[0]);
			int b = Integer.parseInt(s[1]);
			int c = Integer.parseInt(s[2]);

/*			s[0] = toBinary(a);
			s[1] = toBinary(b);
			s[2] = toBinary(c);

			int len = Math.max(s[0].length(), s[1].length());
			len = Math.max(len, s[2].length());

			while(s[0].length() < len) s[0] = "0" + s[0];
			while(s[1].length() < len) s[1] = "0" + s[1];
			while(s[2].length() < len) s[2] = "0" + s[2];

			long[][] x = new long[len+1][8];

			x[0][0] = 1;

			for(int i = 1; i < len+1; i++) {
				char ab = s[0].charAt(i-1);
				char bb = s[1].charAt(i-1);
				char cb = s[2].charAt(i-1);

				if(cb == '1' || ab == '0' || bb == '0') x[i][0] = x[i-1][0];



			}
*/

			long ans = 0;
			for(int i = 0; i < a; i++) for(int j = 0; j < b; j++) {
				if((i & j) < c) ans++;
			}

			pw.println("Case #" + (p+1) + ": " + ans);
		}


		pw.flush();
		pw.close();

	}

	public static String toBinary(int a) {
		String ret = "";
		int b = a;
		while(b>0) {
			if(b % 2 == 0) {
				ret = "0" + ret;
			} else {
				ret = "1" + ret;
			}
			b /= 2;
		}

		return ret;
	}
}