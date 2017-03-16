import java.io.File;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.Formatter;
import java.util.Scanner;

public class D {
    private static final String ANS = "Case #%s: %s %s\n";

    public static void main(String[] args) throws Exception {
        try (Scanner in = new Scanner(new File("io/D/Ds.in.txt")); Formatter out = new Formatter("io/D/Ds.out.txt")) {
            int tests = in.nextInt();
            for (int i = 1; i <= tests; ++i) {
                new D(in).solve(i, out);
            }
        }
    }

    private final ArrayDeque<Double> na;
    private final ArrayDeque<Double> ke;

    public D(Scanner in) {
        int n = in.nextInt();
        ArrayList<Double> _na = new ArrayList<>(n);
        ArrayList<Double> _ke = new ArrayList<>(n);
        for (int i = 0; i < n; ++i) {
            _na.add(in.nextDouble());
        }
        for (int i = 0; i < n; i++) {
            _ke.add(in.nextDouble());
        }
        Collections.sort(_na);
        Collections.sort(_ke);
        na = new ArrayDeque<>(_na);
        ke = new ArrayDeque<>(_ke);
    }

    private void solve(int testNo, Formatter out) {
        out.format(ANS, testNo, deceitfulWar(), war());
    }

    private int war() {
        Deque<Double> na = this.na.clone();
        Deque<Double> ke = this.ke.clone();
        int points = 0;
        while (!na.isEmpty()) {
            if (na.pollLast() < ke.peekLast()) {
                ke.pollLast();
            } else {
                ke.pollFirst();
                points++;
            }
        }
        return points;
    }

    private int deceitfulWar() {
        Deque<Double> na = this.na.clone();
        Deque<Double> ke = this.ke.clone();
        int points = 0;
        while (!na.isEmpty()) {
            if (na.pollFirst() < ke.peekFirst()) {
                ke.pollLast();
            } else {
                ke.pollFirst();
                points++;
            }
        }
        return points;
    }
}
