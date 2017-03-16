
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author adam
 */
public class ProblemA {
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        int casenum=s.nextInt();
        for (int i=1;i<=casenum;i++)
        {
            System.out.print("Case #"+i+": ");
            solve(s);
            System.out.println();
        }
    }
     private static void solve(Scanner s) {
         double r=s.nextDouble();
         double t=s.nextDouble();
         //System.err.println(r+" "+t);
         //1 mililiter pi^2 terület
         double remaining=t;
         int c=0;
         while (true)
         {
             
             double area=( ((r+1)*(r+1))-r*r );
             //System.err.println("area:"+area+" "+r);
             if (area<0) break;
             //double mililiters=;
             if (remaining-area<0) break;
             remaining-=area;
             r+=2;
             c++;
         }
         System.out.print(c);
     }
}
