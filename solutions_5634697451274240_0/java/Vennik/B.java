import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class B {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new File("B-small-attempt0.in"));
        FileWriter fw = new FileWriter(new File("b.out"));
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.println(String.format("Case #%d", i));
            fw.append(String.format("Case #%d: %s", i, new B().solve(sc))).append('\n');
        }
        fw.close();
        sc.close();

    }

    private String solve(Scanner sc) {

        boolean flipped = false;
        int counter = 0;

        String in = sc.next();
        for (int i = in.length() - 1; i >= 0; i--) {

            char pancake = in.charAt(i);
            if ((pancake == '+' && flipped) || (pancake == '-' && !flipped)) {
                flipped = !flipped;
                counter++;
            }

        }

        return Integer.toString(counter);

    }

}
