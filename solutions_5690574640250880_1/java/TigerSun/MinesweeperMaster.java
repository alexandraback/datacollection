import java.util.Arrays;
import java.util.Scanner;

/**
 * FileName: MinesweeperMaster.java
 * @Description: Google code jam Problem C. Minesweeper Master
 * 
 * @author Xunhu(Tiger) Sun
 *         email: sunx2013@my.fit.edu
 * @date Apr 12, 2014 3:10:48 AM
 */
public class MinesweeperMaster {
    public static void main (final String[] args) {
        final Scanner s = new Scanner(System.in);
        final int tc = s.nextInt();
        s.nextLine();
        for (int tci = 1; tci <= tc; tci++) {
            final int r = s.nextInt();
            final int c = s.nextInt();
            final int m = s.nextInt();

            final char[][] map = new char[r][c];
            for (int i = 0; i < map.length; i++) {
                Arrays.fill(map[i], '.');
            }
            int i = r - 1;
            int j = c - 1;
            int mt = m;
            boolean isvalid = true;
            while (mt != 0) {
                if (i < j) { // row shorter than column.
                    if (i + 1 <= mt) {
                        // fill one column
                        for (int k = 0; k <= i; k++) {
                            map[k][j] = '*';
                        }
                        mt -= i + 1;
                        j--;
                    } else {// i +1> m store in long edge
                        if (i == 1 && mt == 1) {
                            isvalid = false;
                            break;
                        }
                        if (j == mt) {// store this one in corner
                            if (j - 1 == 1) {
                                isvalid = false;
                                break;
                            }
                            map[i - 1][j] = '*';
                            mt--;
                        }
                        for (int k = j; k > j - mt; k--) {
                            map[i][k] = '*';
                        }
                        mt = 0;
                    }
                } else { // if (i >= j) row longer than column.
                    if (j + 1 <= mt) {
                        // fill one column
                        for (int k = 0; k <= j; k++) {
                            map[i][k] = '*';
                        }
                        mt -= j + 1;
                        i--;
                    } else {// j +1 > m store in long edge
                        if (j == 1 && mt == 1) {
                            isvalid = false;
                            break;
                        }
                        if (i == mt) {// store this one in corner
                            if (i - 1 == 1) {
                                isvalid = false;
                                break;
                            }
                            map[i][j - 1] = '*';
                            mt--;
                        }
                        for (int k = i; k > i - mt; k--) {
                            map[k][j] = '*';
                        }
                        mt = 0;
                    }
                }
            }
            if (r * c - 1 == m) {
                for (int i1 = 0; i1 < map.length; i1++) {
                    Arrays.fill(map[i1], '*');
                }
                map[0][0] = 'c';
                System.out.printf("Case #%d:%n", tci);
                for (int i1 = 0; i1 < map.length; i1++) {
                    System.out.println(String.valueOf(map[i1]));
                }
            } else {
                if (r >= 2) {
                    if (map[1][0] == '*') {
                        isvalid = false;
                    }
                }
                if (c >= 2) {
                    if (map[0][1] == '*') {
                        isvalid = false;
                    }
                }
                if (r >= 2 && c >= 2) {
                    if (map[1][1] == '*') {
                        isvalid = false;
                    }
                }
                if (isvalid) {
                    map[0][0] = 'c';
                    System.out.printf("Case #%d:%n", tci);
                    for (int i1 = 0; i1 < map.length; i1++) {
                        System.out.println(String.valueOf(map[i1]));
                    }
                } else {
                    System.out.printf("Case #%d:%n", tci);
                    System.out.println("Impossible");
                }
            }
        }
        s.close();
    }

}
