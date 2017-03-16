import java.io.*;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

/**


 */
public class Mole {
    private Integer me;
    private List<Integer> others;
    private int moves = 0;
    private List<Integer> solutions = new LinkedList<Integer>();

    public static void main(String[] s) throws IOException {
        InputStream resourceAsStream = Mole.class.getResourceAsStream("A-small-attempt0.in");
//        InputStream resourceAsStream = Mole.class.getResourceAsStream("small.in");
        FileWriter fw = new FileWriter("out.out");
        BufferedWriter bufferedWriter = new BufferedWriter(fw);
        Reader fr = new InputStreamReader(resourceAsStream);
        BufferedReader br = new BufferedReader(fr);
        int i = Integer.valueOf(br.readLine());

        for (int j = 0; j < i; j++) {
            String s1 = br.readLine();
            String[] split = s1.split(" ");
            Mole mole = new Mole();
            mole.me(split[0]);
            String s2 = br.readLine();
            String[] split1 = s2.split(" ");
            List<Integer> l = new LinkedList<Integer>();
            for (String k : split1) {
                l.add(Integer.valueOf(k));
            }
            mole.others(l);
            String sol = mole.solve();
            int pos = j + 1;
            bufferedWriter.write("Case #" + pos + ": " + sol);
            bufferedWriter.newLine();
        }
        bufferedWriter.close();
    }

    private String solve() {
        Collections.sort(others);
        System.out.println("Me: " + me + " Oth: " + others);
        solutions.add(moves + others.size());
        while (!others.isEmpty() && others.get(0) < me) {
            me = me + others.get(0);
            others.remove(0);
        }
        if (others.isEmpty()) {
            Collections.sort(solutions);
            int min = solutions.get(0);
            return moves < min ? moves + "" : min + "";

        }
        addSolution(moves + others.size());
        if (me - 1 == 0) {
            moves++;
            others.remove(0);
        } else {
            me = me + (me - 1);
            moves++;
        }
        return solve();

    }

    void addSolution(int i) {
        solutions.add(i);
    }

    private void others(List<Integer> split1) {
        others = split1;
    }

    private void me(String s) {
        this.me = Integer.valueOf(s);
    }
}
