import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.text.DecimalFormat;
import java.util.InputMismatchException;


public class ProblemB {
	
	public static void main(String[] args) throws IOException {
		String inputFileName = "B-small-attempt0.in";
		Reader reader = new Reader(new FileInputStream(inputFileName));
		
		String outputFileName = inputFileName.split("\\.")[0] + ".out";
		File file = new File(outputFileName);
		file.createNewFile();
		BufferedWriter out = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
		

		int T = (int) reader.nextInt();
		
		for (int t = 1; t <= T; t++) {
			int K = (int) reader.nextInt();
			int L = (int) reader.nextInt();
			int S = (int) reader.nextInt();
			
			String keyboard = reader.next();
			String targetWord = reader.next();
			
			
			
			long totalPossibilities = 1; 
			for (int i = 0; i < S; i++) {
				totalPossibilities *= K;
			}
			
			long maxOccurences = Long.MIN_VALUE;
			double totalOccurences = 0;
			for (int i = 0; i < totalPossibilities; i++) {
				String currWord = getString(keyboard, S, K, i);
				
				long currOccurences = countOccurences(targetWord, currWord);
				totalOccurences += currOccurences;
				
				if (currOccurences > maxOccurences) {
					maxOccurences = currOccurences;
				}
			}
			
//			System.out.println(maxOccurences + "," + totalOccurences + "," + totalPossibilities);
			double expectedRemainingBanans = maxOccurences - (totalOccurences / totalPossibilities);
			String answer = String.format("%.7f", expectedRemainingBanans);
			
			answer = "Case #" + t + ": " + answer;
			
			if (t != T) {
				answer = answer + "\n";
			}
			
			out.write(answer);
			System.out.print(answer);
		}
		
		
		out.flush();
		out.close();
	}
	
	public static long countOccurences(String sub, String main) {
		long count = 0;
		
		for (int i = 0; i <= main.length() - sub.length(); i++) {
			if (sub.equalsIgnoreCase(main.substring(i, i + sub.length()))) {
				count++;
			}
		}
		return count;
	}
	
	public static String getString(String s, int S, int K, int n) {
		String result = "";
		
		for(int i = 0; i < S; i++) {
			result = result + s.charAt(n % K);
			n = n / K;
		}
		return result;
	}
	
	public static void perm(String s) {
		perm("", s);
	}
	
	public static void perm(String prefix, String s) {
		int N = s.length();
		if (N == 0) {
			System.out.println(prefix);
		} else {
			for (int i = 0; i < N; i++) {
				perm(prefix + s.charAt(i), s.substring(0, i) + s.substring(i + 1, N));
			}
		}
	}

	static class Permutation {
		private int n, r;
		private int[] index;
		private boolean hasNext = true;

		public Permutation(int n, int r) {
			this.n = n;
			this.r = r;
			index = new int[n];
			for (int i = 0; i < n; i++) index[i] = i;
			reverseAfter(r - 1);
		}

		public boolean hasNext() { return hasNext; }

		// Based on code from KodersCode:
		// The algorithm is from Applied Combinatorics, by Alan Tucker.
		// Move the index forward a notch. The algorithm first finds the 
		// rightmost index that is less than its neighbor to the right. This 
		// is the dip point. The algorithm next finds the least element to
		// the right of the dip that is greater than the dip. That element is
		// switched with the dip. Finally, the list of elements to the right 
		// of the dip is reversed.
		//
		// For example, in a permutation of 5 items, the index may be 
		// {1, 2, 4, 3, 0}. The dip is 2  the rightmost element less 
		// than its neighbor on its right. The least element to the right of 
		// 2 that is greater than 2 is 3. These elements are swapped, 
		// yielding {1, 3, 4, 2, 0}, and the list right of the dip point is 
		// reversed, yielding {1, 3, 0, 2, 4}.

		private void moveIndex() {
			// find the index of the first element that dips
			int i = rightmostDip();
			if (i < 0) {
				hasNext = false;
				return;
			}

			// find the smallest element to the right of the dip
			int smallestToRightIndex = i+1;
			for (int j=i+2; j<n; j++)
				if ((index[j] < index[smallestToRightIndex]) &&  (index[j] > index[i]))
					smallestToRightIndex = j;

			// switch dip element with smallest element to its right
			swap(index,i,smallestToRightIndex);

			if (r - 1 > i) {
				// reverse the elements to the right of the dip
				reverseAfter(i);
				// reverse the elements to the right of r - 1
				reverseAfter(r - 1);
			}
		}

		public int[] next() {
			if (!hasNext) return null;
			int[] result = new int[r];
			for (int i=0; i<r; i++) result[i] = index[i];
			moveIndex();
			return result;
		}

		// Reverse the index elements to the right of the specified index.
		private void reverseAfter(int i) {
			int start = i+1;
			int end = n-1;
			while (start < end) {
				swap(index,start,end);
				start++;
				end--;
			}
		}

		// return int the index of the first element from the right
		// that is less than its neighbor on the right.
		private int rightmostDip() {
			for (int i=n-2; i>=0; i--)
				if (index[i] < index[i+1])
					return i;
			return -1;
		}

		private void swap(int[] a, int i, int j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	static class Reader {

		private InputStream stream;
		private byte[] buf = new byte[1024 * 1024];
		private int curChar;
		private int numChars;

		public Reader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
		
		public long nextInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c & 15;
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public static boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}
}