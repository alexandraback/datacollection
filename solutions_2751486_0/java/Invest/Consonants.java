import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Consonants {

	private char[] vowels;

	private long getCount(String name, int n) {
		vowels = new char[] { 'a', 'e', 'i', 'o', 'u'};
		
		long res = 0;
		int last = 0;
		int count = 0;
		for (int i = 0; i < name.length(); i++) {
			if (!isVowel(name.charAt(i))) {
				count++;
				if (count == n) {
					res += (i - n + 2 - last) * (name.length() - i);
					last = i - n + 2;
					count--;
				}
			} else {
				count = 0;
			}
		}
		
		return res;
	}
	
	private boolean isVowel(char ch) {
		for (int i = 0; i < vowels.length; i++) {
			if (vowels[i] == ch) return true;
		}
		return false;
	}

	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");

			in = new Scanner(new File(INPUT_FILE_PATH));
			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			int testCount = in.nextInt();

			for (int i = 0; i < testCount; i++) {
				String name = in.next();
				int n = in.nextInt();

				System.out.println(i);
				writer.println("Case #" + (i + 1) + ": " + new Consonants().getCount(name, n));
			}
			writer.flush();

			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (in != null) in.close();
			if (writer != null) writer.close();
		}
	}

}
