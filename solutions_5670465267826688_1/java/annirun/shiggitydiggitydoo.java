import java.util.Scanner;

/*
 5
 2 1
 ik
 3 1
 ijk
 3 1
 kji
 2 6
 ji
 1 10000
 i

 1
 2 6
 ji
 */
public class shiggitydiggitydoo {
	static class tile {
		static String poss = "1ijk";
		boolean negative;
		int letter;

		static char[][] multTable = { 
			{ '1', 'i', 'j', 'k' },
			{ 'i', '1', 'k', 'j' },
			{ 'j', 'k', '1', 'i' },
			{ 'k', 'j', 'i', '1' }
		};

		static boolean[][] negativeTable = { 
			{ false, false, false, false },
			{ false, true, false, true },
			{ false, true, true, false },
			{ false, false, true, true }, 
		};

		public tile(char c, boolean b) {
			letter = poss.indexOf(c);
			negative = b;
		}

		public tile(int c, boolean b) {
			letter = c;
			negative = b;
		}

		tile mult(tile other) {
			char newLetter = multTable[other.letter][letter];
			boolean newNeg = negativeTable[other.letter][letter] ^ negative
					^ other.negative;
			return new tile(newLetter, newNeg);
		}

		boolean same(char check) {
			return !negative && poss.charAt(letter) == check;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		int cn = 0;

		while (cn++ < cases) {
			int len = in.nextInt();
			long repeats = in.nextLong();

			// remove 4s until between 15-18
			if (repeats > 16) {
				repeats = 16 + (repeats % 4);
			}

			String word = in.next();
			StringBuilder fullWord = new StringBuilder();
			for (int i = 0; i < repeats; i++) {
				fullWord.append(word);
			}

//			System.out.println(fullWord.toString());

			char[] need = "ijk".toCharArray();
			boolean[][][] can = new boolean[2][4][4];
			can[0][0][0] = true;

			char[] letters = fullWord.toString().toCharArray();
			for (char c : letters) {
//				System.out.println("proccess " + c);
				boolean[][][] next = new boolean[2][4][4];

				for (int neg = 0; neg < 2; neg++) {
					for (int letter = 0; letter < 4; letter++) {
						tile poss = new tile(letter, neg == 1).mult(new tile(c,
								false));
						for (int zone = 0; zone < 3; zone++) {
							if (can[neg][letter][zone]) {
								next[poss.negative ? 0 : 1][poss.letter][zone] = true;
//								System.out.println("can Z" + zone + ": "
//										+ (poss.negative ? "-" : "")
//										+ poss.poss.charAt(poss.letter));

								if (poss.same(need[zone])) {
//									System.out.println("move up from "
//											+ need[zone]);
									next[0][0][zone + 1] = true;
								}
							}
						}
					}
				}

				can = next;
			}

			System.out
					.printf("Case #%d: %s\n", cn, can[0][0][3] ? "YES" : "NO");
		}
		in.close();
	}

}
