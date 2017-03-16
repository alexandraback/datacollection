import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileReader("B-small-attempt2.in"));
        PrintWriter out = new PrintWriter(new FileWriter("Output.out"));

        Task solver = new Task();
        int testCases = in.nextInt();
        for (int i = 1; i <= testCases; ++i)
            solver.solve(i, in, out);

        in.close();
        out.close();
    }
}

class Task {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int N = in.nextInt();
        Game[] gamesType1 = new Game[N];
        Game[] gamesType2 = new Game[N];
        for (int i = 0; i < N; ++i) {
            gamesType1[i] = new Game(i, in.nextInt());
            gamesType2[i] = new Game(i, in.nextInt());
        }
        Arrays.sort(gamesType2, new Comparator<Game>() {
            public int compare(Game o1, Game o2) {
                if (o1.needed == o2.needed) return o1.level - o2.level;
                else return o1.needed - o2.needed;
            }
        });
        final int[] placedAt = new int[N];
        for (int i = 0; i < N; ++i)
            placedAt[gamesType2[i].level] = i;
        Arrays.sort(gamesType1, new Comparator<Game>() {
            public int compare(Game o1, Game o2) {
                if (o1.needed == o2.needed) return placedAt[o2.level] - placedAt[o1.level];
                else return o1.needed - o2.needed;
            }
        });
        boolean[] playedType1 = new boolean[N];
        boolean[] playedType2 = new boolean[N];
        boolean possible = true;
        int res = 0, points = 0;
        for (int i = 0; i < N; ++i) {
            if (points < gamesType2[i].needed) {
                for (int j = 0; j < N; ++j) {
                    if (playedType2[gamesType1[j].level]) continue;
                    if (playedType1[gamesType1[j].level]) continue;
                    if (points < gamesType1[j].needed) break;
                    ++res;
                    points += 1;
                    playedType1[gamesType1[j].level] = true;
                    if (points == gamesType2[i].needed) break;
                }
                if (points < gamesType2[i].needed) {
                    possible = false;
                    break;
                }
            }
            if (playedType1[gamesType2[i].level]) points += 1;
            else points += 2;
            ++res;
            playedType2[gamesType2[i].level] = true;
        }

        out.print("Case #" + testNumber + ": " );
        if (!possible) out.println("Too Bad");
        else out.println(res);
    }

    class Game {
        int level, needed;

        public Game(int level, int needed) {
            this.level = level;
            this.needed = needed;
        }
    }
}
