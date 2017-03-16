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
        up: while(t>0)
        {
            t--;ctr++;
            int n=Integer.parseInt(br.readLine());
            int a[][]=new int[n+1][n+1];
            //int visit[]=new visit[n+1];
            int i,j,k,l;
      
            for(i=1;i<=n;i++)
             {
               st=new StringTokenizer(br.readLine());
               int m=Integer.parseInt(st.nextToken());
               for(j=0;j<m;j++)
               {
                   int val=Integer.parseInt(st.nextToken());
                   a[i][val]=1;
                }
              }
           
             /* for(i=0;i<=n;i++)
              {
                  for(j=0;j<=n;j++)
                  {
                      pw.print(a[i][j]+" ");
                    }
                    pw.println();
                }*/
              
              
              
              for(i=1;i<=n;i++)
              {
                  if(travel(i,a,n))
                  {
                  pw.println("Case #"+ctr+": Yes");
                  continue up;
                  }
              }
              
              pw.println("Case #"+ctr+": No");
         }
         pw.flush();
       }
                
                
                
      public static boolean travel(int x,int a[][],int n)
     {
         int i,j,k,l;
         int visit[]=new int[n+1];
         boolean status=false;
         for(i=1;i<=n;i++)
             {
                 
                 visit[i]=a[x][i];
                }
         
           up: for(i=1;i<=n;i++)
            {
                if(visit[i]==1)
                {
                    
                    for(j=1;j<=n;j++)
                    {
                        if(a[i][j]==1)
                        {
                            
                            
                            if(i!=j && visit[j]>=1)
                            return true;
                            else
                            visit[j]=1;
                        }
                    }
                    visit[i]=2;
                    status=true;
                }
                if(status)
                {
                    status=false;
                    i=0;continue up;
                }
            }
                
            return false;
        }
}