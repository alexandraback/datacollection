import java.io.*;
class consonants
{
       int n;
  void main()throws IOException
  {
      BufferedReader obj= new BufferedReader(new FileReader("A-small-attempt0.in"));
      PrintWriter P= new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
      int c,k,tt;
      int T = Integer.parseInt(obj.readLine());
      String s,cs;
      n=0;
      for(int t=1;t<=T;t++)
      {
          c=0;
          s="";
          cs="";
       s=obj.readLine();
       for(k=0;k<s.length();k++)
       {  if(s.charAt(k)==' ')
            { n=Integer.parseInt(s.substring(k+1,s.length()));
             tt=n;
              s=s.substring(0,k);
              break;
             }
            }

       
       for(tt=n;tt<=s.length();tt++)
       {
       for(k=0;k<=s.length()-tt;k++)
       {
           cs=s.substring(k,k+tt);
           c+=cf(cs);
           
           
        }
    }
        
        P.println("Case #"+t+": "+c);
    }
    P.flush();
    P.close();
}

int cf(String a)
 {
     int c=0;
     int k,flag=0,j;
     for(j=0;j<=a.length()-n;j++)
       {
           flag=0;
          
           for(k=j;k<j+n;k++)
             { if(a.charAt(k)=='a'||a.charAt(k)=='e'||a.charAt(k)=='i'||a.charAt(k)=='o'||a.charAt(k)=='u')
              {
                  flag=1;
                }
            }
            
            if(flag==0)
            {
                c=1;
            }
        }
        
        return c;
    }
}
                
            
     
     
  