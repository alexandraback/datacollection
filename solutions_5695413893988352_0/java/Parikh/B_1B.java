package coding;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class B_1B {

	public static List<String> lista;
	public static List<String> listb;

	public static void main(String args[]) throws IOException {
		FileReader fileReader = new FileReader(
				"/home/parikh/Downloads/B-small-attempt1.in");
		BufferedReader obj = new BufferedReader(fileReader);
		PrintWriter write = new PrintWriter(new File("/home/parikh/output.txt"));
		String l = obj.readLine();
		int t = Integer.parseInt(l);
		for (int k = 1; k <= t; k++) {
			String inp = obj.readLine();
			String str[] = inp.split(" ");
			String a = str[0];
			String b = str[1];
			System.out.println(a + " " + b);
			int q1 = 0;
			int q2 = 0;
			lista = new ArrayList<String>();
			listb = new ArrayList<String>();
			int min = Integer.MAX_VALUE;
			List<Integer> minusone = new ArrayList<Integer>();
			int ans[] = new int[a.length()];
			for (int i = 0; i < a.length(); i++) {
				char c = a.charAt(i);
				if (c == '?') {
					q1++;
					minusone.add(i);
				} else {
					ans[i] = c - '0';
				}
			}
			recA(a, q1, minusone, ans);
			minusone = new ArrayList<Integer>();
			ans = new int[a.length()];
			for (int i = 0; i < b.length(); i++) {
				char c = b.charAt(i);
				if (c == '?') {
					q2++;
					minusone.add(i);
				} else {
					ans[i] = c - '0';
				}
			}
			recB(b, q2, minusone, ans);
			String ansa = "";
			String ansb = "";
			
			Collections.sort(lista);
			Collections.sort(listb);
			System.out.println(lista);
			System.out.println(listb);
			for (int i = 0; i <lista.size(); i++) {

				for (int j = 0; j<listb.size(); j++) {
					int aa = Integer.parseInt(lista.get(i));
					int bb = Integer.parseInt(listb.get(j));
					int val = Math.abs(aa - bb);
					if (val < min) {
						min = val;
						ansa = lista.get(i);
						ansb = listb.get(j);
					}

				}
			}

			write.println("Case #" + k + ": " + ansa + " " + ansb);
		}

		write.close();
	}

	public static void recA(String a, int q, List<Integer> minus, int ans[]) {

		if (q == 0) {

			String s = "";
			for (int i = 0; i < a.length(); i++)
				s += ans[i];
			lista.add(s);
			return;
		}

		int idx = minus.get(q - 1);
		for (int i = 9; i >= 0; i--) {
			ans[idx] = i;
			recA(a, q - 1, minus, ans);
		}

	}

	public static void recB(String a, int q, List<Integer> minus, int ans[]) {

		if (q == 0) {

			String s = "";
			for (int i = 0; i < a.length(); i++)
				s += ans[i];
			listb.add(s);
			return;
		}

		int idx = minus.get(q - 1);
		for (int i = 9; i >= 0; i--) {
			ans[idx] = i;
			recB(a, q - 1, minus, ans);
		}
	}
}
