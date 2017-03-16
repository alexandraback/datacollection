package gcj2015.qr;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Date;
import java.util.Scanner;

public class c1 {
	public static void main(String[] args) {
//		readAndSolve("resource/gcj2015/qr/c1/sample.in", "resource/gcj2015/qr/c1/sample.out");
		readAndSolve("resource/gcj2015/qr/c1/C-large.in", "resource/gcj2015/qr/c1/C-large.out");
//		readAndSolve("resource/gcj2015/qr/c1/C-small-attempt0.in", "resource/gcj2015/qr/c1/C-small-attempt0.out");
	}

	/**
	 * @param inputName
	 * @param outputName
	 */
	private static void readAndSolve(String inputName, String outputName) {
		BufferedReader input = null;
		BufferedWriter output = null;
		Date d1 = new Date();
		try {
			input = new BufferedReader(new FileReader(inputName));
			output = new BufferedWriter(new FileWriter(outputName));
			String line1 = null;
			String line2 = null;
			int expectedCases = 0;
			int actualCase = -1;
			line1 = input.readLine();
			expectedCases = Integer.parseInt(line1);
			for (actualCase = 1; actualCase <= expectedCases; actualCase++) {
				line1 = input.readLine();
				line2 = input.readLine();
				String result = solve(line1, line2);
				output.write("Case #" + actualCase + ": " + result + "\n");
//				System.out.println("Case #" + actualCase + ": " + result);
			}
			input.close();
			output.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {

		}
	}

	static char I = 'i';
	static char J = 'j';
	static char K = 'k';

	private static String solve(String line1, String line2) {
//		System.out.println(line1 + "" + line2);
		Scanner sc = new Scanner(line1);
		int charsl = sc.nextInt();
		long times = sc.nextLong();
		char[] chars = line2.toCharArray();
		if (chars.length * times < 3) {
			return "NO";
		}
		boolean foundi = false;
		boolean foundj = false;
		boolean foundk = false;
		int m = 1;
		long i = 0;
		for ( i = 0; i < times && ( i<5 || foundi) && (i<9 ) && (!foundj); i++) {
			for (int j = 0; j < chars.length; j++) {
				m = multi(m, chars[j]);
//				System.out.print(chars[j] + " (" + (int) chars[j] + ") (" + m + ") ; ");
				if (!foundi) {
					if ((int) I == m) {
						foundi = true;
						m = 1;
//						System.out.println("\n i megvan");
					}
				} else {
					if (!foundj && ((int) J == m)) {
						foundj = true;
						m = 1;
//						System.out.println("\n j megvan");
					}
				}
			}
		}
		if (i < times ) {
			int k = 1;
			for (int j = 0; j < chars.length; j++) {
				k = multi(k, chars[j]);
			}
			k = quad(k, times-i);
			m = multi (m, k);
		}
		foundk = ((int) K == m);
//		System.out.println("");
		if (foundi && foundj && foundk) {
			return "YES";
		}
		return "NO";
	}

	private static int multi(int c1, int c2) {
		int s1 = c1 < 0 ? -1 : 1;
		int s2 = c2 < 0 ? -1 : 1;
		int uc1 = Math.abs(c1);
		int uc2 = Math.abs(c2);
		if (uc1 == 1) {
			return c2 * s1;
		}
		if (uc2 == 1) {
			return c1 * s2;
		}

		if (uc1 == I) {
			if (uc2 == I) {
				return -1 * s1 * s2;
			}
			if (uc2 == J) {
				return K * s1 * s2;
			}
			if (uc2 == K) {
				return (-1 * J * s1 * s2);
			}
		}
		if (uc1 == J) {
			if (uc2 == J) {
				return -1 * s1 * s2;
			}
			if (uc2 == I) {
				return -1 * K * s1 * s2;
			}
			if (uc2 == K) {
				return (I * s1 * s2);
			}
		}
		if (uc1 == K) {
			if (uc2 == K) {
				return -1 * s1 * s2;
			}
			if (uc2 == J) {
				return -1 * I * s1 * s2;
			}
			if (uc2 == I) {
				return (J * s1 * s2);
			}
		}
		return 0;
	}
	
	private static int quad (int c1, long q) {
		int s1 = c1 < 0 ? -1 : 1;
		int uc1 = Math.abs(c1);
		long l = q % 2l;
		if (uc1 == 1) {
			if (l == 0l) {
				return uc1;
			}
			return s1 * uc1;
		}
		int mod = (int)(q % 4l);
		int result = 1;
		switch (mod) {
		case 0:
			return 1;
		case 1:
			return c1;
		case 2:
			return -1;
		case 3:
			return -1 * c1;
		default:
			break;
		}
		
		return result;		
	}
}
