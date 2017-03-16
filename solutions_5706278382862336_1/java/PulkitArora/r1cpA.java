/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package codejam1c;

import java.util.Scanner;

/**
 *
 * @author Pulkit
 */
class problemA {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        long t,t1;
        t=sc.nextLong();
        String garbage=sc.nextLine();
        for(t1=1;t1<=t;t1++)
        {
            String s = sc.nextLine();
            String[] ar = new String[2];
            ar = s.split("/");
            long a,b;
            a=Long.parseLong(ar[0]);
            b=Long.parseLong(ar[1]);
            if(b%2!=0)
            {
                System.out.println("Case #"+t1+": impossible");
                continue;
            }
            long countyet=0;
            while(true)
            {
                if((((float)a)/((float)b)) >= (1.0/(Math.pow(2, countyet))))
                {
                    System.out.println("Case #"+t1+": "+countyet);
                    break;
                }
                else
                    countyet++;
            }
            
        }
    }
    
}

