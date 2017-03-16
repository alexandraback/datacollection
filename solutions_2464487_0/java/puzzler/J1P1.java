import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;

public class J1P1 {

	public static void solve(InputStream input, PrintStream out) {
		Scanner in = new Scanner(input);
		final int testCases = in.nextInt();

		testCaseLoop: for (int testCase = 1; testCase <= testCases; ++testCase) {
			long firstRadius = in.nextLong();
			long paint = in.nextLong();

			long radius = firstRadius;
			long paintLeft = paint;

			int rings = 0;
			do {
				long area = (2 * radius + 1);
				if (area > paintLeft) {
					break;
				}
				paintLeft -= area;
				radius += 2;
				rings++;
			} while (true);

			out.println("Case #" + testCase + ": " + rings);
			System.out.println("Case #" + testCase + ": " + rings);
		} // testCaseLoop
	}

	public static void main(String[] args) throws IOException {
		final String prefix = "data";
		String[] paths;

		if (args.length == 0) {
			paths = new String[1];

			File f = new File(prefix);
			FilenameFilter ff = new FilenameFilter() {
				@Override
				public boolean accept(File dir, String name) {
					return name.endsWith(".in");
				}
			};
			String[] inputFiles = f.list(ff);

			if (inputFiles.length == 0) {
				System.out.print("Input file name: ");
				BufferedReader in = new BufferedReader(new InputStreamReader(
						System.in));
				paths[0] = in.readLine();
			} else {
				int counter = 0;
				for (String option : inputFiles) {
					System.out.println(++counter + " : " + option);
				}
				System.out.print("Choose: ");
				int choice = Integer.parseInt(new BufferedReader(
						new InputStreamReader(System.in)).readLine());
				paths[0] = inputFiles[choice - 1];
			}
		} else {
			paths = args;
		}

		for (String path : paths) {
			try {
				FileInputStream in = new FileInputStream(prefix + "/" + path);

				String outPath;
				if (path.endsWith(".in")) {
					outPath = path.replaceFirst("\\.in$", ".out");
				} else {
					outPath = path + ".out";
				}

				PrintStream out = new PrintStream(new BufferedOutputStream(
						new FileOutputStream(prefix + "/" + outPath)));
				solve(in, out);
				out.close();
			} catch (FileNotFoundException e) {
				System.err.println(e.getMessage());
			}
		}
	}
}
