import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) throws Exception {
		// this should fail on large test case
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(bf.readLine());
		for (int tc = 1; tc <= t; tc++) {

			StringTokenizer st = new StringTokenizer(bf.readLine());
			int l = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			String pattern = bf.readLine();
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < x; i++) {
				sb.append(pattern);
			}
			String word = sb.toString();

			int size = l * x;
			int[][] letter = new int[size + 1][size];
			for (int length = 1; length <= size; length++) {
				for (int start = 0; start < size - length + 1; start++) {
					if (length == 1) {
						letter[length][start] = charToLetter(word.charAt(start));
					} else {
						letter[length][start] = mult(letter[length - 1][start],
								letter[1][start + length - 1]);
					}
				}
			}

			boolean found = false;
			// now see if some partitioning results in ijk
			for (int first = 1; first <= size - 2; first++) {
				for (int second = first + 1; second <= size - 1; second++) {
					int lenA = first;
					int lenB = second - first;
					int lenC = size - second;

					int firstLetter = letter[lenA][0];
					int secondLetter = letter[lenB][first];
					int thirdLetter = letter[lenC][second];

					if (firstLetter == 2 && secondLetter == 3
							&& thirdLetter == 4) {
						found = true;
						// System.out.println("answer: "
						// + word.substring(0, first) + "|"
						// + word.substring(first, second) + "|"
						// + word.substring(second, size));
						break;
					}
				}
				if (found) {
					break;
				}
			}

			System.out.println("Case #" + tc + ": " + (found ? "YES" : "NO"));
		}
	}

	private static int[][] multTable = { { 0, 0, 0, 0, 0 }, { 0, 1, 2, 3, 4 },
			{ 0, 2, -1, 4, -3 }, { 0, 3, -4, -1, 2 }, { 0, 4, 3, -2, -1 }, };

	private static int mult(int a, int b) {
		// 1=1
		// i=2
		// j=3
		// k=4

		int prod = multTable[Math.abs(a)][Math.abs(b)];
		if (a * b > 0) {
			return prod;
		} else {
			return -prod;
		}
	}

	private static int charToLetter(char cur) {
		switch (cur) {
		case 'i':
			return 2;
		case 'j':
			return 3;
		case 'k':
			return 4;
		}
		return 0;
	}

}
