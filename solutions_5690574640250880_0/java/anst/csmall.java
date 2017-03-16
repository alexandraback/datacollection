import static java.lang.System.*;import static java.lang.Math.*;import static java.lang.Character.*;import java.io.*;import java.text.*;import java.util.*;import java.util.regex.*;import java.math.*;
public class snakeLatin {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("snakeLatin.dat"));
		int dS = Integer.parseInt(sc.nextLine());
		for (int xxy = 1; xxy <= dS; xxy++) {
		    int r = sc.nextInt();
            int c = sc.nextInt();
            int m = sc.nextInt();

            char[][] maz = new char[r][c];
            for (int i = 0; i < maz.length; i++) {
                Arrays.fill(maz[i], '.');
            }
            int i = r - 1;
            int j = c - 1;
            int mt = m;
            boolean isvalid = true;
            while (mt != 0) {
                if (i < j) {
                    if (i + 1 <= mt) {
                        for (int k = 0; k <= i; k++) {
                            maz[k][j] = '*';
                        }
                        mt -= i + 1;
                        j--;
                    } else {
                        if (i == 1 && mt == 1) {
                            isvalid = false;
                            break;
                        }
                        if (j == mt) {
                            if (j - 1 == 1) {
                                isvalid = false;
                                break;
                            }
                            maz[i - 1][j] = '*';
                            mt--;
                        }
                        for (int k = j; k > j - mt; k--) {
                            maz[i][k] = '*';
                        }
                        mt = 0;
                    }
                } else { 
                    if (j + 1 <= mt) {
                        for (int k = 0; k <= j; k++) {
                            maz[i][k] = '*';
                        }
                        mt -= j + 1;
                        i--;
                    } else {
                        if (j == 1 && mt == 1) {
                            isvalid = false;
                            break;
                        }
                        if (i == mt) {
                            if (i - 1 == 1) {
                                isvalid = false;
                                break;
                            }
                            maz[i][j - 1] = '*';
                            mt--;
                        }
                        for (int k = i; k > i - mt; k--) {
                            maz[k][j] = '*';
                        }
                        mt = 0;
                    }
                }
            }
            if (r * c - 1 == m) {
                for (int i1 = 0; i1 < maz.length; i1++) {
                    Arrays.fill(maz[i1], '*');
                }
                maz[0][0] = 'c';
                System.out.printf("Case #%d:%n", xxy);
                for (int i1 = 0; i1 < maz.length; i1++) {
                    System.out.println(String.valueOf(maz[i1]));
                }
            } else {
                if (r >= 2) {
                    if (maz[1][0] == '*') {
                        isvalid = false;
                    }
                }
                if (c >= 2) {
                    if (maz[0][1] == '*') {
                        isvalid = false;
                    }
                }
                if (r >= 2 && c >= 2) {
                    if (maz[1][1] == '*') {
                        isvalid = false;
                    }
                }
                if (isvalid) {
                    maz[0][0] = 'c';
                    System.out.printf("Case #%d:%n", xxy);
                    for (int i1 = 0; i1 < maz.length; i1++) {
                        System.out.println(String.valueOf(maz[i1]));
                    }
                } else {
                    System.out.printf("Case #%d:%n", xxy);
                    System.out.println("Impossible");
                }
            }
		}
	}
}