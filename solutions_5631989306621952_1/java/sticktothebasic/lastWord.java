import java.util.*;
import java.lang.*;
import java.math.*;

public class lastWord
{
    static String getLastWord(String s){
        char firstChar = s.charAt(0);
        String retStr = "" + firstChar;
        for (int i = 1; i < s.length(); i++){
            if (s.charAt(i) >= firstChar){
                retStr = s.charAt(i) + retStr;
                firstChar = s.charAt(i);
            }
            else {
                retStr = retStr + s.charAt(i);
            }

        }
        return retStr;
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberOfTests = in.nextInt();
        in.nextLine();
        for (int i = 0; i < numberOfTests; i++)
        {
        	String s = in.nextLine();
            System.out.println("Case #" + (i + 1) + ": " + getLastWord(s));
        }  
    }
}