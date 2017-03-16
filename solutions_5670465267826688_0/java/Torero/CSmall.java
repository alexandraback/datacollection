import java.util.Arrays;
import java.util.Scanner;


public class CSmall {

	// i=2, j=3, k=4
	static byte[][] matrix = {
		{ 0, 0, 0, 0, 0},
		{ 0, 1, 2, 3, 4},
		{ 0, 2, -1, 4, -3},
		{ 0, 3, -4, -1, 2},
		{ 0, 4, 3, -2, -1}
	};
	
	static int reduce(int a, int b) {
		boolean negative = a*b < 0;
		if (b < 0 )
			b = (byte) -b;
		if (a < 0)
			a = (byte) -a;
		if (negative)
			return -matrix[a][b];
		return matrix[a][b];
	}
	
	static int[][] reducedCache = null;
	
	static void populateCache(byte array[]) {
		for (int begin = 0; begin < array.length; begin++) {
			int res = 1;
			reducedCache[begin][0] = 1;
			for (int i= begin; i< array.length; i++) {
				res = reduce(res, array[i]);
				reducedCache[begin][i+1] = res;
			}
		}
	}

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try (Scanner scan = new Scanner(System.in)) {
			int T = scan.nextInt();
			for (int t=0; t<T; t++) {
				int L = scan.nextInt();
				int X = scan.nextInt();
				String str = scan.next();
				byte[] array = new byte[L];
				for (int i=0; i<L; i++) {
					char ch = str.charAt(i);
					byte b=0;
					switch (ch) {
					case 'i':
						b = 2;
						break;
					case 'j':
						b = 3;
						break;
					case 'k':
						b = 4;
						break;
					}
					array[i] = b;
				}
				
				reducedCache = new int[L][L+1];
				populateCache(array);
				
				int strReduced = reducedCache[0][L];
				int[] strReducedNTimes = new int[4];
				strReducedNTimes[0] = 1;
				for (int i=1; i<4; i++)
					strReducedNTimes[i] = reduce(strReducedNTimes[i-1], strReduced);
				boolean possible = false;
				for (int n1=0; n1<4; n1++) {
					if (possible)
						break;
					for (int strBreak1 = 0; strBreak1<L; strBreak1++) {
						if (possible)
							break;
						int reducedPart = reducedCache[0][strBreak1];
						int symbol1 = reduce(strReducedNTimes[n1], reducedPart);
						if (symbol1 != 2) //i 
							continue;
						int reducedPart2 = reducedCache[strBreak1][L];
						for (int n2 = 0; n2<4; n2++) {
							int n3 = X - 2 - n1 - n2;
							if (n3 < 0)
								continue;
							n3 = n3 % 4;
							if (possible)
								break;
							for (int strBreak2 = 0; strBreak2 < L; strBreak2++) {
								int reducedPart3 = reducedCache[0][strBreak2];
								int symbol2 = reduce(reducedPart2, strReducedNTimes[n2]);
								symbol2 = reduce(symbol2, reducedPart3);
								if (symbol2 != 3)
									continue;
								int reducedPart4 = reducedCache[strBreak2][L];
								int symbol3 = reduce(reducedPart4, strReducedNTimes[n3]);
								if (symbol3 != 4)
									continue;
								possible = true;
								break;
							}
						}
						//Check the case if we split the string two times
						int n3 = X - 1 - n1;
						if (n3 < 0)
							continue;
						n3 = n3 % 4;
						if (possible)
							break;
						for (int strBreak2 = strBreak1 + 1; strBreak2 < L; strBreak2++) {
							int symbol2 = reducedCache[strBreak1][strBreak2];
							if (symbol2 != 3)
								continue;
							int reducedPart4 = reducedCache[strBreak2][L];
							int symbol3 = reduce(reducedPart4, strReducedNTimes[n3]);
							if (symbol3 != 4)
								continue;
							possible = true;
							break;
						}
					}
				}
				if (possible)
					System.out.format("Case #%d: YES\n",t+1);
				else
					System.out.format("Case #%d: NO\n",t+1);
			}
		}
	}

}
