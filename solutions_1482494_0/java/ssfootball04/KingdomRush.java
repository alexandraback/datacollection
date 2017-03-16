import java.io.*;
public class KingdomRush
{
    public void KingdomRush()throws IOException
    {
         FileInputStream fstream = new FileInputStream("C:/Users/m.l/Desktop/B-small-attempt1.in"); 
          DataInputStream in = new DataInputStream(fstream);
          BufferedReader br = new BufferedReader(new InputStreamReader(in));
          int T=Integer.parseInt(br.readLine());
          int i,j,k,l,p,q,N,stars,levels;String input;
          for(i=0;i<T;i++)
          {
              N=Integer.parseInt(br.readLine());stars=0;levels=0;
              int a[]=new int[N];int b[]=new int[N];
              for(k=0;k<N;k++)
              {
                  input=br.readLine();l=input.length();
                  for(j=0;j<l;j++)
              {
                if(input.charAt(j)==' ')
                {a[k]=Integer.parseInt(input.substring(0,j));break;}
              }
              b[k]=Integer.parseInt(input.substring(j+1));}
              for(p=0;;p++)
          {    
                   for(q=0;;q++) 
              {  for(j=0;j<N;j++)
                {
                  for(k=0;k<N;k++)
                  if(b[k]<b[j])
                  break;
                  if(k==N)
                  break;
                }
               if(stars>=b[j])
               {
                   levels+=1;
                   b[j]=10000;
                   if(a[j]==10000)
                   stars+=1;
                   else
                   {stars+=2;a[j]=10000;}
                }
                else
                break;
            }
              
              for(j=0;j<N;j++)
              {
                  for(k=0;k<N;k++)
                  if(a[k]<a[j])
                  break;
                  if(k==N)
                  break;
                }
               if(a[j]==10000)
               {System.out.println("Case #"+(i+1)+": "+levels);break;}
                if(stars<a[j])
               {System.out.println("Case #"+(i+1)+": Too Bad");break;}
               a[j]=10000;stars+=1;levels+=1;
            }  
            }
        }
    }