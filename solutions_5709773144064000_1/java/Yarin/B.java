package qual2014;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class B {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("qual2014/B-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("qual2014/B-small-0.in"), new FileOutputStream("qual2014/B-small-0.out"));
        io = new Kattio(new FileInputStream("qual2014/B-large-0.in"), new FileOutputStream("qual2014/B-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new B().solve(io);
        }
        io.close();
    }

    private void solve(Kattio io) {
        double farmCost = io.getDouble(), farmRate = io.getDouble(), goal = io.getDouble();

        double currentRate = 2.0, best = Double.MAX_VALUE, tm = 0.0;
        while (true) {
            best = Math.min(best, tm + goal / currentRate);
            double nextFarm = farmCost / currentRate;
            tm += nextFarm;
            if (tm > best) break;
            currentRate += farmRate;
        }
        io.println(best);
    }
}
