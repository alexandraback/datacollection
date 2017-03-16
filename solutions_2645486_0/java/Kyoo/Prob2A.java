/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;

/**
 *
 * @author Kyoo
 */
public class Prob2A {
    //static int[] x= new int[10];
    public static void main(String[] args) throws IOException {
        BufferedReader leer= new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(leer.readLine());
        for (int i = 1; i <= T; i++) {
            System.out.print("Case #"+i+": ");
            String[] rango=leer.readLine().trim().split(" ");
            int E=Integer.parseInt(rango[0]);
            int R=Integer.parseInt(rango[1]);
            int N=Integer.parseInt(rango[2]);
            String[] sDatos=leer.readLine().trim().split(" ");
            int[] V= new int[N];
            for (int j = 0; j < N; j++)
                V[j]=Integer.parseInt(sDatos[j]);
            int max=resolver(E,R,V);
            System.out.println(max);
        }
    }
    private static int resolver(int E, int R, int[] V) {
        return dfs(0,V,E,R,0,E);
    }
    private static int dfs(int i,int[] V,int act,int R, int acum,int E){
        if(i==V.length){
            //System.out.println(Arrays.toString(x)+" "+acum);
            return acum;
        }
        int max=0;
        for (int j = 0; j <= act; j++) {
            //x[i]=j;
            max= Math.max(dfs(i+1,V,act-j+R>E?E:act-j+R,R,acum+V[i]*j,E),max);
        }
        return max;
    }

}