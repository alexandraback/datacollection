import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * @author Max Loewenthal
 */
public class C {
    public void solve(Scanner input, StringBuilder buffer) {
        int C = input.nextInt();
        int D = input.nextInt();
        long V = input.nextInt();

        long reachable = 0;
        long added = 0;

        long[] denominations = new long[D];

        List<Long> available = new ArrayList<>();

        for(int i = 0; i < D; i++) {
            available.add(input.nextLong());
        }

        Collections.sort(available);

        while (reachable < V) {
            while (available.size() > 0 && available.get(0) <= reachable+1) {
                reachable = reachable + available.get(0) * C;
                available.remove(0);
            }

            if (reachable < V) {
                added = added + 1;
                reachable = reachable + (reachable + 1) * C;
            }
        }

        buffer.append(added);
    }

    public static void main(String[] args) {
        try {
            InputStream input = System.in;
            OutputStream output = System.out;

            if (args.length > 0) {
                input = new FileInputStream(new File(args[0]));
            }

            if (args.length > 1) {
                File outputFile = new File(args[1]);

                if (outputFile.exists()) {
                    throw new Exception("Output file already exists");
                }

                output = new FileOutputStream(new File(args[1]));
            }

            Scanner scanner = new Scanner(input);
            PrintWriter writer = new PrintWriter(output);

            C a = new C();

            int count = scanner.nextInt();
            scanner.nextLine();

            for (int i = 0; i < count; i++) {
                StringBuilder result = new StringBuilder();
                a.solve(scanner, result);


                writer.println("Case #" + (i + 1) + ": " + result.toString());
            }

            writer.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

}
