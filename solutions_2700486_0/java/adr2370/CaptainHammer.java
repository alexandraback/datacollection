import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
public class CaptainHammer
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        FileWriter out = new FileWriter(new File("out.txt"));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int Z = Integer.parseInt(st.nextToken());
        for(int z = 1; z <= Z; z++)
        {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int X = Integer.parseInt(st.nextToken());
            int Y = Integer.parseInt(st.nextToken());
            int val=(int)(1.0/4*(Math.sqrt(8*N+1)+1));
            if((Math.abs(X)+Math.abs(Y))%2!=0||Math.abs(X)+Math.abs(Y)>2*val||Y<0) {
                double ans=0.0;
                System.out.println("Case #" +z+ ": " +ans+" Path 3");
                out.write("Case #" +z+ ": " +ans +"\n");
            } else if(Math.abs(X)+Math.abs(Y)<2*val) {
                double ans=1.0;
                System.out.println("Case #" +z+ ": " +ans+" Path 4");
                out.write("Case #" +z+ ": " +ans +"\n");
            } else if(X==0) {
                double ans=0.0;
                System.out.println("Case #" +z+ ": " +ans+" Path 5");
                out.write("Case #" +z+ ": " +ans +"\n");
            } else {
                int leftOver=N-val*(2*val-1);
                int half=(4*val+1)/2;
                if(leftOver<=0) {
                    double ans=0.0;
                    System.out.println("Case #" +z+ ": " +ans+" Path 6");
                    out.write("Case #" +z+ ": " +ans +"\n");
                } else if(leftOver>half) {
                    double ans=0.0;
                    if(leftOver>Y) {
                        ans=chooseSum(leftOver,Y,half);
                    }
                    System.out.println("Case #" +z+ ": " +ans+" Path 1");
                    out.write("Case #" +z+ ": " +ans +"\n");
                } else {
                    double ans=0.0;
                    if(leftOver>Y) {
                        ans=chooseSum(leftOver,Y,half);
                    }
                    System.out.println("Case #" +z+ ": " +ans+" Path 2");
                    out.write("Case #" +z+ ": " +ans +"\n");
                }
            }
        }
        out.close();
    }
    public static double chooseSum(int L,int N,int H) {
        int start=0;
        start=Math.max(start,L-H);
        int end=L-N-1;
        if(start>end) return 1.0;
        double curr=1.0;
        double starting=curr;
        double remove=0.0;
        for(int i=0;i<end;i++) {
            curr*=(L-i);
            curr/=(i+1);
            if(i==start-1) {
                remove=starting;
                starting=0;
            }
            starting+=curr;
        }
        starting/=Math.pow(2,L)-remove*2;
        if(starting>1.0) return 1.0;
        return starting;
    }
}