import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * java -cp bin R0As R0As\A-small-practice.in
 */
public class R0Cs {

	static class MultipleOutputStream extends OutputStream {

		OutputStream[] oss;

		public MultipleOutputStream(OutputStream... os) {
			this.oss = os;
		}

		@Override
		public void write(int b) throws IOException {
			for (OutputStream os : this.oss)
				os.write(b);
		}
	}

	public static void main(String[] args) throws Exception {
		File inFile = new File(args[0]);
		File outFile = new File(args[0] + ".out");
		System.setOut(new PrintStream(new MultipleOutputStream(System.out, new FileOutputStream(outFile))));
		new R0Cs().allCase(inFile);
	}

	private void allCase(File inFile) throws Exception {
		try (Scanner in = new Scanner(inFile, "UTF-8")) {
			long t = Long.parseLong(in.nextLine().trim());
			init();
			for (long i = 1; i <= t; i++) {
				System.out.print("Case #" + i + ": ");
				singleCase(in);
				System.out.println();
			}
		}
	}

	Map<String, String[]> map = new HashMap<>();
	static final int FIND_I = 0;
	static final int FIND_J = 1;
	static final int FIND_K = 2;
	static final int FIND_END = 3;

	private void init() {
		map.put("ii", new String[] { "", "N" });
		map.put("ij", new String[] { "k", "P" });
		map.put("ik", new String[] { "j", "N" });
		map.put("ji", new String[] { "k", "N" });
		map.put("jj", new String[] { "", "N" });
		map.put("jk", new String[] { "i", "P" });
		map.put("ki", new String[] { "j", "P" });
		map.put("kj", new String[] { "i", "N" });
		map.put("kk", new String[] { "", "N" });
	}

	private void singleCase(Scanner in) {
		int L = in.nextInt();
		int X = in.nextInt();
		in.nextLine();
		String s = in.nextLine().trim();
		int stage = FIND_I;
		int positive = 1;
		String buffer = "";

		for (int i = 0; i < X; i++) {
			for (int j = 0; j < s.length(); j++) {
				String c = Character.toString(s.charAt(j));
				buffer += c;

				if (buffer.length() == 2) {
					String[] m = map.get(buffer);
					buffer = m[0];
					positive *= "N".equals(m[1]) ? -1 : 1;
				}

				if (buffer.length() == 1) {
					if (stage == FIND_I && "i".equals(buffer) && positive == 1) {
						stage = FIND_J;
						buffer = "";
					} else if (stage == FIND_J && "j".equals(buffer) && positive == 1) {
						stage = FIND_K;
						buffer = "";
					} else if (stage == FIND_K && "k".equals(buffer) && positive == 1) {
						stage = FIND_END;
						buffer = "";
					}
				}

			}
		}

		System.out.print(stage == FIND_END && positive == 1 && buffer.length() == 0 ? "YES" : "NO");

	}
}
