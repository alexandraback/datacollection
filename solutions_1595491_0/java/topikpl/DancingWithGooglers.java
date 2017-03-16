/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dancingwithgooglers;

import java.util.Scanner;

/**
 *
 * @author topik
 */
public class DancingWithGooglers
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
            final int googlers = scanner.nextInt();
            int surprising = scanner.nextInt();
            final int p = scanner.nextInt();
            
            int goodGooglers = 0;
            
            for( int i=0; i < googlers; i++ )
            {
                final int score = scanner.nextInt();
                
                if( score == 0 )
                {
                    if( p == 0 )
                    {
                        goodGooglers++;
                    }
                    continue;
                }
                
                final int d = score / 3;
                final int r = score % 3;
                
                if( d >= p )
                {
                    goodGooglers++;
                }
                else if( d+1 >= p )
                {
                    if( r > 0 )
                    {
                        goodGooglers++;
                    }
                    else if( surprising > 0 )
                    {
                        surprising--;
                        goodGooglers++;
                    }
                }
                else if( d+2 >= p )
                {
                    if( r == 2 && surprising > 0 )
                    {
                        surprising--;
                        goodGooglers++;
                    }
                }
            }
            
            System.out.println("Case #" + tc + ": " + goodGooglers);
        }
    }
}
