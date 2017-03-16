import java.io.*;
import java.util.*;

public class A {
	static String name;
	static final String vowels = "aeiou";
	public static void main(String[] args) throws IOException {
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("A-small-attempt0.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter(new File("A-small-attempt0.out"));
		StringTokenizer st;
		int cases = Integer.parseInt(br.readLine().trim());
		for (int c = 1; c <= cases; c++) {
			st = new StringTokenizer(br.readLine());
			name = st.nextToken();
			int n = Integer.parseInt(st.nextToken());
			int res = 0;
			for (int i = 0; i < name.length(); i++) {
				for (int j = i+1; j <= name.length(); j++) {
					if(hasConsecutiveCons(n, i, j))
						res++;
				}
			}
			out.println("Case #" + c + ": " + res);
		}
		out.close();
	}
	public static boolean hasConsecutiveCons(int k, int st, int end) {
		int curr = 0;
		for (int i = st; i < end; i++) {
			char ch = name.charAt(i);
			if(vowels.indexOf(ch) >= 0) { // vowel
				if(curr >= k)
					return true;
				curr = 0;
			} else {
				curr++;
			}
		}
		return curr >= k;
	}
}