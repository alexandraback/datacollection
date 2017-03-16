import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.StringTokenizer;


public class GCJ1B_C implements Runnable {

	private static final String SMALL_FILE_NAME = "C-small-attempt0.in";
	private static final String BIG_FILE_NAME = "C-large.in";
	private static final String OUTPUT_FILE_NAME = "output.txt";
	private static final String CASE_PREFIX = "Case #";
	private static final String CASE_MIDDLE = ": ";
	private static final int MAX_S = 51;
	
	private int first;
	private int last;
	private int cnt;
	private int size;
	private int startIndex;
	
	private boolean canPlaced(String word, int i) {
		int previousIndex = -23142134;
		int wordPosition = 0;
		first = -1;
		last = -1;
		cnt = 0;
		for (int position = startIndex; position <= i; ++position) {
			if (word.charAt(wordPosition) != message.charAt(position-1)) {
				if (position - previousIndex < 5) {
					return false;
				}
				else {
					if (first == -1) {
						first = position;
					}
					++cnt;
					last = position;
					previousIndex = position;
				}
			}
			++wordPosition;
		}
		return true;
	}
	
	private int getAnswer() throws IOException {
		message = in.next();
		int length = message.length();
		for (int i = 1; i <= length; ++i) {
			Arrays.fill(dp[i], Integer.MAX_VALUE/3);
		}
		for (int i = 1; i <= length; ++i) {
			for (String word: dictionary) {
				size = word.length();
				if (size > i) {
					continue;
				}
				startIndex = i-size+1;
				if (canPlaced(word, i)) {
					if (first == -1) {
						for (int j = 0; j < 5; ++j) {
							int endFora = j+size;
							if (endFora > 4) {
								endFora = 4;
							}
							if (dp[i][endFora] > dp[startIndex-1][j]) {
								dp[i][endFora] = dp[startIndex-1][j];
							}
						}
					}
					else {
						int fora = first - startIndex;
						int endFora = i - last;
						if (endFora > 4) {
							endFora = 4;
						}
						for (int j = 0; j < 5; ++j) {
							int val = j+1+fora;
							if (val > 4 && dp[i][endFora] > dp[startIndex-1][j]+cnt) {
								dp[i][endFora] = dp[startIndex-1][j] + cnt;
							}
						}
					}
				}
			}
		}
		int minValue = Integer.MAX_VALUE;
		for (int i = 0; i < 5; ++i) {
			if (minValue > dp[length][i]) {
				minValue = dp[length][i];
			}
		}
		return minValue;
	}
	
	private String message;
	private int[][] dp;
	
	private void begin() {
		try {
			dp = new int[MAX_S][5];
			Arrays.fill(dp[0], 0);
//			in = new TokenInputReader(System.in);
//			out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
			in = new TokenInputReader(new FileInputStream(new File(SMALL_FILE_NAME)));
			out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File(OUTPUT_FILE_NAME)))));
			nt = in.nextInt();
			TokenInputReader reader = new TokenInputReader(new FileInputStream(new File("input.txt")));		
			dictionary = new ArrayList<String>();
			while (true) {
				try {
					dictionary.add(reader.next());
				}
				catch (Exception e) {
					break;
				}
			}
		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
			throw new RuntimeException(e);
		}
		catch (IOException e) {
			e.printStackTrace();
			throw new RuntimeException(e);
		}
	}
	
	private List<String> dictionary;
	
	private void end() {
		out.flush();
	}

	private int nt;
	private TokenInputReader in;
	private PrintWriter out;
	
	@Override
	public void run() {
		begin();
		try {
			for (int t = 1; t <= nt; ++t) {
				out.println(CASE_PREFIX + t + CASE_MIDDLE + getAnswer());
			}
		}
		catch (IOException e) {
			e.printStackTrace();
			throw new RuntimeException(e);
		}
		end();
	}
	
	private class TokenInputReader {
	    
		public BufferedReader reader;
	    public StringTokenizer tokenizer;

	    public TokenInputReader(InputStream stream) {
	        reader = new BufferedReader(new InputStreamReader(stream));
	        tokenizer = null;
	    }

	    public String next() throws IOException {
	        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
	        }
	        return tokenizer.nextToken();
	    }
	    
	    public int nextInt() throws IOException {
	    	return Integer.parseInt(next());
	    }
	}

	public static void main(String[] args) {
		new GCJ1B_C().run();
	}
}
