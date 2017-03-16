package round2A.a;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ALarge {
	static String inFile = "src/round2A/a/A-large.in";
	static String outFile = "src/round2A/a/A.out";
	static int selectedTest = -1;


	static String solve(Prerequisite p) throws Exception {
		System.err.println(p.a);
		System.err.println(Arrays.toString(p.motes));
		
		Arrays.sort(p.motes);
		System.err.println(Arrays.toString(p.motes));
		
		
		int numOps1 = 0;
		
		long armin = p.a;
		long[] motes = p.motes.clone();
		int currentIndex = 0;
		while(motes.length > 0){
			if(motes[currentIndex] < armin){
				armin += motes[currentIndex];
				long[] newMotes = new long[motes.length - 1];
				int counter = 0;
				for(int j = 0; j < motes.length; j++)
					if(j != currentIndex)
						newMotes[counter++] = motes[j];
				Arrays.sort(newMotes);
				motes = newMotes;
				
			} else if (armin + armin - 1 > motes[currentIndex]){
				System.err.println("op add " + (armin - 1));
				long[] newMotes = new long[motes.length + 1];
				int counter = 0;
				for(int j = 0; j < motes.length; j++)
					newMotes[counter++] = motes[j];
				newMotes[counter] = armin - 1;
				Arrays.sort(newMotes);
				motes = newMotes;
				
				numOps1++;
			} else {
				System.err.println("op rem" + motes[currentIndex]);
				long[] newMotes = new long[motes.length - 1];
				int counter = 0;
				for(int j = 0; j < motes.length; j++)
					if(j != currentIndex)
						newMotes[counter++] = motes[j];
				Arrays.sort(newMotes);
				motes = newMotes;
				
				numOps1++;
			}
			
		}
	
		
		
		int numOps2 = 0;
		armin = p.a;
		motes = p.motes.clone();
		currentIndex = 0;
		while(motes.length > 0 && numOps2 <= numOps1){
			if(motes[currentIndex] < armin){
				armin += motes[currentIndex];
				long[] newMotes = new long[motes.length - 1];
				int counter = 0;
				for(int j = 0; j < motes.length; j++)
					if(j != currentIndex)
						newMotes[counter++] = motes[j];
				Arrays.sort(newMotes);
				motes = newMotes;
			} else {
				System.err.println("op add " + (armin - 1));
				long[] newMotes = new long[motes.length + 1];
				int counter = 0;
				for(int j = 0; j < motes.length; j++)
					newMotes[counter++] = motes[j];
				newMotes[counter] = armin - 1;
				Arrays.sort(newMotes);
				motes = newMotes;
				
				numOps2++;
			} 
		}
		
		if(numOps1 < numOps2)
			return String.valueOf(numOps1);
		
		return String.valueOf(numOps2);
	}

	static class Prerequisite {
		long a;
		long motes[];
		
		public Prerequisite() throws IOException {
			a = Reader.nextLong();
			motes = new long[Reader.nextInt()];
			for(int i = 0; i < motes.length; i++)
				motes[i] = Reader.nextLong();
			
		}
	}

	public static void init() {
		try (Reader reader = new Reader(new FileInputStream(inFile));
				PrintWriter out = new PrintWriter(new FileWriter(outFile));) {			String result;
			long time, overallTime;

			int tN = Reader.nextInt();
			overallTime = System.currentTimeMillis();
			for (int ti = 1; ti <= tN; ti++) {
				Prerequisite p = new Prerequisite();

				if (selectedTest > 0)
					if (ti != selectedTest)
						continue;

				time = System.currentTimeMillis();
				result = solve(p);
				out.printf("Case #%d: %s", ti, result);

				if (ti != tN)
					out.println();

				System.err.printf("Case %-5s ", String.format("#%d:", ti));
				System.err.printf("%-8s", result);
				System.err.printf("%6sms\n", String.format(".. %.0f",
								(double) (System.currentTimeMillis() - time)));
			}

			System.err.printf("%.4fs\n",
					(double) (System.currentTimeMillis() - overallTime) / 1000);
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static class Reader implements AutoCloseable {
		static BufferedReader in;
		static StringTokenizer tok;

		public Reader(InputStream input) {
			in = new BufferedReader(new InputStreamReader(input));
			tok = new StringTokenizer("");
		}

		@Override
		public void close() throws IOException {
			in.close();
		}

		static String next() throws IOException {
			while (!tok.hasMoreTokens())
				tok = new StringTokenizer(in.readLine());
			return tok.nextToken();
		}

		static int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		static long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		static double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
		
		static BigInteger nextBigInteger() throws IOException {
			return new BigInteger(next());
		}
	}

	public static void main(String[] args) {
		init();
	}
}
