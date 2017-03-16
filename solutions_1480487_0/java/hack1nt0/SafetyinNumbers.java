import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created with IntelliJ IDEA.
 * User: DaiYang
 * Date: 12-5-6
 * Time: 上午12:10
 * To change this template use File | Settings | File Templates.
 */
public class SafetyinNumbers {
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new FileReader("test.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("module\\src\\test.out")));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int T = Integer.parseInt(st.nextToken());
        int[] p = new int[200];
        double[] v=new double[200];
        boolean [] vis=new boolean[200];
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(f.readLine());
            int N = Integer.parseInt(st.nextToken());
            double sum=0;
            for (int i = 0; i < N; i++) {
                p[i]=Integer.parseInt(st.nextToken());
                sum+=p[i];
            }
            out.print("Case #"+t+":");
            double remain = sum;
            Arrays.fill(vis,false);
            for (int cnt = 0; cnt < N; ) {
                double ave=  (sum+remain)/(N-cnt);
                int find=0;
                for (int i = 0; i < N; i++) {
                    if(!vis[i]&&p[i]-ave>=1e-5){v[i]=0.0;vis[i]=true;cnt++;remain-=p[i];find=1;}
                }
                if(find==0)
                {
                    for (int i = 0; i < N; i++) {
                        if(vis[i])continue;
                        v[i]=(ave-p[i])/sum*100;
                    }
                    break;
                }
            }
            for (int i = 0; i < N; i++) out.print(" "+v[i]);
            out.println();
        }
        out.close();
        System.exit(0);
    }
}
