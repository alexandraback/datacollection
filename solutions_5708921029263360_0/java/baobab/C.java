import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        //Scanner scanner = new Scanner(System.in);
        Scanner scanner = new Scanner(new File("inputCsmall.txt"));
        int tests = scanner.nextInt();
        for (int test=1; test<=tests; test++) {
            scanner.nextLine();
            int j = scanner.nextInt();
            int p = scanner.nextInt();
            int s = scanner.nextInt();
            int k = scanner.nextInt();
            int[][][] counts = new int[12][12][12];
            List<Integer> list = new ArrayList<>();
            for (int jacket=1; jacket<=j; jacket++) {
                for (int pants=1; pants<=p; pants++) {
                    for (int shirt=1; shirt<=s; shirt++) {
                        if (counts[jacket][pants][0] >= k) continue;
                        if (counts[jacket][0][shirt] >= k) continue;
                        if (counts[0][pants][shirt] >= k) continue;
                        counts[jacket][pants][0]++;
                        counts[jacket][0][shirt]++;
                        counts[0][pants][shirt]++;
                        list.add(jacket);
                        list.add(pants);
                        list.add(shirt);
                    }
                }
            }

            // verify we cant improve from brute



            System.out.println("Case #" + test + ": " + (list.size()/3));
            for (int i=0; i<list.size(); i+=3) {
                System.out.println(list.get(i) + " " + list.get(i+1) + " " + list.get(i+2));
            }
        }
        scanner.close();
    }
}
