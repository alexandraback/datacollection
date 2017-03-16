/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package recyclednumbers;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author topik
 */
public class RecycledNumbers
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        final Scanner scanner = new Scanner(System.in);
        final int testCases = scanner.nextInt();
        for( int tc=1; tc <= testCases; tc++ )
        {
            final int a = scanner.nextInt();
            final int b = scanner.nextInt();
            int total = 0;
            
            for( int n = a > 10 ? a : 10; n < b; n++ )
            {
                final Set<Integer> seen = new HashSet<Integer>();
                final String nStr = Integer.toString(n);
                final int nStrLen = nStr.length();
                for( int replace = 1; replace < nStrLen; replace++ )
                {
                    final String mStr = nStr.substring(nStrLen - replace) + nStr.substring(0, nStrLen - replace);
                    final int m = Integer.parseInt(mStr);
                    if( m <= b && m > n && ! seen.contains(m) )
                    {
                        seen.add(m);
                        total++;
                    }
                }
            }
            
            System.out.println("Case #" + tc + ": " + total);
        }
    }
}
