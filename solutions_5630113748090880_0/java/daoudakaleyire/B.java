import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token;
        int t;
        t = Integer.parseInt(br.readLine());
        int N;
        int[][] A = new int[51][51];
        int tp;
        int[] B;
        for(int i = 1; i<=t;i++)
        {
            N = Integer.parseInt(br.readLine());
            B = new int[2501];
            for(int j = 1; j< 2*N;j++){
                token = new StringTokenizer(br.readLine());
                for(int k = 1; k<=N;k++){
                    tp = Integer.parseInt(token.nextToken());
                    B[tp]++;
                }
            }
            System.out.print("Case #"+i+": ");
            for(int j = 1; j<=2500;j++){
                if((B[j]&1)>0){
                    System.out.print(j+" ");
                }
            }
            System.out.println();
        }
    }
}
