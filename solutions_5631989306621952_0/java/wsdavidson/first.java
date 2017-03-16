import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class first {
	public static void main(String[] args) {
		try {
			process();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static void process()
	throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int testCases = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < testCases; ++i) {
			System.out.println("Case #" + (i+1) + ":" + processTestCase(reader));
		}
		
		reader.close();
	}
	
	private static String processTestCase(BufferedReader reader)
	throws IOException {
		String S = reader.readLine();
		
		String newString = "" + S.charAt(0);
		
		for (int i = 1; i < S.length(); ++i) {
			if ((int) S.charAt(i) >= (int) newString.charAt(0)) {
				newString = S.charAt(i) + newString;
			}
			else {
				newString += S.charAt(i);
			}
		}
		
		return " " + newString;
	}
}