
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

public class J1P2 {
	
	static class Best {
		long value;
	}
	
	public static void recurse(int maxEnergy, int energy, int recover, int[] values, int index, long gain, Best best) {
		if (index == (values.length - 1)) {
			long newGain = gain + energy * values[index];
			if (newGain > best.value) {
				best.value = newGain;
			}
		} else {
			for (int spend = 0; spend <= energy; spend++) {
				long newGain  = gain + spend * values[index];
				int newEnergy = energy - spend + recover;
				if (newEnergy > maxEnergy){
					newEnergy = maxEnergy;
				}
				recurse(maxEnergy, newEnergy, recover, values, index + 1, newGain , best);
			}
		}
	}
	
	public static void solve(InputStream input, PrintStream out) {
		Scanner in = new Scanner(input);
		final int testCases = in.nextInt();

		testCaseLoop: for (int testCase = 1; testCase <= testCases; ++testCase) {
			
			final int energy = in.nextInt();
			final int recover = in.nextInt();
			final int count = in.nextInt();
			int[] values = new int[count];
			for (int i = 0; i < count; i++) {
				values[i] = in.nextInt();
			}
			
			Best best = new Best();
			
			recurse(energy, energy, recover, values, 0, 0, best);
			
			System.out.println("Case #" + testCase + ": " + best.value);
			out.println("Case #" + testCase + ": " + best.value);
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
				int choice = Integer.parseInt(new BufferedReader(new InputStreamReader(
						System.in)).readLine());
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
