import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws Exception {
		new A().run();
	}
	
	class Item {
		long p, q;
		Item(long p, long q) {
			this.p = p;
			this.q = q;
		}
		@Override
		public int hashCode() {
			return (int) (p * 1000000007 + q);
		}
		
		@Override
		public boolean equals(Object obj) {
			Item o = (Item) obj;
			return p * o.q - q * o.p == 0;
		}
	}
	
	HashMap<Item, Integer> h;
	
	private void run() throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("src\\input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int tc = sc.nextInt();
		h = new HashMap<Item, Integer>();
		for (int t = 1; t <= tc; t++) {
			h.clear();
			String[] s = sc.next().split("/");
			long p = Long.parseLong(s[0]);
			long q = Long.parseLong(s[1]);
			long g = gcd(p, q);
			p /= g;
			q /= g;
			go(0, p, q);
			Item first = new Item(p, q);
			Integer res = h.get(first);			
			if (!(res == null || res.intValue() == Integer.MAX_VALUE))
				pw.printf("Case #%d: %d\n", t, res.intValue());				
			else
				pw.printf("Case #%d: impossible\n", t);
		}
		pw.close();
		sc.close();
	}

	private void go(int i, long p, long q) {
		// TODO Auto-generated method stub
		if (i == 40)
			return;
		if (p == 1 && q == 1) {
			Item cur = new Item(p, q);
			h.put(cur, 0);
		}
		if (q % 2 == 1)
			return;
		Item cur = new Item(p, q);
		if (h.containsKey(cur))
			return;
		long up = q / 2;
		int min = Integer.MAX_VALUE;
		for (long b = 1; b * b <= up; b++) 
			if (up % b == 0) {
				long d = up / b;
				for (long a = 0; a * d <= p; a++) {
					if ((p - a * d) % b != 0)
						continue;
					long c = (p - a * d) / b;
					go(i + 1, a, b);
					go(i + 1, c, d);
					Item i1 = new Item(a, b);
					if (h.containsKey(i1) || a == 0) {
						Item i2 = new Item(c, d);
						if (h.containsKey(i2) || c == 0) {
							Integer r1 = h.get(i1);
							Integer r2 = h.get(i2);
							min = Math.min(r1 == null ? Integer.MAX_VALUE : r1.intValue() + 1, min);
							min = Math.min(r2 == null ? Integer.MAX_VALUE : r2.intValue() + 1, min);
						}
					}
				}
			}
		if (min < Integer.MAX_VALUE)
			h.put(cur, min);
	}

	private long gcd(long a, long b) {
		while (b != 0) {
			long c = a % b;
			a = b;
			b = c;
		}
		return a;
	}

}
