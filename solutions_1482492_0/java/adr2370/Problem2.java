import java.io.*;
import java.util.*;
class Problem2
{
    public static void main (String [] args) throws Exception 
    {
        BufferedReader f = new BufferedReader(new FileReader("input.java"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.java")));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int T=Integer.parseInt(st.nextToken());
        for(int t=0;t<T;t++) {
            st=new StringTokenizer(f.readLine());
            double D=Double.parseDouble(st.nextToken());
            int N=Integer.parseInt(st.nextToken());
            int A=Integer.parseInt(st.nextToken());
            double[][] stuff=new double[N][2]; // time, x
            for(int i=0;i<N;i++) {
                st=new StringTokenizer(f.readLine());
                stuff[i][0]=Double.parseDouble(st.nextToken());
                stuff[i][1]=Double.parseDouble(st.nextToken());
            }
            out.println("Case #"+(t+1)+":");
            st=new StringTokenizer(f.readLine());
            for(int i=0;i<A;i++) {
                double acceleration=Double.parseDouble(st.nextToken());
                double time=Math.sqrt(D/0.5/acceleration);
                if(N>1) {
                    double otherCarSpeed=(stuff[1][1]-stuff[0][1])/(stuff[1][0]-stuff[0][0]);
                    double otherTime=(D-stuff[0][1])/otherCarSpeed;
                    out.println(Math.max(time,otherTime));
                } else {
                    out.println(time);
                }
            }
        }
        out.close();
        System.exit(0);
    }
    private static int[] minVertex (double[][] dist, boolean[][] v) {
        double x = Double.MAX_VALUE;
        int[] y = {-1, -1};   // graph not connected, or no unvisited vertices
        for (int i=0; i<dist.length; i++) {
            for(int j=0;j<dist[0].length;j++) {
                if (!v[i][j] && dist[i][j]<x) {
                    y=new int[2];
                    y[0]=i;
                    y[1]=j;
                    x=dist[i][j];
                }
            }
        }
        return y;
    }
}