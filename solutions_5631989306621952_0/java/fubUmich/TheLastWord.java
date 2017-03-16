import java.util.Scanner;

/**
 * Created by BinghongFu on 4/15/16.
 */
public class TheLastWord {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = Integer.valueOf(s.nextLine());
        String[] input = new String[n];
        for(int i = 0; i < n; ++i){
            input[i] = s.nextLine();
        }

        for(int i = 0; i < n; ++i){
            System.out.print("Case #" + String.valueOf(i+1) + ": ");
            System.out.println(getLastWord(input[i]));
        }
    }

    private static String getLastWord(String s){
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < s.length(); ++i){
            if(sb.length() > 0 && s.charAt(i) >= sb.charAt(0)){
                sb.insert(0, s.charAt(i));
            }
            else
                sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}
