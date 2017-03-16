	

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.math.BigInteger;

public class A {

    private static char[] alph;
    private static String  fileIN = "./A.in"; //archivo de entrada (en el dir local del programita)
    private static String  fileOUT = "./out.txt"; //salida

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(fileIN));
        PrintWriter out = new PrintWriter(new File(fileOUT));
        A.generateMappingCode();
        int T = in.nextInt();
        in.nextLine();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
         }
        
        
        out.close();
    }
/**
* Retorna la solucion a un caso
**/
    private String solve(Scanner in) {
    	String s,r;
    	s= in.nextLine();
    	r = "";
    	for(int i = 0; i< s.length(); i++){
    		if(s.charAt(i)!= ' ')
    		r+= alph[(s.charAt(i))-('a')];
    		else r+= ' ';
    	}
    return r;
    }
    
    private static void generateMappingCode(){
    
    String googlerse = "zy qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    String eng= "qa zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

    	alph = new char[26];
    	char[] g = googlerse.trim().toCharArray();
    	char[] e = eng.trim().toCharArray();
    	char[] used = new char[26];
    	if (g.length != e.length) System.err.println("errorrr");
    	
    	for(int i = 0; i< g.length; i++){
    		if(g[i] == ' ') continue;
    	//	System.out.println("letras "+ g[i]+ " " + e[i]);
    	//	System.out.println("ints "+  (int)g[i] +" "+ (int)(e[i]));
    		alph[g[i]-('a')] = e[i];
    	}

       	for(int i = 0; i< alph.length; i++){
       		System.out.println(alph[i]+", - " + (char)('a'+ i));
       	}

       	}
    	
    	
    }

