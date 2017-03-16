package coding;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class C_1B {
	public static int max = -1;

	public static void main(String args[]) throws IOException {
		FileReader fileReader = new FileReader(
				"/home/parikh/Downloads/C-small-attempt0(1).in");
		BufferedReader obj = new BufferedReader(fileReader);
		PrintWriter write = new PrintWriter(new File("/home/parikh/output.txt"));
		String l = obj.readLine();
		int t = Integer.parseInt(l);
		for (int k = 1; k <= t; k++) {
			l = obj.readLine();
			int n = Integer.parseInt(l);
			int a[] = new int[n];
			max = -1;
			Map<String, Integer> first = new HashMap<String, Integer>();
			Map<String, Integer> second = new HashMap<String, Integer>();
			List<String> finp = new ArrayList<String>();
			List<String> sinp = new ArrayList<String>();
			System.out.println(k);
			for (int i = 0; i < n; i++) {
				String inp = obj.readLine();
				String str[] = inp.split(" ");
				String f = str[0];
				String s = str[1];
				finp.add(f);
				sinp.add(s);
				if (first.get(f) != null) {
					int v = first.get(f);
					first.put(f, v + 1);
				} else {
					first.put(f, 1);
				}

				if (second.get(s) != null) {
					int v = second.get(s);
					second.put(s, v + 1);
				} else {
					second.put(s, 1);
				}
			}

			rec(first, second, finp, sinp, a, n);

			write.println("Case #" + k + ": " + max);
		}

		write.close();
	}

	public static void rec(Map<String, Integer> f, Map<String, Integer> s,
			List<String> finp, List<String> sinp, int a[], int n) {

		if (n == 0) {
//			System.out.println(n);
			Map<String, Integer> f1 = new HashMap<String, Integer>(f);
			Map<String, Integer> s1 = new HashMap<String, Integer>(s);
			// System.out.println(f1 +" " + s1);
			// System.out.println(a);
			boolean val = true;
			int count = 0;
			for (int i = 0; i < a.length; i++) {
				if (a[i] == 1) {
//					System.out.println(f1 + " " + s1);
					count++;
					String ff1 = finp.get(i);
					String ss1 = sinp.get(i);
					int v1 = f1.get(ff1);
					int v2 = s1.get(ss1);
//					System.out.println(ff1 + " " + ss1 + " " + v1 + " " + v2);
					if (v1 <= 1 || v2 <= 1) {
						val = false;
						break;
					} else {
						f1.put(ff1, v1 - 1);
						s1.put(ss1, v2 - 1);
					}
				}
			}
//			System.out.println(val);
			if (val) {
				if (count > max)
					max = count;
			}
			return;

		}

		for (int i = 0; i <= 1; i++) {
			a[n - 1] = i;
			rec(f, s, finp, sinp, a, n - 1);
		}

	}
}
