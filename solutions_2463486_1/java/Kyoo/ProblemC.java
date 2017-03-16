/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;

/**
 *
 * @author Kyoo
 */
public class ProblemC {
    public static void main(String[] args) throws IOException{
        LinkedList<Long> valores=generar(100000000000000L);
        BufferedReader leer= new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(leer.readLine());
        for (int i = 1; i <= T; i++) {
            System.out.print("Case #"+i+": ");
            String[] rango=leer.readLine().trim().split(" ");
            long A=Long.parseLong(rango[0]);
            long B=Long.parseLong(rango[1]);
            
            int n=resolver(A,B,valores);
            System.out.println(n);
        }
    }
    private static int resolver(long A, long B, LinkedList<Long> valores) {
        int indxA=Collections.binarySearch(valores,A-1);
        int indxB=Collections.binarySearch(valores,B);
        indxA=indxA<0?(indxA+1)*-1:indxA+1;
        indxB=indxB<0?(indxB+1)*-1:indxB+1;
        return indxB-indxA;
    }
    private static LinkedList<Long> generar(long l) {
        LinkedList<Long> valores= new LinkedList<>();
        for (long i = 1; i*i <= l; i++)
            if(palindromo(i*i) && palindromo(i))
                valores.add(i*i);
        return valores;
    }
    private static boolean palindromo(long i) {
        StringBuffer sB= new StringBuffer(Long.toString(i));
        return sB.toString().compareTo(sB.reverse().toString())==0;
    }
}
