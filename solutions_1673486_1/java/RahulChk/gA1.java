import java.io.*;
import java.util.*;
import java.lang.Math.*;
public class gA1
{
     public static void main(String args[])throws Exception
     {
         //Scanner in=new Scanner(System.in);
         //BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
         //PrintWriter pw = new PrintWriter(System.out);
         StringTokenizer st;
         //Scanner in=new Scanner(new FileReader("C:\\Users\\Desktop\\gA1.in"))
         BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\rahul\\Desktop\\gA1.in"));
         PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\rahul\\Desktop\\gA1.out")));
         
         int i,j,k,l,n,m,ctr=0;
         int t=Integer.parseInt(br.readLine());
         
         while(t>0)
         {
             t--;ctr++;
             st=new StringTokenizer(br.readLine());
             
             m=Integer.parseInt(st.nextToken());
             n=Integer.parseInt(st.nextToken());
             
             
             
             st=new StringTokenizer(br.readLine());
             double p[]=new double[m];
             for(i=0;i<m;i++)
             {
                 p[i]=Double.parseDouble(st.nextToken());
                }
                
             
                
                
             double b[]=new double[m];
             b[0]=p[0];
             for(i=1;i<m;i++)
             {
                 b[i]=b[i-1]*p[i];
                }
             double a[][]=new double[m][3];
             for(i=0;i<m;i++)
             {
                a[i][0]=1-b[i];a[i][1]=b[i];
                }
             for(i=0;i<m;i++)
             {
                 a[i][0]*=m+2*n-2*i;
                 a[i][1]*=m+n-2*i-1;
                 a[i][2]=a[i][0]+a[i][1];
             }
             double min=9999999999.000000;
             for(i=0;i<m;i++)
             {
                 if(min>a[i][2])
                 {
                     min=a[i][2];
                     
                    }
                }
             if(min> (m+n+1))
             min=(2*m+n+1);
             
             if(min> (n+2))
             min=n+2;
             
             //pw.println("Hello");
             pw.println("Case #"+ctr+": "+min);
            }
         
         pw.flush();
         pw.close();
     }
}