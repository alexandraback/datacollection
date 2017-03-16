
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.*;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author shivam
 */
public class fairandsquare {
    public static void main(String[]args) throws FileNotFoundException, IOException
    {	PrintWriter kl=new PrintWriter("out.txt");
        BufferedReader n=new BufferedReader(new FileReader("input.txt"));
        int test=Integer.parseInt(n.readLine());
        int[] result=new int[test];
        for(int j=0;j<test;j++)
        {
            StringTokenizer k=new StringTokenizer(n.readLine());
		Double temp=Double.parseDouble(k.nextToken());
            long lower=(int) Math.sqrt(temp);
		if(lower*lower!=temp){lower++;}
            long upper=(int) Math.sqrt(Double.parseDouble(k.nextToken()));
		
            int count=0;
            for(;lower<=upper;lower++)
            {
                if(ispalindrome(lower) && ispalindrome(lower*lower))
	        {	
                    count++;
                }
            }
            result[j]=count;
        }
        for(int s=0;s<test;s++)
        {
            kl.println("Case #"+(s+1)+": "+result[s]);
        }
        kl.close();
        
    }
    static boolean ispalindrome(long n)
    {
        char[] work=(""+n).toCharArray();
        int i=0;
        int j=work.length-1;
        while(i<j)
        {
            if(work[i]==work[j])
            {
                i++;j--;
            }
            else
            {
                return false;
                
            }
        }
        return true;
        
    }
    
}

