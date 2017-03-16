import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.Writer;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

public class Pogo {

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        InputStream resourceAsStream = Pogo.class.getClassLoader().getResourceAsStream("in.txt");
        Scanner scanner = new Scanner(resourceAsStream);
        Writer out = new FileWriter("c:\\temp\\2013.txt");

        int tcc = scanner.nextInt();
        for (int ci = 0; ci < tcc; ci++) {
            int x= scanner.nextInt();
            int y = scanner.nextInt();
            StringBuilder b = new StringBuilder();
            if (x>0) {
                for (int i=0; i<Math.abs(x); i++) {
                    b.append("WE");
                }
            } else {
                for (int i=0; i<Math.abs(x); i++) {
                    b.append("EW");
                }
            }

            if (y>0) {
                for (int i=0; i<Math.abs(y); i++) {
                    b.append("SN");
                }
            } else {
                for (int i=0; i<Math.abs(y); i++) {
                    b.append("NS");
                }
            }
            String ress = String.format("Case #%d: %s\n", ci + 1, b.toString());
            out.write(ress);

        }
        out.close();
        return;
    }
}
