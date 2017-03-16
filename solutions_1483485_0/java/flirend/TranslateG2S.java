import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.io.Reader;
import java.util.HashMap;
import java.util.Map;


public class TranslateG2S {

	public static String SMALL_IN_FILE_NAME = "./input.txt";
	static PrintStream out = null;
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File smallIn = new File(SMALL_IN_FILE_NAME);
		BufferedReader br = new BufferedReader(new FileReader(smallIn));
		String s = br.readLine();
		int caseCount = Integer.parseInt(s);
		File smallOut = new File("./output.txt");
		smallOut.createNewFile();
		out = new PrintStream(smallOut);
		File dictionaryBook = new File("./dic.txt");

		// prepare Map
		Map<String, String> dic = new HashMap<String, String>();
		prepareG2SDic(dic, dictionaryBook);
		
		for (int i = 0; i < caseCount; i ++) {
			out.printf("Case #%d: ", i+1);
			String g = br.readLine();
			out.println(translateG2S(g, dic));
		}
	}
	private static String translateG2S(String g, Map<String, String> dic) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < g.length(); i++) {
			String gChar = g.substring(i, i+1);
			String sChar = dic.get(gChar);
			if (sChar == null) {
				throw new RuntimeException("Failed to match " + gChar);
			} else {
				sb.append(sChar);
			}
		}
		return sb.toString();
	}
	private static void prepareG2SDic(Map<String, String> dictionary, File book) {
		if (!book.exists()) {
			return;
		}
		try {
			BufferedReader br = new BufferedReader(new FileReader(book));
			String s = br.readLine();
			while (s != null) {
				String[] result = s.split("=");
				if (dictionary.containsKey(result[0])) {
					if (!result[1].equals(dictionary.get(result[0]))) {
						throw new RuntimeException("bad match");
					}
				} else {
					dictionary.put(result[0], result[1]);
				}
				s = br.readLine();
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	

}
