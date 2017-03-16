import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Formatter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class Recycled {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Path path = Paths.get(args[0]);
		Path file = Paths.get("recycled.txt");
		int numberOfCases;
		try (Scanner scanner = new Scanner(Files.newInputStream(path), "UTF-8");
				OutputStreamWriter output = new OutputStreamWriter(Files.newOutputStream(file), "UTF-8")) {
			Formatter f = new Formatter(output);
			numberOfCases = scanner.nextInt();
			for (int i = 1; i <= numberOfCases; i++) {
				int from = scanner.nextInt();
				int to = scanner.nextInt();
				int result = solve(from, to);
				f.format("Case #%d: %d\n", i, result);
			}
			f.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static int solve(int from, int to) {
		Set<Pair> pairs = new HashSet<>();
		for (int a = from; a < to; a++) {
			String n = Integer.toString(a);
			StringBuilder b;
			for (int i = 1; i < n.length(); i++) {
				b = new StringBuilder(n.substring(n.length()-i));
				b.append(n.substring(0, n.length()-i));
				String rec = b.toString();
				if (rec.charAt(0) != '0') {
					int rev = Integer.parseInt(rec);
					if (rev > a && rev <= to) {
						pairs.add(new Pair(a, rev));
					}
				}
			}
		}
		return pairs.size();
	}

	private static class Pair {
		int first;
		int second;
		
		public Pair(int first, int second) {
			super();
			this.first = first;
			this.second = second;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + first;
			result = prime * result + second;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (first != other.first)
				return false;
			if (second != other.second)
				return false;
			return true;
		}
	}
}
