
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
    static int tau[];
    
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        
        int t=sc.nextInt();
        int test =1;
        while(t>0)
        {
            t--;
            n = sc.nextInt();
            
            tau = new int[n] ;
            for(int i=0;i<n;i++)
            {
                tau[i]=sc.nextInt();
            }
            
            int lim=1<<n-1;
            
            sex s[] = new sex[lim];
            
            for(int i=0;i<lim;i++)
            {
                int sum = findSum(i);
                s[i] = new sex(i, sum);
            }
            
            Arrays.sort(s);
            
            boolean f=false;
            System.out.println("Case #"+test+": ");
            for(int i=1;i<lim;i++)
            {
                if((s[i-1].sum==s[i].sum) && ((s[i-1].bitmask&s[i].bitmask)==0))
                {
                    prMask(s[i-1].bitmask);
                    System.out.println();
                    prMask(s[i].bitmask);
                    f=true;
                    break;
                }
                
            }
            if(!f)
                System.out.println("Impossible");
            
            
            
            System.out.println();
            test++;
            
            
        }
        // TODO code application logic here
    }

    private static int findSum(int i) 
    {
        int sum=0;
        for(int k=0;k<n;k++)
        {
            if(((1<<k)&i)!=0)
            {
                sum=sum+tau[k];
            }
        }
        
        return sum;
        
    }
    
    
    private static int prMask(int i) 
    {
        int sum=0;
        for(int k=0;k<n;k++)
        {
            if(((1<<k)&i)!=0)
            {
                System.out.print(tau[k]+" ");;
            }
        }
        
        return sum;
        
    }
}
class sex implements Comparable<sex>
{
    int bitmask;
    int sum;
    public sex(int b,int s)
    {
        bitmask=b;
        sum=s;
    }
    public int compareTo(sex c)
    {
        if(c.sum-sum>0)return -1;
        return 1;
    }
    
}