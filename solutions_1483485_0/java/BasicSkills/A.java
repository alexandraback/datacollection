package A;
import java.io.*;
import java.util.*;

public class A {
	
	static String[] a = {"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"};
	
	static String[] b = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	
	public static void main(String[] args) throws Exception {
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < a.length; ++ i) {
			for (int j = 0; j < a[i].length(); ++ j) {
				map.put((int) b[i].charAt(j), (int) a[i].charAt(j));
			}
		}
		
		map.put((int) 'z', (int) 'q');
		map.put((int) 'q', (int) 'z');
		
		BufferedReader in = new BufferedReader(new FileReader("src/A/in.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/A/out.txt")));
		
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; ++ i) {
			String st = in.readLine();
			String ans = "";
			for (int j = 0; j < st.length(); ++ j) {
				ans += (char) (int) map.get((int) st.charAt(j));
			}
			out.println("Case #" + (i + 1) + ": " + ans);
		}
		
		out.close();
	}
	
}
