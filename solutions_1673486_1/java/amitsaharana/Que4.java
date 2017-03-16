import java.io.*;
import java.util.*;
public class Que4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int z=1; z<=t; z++) {
            StringTokenizer st = new StringTokenizer(br.readLine()," ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine()," ");
            double[] error = new double[a];
            for(int i=0; i<a; i++) 
            {
                error[i] = Double.parseDouble(st.nextToken());
            }
            double[] p = new double[a+1];
            p[0] = 1;
            for(int i=1; i<=a; i++) {
                p[i] = p[i-1]*error[i-1];
            }
            double min = Double.MAX_VALUE;
            for(int i=0; i<=a; i++) 
            {
                double exp1 = a+b-2*i+1;
                double ans1 = p[i]*exp1;
                double exp2 = exp1+b+1;
                double ans2 = (1-p[i])*exp2;
                double ans3 = ans1+ans2;
                if(min>ans3) min = ans3;
                //System.out.println(exp1+" "+p[i]+" "+exp2+" "+(1-p[i])+" "+ans3+" "+min);
                
            }
            if((b+2)< min) min = (b+2);
            
            
            System.out.println("Case #"+z+": "+min);
        }
    }
}
