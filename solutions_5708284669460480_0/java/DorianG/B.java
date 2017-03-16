import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by pascal on 5/10/15.
 */
public class B {

    static void allStrings(int length, char[] a, String curr, List<String> strings) {
        if(curr.length() == length) {
            strings.add(curr);
        } else {
            for(int i = 0; i < a.length; i++) {
                allStrings(length, a, curr + a[i], strings);
            }
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        int caseNum = 1;
        while((line = reader.readLine()) != null) {
            String[] parts = line.split(" ");
            int K = Integer.parseInt(parts[0]);
            int L = Integer.parseInt(parts[1]);
            int S = Integer.parseInt(parts[2]);
            String keyboard = reader.readLine();
            String target = reader.readLine();
            double result = 1;

            boolean possible = true;
            for(char c: target.toCharArray()) {
                if(!keyboard.contains(c+"")) {
                    possible = false;
                    result = 0.0;
                    break;
                }
            }

            if(possible) {
                List<String> strings = new ArrayList<>();
                allStrings(S, keyboard.toCharArray(), "", strings);
                //System.err.println(caseNum + ":" + strings.toString());
                int max = 0;
                int av = 0;
                for(String s: strings) {
                    int count = 0;
                    for(int i = 0; i < s.length(); i++)
                        if(s.substring(i).startsWith(target)) count++;

                    if(count > max) max = count;
                    av += count;
                }

                double exp = (double)av / strings.size();
                System.err.println(caseNum + ":" + max + ": " + exp);
                result = (double)max - exp;
            }

            System.out.println("Case #" + caseNum + ": " + result);
            caseNum++;
        }
    }
}
