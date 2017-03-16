import java.util.Scanner;
public class GettingTheDigits {

    public static String found(String s, String t) {
        for (int i = 0; i < s.length(); i++) {
            if (s.substring(i, i + 1).equals(t)) {
                return s.substring(0, i) + s.substring(i + 1);
            }
        }
        return "-1";
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            String s = in.next();
            int[] digits = new int[10];
            for (int j = 0; j < digits.length; j++) {
                digits[j] = 0;
            }
            boolean zero = false;
            while (true) {
                zero = false;
                String str = found(s, "Z");
                if (!str.equals("-1")) {
                    s = found(s, "Z");
                    digits[0]++;
                    s = found(s, "E");
                    s = found(s, "R");
                    s = found(s, "O");
                    zero = true;
                }
                if (!zero) {
                    break;
                }
            }
            boolean six = false;
            while (true) {
                six = false;
                String str = found(s, "S");
                String s2 = found(s, "I");
                String s3 = found(s, "X");
                if (!str.equals("-1") && !s2.equals("-1") && !s3.equals("-1")) {
                    s = found(s, "S");
                    digits[6]++;
                    s = found(s, "I");
                    s = found(s, "X");
                    six = true;
                }
                if (!six) {
                    break;
                }
            }
            boolean two = false;
            while (true) {
                two = false;
                String str = found(s, "T");
                String s2 = found(s, "W");
                String s3 = found(s, "O");
                if (!str.equals("-1") && !s2.equals("-1") && !s3.equals("-1")) {
                    s = found(s, "T");
                    digits[2]++;
                    s = found(s, "W");
                    s = found(s, "O");
                    two = true;
                }
                if (!two) {
                    break;
                }
            }
            boolean eight = false;
            while (true) {
                eight = false;
                String str = found(s, "E");
                String s2 = found(s, "I");
                String s3 = found(s, "G");
                String s4 = found(s, "H");
                String s5 = found(s, "T");
                if (!str.equals("-1") && !s2.equals("-1") && !s3.equals("-1") && !s4.equals("-1") && !s5.equals("-1")) {
                    s = found(s, "E");
                    digits[8]++;
                    s = found(s, "I");
                    s = found(s, "G");
                    s = found(s, "H");
                    s = found(s, "T");
                    eight = true;
                }
                if (!eight) {
                    break;
                }
            }
            boolean four = false;
            while (true) {
                four = false;
                String str = found(s, "F");
                String s2 = found(s, "O");
                String s3 = found(s, "U");
                String s4 = found(s, "R");
                if (!str.equals("-1") && !s2.equals("-1") && !s3.equals("-1") && !s4.equals("-1")) {
                    s = found(s, "F");
                    digits[4]++;
                    s = found(s, "O");
                    s = found(s, "U");
                    s = found(s, "R");
                    four = true;
                }
                if (!four) {
                    break;
                }
            }
            boolean one = false;
            while (true) {
                one = false;
                String str = found(s, "O");
                String s2 = found(s, "N");
                String s3 = found(s, "E");
                if (!str.equals("-1") && !s2.equals("-1") && !s3.equals("-1")) {
                    s = found(s, "O");
                    digits[1]++;
                    s = found(s, "N");
                    s = found(s, "E");
                    one = true;
                }
                if (!one) {
                    break;
                }
            }
            boolean three = false;
            while (true) {
                three = false;
                String str = found(s, "T");
                String s2 = found(s, "H");
                String s3 = found(s, "R");
                String s4 = found(s, "E");
                String s5 = found(s, "E");
                if (!str.equals("-1") && !s2.equals("-1") && !s3.equals("-1") && !s4.equals("-1") && !s5.equals("-1")) {
                    s = found(s, "T");
                    digits[3]++;
                    s = found(s, "H");
                    s = found(s, "R");
                    s = found(s, "E");
                    s = found(s, "E");
                    three = true;
                }
                if (!three) {
                    break;
                }
            }
            boolean five = false;
            while (true) {
                five = false;
                String str = found(s, "F");
                String s2 = found(s, "I");
                String s3 = found(s, "V");
                String s4 = found(s, "E");
                if (!str.equals("-1") && !s2.equals("-1") && !s3.equals("-1") && !s4.equals("-1")) {
                    s = found(s, "F");
                    digits[5]++;
                    s = found(s, "I");
                    s = found(s, "V");
                    s = found(s, "E");
                    five = true;
                }
                if (!five) {
                    break;
                }
            }
            boolean seven = false;
            while (true) {
                seven = false;
                String str = found(s, "S");
                String s2 = found(s, "E");
                String s3 = found(s, "V");
                String s4 = found(s, "E");
                String s5 = found(s, "N");
                if (!str.equals("-1") && !s2.equals("-1") && !s3.equals("-1") && !s4.equals("-1") && !s5.equals("-1")) {
                    s = found(s, "S");
                    digits[7]++;
                    s = found(s, "E");
                    s = found(s, "V");
                    s = found(s, "E");
                    s = found(s, "N");
                    seven = true;
                }
                if (!seven) {
                    break;
                }
            }
            boolean nine = false;
            while (true) {
                nine = false;
                String str = found(s, "N");
                String s2 = found(s, "I");
                String s3 = found(s, "N");
                String s4 = found(s, "E");
                if (!str.equals("-1") && !s2.equals("-1") && !s3.equals("-1") && !s4.equals("-1")) {
                    s = found(s, "N");
                    digits[9]++;
                    s = found(s, "I");
                    s = found(s, "N");
                    s = found(s, "E");
                    nine = true;
                }
                if (!nine) {
                    break;
                }
            }
            String number = "";
            for (int j = 0; j < digits.length; j++) {
                for (int k = 0; k < digits[j]; k++) {
                    number += j;
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + number);
        
        }
    }
    
}
