import java.io.File;
import java.io.FileOutputStream;
import java.util.Scanner;

public class Solve2016R1A_A {
	private static String filePath = "A-large.in";

	public static void main(String[] args) {
		StringBuffer answer = new StringBuffer();

		try (Scanner sc = new Scanner(new File(filePath))) {
			int T = sc.nextInt();
			for (int i = 1; i <= T; i++) {
				answer.append("Case #" + i + ": ");
				String S = sc.next();
				
				StringBuffer lastWord = new StringBuffer();
				int len = S.length();
				char first = S.charAt(0);
				lastWord.append(first);
				for (int j = 1; j < len; j++) {
					char c = S.charAt(j);
					if (c < first) {
						lastWord.append(c);
					} else {
						lastWord.insert(0, c);
						first = c;
					}
				}
				answer.append(lastWord.toString()).append("\n");
			}
			output(answer);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static void output(StringBuffer answer) throws Exception {
		String outPath = "answer.out";
		if (filePath != null && !filePath.equals("")) {
			outPath = filePath.substring(0, filePath.length() - 2) + "out";
		}
		try (FileOutputStream fos = new FileOutputStream(outPath, false)) {
			fos.write(answer.toString().getBytes());
		}
		System.out.println(answer);
	}
}
