import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class DeceitfulWar {
    public static void main(String[] arg) throws IOException {
        FileReader file = new FileReader("D-small-attempt0.in");
        FileWriter output = new FileWriter("output.out");
        Scanner in = new Scanner(file);
        int T, cas, num;
        T = in.nextInt();
        ArrayList<Double> Ken, Naomi;
        for (cas = 1; cas <= T; cas++) {
            Ken = new ArrayList<Double>();
            Naomi = new ArrayList<Double>();
            num = in.nextInt();
            for (int i = 0; i < num; i++)
                Naomi.add(in.nextDouble());
            for (int i = 0; i < num; i++)
                Ken.add(in.nextDouble());

            Collections.sort(Naomi);
            Collections.sort(Ken);

            output.append("Case #" + cas + ": ");

            int pp = 0, np = 0;
            int i = 0, j = 0, x = num - 1, y = num - 1;
            for (int k = 0; k < num; k++) {
                if (Ken.get(x) > Naomi.get(y)) {
                    x--;
                    y--;
                    np++;
                } else if (Ken.get(i) > Naomi.get(j)) {
                    i++;
                    j++;
                    np++;
                } else {
                    i++;
                    y--;
                }
            }
            i = 0;
            j = 0;
            x = num -1;
            y = num -1;
            for (int k = 0; k < num; k++) {
                if (Naomi.get(x) > Ken.get(y)) {
                    x--;
                    y--;
                    pp++;
                } else if (Naomi.get(i) > Ken.get(j)) {
                    i++;
                    j++;
                    pp++;
                } else {
                    i++;
                    y--;
                }
            }
            output.append(pp + " " + (num - np) + "\n");
        }
        file.close();
        output.close();
    }
}
