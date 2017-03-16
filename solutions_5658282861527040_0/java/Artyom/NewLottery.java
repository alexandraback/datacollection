import java.util.Scanner;

public class NewLottery {
	public int getNum(int a, int b, int k) {
		int n = 0;
		for (int aa = 0; aa < a; aa++) {
			for (int bb = 0; bb < b; bb++) {
				if ((aa & bb) < k) n++;
			}
		}
		return n;
	}
	public static void main(String[] args) {
		try (final Scanner in = new Scanner(System.in)) {
			final int t = Integer.parseInt(in.nextLine());
			for (int i = 1; i <= t; i++) {
				String[] tok = in.nextLine().split(" ");
				int a = Integer.parseInt(tok[0]);
				int b = Integer.parseInt(tok[1]);
				int k = Integer.parseInt(tok[2]);
				System.out.printf("Case #%s: %s%n", i, new NewLottery().getNum(a, b, k));
			}
		}
	}
}
