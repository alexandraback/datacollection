import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

class tree {
    
    public static void main(String args[])throws IOException
    {
        
        BufferedReader b=new BufferedReader(new InputStreamReader(System.in));
        int i,T= Integer.parseInt(b.readLine());
        Scanner s;
        for(i=0;i<T;i++)
        {
            s=new Scanner(b.readLine());
            s.useDelimiter("/");
            int P= s.nextInt();
            int Q=s.nextInt();
            int r= parent((double)P / (double)Q,1);
             if(r>40)
                System.out.println("Case #"+(i+1)+": impossible");
             else           
            System.out.println("Case #"+(i+1)+": "+r);
            
        }
    }
    
    static int parent(double elf,int g)
    {
        if(g>40)
            return 41;
        if(elf*2-1==0)
            return g;
        if(elf*2 - 1 > 0)
        {
            
            if(parent(elf*2-1,g+1)<=40)
                return g;
            else
                return 41; 
            
        }
        else
            return parent(elf*2,g+1);            
        
            
    }
}