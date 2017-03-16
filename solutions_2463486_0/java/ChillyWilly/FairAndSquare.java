
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URL;
import java.util.Scanner;

/**
 * @author Adrian
 */
public class FairAndSquare {
	private static long numbers[] = {1L, 4L, 
		9L, 
		121L, 484L, 
		10201L, 12321L, 14641L, 40804L, 44944L, 1002001L, 1234321L, 4008004L, 
		
		100020001L, 102030201L, 104060401L, 121242121L, 123454321L, 125686521L, 400080004L, 404090404L, 10000200001L, 10221412201L, 12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L, 1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L, 4004009004004L};
	private static String inputFile;
	private static FileOutputStream outputFile;

	public static void main(String args[]) throws FileNotFoundException, IOException
	{
		File file = new File("output.out");
		outputFile = new FileOutputStream(file);
		inputFile = "C-small-attempt0.in";
		run();
	}
	
	public static void run() throws FileNotFoundException, IOException
	{
		Scanner reader = openFile(inputFile);
		int tests = getTestCases(reader);
		for (int i = 1; i <= tests; i++)
		{
			
			int nr = find(reader);
			writeResult(i, nr);
		}
		outputFile.close();
		reader.close();
	}
	
	private static int find(Scanner reader) {
		Long a = reader.nextLong();
		Long b = reader.nextLong();
		int found = 0;
		for (int i=0; i<numbers.length; i++) {
			if (numbers[i] >= a && numbers[i] <= b) {
				found++;
			}
		}
		return found;
	}
	
	private static void writeResult(int testCase, int nr) throws IOException
	{
		StringBuilder builder = new StringBuilder("Case #");
		builder.append(testCase);
		builder.append(": ");
		builder.append(nr);
		builder.append("\n");
		outputFile.write(builder.toString().getBytes("UTF-8"));
	}

	private static int getTestCases(Scanner reader) throws IOException
	{
		int tests = reader.nextInt();
		return tests;
	}

	private static Scanner openFile(String fileName) throws FileNotFoundException
	{
		URL url = FairAndSquare.class.getClassLoader().getResource(fileName);
		if (url == null)
		{
			throw new FileNotFoundException("Cannot find input file");
		}
		File f = new File(url.getPath());
		Scanner reader = new Scanner(f);
		return reader;
	}
}