import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by arudenko on 03.05.14.
 */
public class B {
    public static void main(String[] args) throws FileNotFoundException {
        String fileName = "B-small-attempt0";
        System.setIn(new FileInputStream(fileName + ".in"));
        System.setOut(new PrintStream(new FileOutputStream(fileName + ".out")));

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for(int ti = 0; ti < t;ti++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int k = sc.nextInt();
            int result = 0;
            for(int ia = 0; ia < a;ia++) {
                for(int ib = 0; ib < b;ib++) {
                    if((ib & ia) < k)
                        result++;
                }
            }
            System.out.println("Case #"+(ti+1)+": " + result);
        }
    }
}
