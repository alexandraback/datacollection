package codejam;

import javax.swing.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

import static java.util.Collections.*;

public class Second {

    public static void main(String[] args) throws FileNotFoundException {
        String path = ClassLoader.getSystemClassLoader().getResource("codejam/").getPath();
        Second worker = new Second();

        worker.scan(new File(path, "second-s.in"), new File(path, "second-s.out"));
//        worker.scan(new File(path, "second-x.in"), new File(path, "second-x.out"));
    }

    private void scan(File input, File output) throws FileNotFoundException {
        Scanner in = new Scanner(input);
        PrintWriter out = new PrintWriter(output);

        int n = Integer.parseInt(in.nextLine());
        for (int i = 0; i < n; i++) {
            int m = Integer.parseInt(in.nextLine());
            List<Integer> ones = new ArrayList<Integer>(m);
            List<Integer> twos = new ArrayList<Integer>(m);
            for (int j = 0; j < m; j++) {
                String[] x = in.nextLine().split(" ");
                ones.add(Integer.parseInt(x[0]));
                twos.add(Integer.parseInt(x[1]));
            }
            out.printf("Case #%d: %s\n", i + 1, solve(ones, twos));
        }

        out.flush();
        out.close();
        in.close();
    }

    public String solve(List<Integer> os, List<Integer> ts) {
        int stars = 0;
        int atmp = 0;

        while (!ts.isEmpty()) {
            int index = findMin(ts);
            int odx = findMin(os);
            if (stars >= ts.get(index)) {
                stars += 2;
                atmp++;
                ts.remove(index);
                os.remove(index);
            } else if (stars >= os.get(odx)) {
                stars += 1;
                atmp++;
                os.set(odx, Integer.MAX_VALUE);
            } else {
                return "Too Bad";
            }
        }

        return "" + atmp;
    }

    public int findMin(List<Integer> l) {
        int min = 0;
        for (int i = 0; i < l.size(); i++) {
            if (l.get(i) < l.get(min)) {
                min = i;
            }
        }
        return  min;
    }
}
