import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Arrays;

public class A
{
    public static void solve() throws Exception
    {
        PrintWriter out =new PrintWriter(new File("A-small.out"));
        Scanner s =new Scanner(new File("A-small.in"));
        int testCase=s.nextInt();
        for (int i = 1; i <= testCase; i++)
        {
           int x1=0;
           int y1=0;
           int x = s.nextInt();
           int y = s.nextInt();
           String ans= new String();
           for(int j=1; j<500; j++)
           {
               if(x1==x && y1==y)
               {
                   break;
               }
               else if(x1 < x && (x - x1) == j)
               {
                   x1+=j;
                   ans=ans+"E";
                 
               }
                else if(y1 < y && (y - y1) == j)
               {
                   y1+=j;
                   ans=ans+"N";
                   
               }
                else if(x1 > x && (x1 - x) == j)
               {
                   x1-=j;
                   ans=ans+"W";
                   
               }
               else if(y1 > y && (y1 - y) == j)
               {
                   y1-=j;
                   ans=ans+"S";
                  
               }

               else if(x1 < x && (x - x1) > j)
               {
                   x1+=j;
                   ans=ans+"E";
                   
               }
               else if(x1<x && (x-x1)<j)
               {
                   x1-=j;
                   ans=ans+"W";
                  
               }
               else if(y1<y && (y-y1)>j)
               {
                   y1+=j;
                   ans=ans+"N";
                   
               }
               else if(y1<y && (y-y1)<j)
               {
                   y1-=j;
                   ans=ans+"S";
                  
               }
               else if(x1>x && (x1-x)>j)
               {
                   x1-=j;
                   ans=ans+"W";
                  
               }
               else if(x1>x && (x1-x)<j)
               {
                   x1+=j;
                   ans=ans+"E";
                  
               }
               else if(y1>y && (y1-y)>j)
               {
                   y1-=j;
                   ans=ans+"S";
                   
               }
               else if(y1>y && (y1-y)<j)
               {
                   y1+=j;
                   ans=ans+"N";
                   
               }
                
           }
           
           out.println("Case #"+ i +":" + " "+ ans);
        }
out.close();
    }


    public static void main(String[] args) throws Exception
    {
    solve();
            }


}