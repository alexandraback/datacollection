import java.util.Scanner;

public class R1_A
{
    public static void main(String args[])
    {
        Scanner scan=new Scanner(System.in);
        int T=scan.nextInt();        
        for(int x=1;x<=T;x++)
        {      
            String word="";
            String s=scan.next();
            word=""+s.charAt(0);
            for(int i=1;i<s.length();i++)
            {
                char c=s.charAt(i);
                if((int)c>=(int)word.charAt(0))
                    word=""+c+word;
                else
                    word=word+""+c;
            }
            System.out.println("Case #"+x+": "+word);           
        }
    }
}