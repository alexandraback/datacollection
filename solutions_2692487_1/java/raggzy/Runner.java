package template;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.lang.reflect.Constructor;
import java.util.Locale;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: raggzy
 * Date: 02.05.13
 * Time: 18:07
 * To change this template use File | Settings | File Templates.
 */
public class Runner {
    @SuppressWarnings("unchecked")
    public static <T extends Solver> void main(Class<T> solverClass) throws Exception {
        Locale.setDefault(Locale.US);
        Constructor<T> constructor = solverClass.getConstructor(Scanner.class, PrintStream.class, int.class);
        FileInputStream fis = new FileInputStream("C:/Temp/gcj/in.txt");
        FileOutputStream fos = new FileOutputStream("C:/Temp/gcj/out.txt");
        Scanner in = new Scanner(fis);
        PrintStream out = new PrintStream(fos);
        long TCS = in.nextInt();
        for (int tc = 1; tc <= TCS; tc++) {
            constructor.newInstance(in, out, tc).solve();
        }
    }
}
