
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
            int X, Y;
            int len;
            String dir;
            for(int i=0;i<T;i++)
            {
            	str = in.readLine();
            	Arr = str.split(" ");
            	dir = "";
            	X= Integer.parseInt(Arr[0]);
            	Y= Integer.parseInt(Arr[1]);
            	int a=0,b=0,cnt=1;
            	while(true && X!=0)
            	{

            		if(a+cnt <= X)
            		{
            			a = a+cnt;
            			dir = dir+"E";
            			if(a==X)
            			{
            				cnt++;
            				break;
            			}
            		}
            		else
            		{
            			a= a- cnt;
            			dir = dir+"W";
            			if(a==X)
            			{
            				cnt++;
            				break;
            			}
            		}
            		System.out.println(a);
            		cnt++;
            			
            	}
            	
            	while(true && Y!=0)
            	{

            		if(b+cnt <= Y)
            		{
            			b = b+cnt;
            			dir = dir+"N";
            			if(b==Y)
            			{
            				cnt++;
            				break;
            			}
            		}
            		else
            		{
            			b= b- cnt;
            			dir = dir+"S";
            			if(b==Y)
            			{
            				cnt++;
            				break;
            			}
            		}
            		cnt++;
            		System.out.println(b);
            			
            	}
            	fw.write("Case #"+(i+1)+": "+dir+"\r\n");
            }
            fw.close();
            in.close();
        }
        catch(Exception e)
        {

        }
    }
}
