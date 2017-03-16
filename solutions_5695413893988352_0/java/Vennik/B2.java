import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B2 {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new File("B-small-attempt1.in"));
        FileWriter fw = new FileWriter(new File("b.out"));
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            fw.append(String.format("Case #%d: %s", i, new B2().solve(sc))).append('\n');
        }
        fw.close();
        sc.close();

    }

    private String solve(Scanner sc) {

        System.out.println("---------------");

        String coders = sc.next();
        String jamers = sc.next();

        StringBuilder sbCoders = new StringBuilder();
        StringBuilder sbJamers = new StringBuilder();

        int check = 0;

        int lastZero = 0;

        for (int i = 0; i < coders.length(); i++) {

            char c = coders.charAt(i);
            char j = jamers.charAt(i);

            if (check == 0) {
                if (c == '?' && j == '?') {
                    sbCoders.append(0);
                    sbJamers.append(0);
                    lastZero = i;
                } else if (c == '?') {
                    sbCoders.append(j);
                    sbJamers.append(j);
                    lastZero = i;
                } else if (j == '?') {
                    sbCoders.append(c);
                    sbJamers.append(c);
                    lastZero = i;
                } else {
                    sbCoders.append(c);
                    sbJamers.append(j);
                    if (c > j) {
                        check = 1;
                    }
                    if (j > c) {
                        check = -1;
                    }
                }
            }

            else if (check == 1) {
                if (c == '?' && j == '?') {
                    sbCoders.append(0);
                    sbJamers.append(9);
                } else if (c == '?') {
                    sbCoders.append(0);
                    sbJamers.append(j);
                } else if (j == '?') {
                    sbCoders.append(c);
                    sbJamers.append(9);
                } else {
                    sbCoders.append(c);
                    sbJamers.append(j);
                }
            }

            else {
                if (c == '?' && j == '?') {
                    sbCoders.append(9);
                    sbJamers.append(0);
                } else if (c == '?') {
                    sbCoders.append(9);
                    sbJamers.append(j);
                } else if (j == '?') {
                    sbCoders.append(c);
                    sbJamers.append(0);
                } else {
                    sbCoders.append(c);
                    sbJamers.append(j);
                }
            }

        }

        String co = sbCoders.toString();
        String ja = sbJamers.toString();

        int min = Math.abs(Integer.parseInt(co) - Integer.parseInt(ja));

        char c = coders.charAt(lastZero);
        char j = jamers.charAt(lastZero);

        if (c == '?' && j == '?') {
            System.out.println("cj");
            if (check == 1 &&  ja.charAt(lastZero) != '9') {
                String ja2 = ja.substring(0, lastZero) + ((char) (ja.charAt(lastZero) + 1)) + ja.substring(lastZero + 1, ja.length());
                int temp = Math.abs(Integer.parseInt(co) - Integer.parseInt(ja2));
                if (temp < min) {
                    ja = ja2;
                }
                System.out.println(ja2);
            }
            else if (check == -1 &&  co.charAt(lastZero) != '9') {
                String co2 = co.substring(0, lastZero) + ((char) (co.charAt(lastZero) + 1)) + co.substring(lastZero + 1, co.length());
                int temp = Math.abs(Integer.parseInt(co2) - Integer.parseInt(ja));
                if (temp < min) {
                    co = co2;
                }
                System.out.println(co2);
            }
        } else if (c == '?' && co.charAt(lastZero) != '9') {
            System.out.println("c");
            String co2 = co.substring(0, lastZero) + ((char) (co.charAt(lastZero) + 1)) + co.substring(lastZero + 1, co.length());
            int temp = Math.abs(Integer.parseInt(co2) - Integer.parseInt(ja));
            if (temp < min) {
                co = co2;
            }
        } else if (j == '?' && ja.charAt(lastZero) != '9') {
            System.out.println("j");
            String ja2 = ja.substring(0, lastZero) + ((char) (ja.charAt(lastZero) + 1)) + ja.substring(lastZero + 1, ja.length());
            System.out.println("------" + ja2);
            int temp = Math.abs(Integer.parseInt(co) - Integer.parseInt(ja2));
            if (temp < min) {
                ja = ja2;
            }
        }

        return co + " " + ja;

    }

}
