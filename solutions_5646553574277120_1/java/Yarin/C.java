package round1c;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Collections;

public class C {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round1c/C-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round1c/C-small-attempt0.in"), new FileOutputStream("round1c/C-small-0.test"));
        io = new Kattio(new FileInputStream("round1c/C-large.in"), new FileOutputStream("round1c/C-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new C().solve(io);
        }
        io.close();
    }

    private void solve(Kattio io) {
        int C = io.getInt(), D = io.getInt(), V = io.getInt();
        ArrayList<Integer> denom = new ArrayList<>();
        for (int i = 0; i < D; i++) {
            denom.add(io.getInt());
        }
        Collections.sort(denom);

        long max = 0, added = 0;
        int i = 0;
        while (max < V) {
            if (i >= denom.size() || denom.get(i) > max+1) {
                denom.add((int)(max + 1));
                Collections.sort(denom);
                added++;
            }
            max += denom.get(i) * ((long) C);
            i++;
        }
        io.println(added);
//        io.println(denom);
    }
}
