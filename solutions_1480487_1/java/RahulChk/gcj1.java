import java.io.*;
import java.util.*;
import java.lang.Math.*;
public class gcj1 
{
   

     public static void main(String args[])throws Exception
     {
         //Scanner in=new Scanner(System.in);
         //BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
         
         //PrintWriter pw = new PrintWriter(System.out);
         StringTokenizer st;
BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\rahul\\Desktop\\gcj1.in"));
PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\rahul\\Desktop\\gcj1.out")));
         int t=Integer.parseInt(br.readLine()),ctr=0;
         while(t>0)
         {
             t--;
             ctr++;
             st=new StringTokenizer(br.readLine());
             int n=Integer.parseInt(st.nextToken());
             int a[]=new int[n];
             int inp[]=new int[n];
             int i,j;
             double sum=0.0,amt=0.0;
             for(i=0;i<n;i++)
             {
                 inp[i]=Integer.parseInt(st.nextToken());
                 a[i]=inp[i];
                 sum+=a[i]+0.0;
              }
              double org=sum;
                Arrays.sort(a);
             double b[]=new double[n];
             
             for(i=n-1;i>0;i--)
             {
                 amt=0.0;
                 for(j=0;j<i;j++)
                 {
                     amt+=0.0+a[i]-a[j];
                     
                    }
                    if(amt>sum)
                    {
                        b[i]=0.00;
                    }
                    else
                    {
                        amt=sum-amt;
                        
                            b[i]+=amt/(double)(i+1);
                           sum-=b[i];
                        b[i]=b[i]/org;
                    }
                    
                }
             
             
             
             b[0]=sum/org;
             double c[]=new double[200];
             pw.print("Case #"+ctr+":");
             for(i=0;i<n;i++)
             {
                 c[a[i]]=b[i];
                }
                for(i=0;i<n;i++)
                {
                pw.print(" "+(c[inp[i]]*100));
                }
                pw.println();
            }
            pw.flush();
     }
}