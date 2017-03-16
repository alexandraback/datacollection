import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * Created by fleeon on 5/8/16.
 */
public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("C.in"));
        PrintWriter writer = new PrintWriter("C.out");
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int J = scanner.nextInt();
            int P = scanner.nextInt();
            int S = scanner.nextInt();
            int K = scanner.nextInt();
            TreeMap<Integer, Integer> JP = new TreeMap<Integer, Integer>();
            TreeMap<Integer, Integer> JS = new TreeMap<Integer, Integer>();
            TreeMap<Integer, Integer> PS = new TreeMap<Integer, Integer>();
            writer.printf("Case #%d: ", t + 1);
            ArrayList<String> res = new ArrayList<String>();
            for (int j = 0; j < J; j++) {
                for (int p = 0; p < P; p++) {
                    for (int s = 0; s < S; s++) {
                        int jp = j * P + p;
                        int js = j * S + s;
                        int ps = p * S + s;
                        Integer jpv = JP.get(jp);
                        if (jpv == null) jpv = 0;
                        Integer jsv = JS.get(js);
                        if (jsv == null) jsv = 0;
                        Integer psv = PS.get(ps);
                        if (psv == null) psv = 0;
                        if (jpv + jsv + psv < K) {
                            JP.put(jp, jpv + 1);
                            JS.put(js, jsv + 1);
                            PS.put(ps, psv + 1);
                            res.add((j + 1) + " " + (p + 1) + " " + (s + 1));
                        }
                    }
                }
            }
            writer.println(res.size());
            for (String re : res) {
                writer.println(re);
            }
        }
        writer.close();
    }
}
