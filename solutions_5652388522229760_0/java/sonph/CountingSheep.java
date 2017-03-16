package gcj2016;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;

public class CountingSheep {
	private static final String INPUT_FILE_NAME = "A-small-attempt1.in";
	private static final String OUTPUT_FILE_NAME = "A-small.out";
	private static final long TOTAL_TIME = 7 * 60 * 1000;
	private static final long TOTAL_TEST = 200;

	public static void main(String[] args) {
		new CountingSheep().start();
	}
	
	private void start() {
		try (
				MyReader reader = new MyReader(new BufferedReader(new FileReader(INPUT_FILE_NAME)));
				PrintWriter printer = new PrintWriter(new FileWriter(OUTPUT_FILE_NAME))) {
			Integer ncases = reader.nextInt();
			for(int i = 0 ; i < ncases ; i++) {
				Integer x = reader.nextInt();
				printer.println("Case #" + (i+1) + ": " + lastNumber(x));
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private String lastNumber(int x) {
		if ( x == 0) return "INSOMNIA";
		BigInteger step = new BigInteger(""+x);
		BigInteger num = new BigInteger(""+x);
		boolean[] seen = new boolean[10];
		Arrays.fill(seen, false);
		while (true) {
			fillSeen(seen,num);
			if ( seeAll(seen)) return num.toString();
			num = num.add(step);
		}
	}

	private boolean seeAll(boolean[] seen) {
		for(int d = 0 ; d <= 9 ; d++)
			if ( ! seen[d]) return false;
		return true;
	}

	private void fillSeen(boolean[] seen, BigInteger num) {
		char[] cc = num.toString().toCharArray();
		for(char c : cc) {
			seen[ c -'0'] = true;
		}
	}

	public class MyReader implements AutoCloseable {

		private BufferedReader br;
		private int index;
		private String[] words;

		public MyReader(BufferedReader br) {
			this.br = br;
		}
				
		public Integer nextInt() {
			try {
				String s = getNextWord();
				if ( s == null ) return null;
				return Integer.parseInt(s);
			} catch (Exception e) {
				e.printStackTrace();
				return null;
			}
		}				
		
		private String getNextWord() throws IOException {
			if ( words == null || index >= words.length) {
				String line = br.readLine();
				if ( line == null ) return null;
				index = 0;
				words = line.split(" ");
			}
			return words[index++];
		}

		public String nextString() {
			try {
				String s = getNextWord();
				if ( s == null ) return null;
				return s;
			} catch (IOException e) {
				e.printStackTrace();
				return null;
			}
		}

		@Override
		public void close() throws Exception {
			try { this.br.close(); } catch (Exception e) {}
		}
	}
}
