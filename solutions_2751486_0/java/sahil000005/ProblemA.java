package CodeJam2013.Round1C;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class ProblemA {

public static void main(String args[]) throws Exception
{
    BufferedWriter out=null;
    try
    {
    String path="C:\\Users\\SAHIL\\Documents\\NetBeansProjects\\GoogleCodeJam\\src\\CodeJam2013\\Round1C\\";

        Scanner sc=new Scanner(new File(path+"A-small-practice.in"));
        FileWriter fstream = new FileWriter(path+"A-small-practice.out");
        out = new BufferedWriter(fstream);
        int T=sc.nextInt();
        sc.nextLine();
        for(int i=0;i<T;i++)
        {
            String name=sc.next();
            int n=sc.nextInt();
            int L=name.length();
            int ans=0;
            int tempn;
            for(int j=0;j<L;j++)
            {
                tempn=n;
                while(tempn+j<=L)
                {
                if(test(name.substring(j,j+tempn),n))
                {
                    ans++;
                    //System.out.println(name.substring(j,j+tempn)+" "+test(name.substring(j,j+tempn),n)+" "+ans);      
                }
                    tempn++;
                }
            }
            
           // System.out.println(name+" "+n);
           out.write("Case #"+(i+1)+": "+ans+"\n");
           System.out.println("Case #"+(i+1)+": "+ans);
            
        }
    }
    catch(Exception e)
    {
        e.printStackTrace();
    }
    finally
    {
        out.close();
    }        
}
static boolean test(String name,int n)
{
    int cnt=0;
    for(int i=0;i<name.length();i++)
    {
        if(name.charAt(i)!='a' &&name.charAt(i)!='e' &&name.charAt(i)!='i' &&name.charAt(i)!='o' &&name.charAt(i)!='u')
            cnt++;
        else
            cnt=0;
        
        if(cnt>=n)
            return true;
    }
    return false;
}
}