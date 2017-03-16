package round1c;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class problemA {
	
	private static int inst;

	public static void main(String[] args) {

        //String input = "/home/nikos/input";
        String input = "/home/nikos/A-small-attempt0 (1).in";
        String output = "/home/nikos/output";
		try {
            Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                checkInsatnce(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
        	ex.printStackTrace();
        } catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static void checkInsatnce(Scanner sc, PrintWriter pw) throws IOException {
		String l = sc.nextLine();
		StringTokenizer tok = new StringTokenizer(l);
		String name=tok.nextToken();
		int n = Integer.parseInt(tok.nextToken());
		//System.out.println(name+" "+n);
        
		char[] c = name.toCharArray();
		int res=0, lastbegin=0;
		for (int i = 0; i < c.length-n+1; i++) {
			int found=0;
			//System.out.println("check: "+c[i]);
			for (int j = 0; j < n; j++) {
				if(isConsonants(c[i+j])){
					found++;
				}
			}
			if(found==n){
		    	//System.out.println(i-lastbegin+1);
		    	//System.out.println(c.length-(i+n)+1);
				res+=(i-lastbegin+1)*(c.length-(i+n)+1);
				lastbegin=i+1;
			}
				
		}
		
    	System.out.println(res);
    	pw.print(res);
    	
    	
    		
        
		
	}

	private static boolean isConsonants(char c) {
		return (c!='a' && c!='e' && c!='i' && c!='o' &&c!='u') ;
	}

}
