import java.util.Scanner;

public class QR_A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++)
			new Case(sc, i + 1);
	}

}

class Case {
	Case(Scanner sc, int caseNo) {
		int N = sc.nextInt() + 1;
		String S_str = sc.next();
		int S[] = new int[N];
		for (int i = 0; i < N; i++)
			S[i] = S_str.charAt(i) - '0';
		int sum = 0, need = 0;
		for (int i = 0; i < N; i++) {
			if (i - sum > 0) {
				need += i - sum;
				sum = i;
			}
			sum += S[i];
		}
		System.out.println("Case #" + caseNo + ": " + need);
	}
}