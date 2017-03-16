
import java.util.Scanner;

/**
 * Created by akshitsharma on 4/16/2016.
 */
public class Main {

    public static String getLastWord(String input){
        char first = input.charAt(0);
        String ret;
        ret = String.valueOf(first);

        while (input.length()>1) {
            input = input.substring(1);
            first = input.charAt(0);
            if(first<ret.charAt(0)) {
                ret = ret+String.valueOf(first);
            }else{
                ret = String.valueOf(first)+ret;
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int trys,cases;
        trys = scanner.nextInt();
        cases = 0;
        while (cases<trys){
            cases++;
            String input = scanner.next();
            String output = getLastWord(input);
            System.out.println("Case #"+cases+": "+output);
        }

    }

}
