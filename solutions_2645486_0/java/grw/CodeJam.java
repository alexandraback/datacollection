package codejam;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class CodeJam {
	
	public static abstract class Problem {
		protected void solveCase(Scanner scanner, PrintWriter writer) {
			writer.print(solveCase(scanner).toString());
		}

		protected Object solveCase(Scanner scanner) {
			return solveCase(scanner.nextLine());
		}
		
		protected Object solveCase(String nextLine) {
			return null;
		}
	}

	private static final String DOWNLOADS = "Downloads";
	private static final String UPLOADS = "workspace/java/CodeJam2013/src/codejam";
	private static final Charset ENCODING = StandardCharsets.US_ASCII;
	
	public static void runBatch(Problem task, Scanner scanner, PrintWriter writer) throws IOException {
		int t = scanner.nextInt();
		scanner.nextLine();
		for (int i = 1; i <= t; i++) {
			writer.print("Case #");
			writer.print(i);
			writer.print(": ");
			task.solveCase(scanner, writer);
			writer.println();
			writer.flush();
		}
	}
	
	public static void runBatch(Problem task, Path input, Path output) throws IOException {
		try (
				Scanner scanner = new Scanner(input, ENCODING.name());
				PrintWriter writer = new PrintWriter(Files.newBufferedWriter(output, ENCODING));
		) {
			runBatch(task, scanner, writer);
		}		
	}
	
	public static PrintWriter getAuxWriter() throws IOException {
		String home = System.getenv().get("HOME");
		if (home == null)
			home = System.getenv().get("USERPROFILE");
		if (home == null)
			throw new RuntimeException("no home dir");
		Path aux = Paths.get(home, "Desktop", "fairAndSquare.out");
		PrintWriter writer = new PrintWriter(Files.newBufferedWriter(aux, ENCODING));
		return writer;
	}

	public static void runBatch(Problem task, String file) throws IOException {
		String home = System.getenv().get("HOME");
		if (home == null)
			home = System.getenv().get("USERPROFILE");
		if (home == null)
			throw new RuntimeException("no home dir");
		runBatch(task, Paths.get(home, DOWNLOADS, file + ".in"), Paths.get(home, UPLOADS, file + ".out"));
	}
}
