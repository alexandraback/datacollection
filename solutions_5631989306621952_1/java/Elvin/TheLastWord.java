import java.io.*;
import java.util.*;

public class TheLastWord {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(args[0]));
		PrintWriter pw = new PrintWriter(new FileWriter(args[0]+".out.txt"));

		int numOfCase = sc.nextInt();
		List<Character> list = null;
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < numOfCase; i++) {
			char[] token = sc.next().toCharArray();
			int len = token.length;
			list = new LinkedList<Character>();

			for (int j = 0; j < len; j++) {
				if (list.size() == 0 || token[j] < list.get(0)) {
					list.add(token[j]);
				} else {
					list.add(0, token[j]);
				}
			}

			sb.setLength(0);
			for (Character ch : list) {
				sb.append(ch);
			}
			pw.println("Case #" + (i + 1) + ": " + sb.toString());
		}

		pw.flush();
		pw.close();
		sc.close();
	}
}