import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.Scanner;

public class D {

	class Block {
		boolean naomi;
		double weight;
	}

	void solve(int icase) {
		int n = si();
		Block[] blocks = new Block[2 * n];
		readBlocks(blocks, n, 0, true);
		readBlocks(blocks, n, n, false);
		Arrays.sort(blocks, new Comparator<Block>() {
			@Override
			public int compare(Block o1, Block o2) {
				if (o1.weight < o2.weight) {
					return -1;
				}
				if (o1.weight > o2.weight) {
					return 1;
				}
				return 0;
			}
		});

		int resdw = 0;
		int resw = 0;

		int iw = 0;
		int idw = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (blocks[i].naomi) {
				if (idw > 0) {
					idw--;
					resdw++;
				}
				iw++;
			} else {
				idw++;
				if (iw > 0) {
					iw--;
				} else {
					resw++;
				}
			}
		}

		printf("Case #%d: %d %d\n", icase, resdw, resw);
	}

	void readBlocks(Block[] blocks, int n, int off, boolean naomi) {
		for (int i = 0; i < n; i++) {
			Block b = blocks[off + i] = new Block();
			b.naomi = naomi;
			b.weight = sd();
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new D().repSolve();
	}

	void repSolve() throws Exception {
		scanner = new Scanner(System.in);
		// scanner = new Scanner(new java.io.File(""));
		int ncase = si();
		sline();
		for (int icase = 1; icase <= ncase; icase++) {
			solve(icase);
			System.err.println("[[ " + icase + " ]]");
		}
	}

	Scanner scanner;

	int si() {
		return scanner.nextInt();
	}

	long sl() {
		return scanner.nextLong();
	}

	double sd() {
		return scanner.nextDouble();
	}

	String ss() {
		return scanner.next();
	}

	String sline() {
		return scanner.nextLine();
	}

	void printf(String format, Object... args) {
		System.out.printf(format, args);
	}

}
