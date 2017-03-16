

package Qualification_2015;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 *
 * @author utilisateur
 */
public class House_of_pancake_4{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int [] a =new int[1200];
        int t,step=0;
        int n,i,j,max1=0,min1=0,sum=0;
        t=sc.nextInt();
        while(t>0)
        {
           n=sc.nextInt();
           for(i=0;i<n;i++)
           {
               a[i]=sc.nextInt();
               max1=Math.max(max1,a[i]);
               
           }
           min1=max1;
           for(i=1;i<=max1;i++)
           {
               sum=i;
               for(j=0;j<n;j++)
               {
                   if(a[j]>i)
                   {
                       if(a[j]%i==0)
                           sum+=(a[j]/i-1);
                       else
                           sum+=(a[j]/i);
                   }
               }
               min1=Math.min(min1,sum);
           }
           System.out.println("Case #"+(++step)+": "+min1);
           t--;
        }
    }
}
