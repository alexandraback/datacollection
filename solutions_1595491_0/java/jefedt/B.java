	

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.lang.reflect.Array;
import java.math.BigInteger;

import javax.rmi.CORBA.Util;

public class B {

   
    private static String  fileIN = "./A.in"; //archivo de entrada (en el dir local del programita)
    private static String  fileOUT = "./out.txt"; //salida

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(fileIN));
        PrintWriter out = new PrintWriter(new File(fileOUT));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }
/**
* Retorna la solucion a un caso
**/
    private String solve(Scanner in) {
    	int N = in.nextInt();
    	int S = in.nextInt();
    	int P = in.nextInt();
    	ArrayList<Integer> scores = new ArrayList<Integer>(N);
    	
    	for(int i = 0; i< N; i++){
    		scores.add(in.nextInt());
    	}
    	Collections.sort(scores);
    	
    	int min= 2*(Math.max(P-1, 0)) +P;
    	int minS= 2*(Math.max(P-2, 0)) +P;
    	System.out.println(min);
    	System.out.println(minS);
    	int cant = 0;
    	for(int i = 0; i< N; i++){
    		if(scores.get(N-i-1)>= min) cant++;
    		else if(scores.get(N-i-1)>= minS){
    			S--;
    			if(S<0) break;
    			cant++;
    		}
    	}
    	return String.valueOf(cant);
    
    }

}
