import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FashionPolice {
    private static final String ANSWER_PREFIX = "Case #";

    private static boolean isOutfitValid(Outfit o, List<Outfit> history, int duplicate) {
        boolean valid = true;

        int i = 0;
        int duplicateJP = 0;
        int duplicateJS = 0;
        int duplicatePS = 0;
        while (valid && i < history.size()) {
            Outfit old = history.get(i);
            if (o.j == old.j && o.p == old.p) {
                duplicateJP++;
            }
            if (o.j == old.j && o.s == old.s) {
                duplicateJS++;
            }
            if (o.p == old.p && o.s == old.s) {
                duplicatePS++;
            }
            if (duplicateJP >= duplicate || duplicateJS >= duplicate || duplicatePS >= duplicate) {
                valid = false;
            }
            i++;
        }

        return valid;
    }

    public static void test(int caseNb, Scanner sc, PrintWriter pw) {
        String answer = ANSWER_PREFIX;

        int jacket = sc.nextInt();
        int pants = sc.nextInt();
        int shirt = sc.nextInt();
        int duplicate = sc.nextInt();
        int nbDay = 0;
        answer = answer.concat(String.valueOf(caseNb)).concat(": ");
        String outfits = "";
        List<Outfit> history = new ArrayList<>();
        for (int j = 1; j <= jacket; j++) {
            for (int p = 1; p <= pants; p++) {
                for (int s = 1; s <= shirt; s++) {
                    Outfit o = new Outfit(j, p, s);
                    if (isOutfitValid(o, history, duplicate)) {
                        nbDay++;
                        outfits = outfits.concat("\r\n").concat(o.toString());
                        history.add(o);
                    }
                }
            }
        }
        answer = answer.concat(String.valueOf(nbDay)).concat(outfits);
        pw.println(answer);
        System.out.println(answer);
    }

    public static void main(String[] args) {
        ClassLoader classLoader = CountigSheep.class.getClassLoader();
        File input = new File(classLoader.getResource("C-small-attempt1.in").getFile());
        Scanner sc;
        try {
            sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(input.getPath().replaceAll("\\.in", ".out"));

            int T = Integer.parseInt(sc.nextLine());
            for (int i = 1; i <= T; i++) {
                test(i, sc, pw);
            }
            pw.close();
            sc.close();
        } catch (FileNotFoundException e) {
            System.err.println("Error reading/writing file.");
            e.printStackTrace();
        }

    }

    static class Outfit {
        int j;

        int p;

        int s;

        public Outfit(int j, int p, int s) {
            this.j = j;
            this.p = p;
            this.s = s;
        }

        @Override
        public String toString() {
            return j + " " + p + " " + s;
        }
    }
}
