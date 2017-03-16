
import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author dave
 */
public class Main 
{

    /**
     * @param args the command line arguments
     */
    
    static int n;
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        
        int t=sc.nextInt();
        int test =1;
        while(t>0)
        {
            t--;
            n = sc.nextInt();
            int sum=0;
            int s[] = new int[n];
            for(int i=0;i<n;i++)
            {
                s[i]=sc.nextInt();
                sum = sum + s[i];
            }
            
            System.out.print("Case #"+test+": ");
            for(int i=0;i<n;i++)           
            {
                find(s,sum,i);
                
            }
            System.out.println();
            
            test++;
        }
        // TODO code application logic here
    }
    
    public static void find(int p[],int sum,int index)
    {
        double s=0;
        double e=100.1; 
        double ans=0;
        //while(e-s> 1e-5)
        for(int x = 0;x<800;x++)
        {
            double m = (s+e)/2;
            if(fail(m,sum,index,p)) // possible to fail?
            {
                ans = m;
                s=m;
            }
            else
            {
                e=m;
            }
                
        }
        
       
        System.out.print(ans+" ");;
        
        
    }

    private static boolean fail(double m,int sum,int j,int p[]) {
        
        double fracRem = 100-m;
        double alloc =0;
        
        double scoreCur = (sum*m)/100 + p[j]; // jth judged pts
        
        for(int i=0;i<n;i++)
        {
            
            if(i==j)
                continue;
            
            if(p[i]>=scoreCur)
                continue;
            
            alloc = ((scoreCur - p[i])/sum)*100;
            fracRem = fracRem-alloc;
            if(fracRem<0)
                return false;
        }
               
        return true;
    }
    
    
}
