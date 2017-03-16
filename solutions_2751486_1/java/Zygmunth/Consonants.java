import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.Writer;
import java.math.BigInteger;
import java.util.*;

public class Consonants {

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        InputStream resourceAsStream = Consonants.class.getClassLoader().getResourceAsStream("in.txt");
        Scanner scanner = new Scanner(resourceAsStream);
        Writer out = new FileWriter("c:\\temp\\2013.txt");

        int tcc = scanner.nextInt();
        for (int ci = 0; ci < tcc; ci++) {
            Set<Character> vovels = new HashSet<Character>();
            vovels.add('a');
            vovels.add('e');
            vovels.add('i');
            vovels.add('o');
            vovels.add('u');
            char[] name = scanner.next().toCharArray();
            int n = scanner.nextInt();
            int L = name.length;
            int min=0;
            BigInteger res = BigInteger.ZERO;
            for (int i = 0; i < L; i++) {
                int cons=0;
                int start = i;
                while (true) {
                    char c = name[i];
                    if (vovels.contains(c)) {
                        break;
                    }
                    cons++;
                    i++;
                    if (i==L) {
                        break;
                    }
                }
                if (cons >= n) {
                    int endOfName = start+n-1;
                    int b = 1+start-min;
                    int a = L-endOfName;
                    res = res.add(BigInteger.valueOf(a).multiply(BigInteger.valueOf(b)));
                    int remain = cons-n;
                    for (int j = 0; j < remain; j++) {
                        endOfName++;
                        a = L-endOfName;
                        res = res.add(BigInteger.valueOf(a));
                    }
                    min = i+1-n;
                }
            }

            String ress = String.format("Case #%d: %s\n", ci + 1, res.toString());
            out.write(ress);

        }
        out.close();
        return;
    }
}
