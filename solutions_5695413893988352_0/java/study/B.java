import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * Created by study on 4/15/16.
 */
public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        for (int i = 1; i <= T; i++) {
            System.out.print(String.format("Case #%d: ", i));
            solve(scanner);
        }
    }

    public static void solve(Scanner scanner) {
        String A = scanner.next();
        String B = scanner.next();

        //StringBuilder sba = new StringBuilder(A.length());
        //StringBuilder sbb = new StringBuilder(B.length());
       // System.out.print(A + " ");
        //System.out.println(B);

        int c;
        String p;
        if (A.length() == 1) {
            c = 9;
            p = "%d";
        } else if (A.length() == 2) {
            c = 99;
            p = "%02d";
        } else {
            c = 999;
            p = "%03d";
        }

        List<Integer> lista = new ArrayList<>();
        List<Integer> listb = new ArrayList<>();

        if (!A.contains("?")) {
            lista.add(Integer.valueOf(A));
        }
        if (!B.contains("?")) {
            listb.add(Integer.valueOf(B));
        }

        A = A.replace("?", "[0-9]");
        B = B.replace("?", "[0-9]");
        for (int i = 0; i <= c; i++) {
            String num = String.format(p, i);
            if (Pattern.matches(A, num)) {
                lista.add(Integer.parseInt(num));
            }
            if (Pattern.matches(B, num)) {
                listb.add(Integer.parseInt(num));
            }
        }

        for (int i = 0; i < listb.size(); i++) {
            int value = listb.get(i);
            if (lista.contains(value)) {
                System.out.println(String.format(p, value) + " " + String.format(p, value));
                return;
            }
        }

//        int aa = lista.get(0);
//        int bb = listb.get(0);
//        if (aa > bb) {
        int pmin = Integer.MAX_VALUE;
        int pa = Integer.MAX_VALUE;
        int pb = Integer.MAX_VALUE;

        if(lista.size() > listb.size()) {
            for (int j = 0; j < lista.size(); j++) {
                int valuea = lista.get(j);
                for (int i = 0; i < listb.size(); i++) {
                    int valueb = listb.get(i);
                    int min = Math.abs(valuea - valueb);

                    if (min < pmin) {
                        pmin = min;
                        pa = valuea;
                        pb = valueb;
                    }
                }
            }
        } else {
            for (int j = 0; j < listb.size(); j++) {
                int valueb = listb.get(j);
                for (int i = 0; i < lista.size(); i++) {
                    int valuea = lista.get(i);
                    int min = Math.abs(valuea - valueb);

                    if (min < pmin) {
                        pmin = min;
                        pa = valuea;
                        pb = valueb;
                    }
                }
            }
        }
//
        System.out.print(String.format(p, pa) + " ");
        System.out.println(String.format(p, pb));
//
//        } else if (aa < bb) {
//            int pmin = Integer.MAX_VALUE;
//            int pvalue = -1;
//            for (int i = 0; i < lista.size(); i++) {
//                int value = lista.get(i);
//                int min = Math.abs(bb - value);
//                if (min < pmin) {
//                    pmin = min;
//                    pvalue = value;
//                }
//            }
//            System.out.print(String.format(p, pvalue) + " ");
//            System.out.println(String.format(p, bb));
//        } else {
//            System.out.println(String.format(p, aa) + " " + String.format(p, bb));
//        }


//        System.out.print(sba.toString() + " ");
//        System.out.println(sbb.toString());
    }
}
