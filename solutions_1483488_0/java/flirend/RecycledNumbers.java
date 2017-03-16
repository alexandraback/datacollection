import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;


public class RecycledNumbers {


	public static String SMALL_IN_FILE_NAME = "./input.txt";
	static PrintStream out = null;
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		File smallIn = new File(SMALL_IN_FILE_NAME);
		BufferedReader br = new BufferedReader(new FileReader(smallIn));
		String s = br.readLine();
		int caseCount = Integer.parseInt(s);
		File smallOut = new File("./output.txt");
		smallOut.createNewFile();
		out = new PrintStream(smallOut);
//		out = System.out;

		for (int i = 0; i < caseCount; i ++) {
			out.printf("Case #%d: ", i+1);
			s = br.readLine();
			TestCase t = new TestCase(s);
			out.println(t.solve());
		}
	}

}
