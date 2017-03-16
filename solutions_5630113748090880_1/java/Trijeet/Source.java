import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
public class R1_B
{
    public static void main(String args[])
    {
        Scanner scan=new Scanner(System.in);
        int T=scan.nextInt(); 
        ArrayList H=new ArrayList();
        ArrayList C=new ArrayList();
        ArrayList F=new ArrayList();
        for(int x=1;x<=T;x++)
        {
            int N=scan.nextInt();
            for(int i=0;i<(N*(2*N-1));i++)
            {
                int a=scan.nextInt();
                if(!H.contains(a))
                    H.add(a);
                C.add(a);               
            }
            for(int i=0;i<H.size();i++)
            {
                int a=Collections.frequency(C, H.get(i));                
                if(a%2!=0)
                    F.add(H.get(i));
            }
            Collections.sort(F);
            System.out.print("Case #"+x+": ");    
            for(int i=0;i<F.size();i++)
            {
                System.out.print(F.get(i)+" ");
            }
            System.out.println();
		H.clear();
            C.clear();
            F.clear();
        }
    }
}
