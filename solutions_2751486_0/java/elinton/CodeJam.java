package codejam;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.AbstractCollection;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;


public abstract class CodeJam {
	
	protected BufferedReader reader;
	protected FileWriter writer;
	
	//used in multithread mode
	protected String[] inputLines;
	protected String[] outputLines;
	protected int linesPerCase;
	private long start;
	
	protected String caseLabel = "Case #";
	
	protected boolean runningMultiThread = false;
	
	public CodeJam(String file) throws Exception {
		this(file, -1);
	}
	
	public CodeJam(String file, int linesPerCase) throws Exception {
		start = System.currentTimeMillis();
		
		this.linesPerCase = linesPerCase;
		FileReader fileReader = new FileReader(new File(file));
		reader = new BufferedReader(fileReader);
		File outFile = new File(file.replaceAll("\\.\\w+$", ".out"));
		outFile.delete();
		writer = new FileWriter(outFile);
		
	}

	public void start() throws IOException,
			InterruptedException {
		String readLine = reader.readLine();
		//total number of cases
		int t = Integer.parseInt(readLine);
		
		int threads = 1;
		if (linesPerCase > 0) {
			runningMultiThread = true;
			loadInputLines(t*linesPerCase);
			outputLines = new String[t];
			threads = 4;
		}
		ExecutorService newCachedThreadPool = Executors.newCachedThreadPool();
		
		for (int i = 0; i < threads; i++) {
			newCachedThreadPool.execute(new CaseProcessor(i*t/threads+1, (i+1)*t/threads));
		}
		newCachedThreadPool.shutdown();
		newCachedThreadPool.awaitTermination(8*60*1000, TimeUnit.MILLISECONDS);

		if (runningMultiThread) {
			for (int i = 0; i < outputLines.length; i++) {
				writer.write(outputLines[i]);
			}
		}
		writer.flush();
		
		long delay = System.currentTimeMillis() - start;
		
		if (delay < 5000) {
			System.out.println("Total time "+delay+ " millis");
		} else {
			System.out.println("Total time "+(delay/1000)+ " secs");
		}
		
		System.exit(0);
	}
	
	class CaseProcessor implements Runnable {
		
		int firstCase;
		int lastCase;
		
		public CaseProcessor(int firstCase, int lastCase) {
			this.firstCase = firstCase;
			this.lastCase = lastCase;
		}

		public void run() {
			for (int i = firstCase; i <= lastCase; i++) {
				Object result;
				try {
					result = processCase(i);
					writeCaseResult(i, result);
				} catch (Exception e) {
					e.printStackTrace();
				}
				
				if (i%10 == 0) {
					long timeRemaing = (System.currentTimeMillis() - start)/i * (lastCase-i);
					if (timeRemaing < 5000) {
						System.out.println(i*100f/lastCase+" % Complete (Time remaing: "+timeRemaing+" millis)");
					} else {
						System.out.println(i*100f/lastCase+" % Complete (Time remaing: "+timeRemaing/1000+" secs)");
					}
				}
			}
			System.out.println("Finish"+firstCase);
		}
		
	}
	
	private void loadInputLines(int lines) throws IOException {
		inputLines = new String[lines];
		for (int i = 0; i < lines; i++) {
			inputLines[i] = reader.readLine();
		}
		reader.close();
		reader = null;
	}

	public final String readLine() throws IOException {
		return reader.readLine();
	}
	
	public final int readLineInt() throws IOException {
		return Integer.parseInt(reader.readLine());
	}
	
	public final long readLineLong() throws NumberFormatException, IOException {
		return Long.parseLong(reader.readLine());
	}
	
	public final String readLine(int caseNumber, int i) {
		return inputLines[(caseNumber-1)*linesPerCase+i];		
	}
	
	public final int[] readIntArray() throws IOException {
		String[] numbers = readLine().split(" ");
		int[] n = new int[numbers.length];
		
		for (int i = 0; i < numbers.length; i++) {
			n[i] = Integer.parseInt(numbers[i]);
		}
		return n;
	}
	
	public final long[] readLongArray(int caseNumber, int line) throws IOException {
		String[] numbers = readLine(caseNumber, line).split(" ");
		long[] n = new long[numbers.length];
		
		for (int i = 0; i < numbers.length; i++) {
			n[i] = Long.parseLong(numbers[i]);
		}
		return n;
	}
	
	public final long[] readLongArray() throws IOException {
		String[] numbers = readLine().split(" ");
		long[] n = new long[numbers.length];
		
		for (int i = 0; i < numbers.length; i++) {
			n[i] = Long.parseLong(numbers[i]);
		}
		return n;
	}
	
	public final int[] readIntArray(int caseNumber, int line) {
		String[] numbers = readLine(caseNumber, line).split(" ");
		int[] n = new int[numbers.length];
		
		for (int i = 0; i < numbers.length; i++) {
			n[i] = Integer.parseInt(numbers[i]);
		}
		return n;
	}
	
	public final Integer[] readIntegerArray(int caseNumber, int line) {
		String[] numbers = readLine(caseNumber, line).split(" ");
		Integer[] n = new Integer[numbers.length];
		
		for (int i = 0; i < numbers.length; i++) {
			n[i] = Integer.parseInt(numbers[i]);
		}
		return n;
	}
	
