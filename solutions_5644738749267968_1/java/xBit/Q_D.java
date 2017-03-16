import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Q_D {

    public static void main(String args[]) throws IOException {
        //String path = "/Users/xinzhong/Dropbox/projects/practice/code/data/Q_D_test.in";
        //String pathOut = "/Users/xinzhong/Dropbox/projects/practice/code/data/Q_D_test.txt";
        //String path = "/Users/xinzhong/Downloads/D-small-attempt1.in";
        //String pathOut = "/Users/xinzhong/Dropbox/projects/practice/code/data/D-small-attempt1.in";

        String path = "/Users/xinzhong/Downloads/D-large.in";
        String pathOut = "/Users/xinzhong/Dropbox/projects/practice/code/data/D-large.out";
        try (Scanner scanner = new Scanner(new BufferedReader(new FileReader(path)));
             BufferedWriter writer = new BufferedWriter(new FileWriter(pathOut))) {
            int n = scanner.nextInt();

            for (int T = 1; T <= n; T++) {
               int N = scanner.nextInt();

                List<Double> a = new ArrayList<>();
                List<Double> b = new ArrayList<>();

                for (int i = 0; i < N; i++) {
                    a.add(scanner.nextDouble());
                }

                for (int i = 0; i < N; i++) {
                    b.add(scanner.nextDouble());
                }

                Collections.sort(a);
                Collections.sort(b);


                int q = a.size() - getNumBWin(a,b, a.size());

                /*int max = q;
                for (int i = 1; i < a.size(); i++) {
                     int cnt = a.size() - i - getNumBWin(a,b, a.size() - i);
                    if ( cnt > max) {
                        max =cnt;
                    }
                }*/
                //System.out.println(getNumBWin(b,a, a.size()));
                //System.out.println(max);
                //System.out.println(q);
                //System.out.println(a);
                //System.out.println(b);

                String s = "Case #" + T + ": ";

                writer.write(s + getNumBWin(b,a, a.size()) +" " + q+ "\n");
            }
        }
    }

    private static int getNumBWin(List<Double> a, List<Double> b, int length) {
        int cnt = 0, j = length - 1, i = b.size() - 1;
        while(j >=0 && i >= b.size() - length) {
            if ( b.get(j) > a.get(i)) {
                cnt++;
                i--;
                j--;
            } else {
                i--;
            }
        }
        return cnt;
    }



}
