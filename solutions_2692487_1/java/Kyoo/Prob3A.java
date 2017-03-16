package Codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;

/**
 *
 * @author Kyoo
 */
public class Prob3A {
    public static void main(String[] args) throws IOException {
        BufferedReader leer= new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(leer.readLine());
        for (int i = 1; i <= T; i++) {
            String[] d=leer.readLine().trim().split(" ");
            long A=Long.parseLong(d[0]);
            int N=Integer.parseInt(d[1]);
            long[] B= new long[N];
            d=leer.readLine().trim().split(" ");
            for (int j = 0; j < N; j++)
                B[j]=Integer.parseInt(d[j]);
            long respuesta=resolver(A,B);
            System.out.println("Case #"+i+": "+respuesta);
        }
    }

    private static long resolver(long A, long[] B) {
        Arrays.sort(B);
        TreeMap<Long,Integer> sol= new TreeMap<>();
        sol.put(0L, B.length);
        long c=0;
        for (int i = 0; i < B.length&& A>1; i++) {
            if(A>B[i]){
                A+=B[i];
                sol.put(c, B.length-i-1);
            }
            else{
                A+=A-1;
                i--;
                c++;
            }
        }
        long min=B.length;
        for(Map.Entry<Long,Integer> e :sol.entrySet()){
            if(e.getKey()+e.getValue()<min)
                min=e.getKey()+e.getValue();
        }
        return min;
    }
}