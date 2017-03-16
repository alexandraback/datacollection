package gcj;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

// I hope no one will ever review this code =)
public class MinesweeperMaster {
    public static void main(String[] args) {
        try (InputStream is = MagicTrick.class.getResourceAsStream("/MinesweeperMaster.txt");
             Scanner in = new Scanner(is);
             FileWriter fw = new FileWriter("C:\\Users\\Valdemar\\Documents\\MinesweeperMaster.txt");
             BufferedWriter bw = new BufferedWriter(fw)) {
            int numCases = in.nextInt();
            for (int caseNum = 1; caseNum <= numCases; caseNum++) {
                int r = in.nextInt();
                int c = in.nextInt();
                int m = in.nextInt();

                int free = r * c - m;
                char[][] field = null;
                if (m == 0) {
                    field = newEmptyField(r, c);
                    field[0][0] = 'c';
                }
                if (check(field)) {
                    System.out.println("strategy 0 works!");
                    System.out.println(r + " " + c + " " + m);
                    print(field);
                    bw.write("Case #" + caseNum + ":\n" + toString(field));
                    continue;
                }
                if (m <= (r - 2) * (c - 2)) {
                    field = strategy1(r, c, m);
                }
                if (check(field)) {
                    System.out.println("strategy 1 works!");
                    System.out.println(r + " " + c + " " + m);
                    bw.write("Case #" + caseNum + ":\n" + toString(field));
                    print(field);
                    continue;
                }
                field = strategy2(r, c, free);
                if (check(field)) {
                    System.out.println("strategy 2 works!");
                    System.out.println(r + " " + c + " " + m);
                    bw.write("Case #" + caseNum + ":\n" + toString(field));
                    print(field);
                    continue;
                }
                field = strategy3(r, c, m);
                if (check(field)) {
                    System.out.println("strategy 3 works!");
                    System.out.println(r + " " + c + " " + m);
                    bw.write("Case #" + caseNum + ":\n" + toString(field));
                    print(field);
                    continue;
                }
                field = strategy4(r, c, m);
                if (check(field)) {
                    System.out.println("strategy 4 works!");
                    System.out.println(r + " " + c + " " + m);
                    bw.write("Case #" + caseNum + ":\n" + toString(field));
                    print(field);
                    continue;
                }
                bw.write("Case #" + caseNum + ":\nImpossible\n");
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private static char[][] strategy2(int r, int c, int free) {
        char[][] field = newFullField(r, c);
        field[0][0] = 'c';
        free -= 1;
        if (free == 0) return field;
        for (int a = 1; ; a++) {
            for (int i = 0; i < a; i++) {
                int j = a;
                if (inBoundaries(field, i, j)) {
                    field[i][j] = '.';
                    free--;
                }
                if (free == 0) return field;
            }
            for (int j = 0; j <= a; j++) {
                int i = a;
                if (inBoundaries(field, i, j)) {
                    field[i][j] = '.';
                    free--;
                }
                if (free == 0) return field;
            }
        }
    }


    private static char[][] strategy3(int r, int c, int m) {
        char[][] field = newEmptyField(r, c);
        field[r-1][c-1] = 'c';
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                field[i][j] = '*';
                m--;
                if (m == 0) return field;
            }
        }
        throw new RuntimeException();
    }

    private static char[][] strategy4(int r, int c, int m) {
        char[][] field = newEmptyField(r, c);
        field[r-1][c-1] = 'c';
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                field[i][j] = '*';
                m--;
                if (m == 0) return field;
            }
        }
        throw new RuntimeException();
    }

    private static char[][] strategy1(int r, int c, int m) {
        char[][] field = newEmptyField(r, c);
        i:
        for (int i = 0; i < r - 2; i++) {
            for (int j = 0; j < c - 2; j++) {
                if (m == 0) break i;
                field[i][j] = '*';
                m--;
            }
        }
        field[r - 1][c - 1] = 'c';
        return field;
    }

    private static char[][] newEmptyField(int r, int c) {
        char[][] field = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                field[i][j] = '.';
            }
        }
        return field;
    }

    private static char[][] newFullField(int r, int c) {
        char[][] field = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                field[i][j] = '*';
            }
        }
        return field;
    }

    private static void print(char[][] field) {
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[i].length; j++) {
                System.out.print(field[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    private static String toString(char[][] field) {
        String s = "";
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[i].length; j++) {
                s += field[i][j] + "";
            }
            s += '\n';
        }
        return s;
    }

    private static boolean check(char[][] field) {
        if (field == null) return false;
        field = copy(field);
        open(field);
        for (int k = 0; k < field.length; k++) {
            for (int l = 0; l < field[k].length; l++) {
                if (field[k][l] == '.')
                    return false;
            }
        }
        return true;
    }

    private static char[][] copy(char[][] field) {
        char[][] copy = field.clone();
        for (int i = 0; i < field.length; i++) {
            copy[i] = field[i].clone();
        }
        return copy;
    }

    private static void open(char[][] field) {
        int i, j = 0;
        i:
        for (i = 0; i < field.length; i++) {
            for (j = 0; j < field[i].length; j++) {
                if (field[i][j] == 'c')
                    break i;
            }
        }
        open(field, i, j);
    }

    private static void open(char[][] field, int i, int j) {
        if (i < 0 || i >= field.length) return;
        if (j < 0 || j >= field[i].length) return;
        if (isMine(field, i, j)) return;
        if (field[i][j] != '.' && field[i][j] != 'c') return;
        int mines = 0;
        if (isMine(field, i - 1, j - 1)) mines++;
        if (isMine(field, i - 1, j)) mines++;
        if (isMine(field, i - 1, j + 1)) mines++;
        if (isMine(field, i + 1, j - 1)) mines++;
        if (isMine(field, i + 1, j)) mines++;
        if (isMine(field, i + 1, j + 1)) mines++;
        if (isMine(field, i, j - 1)) mines++;
        if (isMine(field, i, j + 1)) mines++;
        field[i][j] = Character.forDigit(mines, 10);
        if (mines == 0) {
            open(field, i - 1, j - 1);
            open(field, i - 1, j);
            open(field, i - 1, j + 1);
            open(field, i + 1, j - 1);
            open(field, i + 1, j);
            open(field, i + 1, j + 1);
            open(field, i, j - 1);
            open(field, i, j + 1);
        }
    }

    private static boolean inBoundaries(char[][] field, int i, int j) {
        return i >= 0 && i < field.length && j >= 0 && j < field[i].length;
    }

    private static boolean isMine(char[][] field, int i, int j) {
        if (i < 0 || i >= field.length) return false;
        if (j < 0 || j >= field[i].length) return false;
        return field[i][j] == '*';
    }
}
