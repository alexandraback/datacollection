/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Kyoo
 */
public class ProblemC {
    public static void main(String[] args) throws IOException{
        BufferedReader leer= new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(leer.readLine());
        for (int i = 1; i <= T; i++) {
            System.out.print("Case #"+i+": ");
            String[] rango=leer.readLine().trim().split(" ");
            long A=Long.parseLong(rango[0]);
            long B=Long.parseLong(rango[1]);
            int n=resolver(A,B);
            System.out.println(n);
        }
    }
    private static int resolver(long A, long B) {
        int nA=calcular(A-1);
        int nB=calcular(B);
        return nB-nA;
    }

    private static int calcular(long l) {
        int c=0;
        for (long i = 1; i*i <= l; i++)
            if(palindromo(i*i) && palindromo(i))
                c++;
        return c;
    }

    private static boolean palindromo(long i) {
        StringBuffer sB= new StringBuffer(Long.toString(i));
        return sB.toString().compareTo(sB.reverse().toString())==0;
    }
}
