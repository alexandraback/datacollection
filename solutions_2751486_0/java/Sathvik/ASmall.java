
import java.util.*;
import java.io.*;

class ASmall
{
    static String ip;
    static int n;
    static int ans;
    public static void main(String[] args) throws IOException
    {
        File f=new File("asi.in");
        Scanner sc=new Scanner(f);
        FileWriter fw=new FileWriter("aso.in");
        
        int t=sc.nextInt();
        for(int tab=1;tab<=t;tab++)
        {
            ans=0;
            ip=sc.next();
            n=sc.nextInt();
            
            for(int i=n;i<=ip.length();i++)
            {
                calc(i);
            }
            
            fw.write("Case #"+tab+": "+ans+"\n");
        }
        
        fw.close();
    }
    
    public static void calc(int a)
    {
        
        for(int i=0;i<=ip.length()-a;i++)
        {
            String temp=ip.substring(i,i+a);
            int count=0;
            for(int j=0;j<temp.length();j++)
            {
                char c=temp.charAt(j);
                if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                    count=0;
                else
                    count++;
                if(count==n)
                {
                    ans++;
                    break;
                }
            }
            
        }
    }
}
