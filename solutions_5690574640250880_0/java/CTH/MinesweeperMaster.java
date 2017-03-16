import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class MinesweeperMaster {
    private static void solve(Scanner in, FileWriter output, int cas)
            throws IOException {
        int R, C, M, tot, empty;
        R = in.nextInt();
        C = in.nextInt();
        M = in.nextInt();
        tot = R * C;
        empty = tot - M;
        output.append("Case #" + cas + ":\n");
        if (empty == 2 && !(R == 1 || C == 1)) {
            output.append("Impossible\n");
            return;
        }
        if ((R == 2 || C == 2) && empty % 2 == 1 && empty != 1) {
            output.append("Impossible\n");
            return;
        }
        char[][] map = new char[R][C];
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                map[i][j] = '*';
        if (empty == 1) {
            map[0][0] = 'c';
        } else if (R == 1) {
            for (int i = 0; i < empty; i++)
                map[0][i] = '.';
        } else if (C == 1) {
            for (int i = 0; i < empty; i++)
                map[i][0] = '.';
        } else if (R == 2) {
            for (int i = 0; i < empty / 2; i++) {
                map[0][i] = '.';
                map[1][i] = '.';
            }
        } else if (C == 2) {
            for (int i = 0; i < empty / 2; i++) {
                map[i][0] = '.';
                map[i][1] = '.';
            }
        } else {
            int k;
            for (k = C; k > 1; k--) {
                int row = empty / k;
                if (row < 2)
                    continue;
                else if (row == 2) {
                    int remain = empty % k;
                    if (remain == 1)
                        continue;
                    else {
                        for (int i = 0; i < row; i++) {
                            for (int j = 0; j < k; j++)
                                map[i][j] = '.';
                        }
                        for (int i = 0; i < remain; i++)
                            map[row][i] = '.';
                        break;
                    }
                } else if (row > 2) {
                    int remain = empty % k;
                    if (remain == 0) {
                        if (row <= R) {
                            for (int i = 0; i < row; i++) {
                                for (int j = 0; j < k; j++)
                                    map[i][j] = '.';
                            }
                            break;
                        } else
                            continue;
                    } else {
                        if (row < R) {
                            if (remain == 1 && k == 2)
                                continue;
                            for (int i = 0; i < row; i++) {
                                for (int j = 0; j < k; j++)
                                    map[i][j] = '.';
                            }
                            for (int i = 0; i < remain; i++)
                                map[row][i] = '.';
                            if (remain == 1) {
                                map[row - 1][k - 1] = '*';
                                map[row][1] = '.';
                            }
                            break;
                        } else
                            continue;
                    }
                }
            }
            if (k <= 1) {
                output.append("Impossible\n");
                return;
            }
        }
        map[0][0] = 'c';
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                output.append(map[i][j]);
            output.append("\n");
        }
    }

    public static void main(String[] arg) throws IOException {
        FileReader input = new FileReader("C-small-attempt0.in");
        FileWriter output = new FileWriter("output.out");
        Scanner in = new Scanner(input);
        int T, cas;
        T = in.nextInt();
        for (cas = 1; cas <= T; cas++) {
            solve(in, output, cas);
        }
        input.close();
        output.close();
    }
}
