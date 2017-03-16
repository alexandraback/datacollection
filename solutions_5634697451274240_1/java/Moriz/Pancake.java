import java.util.Scanner;

class Pancake {
	public static void main(String argv[]) {
		Scanner reader = new Scanner(System.in);
		int T;
		String S;
		T = reader.nextInt();
		S = reader.nextLine();
		for (int i = 1; i <= T; i++) {
			S = reader.nextLine();
			int result = 0;
			char current, next;

			for (int j = 0; j < S.length() - 1; j++) {
				current = S.charAt(j);
				next = S.charAt(j + 1);
				if (current != next) result++;
			}
			if(S.charAt(S.length() - 1)=='-') result++;
			System.out.print("Case #" + i + ": ");
			System.out.println(result);
		}
	}
}