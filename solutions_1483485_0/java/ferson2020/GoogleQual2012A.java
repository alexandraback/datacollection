import java.io.*;
import java.util.*;

public class GoogleQual2012A
{   public static void main(String[] args) throws Throwable
    {   new GoogleQual2012A();
    }
    
    public GoogleQual2012A() throws Throwable
    {   Scanner in = new Scanner(new File("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileWriter("A-small-attempt0.out"));
      
        int[] engToGoog = new int[26];
        engToGoog['a' - 'a'] = 'y' - 'a';
        engToGoog['b' - 'a'] = 'n' - 'a';
        engToGoog['c' - 'a'] = 'f' - 'a';
        engToGoog['d' - 'a'] = 'i' - 'a';
        engToGoog['e' - 'a'] = 'c' - 'a';
        engToGoog['f' - 'a'] = 'w' - 'a';
        engToGoog['g' - 'a'] = 'l' - 'a';
        engToGoog['h' - 'a'] = 'b' - 'a';
        engToGoog['i' - 'a'] = 'k' - 'a';
        engToGoog['j' - 'a'] = 'u' - 'a';
        engToGoog['k' - 'a'] = 'o' - 'a';
        engToGoog['l' - 'a'] = 'm' - 'a';
        engToGoog['m' - 'a'] = 'x' - 'a';
        engToGoog['n' - 'a'] = 's' - 'a';
        engToGoog['o' - 'a'] = 'e' - 'a';
        engToGoog['p' - 'a'] = 'v' - 'a';
        engToGoog['q' - 'a'] = 'z' - 'a'; //unknown, but only letter left
        engToGoog['r' - 'a'] = 'p' - 'a';
        engToGoog['s' - 'a'] = 'd' - 'a';
        engToGoog['t' - 'a'] = 'r' - 'a';
        engToGoog['u' - 'a'] = 'j' - 'a';
        engToGoog['v' - 'a'] = 'g' - 'a';
        engToGoog['w' - 'a'] = 't' - 'a';
        engToGoog['x' - 'a'] = 'h' - 'a';
        engToGoog['y' - 'a'] = 'a' - 'a';
        engToGoog['z' - 'a'] = 'q' - 'a';
        
        int[] googToEng = new int[26];
        for (int i = 0; i < googToEng.length; i++)
        {   boolean found = false;
            for (int j = 0; !found; j++)
            {   if (engToGoog[j] == i)
                {   googToEng[i] = j;
                    found = true;
                }
            }
        }
        
        int numTests = in.nextInt();
        in.nextLine();
        for (int i = 0; i < numTests; i++)
        {   out.print("Case #" + (i + 1) + ":");
            String[] words = in.nextLine().split(" ");
            for (int j = 0; j < words.length; j++)
            {   out.print(" ");
                out.print(this.googToEng(words[j], googToEng));
            }
            out.println();
        }
        out.close();
    }
    
    private String googToEng(String goog, int[] googToEng)
    {   String toRet = "";
        for (int i = 0; i < goog.length(); i++)
        {   toRet += (char)('a' + googToEng[goog.charAt(i) - 'a']);
        }
        return toRet;
    }
}