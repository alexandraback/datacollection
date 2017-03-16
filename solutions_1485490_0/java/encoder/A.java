package Reound1C;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Stack;

public class A {
	static class ASt {
		public ASt(long n, long t) {
			this.n = n;
			this.t = t;
		}
		long n;
		long t;
	}
	
	static class BSt {
		long n;
		long t;
		public BSt(long n, long t) {
			this.n = n;
			this.t = t;
		}
	}

	public static void main(String[] args) {
		try {
			FileWriter w = new FileWriter(new File("E:\\output.out"));
			BufferedReader r = new BufferedReader(new FileReader(new File("E:\\C-small-attempt2.in")));
			long numbeOfCases = Integer.parseInt(r.readLine());
			for(long t = 0; t < numbeOfCases; t++) {
				String[] s = r.readLine().split(" ");
				int n = Integer.parseInt(s[0]);
				int m = Integer.parseInt(s[1]);
				
				ASt[] a = new ASt[n]; 
				s = r.readLine().split(" ");
				for(int i = 0; i < n; i++)
					a[i] = new ASt(Long.parseLong(s[2 * i]), Long.parseLong(s[2 * i + 1]));
				
				BSt[] b = new BSt[m]; 
				s = r.readLine().split(" ");
				for(int i = 0; i < m; i++)
					b[i] = new BSt(Long.parseLong(s[2 * i]), Long.parseLong(s[2 * i + 1]));
				
				int si = 0, sj = 0;
				/*
				 * for(long i = sj; i < m; i++) {
						if(a[si].t == b[i].t) {
							pi += Math.min(a[si].n, b[i].n);
							cj = i;
							break;
						}
					}
					for(long i = si; i < n; i++) {
						if(b[sj].t == a[i].t) {
							pj += Math.min(b[sj].n, a[i].n);
							ci = i;
							break;
						}
					}
				 */
				class Cache {
					int si, sj;
					ASt[] a;
					BSt[] b;
				}
				long maxP = 0;
				Stack<Cache> st = new Stack<Cache>();
				
				Cache c = new Cache();
				st.add(c);
				c.si = si;
				c.sj = sj;
				c.a = copy(a);
				c.b = copy(b);
				st.add(c);
				
				while(!st.isEmpty()) {
					Cache pop = st.pop();
					si = pop.si;
					sj = pop.sj;
					a = pop.a;
					b = pop.b;
					long p = 0;
					while(si < n && sj < m) {
						if(a[si].t == b[sj].t) {
							p += Math.min(a[si].n, b[sj].n);
							switch((int)Math.signum(a[si].n - b[sj].n)){
								case 1:
									a[si].n -= b[sj].n;
									b[sj].n = 0;
									sj++;
								break;
								case -1:
									b[sj].n -= a[si].n;
									a[si].n = 0;
									si++;
								break;
								case 0:
									a[si].n = 0;
									b[sj].n = 0;
									si++;
									sj++;
								break;
							}
						} else {
							si++;
							c = new Cache();
							st.add(c);
							c.si = si;
							c.sj = sj + 1;
							c.a = copy(a);
							c.b = copy(b);
							st.add(c);
						}
					}
					maxP = Math.max(maxP, p);
				}
				w.write("Case #" + (t + 1) + ": " + maxP);
				//System.out.print("Case #" + (t + 1) + ": " + maxP);
				if(t < numbeOfCases - 1)
					//System.out.print("\n");
					w.write("\n");
				System.out.println(t);
			}
			w.close();
			r.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static ASt[] copy(ASt[] a) {
		ASt[] ac = new ASt[a.length];
		for(int i = 0; i < a.length; i++)
			ac[i] = new ASt(a[i].n, a[i].t);
		return ac;
	}
	private static BSt[] copy(BSt[] a) {
		BSt[] ac = new BSt[a.length];
		for(int i = 0; i < a.length; i++)
			ac[i] = new BSt(a[i].n, a[i].t);
		return ac;
	}
}