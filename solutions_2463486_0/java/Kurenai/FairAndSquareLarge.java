package googlecodejam.fairsquare;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;

public class FairAndSquareLarge {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        ArrayList<String> lines = readFile("C:\\Users\\Patri\\Downloads\\C-small-attempt0.in");
        for (int i = 1; i < lines.size(); i++) {
            String[] split = lines.get(i).split(" ");
            BigDecimal a = new BigDecimal(split[0]);
            BigDecimal b = new BigDecimal(split[1]);
            ArrayList<BigDecimal> fairsAndSquares = findSquareAndFairs(a, b);
            System.out.println("Case #" + i + ": " + fairsAndSquares.size());
        }
    }

    public static ArrayList<BigDecimal> findSquareAndFairs(BigDecimal a, BigDecimal b) {
        ArrayList<BigDecimal> squares = new ArrayList();
        BigDecimal sqrtA = sqrt(a, 4);
        BigDecimal sqrtB = sqrt(b, 4);
        BigDecimal init = sqrtA.setScale(0, RoundingMode.CEILING);
        BigDecimal end = sqrtB.setScale(0, RoundingMode.FLOOR);

        BigDecimal i = init;
        while(i.compareTo(end)<=0){
            if (isFair(i) && isFair(i.multiply(i))) {
                squares.add(i.multiply(i));
            }
            i = i.add(new BigDecimal(1));
        }
        return squares;
    }

    public static boolean isFair(BigDecimal num) {
        boolean isFair = true;
        String string = num.toPlainString().replaceAll("\\..*", "");
        char[] chars = string.toCharArray();
        int half = (chars.length + 1) / 2;
        for (int i = 0; i < half; i++) {
            if (chars[i] != chars[chars.length - 1 - i]) {
                isFair = false;
                break;
            }
        }
        return isFair;
    }

    public static ArrayList<String> readFile(String aFileName) throws FileNotFoundException, IOException {
        ArrayList<String> result = new ArrayList<String>();
        FileReader fr = new FileReader(aFileName);
        BufferedReader br = new BufferedReader(fr);
        String s;
        while ((s = br.readLine()) != null) {
            result.add(s);
        }
        return result;
    }

    public static BigDecimal sqrt(BigDecimal in, int scale) {
        BigDecimal sqrt = new BigDecimal(1);
        sqrt.setScale(scale + 3, RoundingMode.FLOOR);
        BigDecimal store = new BigDecimal(in.toString());
        boolean first = true;
        do {
            if (!first) {
                store = new BigDecimal(sqrt.toString());
            } else {
                first = false;
            }
            store.setScale(scale + 3, RoundingMode.FLOOR);
            sqrt = in.divide(store, scale + 3, RoundingMode.FLOOR).add(store).divide(
                    BigDecimal.valueOf(2), scale + 3, RoundingMode.FLOOR);
        } while (!store.equals(sqrt));
        return sqrt.setScale(scale, RoundingMode.FLOOR);
    }
}
