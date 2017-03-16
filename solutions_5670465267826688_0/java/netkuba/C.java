import java.util.Scanner;

public class C {
	
	static final int[][] MAP = new int[8][8];
	
	static int O = 0;
	static int I = 1;
	static int J = 2;
	static int K = 3;
	
	static {
		MAP[O][O] = O;
		MAP[O][I] = I;
		MAP[O][J] = J;
		MAP[O][K] = K;
		MAP[I][O] = I;
		MAP[I][I] = O+4;
		MAP[I][J] = K;
		MAP[I][K] = J+4;
		MAP[J][O] = J;
		MAP[J][I] = K+4;
		MAP[J][J] = O+4;
		MAP[J][K] = I;
		MAP[K][O] = K;
		MAP[K][I] = J;
		MAP[K][J] = I+4;
		MAP[K][K] = O+4;
		
		for (int i=0; i<4; ++i) {
			for (int j=0; j<4; ++j) {
				MAP[i+4][j] = MAP[i][j] + 4;
				MAP[i][j+4] = MAP[i][j] + 4;
				MAP[i+4][j+4] = MAP[i][j];
			}
		}
		for (int i=0; i<8; ++i) {
			for (int j=0; j<8; ++j) {
				MAP[i][j] = MAP[i][j] % 8;
			}
		}
	}
	
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int testsNumber = scanner.nextInt();
		for (int test = 1; test <= testsNumber; ++test) {
			int length = scanner.nextInt();
			int multiplier = scanner.nextInt();
			String string = scanner.next();
			System.out.println(String.format("Case #%s: %s",
					test, new C().solve(length, multiplier, string)));
		}
		scanner.close();
	}

	private int power(int a, int b) {
		if (b == 0) return 0;
		if ((b & 1) == 1) return MAP[power(MAP[a][a], b/2)][a];
		return power(MAP[a][a], b/2);
	}
	
	private String solve(int length, int multiplier, String string) {
		int values[] = new int[length];
		for (int i=0; i<string.length(); ++i) {
			switch (string.charAt(i)) {
			case 'i': values[i] = I; break;
			case 'j': values[i] = J; break;
			case 'k': values[i] = K; break;
			}
		}
		
		int rowProduct = O;
		for (int i=0; i<values.length; ++i) {
			rowProduct = MAP[rowProduct][values[i]];
		}
		
		int total = power(rowProduct, multiplier);
		if (MAP[MAP[I][J]][K] != total) {
			return "NO";
		}
		
		int prefixCounter = 0;
		int prefixProduct = O;
		boolean match = false;
		for (int i = 0; i < Math.min(8, multiplier); ++i) {
			for (int j = 0; j < values.length; ++j) {
				++prefixCounter;
				prefixProduct = MAP[prefixProduct][values[j]];
				//System.out.println("a " + prefixProduct);
				if (prefixProduct == I) {
					match = true;
					break;
				}
			}
			if (match) {
				break;
			}
		}
		if (!match) return "NO";
		
		int sufixCounter = 0;
		int sufixProduct = O;
		match = false;
		for (int i = 0; i < Math.min(8, multiplier); ++i) {
			for (int j = values.length - 1; j >= 0; --j) {
				++sufixCounter;
				sufixProduct = MAP[values[j]][sufixProduct];
				//System.out.println("b " + sufixProduct);
				if (sufixProduct == K) {
					match = true;
					break;
				}
			}
			if (match) {
				break;
			}
		}
		if (!match) return "NO";
		
		if (sufixCounter + prefixCounter >= length * multiplier) return "NO";
		
		return "YES";
	}
}
