package coding;

import java.util.*;
import java.io.* ;
import java.lang.Math;
public class first_1 {

    /**
     * @param args the command line arguments
     */
	public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int t , r , c , w , i , j , k , ans;
        t = in.nextInt();
        for(k=1;k<=t;k++)
        {
            r = in.nextInt();
            c = in.nextInt();
            w = in.nextInt();
            ans = 0 ;
            ans = (int)(Math.ceil((double)c/w)) ;
            ans += w-1 ;
            ans += (r-1)*(int)(c/w) ;
            System.out.println("Case #"+k+": "+ans);
        }
    }
}
