import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class Problem {

	public static void solve(String file) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File("./" + file + ".in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("./" + file + ".out"), false));

		try {
			int num = Integer.parseInt(reader.readLine());

			String[] cols;
			for (int n = 1; n <= num; ++n) {
				cols = reader.readLine().split("\\s");
				int X = Integer.parseInt(cols[0]);
				int Y = Integer.parseInt(cols[1]);

				StringBuilder sb = new StringBuilder();
				if (X != 0) {
					if (X < 0) {
						for (int i = 0; i < -X; ++i) {
							sb.append("EW");
						}
					} else {
						for (int i = 0; i < X; ++i) {
							sb.append("WE");
						}
					}
				}

				if (Y != 0) {
					if (Y < 0) {
						for (int i = 0; i < -Y; ++i) {
							sb.append("NS");
						}
					} else {
						for (int i = 0; i < Y; ++i) {
							sb.append("SN");
						}
					}
				}

				writer.write("Case #" + n + ": " + sb.toString());
				writer.newLine();

			}
		} finally {
			writer.close();
			reader.close();
		}
	}

	public static void main(String[] args) throws Exception {
		solve("B-small-attempt1");
	}

}
