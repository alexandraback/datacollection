import java.util.*;
import java.util.Set;
import java.io.*;

public class B
{

    public static double probability(String key, char t, int k)
    {
        double counter = 0;
        for( int i=0; i<k; i++) {
            if( key.charAt(i) == t ) {
                counter++;
            } 
        }
        return counter/(double)k;
    }

    public static boolean lettersExist(String key, String target, int l)
    {
        for(int i=0; i<l; i++)
        {
            String ch = ""+target.charAt(i);
            if(!key.contains(ch))
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws Exception
    {
        File file = new File("B-small-attempt1.in");
        Scanner input = new Scanner(file);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int k = input.nextInt();//number of letters in the keyboard
            int l = input.nextInt();//number of letters in the target word
            int s = input.nextInt();//number of letters that can be typed
            String reverse = "";
            double nobtb = s/l;
            String keyboard = input.next();
            String target = input.next();
            for ( int i = l-1; i >= 0; i-- )
                reverse = reverse + target.charAt(i);
            if(reverse == target)
                nobtb = s - l;
            /*System.out.println(k+" "+l+" "+s);
            System.out.println(keyboard);
            System.out.println(target);*/
            double probs = 1.0;
            if(lettersExist(keyboard,target,l))
            {
                for(int i=0;i<l;i++)
                {
                    probs *= probability(keyboard, target.charAt(i), k);
                }
                probs = (1-probs)*nobtb;
            }
            else {
                probs = 0.0;
            }
            System.out.println("Case #"+(n+1)+": "+probs);
        }
    }
}