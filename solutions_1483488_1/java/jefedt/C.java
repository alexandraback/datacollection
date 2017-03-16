	

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.ObjectInputStream.GetField;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.math.BigInteger;

public class C {

    private static char[] alph;
    private static String  fileIN = "./A.in"; //archivo de entrada (en el dir local del programita)
    private static String  fileOUT = "./out.txt"; //salida

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(fileIN));
        PrintWriter out = new PrintWriter(new File(fileOUT));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
         }
        
        
        out.close();
    	//getCombinaciones(1234);
    }
/**
* Retorna la solucion a un caso
**/
    private String solve(Scanner in) {
    	int min, max = 0;
    	min= in.nextInt();
    	max= in.nextInt();
    	int tot = 0;
    	int tot_[] = new int[6];
    	int prov = 0;
    
    	for(int i = min; i< max; i++){
    		for(Integer j: getCombinaciones(i)){
    			//System.out.println(j);
    			if(j>i)
    			if(isValid(j, min, max)) prov++;
    		}
    		tot_[prov]++;
    		tot+= prov;
    		prov =0;
    	}
    /*	for(int i = 0; i < tot_.length; i++){
    		tot-= 
    	}*/
    	
    	return String.valueOf(tot);
    }
    
	private boolean isValid(Integer j, int min, int max) {
		
		return j<=max && j>=min;
	}
	private static List<Integer> getCombinaciones(int i) {
		ArrayList<Integer> l = new ArrayList<Integer>();
		
		String is = String.valueOf(i); 
		String aux = String.valueOf(i);
		if(symetric(is)) return l;
		do{
			aux = aux.charAt(aux.length()-1)+ aux.substring(0, aux.length()-1);
		
			if(aux.charAt(0)!='0')
			l.add(Integer.valueOf(aux));
		}
		while(!is.equals(aux));
		l.remove(l.size()-1);
		
		return l;
	}
	private static boolean symetric(String is) {
		if(is.length() % 2 ==1) return false;
		else return is.substring(0, is.length()/2).equals(is.substring(is.length()/2 + 1, is.length()));
		
	}
	    
    
   
  }

