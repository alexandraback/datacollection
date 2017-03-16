import java.io.*;
import java.util.*;
/**
 *
 * @author Akash_Mahajan
 */
public class temp2
 {
    int maxGain(int e,int i,int r,int n,int max)
    {
        e = e+r;
        if(e>max)
            e=max;
        if(i>n)
            return 0;
       
        int maxe=0;
        for(int k=0;k<=e;k++)
        {
            int temp = maxGain(e-k,i+1,r,n,max) + k*a[i];
            if (temp>maxe)
            {
                maxe = temp;
            }
        }
        
        return maxe;
    }
    static int a[] = new int[10];
    public static void main(String[] args) throws Exception
    {
    BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
    int testcase = Integer.parseInt(br.readLine());
    int i = 1;
   
    for(;i<=testcase;i++)
    {
        a = new int[10000000];
       String s = br.readLine();
       StringTokenizer st = new StringTokenizer(s," ");
       int e = Integer.parseInt(st.nextToken());
       int r = Integer.parseInt(st.nextToken());
       int n = Integer.parseInt(st.nextToken());
       s = br.readLine();
       st = new StringTokenizer(s," ");
       int j = 0;
       for(;j<n;j++)
       {
           a[j] = Integer.parseInt(st.nextToken());
       }
               
      System.out.println("Case #"+i+": "+new temp2().maxGain(e,0,r,n,e)); 
    }
    
    }

}
