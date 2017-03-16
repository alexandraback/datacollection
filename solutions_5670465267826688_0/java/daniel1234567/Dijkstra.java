import java.io.*;

/**
 * Created by danie_000 on 4/10/2015.
 */
public class Dijkstra {

    private static char[][] table = {{1, 'i', 'j', 'k'},
                                    {'i', 1, 'k', 'j'},
                                    {'j', 'k', 1, 'i'},
                                    {'k', 'j', 'i', 1}};
    private static boolean[][] positives = {{true, true, true, true},
                                            {true, false, true, false},
                                            {true, false, false, true},
                                            {true, true, false, false}};

    public static void main (String[] args) {
        BufferedReader br;
        BufferedWriter bw;
        try {
            br = new BufferedReader(new FileReader("C-small-attempt1.in"));
            bw = new BufferedWriter(new FileWriter("C-small.out"));
            int n = Integer.parseInt(br.readLine());
            for (int iii = 1; iii <= n; iii++) {
                bw.write("Case #" + iii + ": ");
                String[] splits = br.readLine().split(" ");
                int l = Integer.parseInt(splits[0]);
                int x = Integer.parseInt(splits[1]);
                String sequence = br.readLine();
                if (l * x < 3 || l == 1) {
                    bw.write("NO");
                    bw.newLine();
                } else if (sequence.equals("ijk")) {
                    bw.write("YES");
                    bw.newLine();
                } else {
                    sequence = new String(new char[x]).replace("\0", sequence);
                    int iEnd = find(sequence, 0, 'i');
                    if (iEnd == -1)  {
                        bw.write("NO");
                        bw.newLine();
                    } else {
                        int jEnd = find(sequence, iEnd, 'j');
                        if (jEnd == -1) {
                            bw.write("NO");
                            bw.newLine();
                        } else {
                            int kEnd = find(sequence, jEnd, 'k');
                            if (kEnd == -1) {
                                bw.write("NO");
                                bw.newLine();
                            } else {
                                bw.write("YES");
                                bw.newLine();
                            }
                        }
                    }
                }
            }
            bw.close();
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int find(String sequence, int start, char c) {
        try {
            if (sequence.charAt(start) == c && !(c == 'k' && start != sequence.length() - 1)) {
                return start + 1;
            } else {
                Letter l = multiply(sequence.charAt(start), sequence.charAt(start + 1));
                if (c != 'k'){
                    if (l.isPositive() && l.getValue() == c) return start + 2;
                    for (int iii = start + 2; iii < sequence.length() - (107 - c); iii++) {
                        l = multiply(l, sequence.charAt(iii));
                        if (l.isPositive() && l.getValue() == c) return iii + 1;
                    }
                } else {
                    if (start + 1 == sequence.length() - 1) {
                        if (l.isPositive() && l.getValue() == c) return start + 2;
                    }
                    for (int iii = start + 2; iii < sequence.length(); iii++) {
                        l = multiply(l, sequence.charAt(iii));
                    }
                    if (l.isPositive() && l.getValue() == c) return sequence.length();
                }
            }
        } catch(IndexOutOfBoundsException e) {
            return -1;
        }
        return -1;
    }

    private static Letter multiply(char c, char c1) {
        if (c == 1) {
            c--;
        } else {
            c -= 104;
        }

        if (c1 == 1) {
            c1--;
        } else {
            c1 -= 104;
        }
        return new Letter(table[c][c1], positives[c][c1]);
    }

    private static Letter multiply(Letter l, char c) {
        char lc = l.getValue();
        boolean lb = l.isPositive();
        if (c == 1) {
            c--;
        } else {
            c -= 104;
        }

        if (lc == 1) {
            lc--;
        } else {
            lc -= 104;
        }
        return new Letter(table[lc][c], !(positives[lc][c] ^ lb));
    }

}

class Letter {
    public char getValue() {
        return value;
    }

    public void setValue(char value) {
        this.value = value;
    }

    private char value;

    public boolean isPositive() {
        return positive;
    }

    public void setPositive(boolean positive) {
        this.positive = positive;
    }

    private boolean positive;

    public Letter (char c, boolean b) {
        value = c;
        positive = b;
    }



}