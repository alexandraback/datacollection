import java.util.Scanner;

public class A {
	private String getWord(String word) {
		StringBuilder result = new StringBuilder();
		char first = word.charAt(0);
		result.append(word.charAt(0));
		for (int i = 1; i < word.length(); i++) {
			if (first > word.charAt(i)) {
				result.append(word.charAt(i));
			} else {
				result.insert(0, word.charAt(i));
				first = word.charAt(i);
			}
		}

		return result.toString();
	}

	public static void main(String[] args) {
		Scanner in = null;
		A a = new A();
		try {
			in = new Scanner(System.in);
			int count = in.nextInt();
			in.nextLine();
			for (int test = 1; test <= count; test++) {
				String word = in.nextLine();
				String result = a.getWord(word);
				System.out.println("Case #" + test + ": " + result);
			}
			in.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}