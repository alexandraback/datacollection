import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class B{
    public static void main(String[] args) throws Exception{
        new B().run();
    }

    int h, w;
    int[][] f;
    boolean[][] checked;

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            System.out.printf("Case #%d: ", o);
            h = sc.nextInt();
            w = sc.nextInt();
            f = new int[h][w];
            for(int i = 0; i < h; i++)
                for(int j = 0; j < w; j++)
                    f[i][j] = sc.nextInt();
            checked = new boolean[h][w];
            for(int a = 1; a < 100; a++){
                for(int i = 0; i < h; i++)
                    for(int j = 0; j < w; j++)
                        if(f[i][j] == a && !checked[i][j]){
                            // horizontal
                            boolean ok = true;
                            for(int k = 0; k < w; k++)
                                if(f[i][k] != a && !checked[i][k]){
                                    ok = false;
                                    break;
                                }
                            if(ok){
                                for(int k = 0; k < w; k++)
                                    checked[i][k] = true;
                            }
                            // vertical
                            ok = true;
                            for(int k = 0; k < h; k++)
                                if(f[k][j] != a && !checked[k][j]){
                                    ok = false;
                                    break;
                                }
                            if(ok){
                                for(int k = 0; k < h; k++)
                                    checked[k][j] = true;
                            }
                        }
            }
            boolean ok = true;
            for(int i = 0; i < h; i++)
                for(int j = 0; j < w; j++)
                    if(f[i][j] != 100 && !checked[i][j])
                        ok = false;
            System.out.println(ok ? "YES" : "NO");
        }
    }
}
