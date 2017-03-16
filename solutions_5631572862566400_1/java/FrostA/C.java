import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class C {
//	 static PrintStream writer = System.out;
	public static int[] a;
	public static int[] parent;
	public static int[] count;
	public static boolean[] cp;
	public static boolean[] visit;
	public static int n;

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner sc = new Scanner(new File("./src/C-large.in"));
		int t = sc.nextInt();
		PrintWriter writer = new PrintWriter("./src/C-large.out", "UTF-8");

		for (int k = 1; k <= t; k++) {
			writer.print("Case #" + k + ": ");
			n = sc.nextInt();

			a = new int[1000];
			parent = new int[1000];
			for (int i = 0; i < n; i++)
				parent[i] = -1;
			count = new int[1000];

			cp = new boolean[1000];
			visit = new boolean[1000];

			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt() - 1;
			}

			for (int i = 0; i < n; i++)
				if (i == a[a[i]]) {
					cp[i] = true;
					visit[i] = true;
					parent[i] = i;
				}

//			 for (int i = 0; i < n; i++)
//			 writer.print(cp[i]+" ");
//			 writer.println();

			for (int i = 0; i < n; i++) {
				if (!visit[i])
					update(i);
			}

			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (cp[i])
					ans += count[i] + 1;
			}

			for (int i = 0; i < n; i++)
				if (visit[i] && parent[i] == -1)
					visit[i] = false;

//			writer.println(ans);
//
//			for (int i = 0; i < n; i++)
//			writer.print(visit[i]+" ");
//			writer.println();

			for (int i = 0; i < n; i++) {
				if (visit[i])
					continue;
				parent[i] = 0;
				visit[i] = true;

				int xxx = search(a[i], 1);

//				 writer.println(xxx);

				ans = Math.max(ans, xxx);
				
				change(i);
			}
			writer.println(ans);
		}

		writer.close();
		sc.close();
	}

	private static void change(int i) {
		// TODO Auto-generated method stub
		if(parent[i] == 100000)
			return;
		parent[i] = 100000;
		change(a[i]);
	}

	private static int search(int i, int num) {
		// TODO Auto-generated method stub
//		 writer.println(i + " " + num);

		if (visit[i])
			return num - parent[i];
		visit[i] = true;

		parent[i] = num;
		return search(a[i], num + 1);
	}

	private static void update(int i) {
		// TODO Auto-generated method stub

		visit[i] = true;

		if (cp[a[i]]) {
			count[i] = 1;
			parent[i] = a[i];
			visit[i] = true;

			if (parent[i] != -1)
				count[parent[i]] = Math.max(count[parent[i]], count[i]);

			// writer.println("WTF+ "+ i + " "+ count[i]+" "+count[parent[i]]);

			return;
		}
		if (!visit[a[i]])
			update(a[i]);

		parent[i] = parent[a[i]];
		count[i] = count[a[i]] + 1;
		if (parent[i] != -1)
			count[parent[i]] = Math.max(count[parent[i]], count[i]);
	}

}
