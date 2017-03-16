import java.util.Scanner;


public class Utils {

    public static int readIntegerLine(Scanner sc) {
        String s = readStringLine(sc);
        return Integer.parseInt(s);
    }

    public static String readStringLine(Scanner sc) {
        return sc.nextLine();
    }

    public static int readInteger(Scanner sc) {
        return sc.nextInt();
    }

    public static long readLong(Scanner sc) {
        return sc.nextLong();
    }

    public static double readDouble(Scanner sc) {
        return sc.nextFloat();
    }

    public static double[] readDoubleArray(Scanner sc) {
        String s = sc.nextLine();
        String[] split = s.split(" ");
        double[] d = new double[split.length];
        for (int i = 0; i < d.length; i++) {
            d[i] = Double.parseDouble(split[i]);
        }
        return d;
    }

}
