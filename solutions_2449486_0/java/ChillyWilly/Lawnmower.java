
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URL;
import java.util.Scanner;

/**
 * @author Adrian
 */
public class Lawnmower
{
	private static String inputFile;
	private static FileOutputStream outputFile;
	
	public static void main(String args[]) throws FileNotFoundException, IOException
	{
		File file = new File("output.out");
		outputFile  = new FileOutputStream(file);
		inputFile = "B-small-attempt0.in";
		run();
	}
	
	public static void run() throws FileNotFoundException, IOException
	{
		Scanner reader = openFile(inputFile);
		int tests = getTestCases(reader);
		for (int i = 1; i <= tests; i++)
		{
			boolean isPossible = checkPossibility(reader);
			writeResult(i, isPossible);
		}
		outputFile.close();
		reader.close();
	}

	private static void writeResult(int testCase, boolean possible) throws IOException
	{
		StringBuilder builder = new StringBuilder("Case #");
		builder.append(testCase);
		builder.append(": ");
		if (possible) {
				builder.append("YES");
		}
		else {
			builder.append("NO");
		}
		builder.append("\n");
		outputFile.write(builder.toString().getBytes("UTF-8"));
	}

	private static boolean checkPossibility(Scanner reader) throws IOException
	{
		int n, m;
		n = reader.nextInt();
		m = reader.nextInt();
		int lawn[][] = new int[n][m];
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				lawn[i][j] = reader.nextInt();
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (checkPossibility(lawn, n, m, i, j) == false) {
					return false;
				}
			}
		}
		return true;
	}
	
	private static boolean checkPossibility(int lawn[][], int n, int m, int x, int y) {
		int maxLine = 0;
		int maxCol = 0;
		for (int i=0; i<n; i++) {
			if (i != x) {
				if (maxLine < lawn[i][y]) {
					maxLine = lawn[i][y];
				}
			}
		}
		for (int j=0; j<m; j++) {
			if (j != y) {
				if (maxCol < lawn[x][j]) {
					maxCol = lawn[x][j];
				}
			}
		}
		if (lawn[x][y] < maxLine && lawn[x][y] < maxCol) {
			return false;
		}
		return true;
	}

	private static int getTestCases(Scanner reader) throws IOException
	{
		int tests = reader.nextInt();
		return tests;
	}

	private static Scanner openFile(String fileName) throws FileNotFoundException
	{
		URL url = Lawnmower.class.getClassLoader().getResource(fileName);
		if (url == null)
		{
			throw new FileNotFoundException("Cannot find input file");
		}
		File f = new File(url.getPath());
		Scanner reader = new Scanner(f);
		return reader;
	}
}
