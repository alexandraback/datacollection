import java.io.*;
import java.util.*;
class Problem1
{
    public static void main (String [] args) throws Exception 
    {
        BufferedReader f = new BufferedReader(new FileReader("input.java"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.java")));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int T=Integer.parseInt(st.nextToken());
        for(int t=0;t<T;t++) {
            st=new StringTokenizer(f.readLine());
            int A=Integer.parseInt(st.nextToken());
            int B=Integer.parseInt(st.nextToken());
            double[] probs=new double[A];
            st=new StringTokenizer(f.readLine());
            for(int i=0;i<A;i++) {
                probs[i]=Double.parseDouble(st.nextToken());
            }
            double currProb=1;
            double pressEnter=2+B;
            double[] numBackspaces=new double[A+1];
            for(int i=0;i<=A;i++) {
                if(i>0) currProb*=probs[i-1];
                for(int j=0;j<=A;j++) {
                    if(j<A-i) {
                        if(i<A) 
                            numBackspaces[j]+=currProb*(1-probs[i])*(2*j+2*B-A+2);
                        else
                            numBackspaces[j]+=currProb*(2*j+2*B-A+2);
                    } else {
                        if(i<A) 
                            numBackspaces[j]+=currProb*(1-probs[i])*(2*j+B-A+1);
                        else
                            numBackspaces[j]+=currProb*(2*j+B-A+1);
                    }
                }
            }
            double ans=Integer.MAX_VALUE;
            for(int i=0;i<=A;i++) {
                ans=Math.min(ans,numBackspaces[i]);
            }
            ans=Math.min(ans,pressEnter);
            out.println("Case #"+(t+1)+": "+ans);
        }
        out.close();
        System.exit(0);
    }
}