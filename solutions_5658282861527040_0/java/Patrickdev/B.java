package R1B2014.B;

import java.io.*;
import java.math.BigInteger;

/**
 * Created by Patrick on 12-4-14.
 */
public class B {

	final static String INPUTFILE = "D:\\Projecten\\GCJ\\src\\R1B2014\\B\\B-small-attempt0.in";

	static void docase(int casenumber) throws Exception {

		int a = in.nextInt();
		int b = in.nextInt();
		int k = in.nextInt();

		int result = 0;

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {

				int r = i & j;
				if (r < k) {
					result++;
				}
			}
		}

		out.add("Case #" + casenumber + ": " + result);

	}



	public static void main(String args[]) {
		try {

			int totalcases = in.nextInt();

			caseloop:
			for (int currentcase = 1; currentcase <= totalcases; currentcase++) {

				docase(currentcase);

			}

			out.write();

		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	static class In {
		BufferedReader br;
		String buffer = "";

		In() throws Exception {
			br = new BufferedReader(new FileReader(INPUTFILE));
		}

		String nextLine() throws Exception {
			buffer = "";
			return br.readLine();
		}

		String nextString() throws Exception {
			if (buffer.equals("")) {
				buffer = nextLine();
			}

			String line = buffer;

			if (line.contains(" ")) {
				int spacePos = line.indexOf(" ");
				buffer = line.substring(spacePos + 1, line.length());
				return line.substring(0, spacePos);
			} else {
				buffer = "";
				return line;
			}

		}

		int nextInt() throws Exception {
			return Integer.parseInt(nextString());
		}

		BigInteger nextBigInteger() throws Exception {
			return new BigInteger(nextString());
		}
	}

	static class Out {
		StringBuilder strBuilder = new StringBuilder();

		void add(Object str) {
			strBuilder.append(str.toString());
			strBuilder.append("\n");
			log(str);
		}

		void write() throws Exception {
			File file = new File(INPUTFILE.replace(".in", ".out"));
			if (file.exists()) {
				file.delete();
				file.createNewFile();
			}

			BufferedWriter bw = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
			bw.write(strBuilder.toString());
			bw.close();
		}
	}

	static In in;
	static Out out;
	static {
		try {
			in = new In();
			out = new Out();
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}


	static void log(Object o) {
		System.out.println("" + o);
	}
}
