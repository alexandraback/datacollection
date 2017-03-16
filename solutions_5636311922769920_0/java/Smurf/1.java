import java.io.*;
import java.util.*;
import java.math.*;

class Solution {
    
    public static void main(String[] args) throws Exception {
        
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();


        for(int m=1;m<=t;m++)
        {
           int k=in.nextInt(); 
           int c=in.nextInt(); 
           int s=in.nextInt();
           System.out.printf("Case #%d: ",m);
            if(k==s)
            {
                for(int i=0;i<s-1;i++)
                {
                    System.out.print(i+1+ " ");
                } 

            }
            System.out.println(s);
        }
    }
}
