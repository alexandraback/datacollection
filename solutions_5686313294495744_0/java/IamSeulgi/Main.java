import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        final Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("input.in")));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(new FileOutputStream("output.out")));

        int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            int N = scanner.nextInt();

            Name[] names = new Name[N];

            for(int i=0; i < N; i++) {
                names[i] = new Name(scanner.next(), scanner.next());
            }

            final Solver solver = new Solver(names);

            writer.printf("Case #%d: %s\n", cid, solver.solve());
        }
        writer.flush();
    }
}

/*
    Greedily find solutions
 */


class Name {
    String first;
    String second;

    public Name(String first, String second) {
        this.first = first;
        this.second = second;
    }
}

class Solver {
    Name[] names;
    boolean[] isDup;

    public Solver(Name[] names) {
        this.names = names;
        isDup = new boolean[names.length];
        Arrays.fill(isDup, false);
    }

    public int solve() {

        int res = 0;
        boolean foundFirst, foundSecond;

        for(int x=0; x < names.length; x++) {
            foundFirst = foundSecond = false;
            for(int y=0; y < names.length; y++) {
                if(x == y) continue;
//                if(isDup[y]) continue;
                if(names[x].first.equals(names[y].first)) foundFirst = true;
                if(names[x].second.equals(names[y].second)) foundSecond = true;
            }

            if(foundFirst && foundSecond) {
                res++;
                isDup[x] = true;
            }
        }

        if( res == names.length) return res - 2;
        return res;
    }

}