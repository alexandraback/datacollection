
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Dancing {

    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new File("dance.txt"));
        PrintWriter fw = new PrintWriter(new FileWriter(new File("dance.out")));
        int cases = in.nextInt();
        for (int c = 1; c <= cases; c++) {
            int N = in.nextInt(); // number of googlers
            int S = in.nextInt(); // number of surprising triplets
            int p = in.nextInt(); // best result
            ArrayList<Integer> scores = new ArrayList<Integer>();
            for (int n = 0; n < N; n++) {
                int googler = in.nextInt();
                scores.add(googler);
            }
            Collections.sort(scores);
            int pass = 0;
            for (int i = 0; i < scores.size(); i++) {
                int score = scores.get(i);
                int mod = score % 3;
                int max = score / 3;
                int low = max;
                if (mod > 0) {
                    max++;
                }
                if (max >= p) {
                    pass++;
                    continue;
                }
                if (S > 0) {
                    if (mod % 2 == 0) {
                        if(mod == 0 && low == 0){
                            continue;
                        }
                        max++;
                        if (max >= p) {
                            pass++;
                            S--;
                            continue;
                        }
                    }
                }

            }// for loop
            String fwout = "Case #" + c + ": " + pass;
            fw.println(fwout);
        }
        fw.close();
    }
}
