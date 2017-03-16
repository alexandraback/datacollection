rt java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.math.*;
import java.io.*;
public class D {
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int t,x,r,c;
        t=sc.nextInt();
        for(int i=0;i<t;i++)
        {
            x=sc.nextInt();
            r=sc.nextInt();
            c=sc.nextInt();
            if(((r*c)%x)!=0)
            {
                int e=i+1;
                System.out.println("Case #"+e+": RICHARD");
            }else if((x-1)>r||(x-1)>c)
            {
                int e=i+1;
                System.out.println("Case #"+e+": RICHARD");
            }else
            {
                int e=i+1;
                 System.out.println("Case #"+e+": GABRIEL");
            }
        }
    }
    
}
