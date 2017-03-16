package qr16;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dzhang on 5/4/16.
 */
public class C {
//    private static final String MODE = "sample";
    private static final String MODE = "small-attempt0";
//    private static final String MODE = "large";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("in/" + C.class.getPackage().getName() + "/" + C.class.getSimpleName() + "-" + MODE + ".in"));

        File outFile = new File("out/" + C.class.getPackage().getName() + "/" + C.class.getSimpleName() + "-" + MODE + ".out");
        outFile.createNewFile();
        BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));

        C solution = new C();

        int T = Integer.parseInt(br.readLine());

        String[] line = br.readLine().split(" ");
        int digit = Integer.parseInt(line[0]);
        int count = Integer.parseInt(line[1]);
        List<String> output = solution.solve(digit, count);
        bw.write("Case #1:\n");
        System.out.print("Case #1:\n");
        for (String str : output){
            bw.write(str + "\n");
            System.out.print(str + "\n");
        }
        br.close();
        bw.close();
    }

    private List<String> solve(int digit, int count) {
        List<String> list = new ArrayList<>(count);

        char[] digits = new char[digit];
        digits[0] = digits[digit / 2 - 1] = digits[digit / 2] = digits[digit - 1] = '1';
        solve(list, digits, 1, count);

        return list;
    }

    private void solve(List<String> list, char[] digits, int i, int count) {
        if(i > digits.length / 2 - 2){
            if(list.size() >= count){
                return;
            }
            StringBuilder sb = new StringBuilder();
            for(int j = 0; j < digits.length; j ++) {
                sb.append(digits[j]);
            }
            appendFactors(sb, digits);
            list.add(sb.toString());
            return;
        }
        char[] digit1 = digits.clone();
        digit1[i] = digit1[i + digits.length / 2] = '1';
        solve(list, digit1, i + 1, count);
        char[] digit2 = digits.clone();
        digit2[i] = digit2[i + digits.length / 2] = '0';
        solve(list, digit2, i + 1, count);
    }

    private void appendFactors(StringBuilder sb, char[] digits) {
        for (int base = 2; base < 11; base ++){
            BigInteger sum = BigInteger.ZERO;
            for (int i = 0; i < digits.length / 2; i ++) {
                if(digits[i] == '1')
                sum = sum.add(BigInteger.valueOf(base).pow(digits.length / 2 - 1 - i));
            }
            sb.append(' ');
            sb.append(sum.toString());
        }
    }

}
