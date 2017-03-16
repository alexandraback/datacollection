import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Ex1 {
    private static String input = "A-small-attempt0.in";
    private static String output = "out.txt";
    private PrintWriter out;

    public int execute(String s) {
        List<Integer> ans = new ArrayList<>();
        s = s.toLowerCase();
        int m = 'z'-'a'+1;
        int n = s.length();
        int[] cnts = new int[m];
        for (int i=0; i<n; i++)  cnts[s.charAt(i)-'a']++;
//        for (int i=0; i<m; i++) if (cnts[i]!=0)
//            System.out.print((char)(i+'a') + " = " + cnts[i]+" ");
//        System.out.println();

        while (cnts['z'-'a'] > 0) {
            ans.add(0);
            cnts['z'-'a']--;
            cnts['e'-'a']--;
            cnts['r'-'a']--;
            cnts['o'-'a']--;
        }

        while (cnts['x'-'a'] > 0) {
            ans.add(6);
            cnts['s'-'a']--;
            cnts['i'-'a']--;
            cnts['x'-'a']--;
        }

        while (cnts['s'-'a'] > 0) {
            ans.add(7);
            cnts['s'-'a']--;
            cnts['e'-'a']--;
            cnts['v'-'a']--;
            cnts['e'-'a']--;
            cnts['n'-'a']--;
        }

        while (cnts['w'-'a'] > 0) {
            ans.add(2);
            cnts['t'-'a']--;
            cnts['w'-'a']--;
            cnts['o'-'a']--;
        }

        while (cnts['g'-'a'] > 0) {
            ans.add(8);
            cnts['e'-'a']--;
            cnts['i'-'a']--;
            cnts['g'-'a']--;
            cnts['h'-'a']--;
            cnts['t'-'a']--;
        }

        while (cnts['v'-'a'] > 0) {
            ans.add(5);
            cnts['f'-'a']--;
            cnts['i'-'a']--;
            cnts['v'-'a']--;
            cnts['e'-'a']--;
        }

        while (cnts['f'-'a'] > 0) {
            ans.add(4);
            cnts['f'-'a']--;
            cnts['o'-'a']--;
            cnts['u'-'a']--;
            cnts['r'-'a']--;
        }

        while (cnts['h'-'a'] > 0) {
            ans.add(3);
            cnts['t'-'a']--;
            cnts['h'-'a']--;
            cnts['r'-'a']--;
            cnts['e'-'a']--;
            cnts['e'-'a']--;
        }

        while (cnts['o'-'a'] > 0) {
            ans.add(1);
            cnts['o'-'a']--;
            cnts['n'-'a']--;
            cnts['e'-'a']--;
        }

        while (cnts['n'-'a'] > 0) {
            ans.add(9);
            cnts['n'-'a']--;
            cnts['i'-'a']--;
            cnts['n'-'a']--;
            cnts['e'-'a']--;
        }

        int[] res = new int[ans.size()];
        for (int i=0; i<res.length; i++) res[i] = ans.get(i);
        Arrays.sort(res);

        for (int i=0; i<res.length; i++) out.print(res[i]);
        return 1;
    }



    public void runTests(Scanner input) throws FileNotFoundException {
        out = new PrintWriter(output);
        int testsNo = Integer.valueOf(input.nextLine());

        for (int i=1; i<=testsNo; i++) {
            String str = input.nextLine();

            out.print("Case #"+i+": ");
            execute(str);
            out.println();
        }
        out.close();
    }


    public static void main(String[] args) throws FileNotFoundException {
        Scanner file = new Scanner(new FileInputStream(input));
        new Ex1().runTests(file);
        file.close();
    }
}
