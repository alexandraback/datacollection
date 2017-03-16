import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;


public class B {

	public static void main(String[] args) throws Exception {
		new B().run();
	}
	
	int res, n, p[];
	boolean w[], was[];
	String s[];
	
	private void run() throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("src\\input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int tc = sc.nextInt();
		p = new int[100];
		w = new boolean[100];
		s = new String[100];
		was = new boolean[26];
		for (int t = 1; t <= tc; t++) {
			res = 0;
			n = sc.nextInt();
			for (int i = 0; i < n; i++)
				s[i] = sc.next();
			Arrays.fill(w, false);
			go(0);
			pw.printf("Case #%d: %d\n", t, res);
			System.err.println(t);
		}		
		pw.close();
		sc.close();
	}

	private void go(int i) {
		if (i == n) {
			check();
			return;
		}
		for (int j = 0; j < n; j++)
			if (!w[j]) {
				w[j] = true;
				p[i] = j;
				go(i + 1);
				w[j] = false;
			}
	}

	private void check() {
		// TODO Auto-generated method stub
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++)
			sb.append(s[p[i]]);
		char[] t = sb.toString().toCharArray();
		int i = 0;
		Arrays.fill(was, false);
		
		while (i < t.length) {
			int j = i;
			while (j < t.length && t[i] == t[j])
				j++;
			if (was[t[i] - 'a'])
				return;
			was[t[i] - 'a'] = true;
			i = j;
		}
		res++;
	}

}
