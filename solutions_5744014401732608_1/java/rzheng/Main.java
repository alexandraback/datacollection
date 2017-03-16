import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int B = sc.nextInt();
			long M = sc.nextLong();
			String s = Long.toBinaryString(M);
			if (s.length() < B - 1) {
				System.out.println("Case #" + i + ": POSSIBLE");
				for (int j = s.length(); j < B; j++) {
					System.out.print(0);
				}
				System.out.println(s);
				for (int j = 1; j < B; j++) {
					for (int k = 0; k < j; k++) {
						System.out.print(0);
					}
					for (int k = j + 1; k < B; k++) {
						System.out.print(1);
					}
					System.out.println(0);
				}
			} else {
				String s2 = Long.toBinaryString(M - 1);
				if (M == 1 || s2.length() < B - 1) {
					if (M == 1) {
						s2 = "";
					}
					System.out.println("Case #" + i + ": POSSIBLE");
					for (int j = s2.length(); j < B; j++) {
						System.out.print(0);
					}
					System.out.println(s2);
					for (int j = 1; j < B; j++) {
						for (int k = 0; k < j; k++) {
							System.out.print(0);
						}
						for (int k = j + 1; k < B; k++) {
							System.out.print(1);
						}
						System.out.println(1);
					}
				} else {
					System.out.println("Case #" + i + ": IMPOSSIBLE");
				}
			}
		}
		sc.close();
	}
}