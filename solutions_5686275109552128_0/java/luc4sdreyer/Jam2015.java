package gcj;

import java.awt.Point;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.Iterator;

public class Jam2015 {
	//10^4 <  Short.MAX_VALUE (2^15)   < 10^5
	//10^9 <  Integer.MAX_VALUE (2^31) < 10^10
	//10^18 < Long.MAX_VALUE (2^63)    < 10^20

	//static String size = "sample";
	//static String size = "small";
	//static String size = "large"=
	static String filename = "D:\\gcj\\2015\\Q\\B-small-attempt3";

	static String outputfile = filename + ".out";
	static MyScanner scan;
	static PrintStream out;

	public static void main(String[] args) throws NumberFormatException, IOException {
		scan = new MyScanner(new FileInputStream(filename+".in"));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream(outputfile)));
		System.out.println(Calendar.getInstance().getTime()+" - Started writing to: "+outputfile);
		
		//standingOvation();
		infiniteHouseOfPancakes4();
		//genInfiniteHouseOfPancakes();
		//genDijkstra();
		//dijkstra();

		System.out.println(Calendar.getInstance().getTime()+" - Finished writing to: "+outputfile);
		scan.close();
		out.close();
	}
	
	public static void genDijkstra() {
		ArrayList<String> output = new ArrayList<>();
		int maxX = 20;
		for (int len = 0; len < 6; len++) {
			int[] num = new int[len+1];
			do {
				for (int i = 1; i <= maxX; i++) {
					char[] s = new char[num.length];
					for (int j = 0; j < num.length; j++) {
						if (num[j] == 0) {
							s[j] = 'i';
						} else if (num[j] == 1) {
							s[j] = 'j';
						} else {
							s[j] = 'k';
						}
					}
					output.add(s.length + " " + i);
					output.add(new String(s));
				}
			} while (next_number(num, 3));
		}
		out.println(output.size());
		for (String string : output) {
			out.println(string);
		}
	}

	static int[][] dijkstraValue = {
		{ 0, 1, 2, 3 },
		{ 1, 0, 3, 2 },
		{ 2, 3, 0, 1 },
		{ 3, 2, 1, 0 },
	};
	
	static int[][] dijkstraSign = {
		{ 1, 1, 1, 1 },
		{ 1,-1, 1,-1 },
		{ 1,-1,-1, 1 },
		{ 1, 1,-1,-1 },
	};
	

	public static void dijkstra2() {
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			scan.nextInt();
			long x = scan.nextLong();
			char[] s = scan.next().toCharArray();
			int[] num = new int[s.length];
			for (int i = 0; i < s.length; i++) {
				if (s[i] == 'i') {
					num[i] = 1;
				} else if (s[i] == 'j') {
					num[i] = 2;
				} else {
					num[i] = 3;
				}
			}
			
			int ans = 0;
			int sign = 1;
			for (int i = 0; i < num.length; i++) {
				sign *= dijkstraSign[ans][num[i]];
				ans = dijkstraValue[ans][num[i]];
			}
			
			int segVal = ans;
			int segSign = sign;
			
			// check if == -1
			ans = 0;
			sign = 1;
			for (long j = 0; j < x % 4; j++) {
				sign *= segSign * dijkstraSign[ans][segVal];
				ans = dijkstraValue[ans][segVal];
			}
			
			if (!(ans == 0 && sign == -1)) {
				out.println("Case #" + (test+1) + ": " + "NO");
				continue;
			}
			
			// check if == ii
			ans = 0;
			sign = 1;
			boolean valid = false;
			int seg1 = 0;
			for (long j = 0; j <= 4 && j < x; j++) {
				for (int i = 0; i < num.length; i++) {
					sign *= dijkstraSign[ans][num[i]];
					ans = dijkstraValue[ans][num[i]];
					
					if ((ans == 1)) {
						valid = true;
						j = x;
						break;
					}
					seg1++;
				}
			}
			
			if (!valid) {
				out.println("Case #" + (test+1) + ": " + "NO");
				continue;				
			}

			ans = 0;
			sign = 1;
			valid = false;
			long seg3 = x * num.length;
			for (long j = 0; j <= 4 && j < x; j++) {
				for (int i = num.length-1; i >= 0; i--) {
					seg3--;
					sign *= dijkstraSign[ans][num[i]];
					ans = dijkstraValue[ans][num[i]];
					
					if ((ans == 3)) {
						valid = true;
						j = x;
						break;
					}
				}
			}
			
			if (!valid || seg1 >= seg3) {
				out.println("Case #" + (test+1) + ": " + "NO");
				continue;				
			}
			
			out.println("Case #" + (test+1) + ": " + "YES");
		}
	}

	public static void dijkstra() {
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			scan.nextInt();
			long x = scan.nextLong();
			char[] s = scan.next().toCharArray();
			int[] num = new int[s.length];
			for (int i = 0; i < s.length; i++) {
				if (s[i] == 'i') {
					num[i] = 1;
				} else if (s[i] == 'j') {
					num[i] = 2;
				} else {
					num[i] = 3;
				}
			}
			
			// check if == -1
			int ans = 0;
			int sign = 1;
			for (int j = 0; j < x; j++) {
				for (int i = 0; i < num.length; i++) {
					sign *= dijkstraSign[ans][num[i]];
					ans = dijkstraValue[ans][num[i]];
				}
			}
			
			if (!(ans == 0 && sign == -1)) {
				out.println("Case #" + (test+1) + ": " + "NO");
				continue;
			}
			
			// check if == ii
			ans = 0;
			sign = 1;
			boolean valid = false;
			int seg1 = 0;
			for (int j = 0; j < x; j++) {
				for (int i = 0; i < num.length; i++) {
					sign *= dijkstraSign[ans][num[i]];
					ans = dijkstraValue[ans][num[i]];
					
					if ((ans == 1)) {
						valid = true;
						j = (int) x;
						break;
					}
					seg1++;
				}
			}
			
			if (!valid) {
				out.println("Case #" + (test+1) + ": " + "NO");
				continue;				
			}

			ans = 0;
			sign = 1;
			valid = false;
			int seg3 = (int) (x * num.length);
			for (int j = 0; j < x; j++) {
				for (int i = num.length-1; i >= 0; i--) {
					seg3--;
					sign *= dijkstraSign[ans][num[i]];
					ans = dijkstraValue[ans][num[i]];
					
					if ((ans == 3)) {
						valid = true;
						j = (int) x;
						break;
					}
				}
			}
			
			if (!valid || seg1 >= seg3) {
				out.println("Case #" + (test+1) + ": " + "NO");
				continue;				
			}
			
			out.println("Case #" + (test+1) + ": " + "YES");
		}
	}

	public static void genInfiniteHouseOfPancakes() {
		int lengths = 5;
		int maxSize = 15;
		ArrayList<String> output = new ArrayList<>();
		for (int i = 1; i <= lengths; i++) {
			int base = maxSize / i;
			int[] number = new int[i];
			do {
				output.add(i + "\n");
				String num = "";
				for (int j = 0; j < number.length; j++) {
					num += (number[j] + 1) + " ";
				}
				output.add(num.trim() + "\n");
			} while ((next_number(number, base)));
		}
		output.add(0, output.size()/2 + "\n");
		for (int i = 0; i < output.size(); i++) {
			out.print(output.get(i));
		}
	}
	
	public static boolean next_number(int list[], int base) {
		int i = list.length - 1;
		
		list[i]++;
		
		if (list[i] == base) {
			boolean carry = true;
			while (carry) {
				if (i == 0) {
					return false;
				}
				
				carry = false;
				list[i] = 0;
				list[--i]++;				
				
				if (list[i] == base) {
					carry = true;
				}
			}
		}
		
		return true;
	}

	public static void infiniteHouseOfPancakes4() {
		int tests = scan.nextInt();
		Random rand = new Random(0);

		for (int test = 0; test < tests; test++) {
			int x = scan.nextInt();
			int[] stacks = scan.nextIntArray(x);
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < 1000000; i++) {
				ArrayList<Integer> st = new ArrayList<>();
				for (int j = 0; j < stacks.length; j++) {
					st.add(stacks[j]);
				}
				
				int steps = 0;
				while (!st.isEmpty()) {
					steps++;
					if (rand.nextBoolean()) {
						ArrayList<Integer> newSt = new ArrayList<>();
						for (int j = 0; j < st.size(); j++) {
							if (st.get(j) > 1) {
								newSt.add(st.get(j) - 1);
							}
						}
						st = newSt;
					} else {
						int max = 0;
						for (int j = 0; j < st.size(); j++) {
							max = Math.max(max, st.get(j));
						}
						if (max == 1) {
							break;
						}
						int idx = rand.nextInt(st.size());
						while (st.get(idx) < 2) {
							idx = rand.nextInt(st.size());
						}
						int slice = rand.nextInt(st.get(idx)-1);
						st.set(idx, st.get(idx) - slice);
						if (st.get(idx) == 0) {
							st.remove(idx);
						}
						if (slice > 0) {
							st.add(slice);
						}
					}
				}
				
				min = Math.min(min, steps);
			}
			System.out.println(Arrays.toString(stacks));
			//System.out.println("Case #" + (test+1) + ": " + min);
			out.println("Case #" + (test+1) + ": " + min);
		}
	}

	public static void infiniteHouseOfPancakes3() {
		int tests = scan.nextInt();

		for (int test = 0; test < tests; test++) {
			int x = scan.nextInt();
			int[] stacks = scan.nextIntArray(x);
			
			int sum = 0;
			for (int i = 0; i < stacks.length; i++) {
				sum += stacks[i];
			}
			int min = Integer.MAX_VALUE;
			

			int N = 1 << (sum+1);
			for (int n = 0; n < N; n++) {
				boolean[] active = new boolean[(sum+1)];
				for (int i = 0; i < (sum+1); i++) {
					if (((1 << i) & n) != 0) {
						active[i] = true;
					}
				}
				
				PriorityQueue<Integer> q = new PriorityQueue<>(x, new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						return Integer.compare(o2, o1);
					}
				});
				
				for (int j = 0; j < stacks.length; j++) {
					q.add(stacks[j]);
				}
				
				int best = q.peek();
				//System.out.println(best);
				min = Math.min(min, best);

				for (int i = 1; i <= sum; i++) {
					
					if (active[i]) {
						ArrayList<Integer> list = new ArrayList<>();
						for (Integer j: q) {
							if (j > 1) {
								list.add(j - 1);
							}
						}
						q.clear();
						for (Integer j: list) {
							q.add(j);
						}
						
					} else if (!q.isEmpty()) {
						int hi = q.poll();
						q.add((int)Math.floor(hi / 2.0));
						q.add((int)Math.ceil(hi / 2.0));
					}
					
					best = (q.isEmpty() ? 0 : q.peek()) + i;
					//System.out.println(best);
					min = Math.min(min, best);
				}
			}
			
			out.println("Case #" + (test+1) + ": " + min);
		}
	}

	public static void infiniteHouseOfPancakes2() {
		int tests = scan.nextInt();

		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int[] stacks = scan.nextIntArray(n);
			
			int max = 0;
			for (int i = 0; i < stacks.length; i++) {
				max = Math.max(max, stacks[i]);
			}
			int min = Integer.MAX_VALUE;
			
			PriorityQueue<Integer> q = new PriorityQueue<>(n, new Comparator<Integer>() {
				@Override
				public int compare(Integer o1, Integer o2) {
					return Integer.compare(o2, o1);
				}
			});
			
			for (int j = 0; j < stacks.length; j++) {
				q.add(stacks[j]);
			}
			
			int best = q.peek();
			//System.out.println(best);
			min = Math.min(min, best);

			for (int i = 1; i <= max; i++) {
				
				if (q.peek() % 2 == 0) {
					ArrayList<Integer> list = new ArrayList<>();
					for (Integer j: q) {
						if (j > 1) {
							list.add(j - 1);
						}
					}
					q.clear();
					for (Integer j: list) {
						q.add(j);
					}
					
				} else {
					int hi = q.poll();
					q.add((int)Math.floor(hi / 2.0));
					q.add((int)Math.ceil(hi / 2.0));
				}
				
				best = q.peek() + i;
				//System.out.println(best);
				min = Math.min(min, best);
			}
			
			out.println("Case #" + (test+1) + ": " + min);
		}
	}

	public static void infiniteHouseOfPancakes() {
		int tests = scan.nextInt();

		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int[] stacks = scan.nextIntArray(n);
			
			int max = 0;
			for (int i = 0; i < stacks.length; i++) {
				max = Math.max(max, stacks[i]);
			}
			int min = Integer.MAX_VALUE;
			
			for (int k = 1; k <= max; k++) {
				
				PriorityQueue<Integer> q = new PriorityQueue<>(n, new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						return Integer.compare(o2, o1);
					}
				});
				
				for (int j = 0; j < stacks.length; j++) {
					q.add(stacks[j]);
				}
				
				int best = q.peek();
				//System.out.println(best);
				min = Math.min(min, best);
	
				for (int i = 1; i <= k; i++) {
					int top = q.peek();
					if (top > 1 && isPerfectSquare(top)) {
						int sqrt = (int)Math.sqrt(top); 
						if (k >= sqrt-1) {
							q.poll();
							for (int j = 0; j < sqrt; j++) {
								q.add(sqrt);
							}
							i += sqrt-2;
							best = q.peek() + i;
							min = Math.min(min, best);
							continue;
						}
					}
					int hi = q.poll();
					q.add((int)Math.floor(hi / 2.0));
					q.add((int)Math.ceil(hi / 2.0));
					
					best = q.peek() + i;
					min = Math.min(min, best);
				}
				
			}
			
			out.println("Case #" + (test+1) + ": " + min);
		}
	}
	
	public static boolean isPerfectSquare(int x) {
		if (((int)Math.sqrt(x) * (int)Math.sqrt(x)) == x) {
			return true;
		} else {
			return false;
		}
	}
	
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner(InputStream in) {
			this.br = new BufferedReader(new InputStreamReader(in));
		}

		public void close() {
			try {
				this.br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = this.nextLong();
			}
			return a;
		}

		int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = this.nextInt();
			}
			return a;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine(){
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

}