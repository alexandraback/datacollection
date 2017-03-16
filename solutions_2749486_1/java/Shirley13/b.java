import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Arrays;

public class b
{
    public static void solution() throws Exception
    {
        PrintWriter out =new PrintWriter(new File("b-small.out"));
        Scanner s =new Scanner(new File("B-large.in"));
        int testCase=s.nextInt();
        for (int i = 1; i <= testCase; i++)
        {
           int p=0;
           int q=0;
           int x = s.nextInt();
           int y = s.nextInt();
           String ans= new String();
           for(int j=1; j<500; j++)
           {
               if(p==x && q==y)
               {break;
               }
               else if(p < x && (x - p) == j)
               {p+=j;
                   ans=ans+"E";
               }
                else if(q < y && (y - q) == j)
               { q+=j;
                   ans=ans+"N";
                }
                else if(p > x && (p - x) == j)
               {p-=j;
                   ans=ans+"W";
                }
               else if(q > y && (q - y) == j)
               { q-=j;
                   ans=ans+"S";
                }
               else if(p < x && (x - p) > j)
               {p+=j;
                   ans=ans+"E";
                 }
               else if(p<x && (x-p)<j)
               { p-=j;
                   ans=ans+"W";
               }
               else if(q<y && (y-q)>j)
               { q+=j;
                   ans=ans+"N";
                 }
               else if(q<y && (y-q)<j)
               { q-=j;
                   ans=ans+"S";
                }
               else if(p>x && (p-x)>j)
               { p-=j;
                   ans=ans+"W";
                 }
               else if(p>x && (p-x)<j)
               { p+=j;
                   ans=ans+"E";
                  
               }
               else if(q>y && (q-y)>j)
               { q-=j;
                   ans=ans+"S";
               }
               else if(q>y && (q-y)<j)
               { q+=j;
                   ans=ans+"N";
                }}
           
           out.println("Case #"+ i +":" + " "+ ans);
        }
out.close();
    }
    public static void main(String[] args) throws Exception
    {
    solution();
   }
}