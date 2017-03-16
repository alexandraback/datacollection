import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class SpeakingInTongues {

	public static byte[] prepare() {
		String[] examples = {
				"ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv" };
		String[] answers = {
				"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up" };

		//           abcdefghijklmnopqrstuvwxyz 
		//           yhesocvxduiglbkr?tnwjpfmaq 
		byte[] tr = "????o???????????z???????a? ".getBytes();
		for (int i = 0; i < examples.length; i++) {
			String example = examples[i];
			byte[] answer = answers[i].getBytes();
			for (int j = 0; j < example.length(); j++) {
				char ch = example.charAt(j);
				int index = (int)ch - (int)'a';
				if (index < 0) {
					continue;
				}
				//System.out.println(ch + "(" + index + ")" + (char)answer[j]);
				tr[index] = answer[j];
			}
		}
		byte[] abc = "abcdefghijklmnopqrstuvwxyz ".getBytes();
		for (int i = 0; i < abc.length; i++) {
			boolean found = false;
			for (int j = 0; j < tr.length; j++) {
				if (tr[j] == abc[i]) {
					found = true;
					break;
				}
			}
			if (!found) {
				for (int j = 0; j < tr.length; j++) {
					if ((char)tr[j] == '?') {
						tr[j] = abc[i];
						break;
					}
				}
			}
		}
		return tr;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setOut(new PrintStream("qualification/A-small-attempt0.out"));
		FileReader reader = new FileReader("qualification/A-small-attempt0.in");
		BufferedReader br = new BufferedReader(reader);
		byte[] tr = prepare();
		int tc = Integer.parseInt(br.readLine());
		for (int t = 0; t < tc; t++) {
			byte[] b = br.readLine().getBytes();
			for (int i = 0; i < b.length; i++) {
				char ch = (char)b[i];
				int index = (int)ch - (int)'a';
				if (index >= 0) {
					b[i] = tr[index];
				}
			}
			System.out.printf("Case #%d: %s\n", t + 1, new String(b));
			System.err.printf("Case #%d: %s\n", t + 1, new String(b));
		}
	}
}
