import java.util.Scanner;

/**
 * Created by james on 16/04/09.
 */
public class Pancakes {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        String ss[] = new String[tests];
        for(int i = 0; i < tests; i++){
            ss[i] = in.next();
        }
        for(int i = 0; i < tests; i++){
            String s = ss[i];
            int count = 0;
            char chars[] = s.toCharArray();
            for(int j = 0; j < chars.length - 1; j++){
                if(chars[j] != chars[j+1])
                    count++;
            }
            if(chars[chars.length - 1] == '-') count++;

            System.out.printf("Case #%d: %d\n", i + 1, count);
        }
    }
}
