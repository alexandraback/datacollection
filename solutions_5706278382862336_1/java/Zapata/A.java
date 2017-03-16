import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Max Loewenthal
 */
public class A {
    public void solve(Scanner input, StringBuilder buffer) {
        String fraction = input.nextLine();

        String[] parts = fraction.split("/");



        long P = Long.parseLong(parts[0]);
        long Q = Long.parseLong(parts[1]);

        long g = gcd(P,Q);

        P= P / g;
        Q = Q / g;

        if (MAX % Q > 0) {
            buffer.append("impossible");
        }
        else {
            P = P * (MAX/Q);

            int gen = 0;
            long bla = MAX;

            while ((P & bla) == 0 && bla > 0) {
                bla = bla / 2;
                gen = gen + 1;
            }

            if (bla <=0) {
                buffer.append("impossible");
            }
            else {
                buffer.append(Integer.toString(gen));
            }
        }


    }
    private long MAX = 1099511627776l;

    private static long gcd(long n1, long n2) {
        if (n2 == 0) {
            return n1;
        }

        return gcd(n2, n1%n2);
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

            A a = new A();

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
