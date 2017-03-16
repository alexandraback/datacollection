
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



/**
 *
 * @author Deep
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        try
        {
            BufferedReader in = new BufferedReader(new FileReader(args[0]));
            FileWriter fw = new FileWriter("output.out");
            int T = Integer.parseInt(in.readLine());
            String str, Arr[];
            String name;
            int len;
            int cnt;
            for(int i=0;i<T;i++)
            {
            	str = in.readLine();
            	Arr = str.split(" ");
            	len = Integer.parseInt(Arr[1]);
            	name = Arr[0];
            //	System.out.println(name.length()+" "+len);
            	cnt = 0;
            	for(int j=len; j<=name.length();j++)
            	{
            		for(int k=0;k<=name.length()-j; k++)
            		{
            			int temp = 0;
            			for(int m=0;m<j;m++)
            			{
            			//	System.out.println(j + " "+ k + " "+ m);
            				//System.out.println(name.charAt(k+m));
            				if(name.charAt(k+m)!= 'a' && name.charAt(k+m)!= 'e' && name.charAt(k+m)!= 'i' && name.charAt(k+m)!= 'o' && name.charAt(k+m)!= 'u')
            				{
            	//				System.out.println("valid");
            					temp++;
            					if(temp==len)
            						break;
            				}
            				else
            					temp = 0;
            			}
            			if(temp==len)
            				cnt++;
            		}
            	}
            	fw.write("Case #"+(i+1)+": "+cnt+"\r\n");
            }
            fw.close();
            in.close();
        }
        catch(Exception e)
        {

        }
    }
}
