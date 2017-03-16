import java.util.*;
import java.math.BigInteger;
//import edu.princeton.cs.algs4.*;


public class A
{

    public static void main (String [] args)
    {
        Scanner sc = new Scanner(System.in);

        int nocase = sc.nextInt();
        sc.nextLine();
        for(int ind=1; ind<=nocase; ind++)
        {
            String inS = sc.nextLine();
            String soln = solve(inS);
            System.out.printf("Case #%d: %s\n", ind, soln);
        }
    }

    public static String solve(String I)
    {

        LinkedList<Character> L = new LinkedList<Character>();
        if(I.isEmpty()) return I;

        L.addFirst(I.charAt(0));
        for(int i=1; i<I.length(); i++)
        {
            if(I.charAt(i)>= L.get(0))
                L.addFirst(I.charAt(i));
            else 
                L.addLast(I.charAt(i));
        }
        StringBuffer sb = new StringBuffer();
        for(Character C:L)
            sb.append(C);
        return sb.toString();
    }

}
