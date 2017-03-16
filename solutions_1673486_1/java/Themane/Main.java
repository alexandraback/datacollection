package codej;

import java.io.*;
public class Main {
    public static void main(String[] args)throws IOException{
        BufferedReader cin=new BufferedReader(new FileReader("A-large.in"));
        PrintWriter cout=new PrintWriter(new BufferedWriter(new FileWriter("out1.txt")));
        String[] in;
        int x,y,a,b,temp;
        double[] p;
        double c,count,tp;
        int t=Integer.parseInt(cin.readLine());
        for(int i=0;i<t;i++){
            in=cin.readLine().split(" ");
            a=Integer.parseInt(in[0]);
            b=Integer.parseInt(in[1]);
            p=new double[a];
            in=cin.readLine().split(" ");
            tp=1.0;
            for(x=0;x<a;x++)
                p[x]=Double.parseDouble(in[x]);
            
            count=b+2;
            for(x=0;x<a;x++){
                tp=1.0;
                for(y=0;y<=x;y++)
                    tp=tp*p[y];
                temp=a-y;
                c=tp*(a-y+b-y+1)+(1-tp)*(a-y+b-y+b+2);
                if(c<count)
                    count=c;
            }
            cout.println("Case #"+(i+1)+": "+count);
        }
        cout.flush();
    }
}
