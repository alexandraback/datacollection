import java.io.*;
import java.util.*;
import java.math.*;

class Solution {
    
    public static void main(String[] args) throws Exception {
        
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();


        for(int m=1;m<=t;m++)
        {
           int n=in.nextInt(); 
           int a[][]=new int[2*n-1][n];
           int count[]=new int[2501];

           for(int i=0;i<2*n-1;i++)
           {
                for(int j=0;j<n;j++)
                {
                    a[i][j]=in.nextInt();   
                    count[a[i][j]]++; 
                }
           }


           System.out.printf("Case #%d: ",m);
            
            int b[]=new int[n];
            int j=0;
           for(int i=0;i<=2500;i++)
           {
            if(count[i]%2==1)
                {
                    b[j]=i;
                    j++;
                }
           }
           Arrays.sort(b);

           for(int i=0;i<n;i++)
           {
                System.out.print(b[i]+" ");
           }
            System.out.println();

        }
    }
}
