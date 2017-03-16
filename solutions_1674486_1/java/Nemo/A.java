import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;


public class A {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new File(A.class.getSimpleName() + "-large.out"));
		int t = in.nextInt();
		for (int i = 0; i < t; i ++ ) {
			String s = "Case #" + (i+1) + ": " + new A().solve(in);
			out.println(s);
			System.out.println(s);
		}
		out.close();
	}

	private String solve(Scanner in) {
		int n = in.nextInt();
		D[] ds = new D[n];
		for (int i = 0; i < n; i ++ ) {
			D d = new D(i+1);
			int p = in.nextInt();
			d.p = new int[p];
			for (int j = 0; j < p; j ++) {
				d.p[j] = in.nextInt();
			}
			ds[i] = d;
		}
		List<D> list = topsort(ds);
		for (int i = 0; i < list.size(); i ++) {
			D d = list.get(i);
			d.stat = 0;
		}
		boolean f = dfs(list, ds);
		if (f) return "Yes";
		return "No";
	}
	
	private boolean dfs(List<D> list, D[] ds) {
		for (int i = 0; i < list.size(); i ++) {
			D cur = list.get(i);
			if (cur.stat != 0) continue;
			Stack<D> stack = new Stack<D>();
			stack.push(cur);
			cur.stat =1;
			cur.root = cur.no;
			while (!stack.isEmpty()) {
				D now = stack.pop();
				for (int j = 0; j < now.p.length; j ++) {
					if (ds[now.p[j]-1].stat == 0 || ds[now.p[j]-1].root != cur.root) {
						stack.push(ds[now.p[j]-1]);
						ds[now.p[j]-1].stat = 1;
						ds[now.p[j]-1].root = cur.root;
					} else {
						return true;
					}
				}
			}
		}
		return false;
	}

	private List<D> topsort(D[] ds) {
		List<D> res = new ArrayList<D>();
		for (int i = 0; i < ds.length; i ++) {
			if (ds[i].stat != 0) continue;
			D cur = ds[i];
			Stack<D> stack = new Stack<D>();
			stack.push(cur);
			cur.stat = 1;
			while (!stack.isEmpty()) {
				D now = stack.peek();
				boolean f = false;
				for (int j = 0; j < now.p.length; j ++) {
					if (ds[now.p[j]-1].stat == 0) {
						f = true;
						stack.push(ds[now.p[j]-1]);
						ds[now.p[j]-1].stat = 1;
					}
				}
				if (!f) {
					now.stat = 2;
					res.add(0, now);
					stack.pop();
				}
			}
		}
		return res;
	}

	static class D {
		public D(int i) {
			this.no = i;
		}
		int no;
		int[] p;
		int stat=0;
		int root=0;
		
	}
}
