
import java.io.File;
import java.util.Scanner;

public class A {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("/home/floris/temp/dev/codejam2013/in/A-large.in"));
        for (int count = sc.nextInt(), current = 1; count > 0; count--, current++) {
            sc.nextLine();
            String[] lines = {sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()};
            System.out.printf("Case #%d: %s%n", current, solve(lines));
        }
    }
    public static String solve(String[] lines) {
        if (test('X', lines)) return "X won";
        if (test('O', lines)) return "O won";
        for (int i = 0; i < lines.length; i++) if (lines[i].contains(".")) return "Game has not completed";
        return "Draw";
    }

    public static boolean test(char v, String[] lines) {
        for (int i = 0; i < 4; i++) {
            boolean a = true, b = true;
            for (int j = 0; j < 4; j++) {
                a &= (lines[j].charAt(i) == v) || (lines[j].charAt(i) == 'T');
                b &= (lines[i].charAt(j) == v) || (lines[i].charAt(j) == 'T');
            }
            if (a || b) return true;
        }
        boolean a = true, b = true;
        for (int i = 0; i < 4; i++) {
            a &= lines[i].charAt(i) == v || lines[i].charAt(i) == 'T';
            b &= lines[i].charAt(3-i) == v || lines[i].charAt(3-i) == 'T';
        }
        return a || b;
    }
}
