package codejam.round1a;

import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.List;

public class Password {
    public static void main(String[] args) throws IOException {
        InputStream is;
        OutputStream os;
        if (args.length > 0) {
            is = new FileInputStream(args[0]);
        }else{
            is = System.in;
        }

        if (args.length > 1) {
            os = new FileOutputStream(args[1]);
        }else{
            os = System.out;
        }

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(os));
        BufferedReader inputReader = new BufferedReader(new InputStreamReader(is));
        String firstLine = inputReader.readLine();
        int count_of_cases = Integer.parseInt(firstLine);

        for (int idx_of_case = 1; idx_of_case <= count_of_cases; idx_of_case++) {
            String caseLine = inputReader.readLine();
            String[] numbers = caseLine.split(" ");

            int inputted = Integer.parseInt(numbers[0]);
            int total = Integer.parseInt(numbers[1]);

            String[] probLine = inputReader.readLine().split(" ");

            List<BigDecimal> probs = new ArrayList<BigDecimal>(inputted);
            for (int i = 0; i < inputted; i++) {
                probs.add(new BigDecimal(probLine[i]));
            }

            BigDecimal keyStoke = keyStoke(total, inputted, probs);

            writer.write(String.format("Case #%d: %s", idx_of_case, keyStoke));
            writer.newLine();
        }

        writer.close();
        inputReader.close();
    }

    public static BigDecimal keyStoke(int total, int inputted, List<BigDecimal> probs) {

        if (inputted == 0) {
            return new BigDecimal(total + 1);
        }
        BigDecimal retype = new BigDecimal(total + 2).setScale(6);
        BigDecimal cont;
        int left = total - inputted + 1;

        BigDecimal probOfCorrect = new BigDecimal(1);

        for (int i = 0; i < inputted; i++) {
            BigDecimal prob = probs.get(i);
            probOfCorrect = probOfCorrect.multiply(prob);
        }

        BigDecimal probOfWrong = new BigDecimal(1).subtract(probOfCorrect);

        BigDecimal right = probOfCorrect.multiply(new BigDecimal(left));
        BigDecimal ifWrong = probOfWrong.multiply(new BigDecimal(left + total + 1));

        BigDecimal fix = fix(total, inputted, probs);
        BigDecimal p = right.add(ifWrong).setScale(6, RoundingMode.HALF_UP);

        BigDecimal conti = retype.compareTo(p) > 0 ? p : retype;
        return conti.compareTo(fix) > 0 ? fix : conti;
    }

    private static BigDecimal fix(int total, int inputted, List<BigDecimal> probs) {
        BigDecimal result = new BigDecimal(1000);
        for (int i = 1; i < inputted; i++) {
            BigDecimal p = keyStoke(total, inputted - i, probs).add(new BigDecimal(i));
            if (p.compareTo(result) < 0) {
                result = p;
            }
        }
        return result;
    }

}
