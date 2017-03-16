import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class ProblemB {

	static PrintStream out = System.out;

	public static void main(String[] args) throws FileNotFoundException {
		new ProblemB().run();
	}

	public void run() throws FileNotFoundException {
		//Scanner in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Documents/Taktik/Sources/problems/files/inb")));
		//Scanner in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Downloads/B-small.in")));
		Scanner in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Downloads/B-large.in")));
		int size = in.nextInt();

		for (int p = 0 ; p < size ; p++) {
			out.println("Case #" + (p+1) + ": " + solve(in.next(),in.next()));
		}
	}

	public String solve(String cScoreS,String jScoreS) {
		char[] cs = cScoreS.toCharArray();
		char[] js = jScoreS.toCharArray();
		if (cs.length > js.length) {
			char[] newjs = new char[cs.length];
			System.arraycopy(js, 0, newjs, newjs.length - js.length, js.length);
			for (int i = 0 ; i < newjs.length - js.length; i++) {
				newjs[i] = '0';
			}
			js = newjs;
		} else {
			char[] newcs = new char[js.length];
			System.arraycopy(cs, 0, newcs, newcs.length - cs.length, cs.length);
			for (int i = 0 ; i < newcs.length - cs.length; i++) {
				newcs[i] = '0';
			}
			cs = newcs;
		}

		Sol sol = diff(cs, js, 0, 0, "", "");
		return sol.cs + " " + sol.js;
	}

	public Sol diff(char[] cs, char[] js, int depth, int greater, String solcs, String soljs) {
		if (depth == js.length) {
			return new Sol(solcs, soljs);
		}

		char csc = cs[depth];
		char jsc = js[depth];

		switch (greater) {
			case -1: {
				if (csc == '?') {
					if (jsc == '?') {
						return diff(cs, js, depth + 1, greater, solcs + '9', soljs + '0');
					} else {
						return diff(cs, js, depth + 1, greater, solcs + '9', soljs + jsc);
					}
				} else if (jsc == '?') {
					return diff(cs, js, depth + 1, greater, solcs + csc, soljs + '0');
				} else {
					return diff(cs, js, depth + 1, greater, solcs + csc, soljs + jsc);
				}
			}
			case 1: {
				if (csc == '?') {
					if (jsc == '?') {
						return diff(cs, js, depth + 1, greater, solcs + '0', soljs + '9');
					} else {
						return diff(cs, js, depth + 1, greater, solcs + '0', soljs + jsc);
					}
				} else if (jsc == '?') {
					return diff(cs, js, depth + 1, greater, solcs + csc, soljs + '9');
				} else {
					return diff(cs, js, depth + 1, greater, solcs + csc, soljs + jsc);
				}
			}
			case 0 : {
				if (csc == '?') {
					if (jsc == '?') {
						Sol t1 =  diff(cs, js, depth + 1, greater, solcs + '0', soljs + '0');
						Sol t2 =  diff(cs, js, depth + 1, -1, solcs + '0', soljs + '1');
						Sol t3 =  diff(cs, js, depth + 1, 1, solcs + '1', soljs + '0');

						Sol min;

						int comp = t1.compareTo(t2);
						if (comp > 0) {
							min = t2;
						} else {
							min = t1;
						}

						 comp = min.compareTo(t3);
						if (comp > 0) {
							return t3;
						} else {
							return min;
						}


					} else {
						Sol t1 =  diff(cs, js, depth + 1, greater, solcs + jsc, soljs + jsc);
						Sol t2 =  diff(cs, js, depth + 1, 1, solcs + (char)(jsc + 1), soljs + jsc);
						Sol t3 =  diff(cs, js, depth + 1, -1, solcs + (char)(jsc - 1), soljs + jsc);

						Sol min;

						int comp = t1.compareTo(t2);
						if (comp > 0) {
							min = t2;
						} else {
							min = t1;
						}

						comp = min.compareTo(t3);
						if (comp > 0) {
							return t3;
						} else {
							return min;
						}
					}
				} else if (jsc == '?') {
					Sol t1 =  diff(cs, js, depth + 1, greater, solcs + csc, soljs + csc);
					Sol t2 =  diff(cs, js, depth + 1, -1, solcs + csc, soljs + (char)(csc + 1));
					Sol t3 =  diff(cs, js, depth + 1, 1, solcs + csc, soljs + (char)(csc - 1));

					Sol min;

					int comp = t1.compareTo(t2);
					if (comp > 0) {
						min = t2;
					} else {
						min = t1;
					}

					comp = min.compareTo(t3);
					if (comp > 0) {
						return t3;
					} else {
						return min;
					}
				} else {
					if (csc > jsc) {
						greater = 1;
						return diff(cs, js, depth + 1, greater, solcs + csc, soljs + jsc);
					} else if (csc < jsc) {
						greater = -1;
						return diff(cs, js, depth + 1, greater, solcs + csc, soljs + jsc);
					} else {
						return diff(cs, js, depth + 1, greater, solcs + csc, soljs + jsc);
					}
				}
			}
		}
		return null;

	}


	static class Sol implements Comparable<Sol>{

		static BigInteger big = new BigInteger("99999999999999999999");


		String cs;
		String js;

		public Sol(String cs, String js) {
			this.cs = cs;
			this.js = js;
		}

		public String getCs() {
			return cs;
		}

		public void setCs(String cs) {
			this.cs = cs;
		}

		public String getJs() {
			return js;
		}

		public void setJs(String js) {
			this.js = js;
		}


		public BigInteger diff() {
			if (cs.contains(":") || cs.contains("/") || js.contains(":") || js.contains("/")) {
				return big;
			}
			return new BigInteger(cs).subtract(new BigInteger(js)).abs();
		}


		@Override
		public int compareTo(Sol o) {
			int comp = this.diff().compareTo(o.diff());
			if (comp != 0) {
				return comp;
			}
			comp = this.cs.compareTo(o.getCs());
			if (comp != 0) {
				return comp;
			}
			return this.js.compareTo(o.getJs());
		}
	}

}
