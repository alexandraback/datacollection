package round0;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class JamCoins {
	public static final int MAX_PRIME = 100;
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round0/C-large.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round0/jamcoins-output.txt");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			generateOutput("Case #" + exercise + ": ");
			doExercise();
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static void doExercise() throws IOException {
		String[] parameters = reader.readLine().split(" ");
		int length = Integer.parseInt(parameters[0]);
		int results = Integer.parseInt(parameters[1]);
		int counter = 0;
		
		long lowerBound = (long) Math.pow(2, length-1);
		for (long i = lowerBound + 1; i < 2*lowerBound; i+=2) {
			Coin coin = new Coin(i);
			coin.calculateDivisors();
			if (coin.isValid()) {
				generateOutput(coin.toString());
				counter++;
				if (counter == results) {
					return;
				}
			}
		}
		System.out.println("Number of jam coins found " + counter);
	}
	
	private static class Coin {
		String coin;
		long[] values = new long[11];
		long[] divisors = new long[11];
		
		Coin(String coin) {
			this.coin = coin;
			for (int b = 2; b <= 10; b++) {
				values[b] = toValue(coin, b);
				divisors[b] = -1;
			}
		}

		public boolean isValid() {
			for (int b = 2; b <= 10; b++) {
				if (divisors[b] == -1) {
					return false;
				}
			}
			return true;
		}

		public Coin(long value2) {
			this(toStringBase2(value2));
		}

		private static String toStringBase2(long value2) {
			StringBuilder result = new StringBuilder();
			while (value2 > 0) {
				result.insert(0, value2 % 2);
				value2/=2;
			}
			return result.toString();
		}

		private static long toValue(String coin, int base) {
			long value = 0;
			for (int i = 0; i < coin.length(); i++) {
				value = base*value;
				if (coin.charAt(i) == '1') {
					value++;
				}
			}
			return value;
		}
		
		void calculateDivisors() {
			for (int b = 2; b <= 10; b++) {
				calculateDivisor(b);
			}
		}

		private void calculateDivisor(int b) {
			for (int p = 3; p <= MAX_PRIME; p+=2) {
				if (values[b] % p == 0) {
					divisors[b] = p;
					return;
				}
			}
		}
		
		@Override
		public String toString() {
			StringBuilder builder = new StringBuilder(coin);
			for (int b = 2; b <= 10; b++) {
				builder.append(" " + divisors[b]);
			}
			return builder.toString();
		}
	}
}