	@SuppressWarnings("unchecked")
	public static <T> T[] reverse(T[] arr) {
		List<T> list = Arrays.asList(arr);
		Collections.reverse(list);
		return (T[]) list.toArray(new Object[arr.length]);
	}
	
	public static void reverse(char[] data) {
	    int left = 0;
	    int right = data.length - 1;

	    while( left < right ) {
	        // swap the values at the left and right indices
	        char temp = data[left];
	        data[left] = data[right];
	        data[right] = temp;

	        // move the left and right index pointers in toward the center
	        left++;
	        right--;
	    }
	}
	
	public static long getFactorial(int n) {
		long fact = 1;
		for (int i = n; i > 1; i--) {
			fact = fact * i;
		}
		return fact;
	}
	
	public static BigInteger getFactorial(long n) {
		BigInteger fact = new BigInteger("1");
		for (long i = n; i > 1; i--) {
			fact = fact.multiply(new BigInteger(i+""));
		}
		return fact;
	}
	
	public static boolean isPrime(int number) {
		if (number == 1 || number == 2)
			return true;
		int max = (int)Math.sqrt(number);
		for (int i = 2; i < max; i++) {
			if (number%i == 0)
				return false;
		}
		return true;
	}
	
	public static boolean isPalindrome(String word) {
		char[] charArray = word.toCharArray();
		reverse(charArray);
		return new String(charArray).equals(word);
	}
	
	public static boolean isPalindromeNumber(long n) {
		long s = 0, a=n; 
		while (n>0) {
			byte rem =(byte) (n%10); 
			s=s*10+rem;
			n=n/10; 
		}
		return s == a;
	}
	
	public <E> String toString(AbstractCollection<E> list) {
        Iterator<E> it = list.iterator();
        if (! it.hasNext())
            return "";

        StringBuilder sb = new StringBuilder();
        for (;;) {
            E e = it.next();
            sb.append(e == this ? "(this Collection)" : e);
            if (! it.hasNext())
                return sb.toString();
            sb.append(' ');
        }
    }

	protected void writeCaseResult(int caseNumber, Object result) throws IOException {
		StringBuilder out = new StringBuilder(caseLabel);//"Case #"
		out.append(caseNumber);
		out.append(": ");
		out.append(result);
		out.append('\n');
		System.out.println(out);
		if (runningMultiThread) {
			outputLines[caseNumber-1] = out.toString();
		} else {
			writer.write(out.toString());
		}
	}
	
	public long convetNumber(int number, int currentBase, int destBase) {
		long result = 0;
		
		int count = 0;
		
		while (number > 0) {
			int remainder = number % destBase;
			
			number /= destBase;
			
			int current = remainder*(int)Math.pow(currentBase,count);
			result += current;
			count++;
		}
		
		return result;
	}
	
	public static int levenshteinDistance(String s, String t) {
		if (s == null || t == null) {
			throw new IllegalArgumentException("Strings must not be null");
		}

		/* The difference between this impl. and the previous is that, rather
          than creating and retaining a matrix of size s.length()+1 by
          t.length()+1,
          we maintain two single-dimensional arrays of length s.length()+1.
          The first, d, is the 'current working' distance array that maintains
          the newest distance cost counts as we iterate through the characters
          of String s.  Each time we increment the index of String t we are
          comparing, d is copied to p, the second int[]. Doing so allows us
          to retain the previous cost counts as required by the algorithm
          (taking the minimum of the cost count to the left, up one, and
          diagonally up and to the left of the current cost count being
          calculated).
          (Note that the arrays aren't really copied anymore, just switched...
          this is clearly much better than cloning an array or doing a
          System.arraycopy() each time  through the outer loop.)

          Effectively, the difference between the two implementations is this
          one does not cause an out of memory condition when calculating the LD
          over two very large strings.
		 */

		int n = s.length(); // length of s
		int m = t.length(); // length of t

		if (n == 0) return m;
		else if (m == 0) return n;

		int p[] = new int[n+1]; //'previous' cost array, horizontally
		int d[] = new int[n+1]; // cost array, horizontally
		int _d[]; //placeholder to assist in swapping p and d

		// indexes into strings s and t
		int i; // iterates through s
		int j; // iterates through t

		char t_j; // jth character of t

		int cost; // cost

		for (i = 0; i<=n; i++) p[i] = i;

		for (j = 1; j<=m; j++) {
			t_j = t.charAt(j-1);
			d[0] = j;

			for (i=1; i<=n; i++) {
				cost = s.charAt(i-1)==t_j ? 0 : 1;
				// minimum of cell to the left+1, to the top+1,
				// diagonally left and up +cost
				d[i] = Math.min(Math.min(d[i-1]+1, p[i]+1),  p[i-1]+cost);
			}

			// copy current distance counts to 'previous row' distance counts
			_d = p;
			p = d;
			d = _d;
		}

		// our last action in the above loop was to switch d and p, so p now
		// actually has the most recent cost counts
		//System.err.println(s+" x "+t+" = "+p[n]);
		return p[n];
	}
	
	public abstract Object processCase(int caseNumber) throws Exception;
	
}
