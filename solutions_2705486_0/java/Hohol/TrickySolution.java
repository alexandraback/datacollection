import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.Math.*;

public class TrickySolution {	
	
	char[] s;	
	int n;
	final int inf = (int)1e9;
	
	void solve() throws IOException {
		char[][] dict = new char[521196][];
		//char[][] dict = new char[1][];
		
		for(int i = 0; i < dict.length; i++) {				
			dict[i] = dictin.readLine().toCharArray();
			//out.println(dict[i]);
			//out.flush();
		}
		int testCnt = readInt();
		for(int testNo = 1; testNo <= testCnt; testNo++) {
			out.print("Case #" + testNo  + ": ");
			s = readString().toCharArray();
			n = s.length;
			int[][] dp = new int[5][n+1];			
			for(int i = 0; i < dp.length; i++) {
				Arrays.fill(dp[i],inf);
			}
			dp[4][0] = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < dp.length; j++) {
					if(dp[j][i] == inf) {
						continue;
					}
					for(int k = 0; k < dict.length; k++) {
						char[] word = dict[k];
						int t = tryUse(i,j,word);
						if(t == inf) {
							continue;
						}
						t = min(4,word.length-t-1);
						int cnt = 0;
						for(int pos = 0; pos < word.length; pos++) {
							if(word[pos] != s[i+pos]) {
								cnt++;
							}
						}
						dp[t][i+word.length] = min(dp[t][i+word.length],
								dp[j][i]+cnt);
								
					}
				}
			}
			int ans = inf;
			for(int i = 0; i < 5; i++) {
				ans = min(ans,dp[i][n]);
			}
			out.println(ans);
		}
	}
	
	int tryUse(int pos, int dist, char[] word) {
		if(pos+word.length-1 >= n) {
			return inf;
		}
		int prev = -dist-1;
		for(int i = 0; i < word.length; i++) {
			if(word[i] != s[pos+i]) {
				if(i-prev < 5) {
					return inf;					
				}
				prev = i;
			}
		}
		return prev;		
	}
	
	
	//-------------------------------------------------
	
	final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
	
	BufferedReader in, dictin;
	PrintWriter out;
	StringTokenizer tok;
		
	public void run() {
		try {
			long startTime = System.currentTimeMillis();
			Locale.setDefault(Locale.US);
			if (ONLINE_JUDGE) {
			//if(true) {				
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			} else {
				dictin = new BufferedReader(new FileReader("dict.txt"));
				in = new BufferedReader(new FileReader("input.txt"));
				out = new PrintWriter("output.txt");
			}
			tok = new StringTokenizer("");
			solve();
			in.close();
			out.close();
			long endTime = System.currentTimeMillis();
			long totalMemory = Runtime.getRuntime().totalMemory();
			long freeMemory = Runtime.getRuntime().freeMemory();
			System.err.println("Time = " + (endTime - startTime) + " ms");
			System.err.println("Memory = " + ((totalMemory - freeMemory) / 1024) + " KB");
		} catch (Throwable e) {
			e.printStackTrace(System.err);
			System.exit(-1);
		}
	}
	
	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) return null;
			tok = new StringTokenizer(line);
		}
		return tok.nextToken();
	}
	
	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}
	
	long readLong() throws IOException {
		return Long.parseLong(readString());
	}
	
	double readDouble() throws IOException {
		return Double.parseDouble(readString());
	}
	
	void debug(Object... o) {
		if (!ONLINE_JUDGE) {
			System.err.println(Arrays.deepToString(o));
		}
	}
	
	public static void main(String[] args) {
		new TrickySolution().run();
	}
	
	
	
//------------------------------------------------------------------------------
	static class Mergesort {

		private Mergesort() {}

		public static void sort(int[] a) {
			mergesort(a, 0, a.length - 1);
		}

		public static void sort(long[] a) {
			mergesort(a, 0, a.length - 1);
		}

		public static void sort(double[] a) {
			mergesort(a, 0, a.length - 1);
		}

		private static final int MAGIC_VALUE = 42;

		private static void mergesort(int[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= MAGIC_VALUE) {
					insertionSort(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) / 2;
					mergesort(a, leftIndex, middleIndex);
					mergesort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void mergesort(long[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= MAGIC_VALUE) {
					insertionSort(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) / 2;
					mergesort(a, leftIndex, middleIndex);
					mergesort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void mergesort(double[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= MAGIC_VALUE) {
					insertionSort(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) / 2;
					mergesort(a, leftIndex, middleIndex);
					mergesort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void merge(int[] a, int leftIndex, int middleIndex, int rightIndex) {
			int length1 = middleIndex - leftIndex + 1;
			int length2 = rightIndex - middleIndex;
			int[] leftArray = new int[length1];
			int[] rightArray = new int[length2];
			System.arraycopy(a, leftIndex, leftArray, 0, length1);
			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
				if (i == length1) {
					a[k] = rightArray[j++];
				} else if (j == length2) {
					a[k] = leftArray[i++];
				} else {
					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
				}
			}
		}

		private static void merge(long[] a, int leftIndex, int middleIndex, int rightIndex) {
			int length1 = middleIndex - leftIndex + 1;
			int length2 = rightIndex - middleIndex;
			long[] leftArray = new long[length1];
			long[] rightArray = new long[length2];
			System.arraycopy(a, leftIndex, leftArray, 0, length1);
			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
				if (i == length1) {
					a[k] = rightArray[j++];
				} else if (j == length2) {
					a[k] = leftArray[i++];
				} else {
					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
				}
			}
		}

		private static void merge(double[] a, int leftIndex, int middleIndex, int rightIndex) {
			int length1 = middleIndex - leftIndex + 1;
			int length2 = rightIndex - middleIndex;
			double[] leftArray = new double[length1];
			double[] rightArray = new double[length2];
			System.arraycopy(a, leftIndex, leftArray, 0, length1);
			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
				if (i == length1) {
					a[k] = rightArray[j++];
				} else if (j == length2) {
					a[k] = leftArray[i++];
				} else {
					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
				}
			}
		}

		private static void insertionSort(int[] a, int leftIndex, int rightIndex) {
			for (int i = leftIndex + 1; i <= rightIndex; i++) {
				int current = a[i];
				int j = i - 1;
				while (j >= leftIndex && a[j] > current) {
					a[j + 1] = a[j];
					j--;
				}
				a[j + 1] = current;
			}
		}

		private static void insertionSort(long[] a, int leftIndex, int rightIndex) {
			for (int i = leftIndex + 1; i <= rightIndex; i++) {
				long current = a[i];
				int j = i - 1;
				while (j >= leftIndex && a[j] > current) {
					a[j + 1] = a[j];
					j--;
				}
				a[j + 1] = current;
			}
		}

		private static void insertionSort(double[] a, int leftIndex, int rightIndex) {
			for (int i = leftIndex + 1; i <= rightIndex; i++) {
				double current = a[i];
				int j = i - 1;
				while (j >= leftIndex && a[j] > current) {
					a[j + 1] = a[j];
					j--;
				}
				a[j + 1] = current;
			}
		}

	}
	
}