import java.util.Scanner;

public class PartElfSmall {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		int P, Q;
		int i, j, k;
		String str[];
		boolean isPossible;
		int ans;
		int num;
		int value;
		int arr[];
		int index;

		for (k = 0; k < T; k++) {
			str = scanner.next().split("/");
			P = Integer.parseInt(str[0]);
			Q = Integer.parseInt(str[1]);
			arr = new int[64];

			isPossible = false;
			ans = 0;
			value = 1;
			index = 0;
			while (value <= Q) {
				if (value == Q) {
					isPossible = true;
					break;
				}
				value *= 2;
				index++;
			}

			if (isPossible == true) {
				num = P;
				for (i = 0; i < 64; i++) {
					arr[i] = 0;
				}
				for (i = index; i >= 0; i--) {
					arr[i] = ((num >> i) & 1);
					if (arr[i] == 1) {
						ans = index - i;
						break;
					}
				}

				System.out.println("Case #" + (k + 1) + ": " + ans);
			} else {
				System.out.println("Case #" + (k + 1) + ": impossible");
			}
		}
	}
}
