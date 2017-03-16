import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
public class ProblemA {
    public static void main(String[] args) throws IOException {
        BufferedReader leer= new BufferedReader(new InputStreamReader(System.in));
        int T=Int(leer.readLine());
        for (int i = 1; i <= T; i++) {
            int N=Int(leer.readLine());
            boolean[][] clases= new boolean[N+1][N+1];
            for (int j = 1; j <= N; j++) {
                StringTokenizer st= new StringTokenizer(leer.readLine());
                int M=Int(st.nextToken());
                for (int k = 0; k < M; k++) {
                    int val=Int(st.nextToken());
                    clases[val][j]=true;
                }
            }
            if(solve(clases))
                System.out.println("Case #"+i+": Yes");
            else
                System.out.println("Case #"+i+": No");
        }
    }
    public static boolean solve(boolean[][] clases){
        for (int c = 1; c < clases.length; c++) {
            int[] conteo= new int[clases.length];
            recursive(clases,c,conteo);
            for (int i = 0; i < clases.length; i++) {
                if(conteo[i]>1)
                    return true;
            }
        }        
        return false;
    }
    public static void recursive(boolean[][] clases, int inicio, int[] conteo){
        conteo[inicio]++;
        for (int i = 1; i < clases.length; i++) {
            if(clases[inicio][i]){
                recursive(clases,i,conteo);
            }
        }
    }
    public static int Int(String s){
        return Integer.parseInt(s);
    }
}
