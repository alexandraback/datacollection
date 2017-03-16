import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

/**
 * Created by danielmckee on 4/15/16.
 */
public class LastWord {
    Scanner in;
    PrintWriter out;
    String s;

    public LastWord() throws FileNotFoundException, UnsupportedEncodingException {
        in = new Scanner(new FileReader("lastword_small_in.txt"));
        out = new PrintWriter("lastword_small_out.txt", "UTF-8");
    }

    private void parse(){
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            s = in.next();
            String output = solve();
            int case_num = i + 1;
            //System.out.println("Case #" + case_num + ": " + output);
            out.println("Case #" + case_num + ": " + output);
        }
        out.close();
    }




    private String solve() {
        String str = s.substring(0, 1);
        for (int i = 1; i < s.length(); i ++) {
            if (s.charAt(i) >= str.charAt(0)) {
                str = s.substring(i, i+1) + str;
            } else {
                str = str + s.substring(i, i+1);
            }
        }
        return str;

    }




    public static void main(String[] args) {
        LastWord l = null;
        try {
            l = new LastWord();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        l.parse();
    }
}
