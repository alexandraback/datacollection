import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class C{
    public static void main(String[] args) throws Exception{
        new C().run();
    }

    int N, M, K;
    int[] ps;
    private static final int LIMIT = 60 * 1000;
    Random rand = new Random(1);

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

        int T = sc.nextInt();
        System.out.printf("Case #1:\n");
        int R = sc.nextInt();
        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();
        ps = new int[K];
        int lim = LIMIT / R;
        int mask = 1<<N;
        for(int o = 0; o < R; o++){
            for(int i = 0; i < K; i++)ps[i] = sc.nextInt();
            long start = System.currentTimeMillis();
            boolean found = false;
            int[] ans = new int[N];
            lim = LIMIT/(R-o);
            while(!found && System.currentTimeMillis()-start <= lim){
                for(int i = 0; i < N; i++)ans[i] = rand.nextInt(M-1)+2;
                HashSet<Integer> hs = new HashSet<Integer>();
                for(int m = 0; m < mask; m++){
                    int p = 1;
                    for(int i = 0; i < N; i++)
                        if(((m>>i)&1)==1)p *= ans[i];
                    hs.add(p);
                }
                boolean ok = true;
                for(int i = 0; i < K; i++)if(!hs.contains(ps[i])){ok = false; break;}
                if(ok){
                    found = true;
                    break;
                }
            }
            for(int i = 0; i < N; i++)System.out.print(ans[i]);
            System.out.println();
        }
    }
}
