import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by linxy on 4/29/16.
 */
public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("C-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("C-small-attempt0.out"));
        int numCase = in.nextInt();
        in.nextLine();
        for (int caseNum = 1; caseNum <= numCase; caseNum++) {
            out.print("Case #" + caseNum + ": ");
            String line = in.nextLine();
            String[] splits = line.split(" ");
            int j = Integer.parseInt(splits[0]);
            int p = Integer.parseInt(splits[1]);
            int s = Integer.parseInt(splits[2]);
            int k = Integer.parseInt(splits[3]);
            Map<List<Integer>, Integer> counts = new HashMap<>();
            int result = 0;
            StringBuilder examples = new StringBuilder();
            for (int t1 = 1; t1 <= j; t1++) {
                for (int t2 = 1; t2 <= p; t2++) {
                    for (int t3 = 1; t3 <= s; t3++) {
                        Suit suit = new Suit(t1, t2, t3);
                        List<List<Integer>> combs = suit.cominations();
                        boolean isOK = true;
                        for (List<Integer> c : combs) {
                            if (counts.containsKey(c)) {
                                int num = counts.get(c);
                                if (num >= k) {
                                    isOK = false;
                                    break;
                                }
                            }
                        }
                        if (isOK) {
                            result++;
                            examples.append(t1 + " " + t2 + " " + t3 + "\n");
                            for (List<Integer> c : combs) {
                                if (counts.containsKey(c)) {
                                    counts.put(c, counts.get(c) + 1);
                                } else {
                                    counts.put(c, 1);
                                }
                            }
                        }
                    }
                }
            }
            out.println(result);
            out.print(examples.toString());
        }
        in.close();
        out.close();
    }
}

class Suit {
    int j;
    int p;
    int s;

    public Suit(int j, int p, int s) {
        this.j = j;
        this.p = p;
        this.s = s;
    }

    public List<List<Integer>> cominations() {
        return Arrays.asList(
                Arrays.asList(0, j, 1, p),
                Arrays.asList(0, j, 2, s),
                Arrays.asList(1, p, 2, s)
        );
    }
}
