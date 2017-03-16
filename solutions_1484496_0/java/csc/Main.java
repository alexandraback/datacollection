package tw.csc.gcj;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;

public class Main {

	/**
	 * @param args
	 */
	

	public static void main(String[] args) {
		
		try {
			goC();
		} catch (Exception e) {

		}
	}
	public static void goC() throws NumberFormatException, IOException{
		File fin = new File("C-small-attempt0.in");
		File fout = new File("C-small-attempt0.out");		
		BufferedReader br = new BufferedReader(new FileReader(fin));
		FileOutputStream fos = new FileOutputStream(fout);
		int c = Integer.parseInt(br.readLine());
		String op = "";		
		for (int i = 0 ; i < c ;i ++ ){
			op+="Case #"+ (i+1)+":\n";
			String[] str = br.readLine().split("[ ]");
			 int n = Integer.parseInt(str[0]);
			 ArrayList<Integer> mainset = new ArrayList<Integer>();
			 for (int k = 0 ; k < n ;k ++ ){
				 mainset.add(Integer.parseInt(str[k+1]));
			 }			
			 long max = (long)Math.pow(2,n);
			 HashMap<Long, HashSet<Integer>> map = new HashMap<Long, HashSet<Integer>>();  
			 for ( long setkey = 1; setkey< max;setkey++ ){
				 
				 HashSet<Integer> sset = new HashSet<Integer>();
				 long tt = 0;
				 for (int m = 0 ; m < n ; m ++){
					 if ((setkey >> m) % 2 == 1){
						 sset.add(mainset.get(m));
						 tt += mainset.get(m);
					 }
				 }
				 if (map.get(tt) != null){
					 for (int val : sset){
						 op+= val +" ";
					 }
					 op += "\n";
					 HashSet<Integer> sset2 = map.get(tt);
					 for (int val : sset2){
						 op+= val +" ";
					 }
					 op += "\n";					 
					 break;
				 }
				 else{
					 map.put(tt, sset);					 
				 }
			 }
			 //op+="\n";
		}
		fos.write(op.getBytes());
		fos.close();
	}
	
	public static void goA() throws NumberFormatException, IOException{
		File fin = new File("A-large.in");
		File fout = new File("A-large.out");		
		BufferedReader br = new BufferedReader(new FileReader(fin));
		FileOutputStream fos = new FileOutputStream(fout);
		int c = Integer.parseInt(br.readLine());
		String op = "";		
		for (int i = 0 ; i < c ;i ++ ){
			op+="Case #"+ (i+1)+": ";
			String[] str = br.readLine().split("[ ]");
			 int n = Integer.parseInt(str[0]);
			 HashMap<Integer, Integer> scr = new HashMap<Integer, Integer>();
			 ArrayList<Integer> arr = new ArrayList<Integer>(); 
			 int tts = 0; 
			 double[][] mat = new double[n][n];
			 for (int k = 0 ; k < n ;k ++ ){
				 int sk = Integer.parseInt(str[k+1]);
				 scr.put(k, sk);
				 tts += sk;
			 }
			 arr.addAll(scr.values());
			 Collections.sort(arr);
			 HashMap<Integer, Double> res = new HashMap<Integer, Double>();
			 int rem = tts;
			 for (int k = 0 ; k < n ;k ++ ){
				 int d;
				 if (k == n-1){
					 for (int t = 0 ; t < n ;t ++ ){
						 mat[k][t] = (double)rem/(double)n;
					 }
				 }
				 else{
					 d = arr.get(k+1) - arr.get(k);
					 if (rem > d * (k+1)){
						 for (int t = 0 ; t <= k ;t ++ ){
							 mat[k][t] = d; 								 					 
						 }	 				
						 rem -= d * (k+1);
					 }
					 else{
						 for (int t = 0 ; t <= k ;t ++ ){
							 mat[k][t] =  (double)rem / (double) (k+1);
						 }
						 break;
					 }
				 }				 
			 }
			 for (int k = 0 ; k < n ;k ++ ){
				 int idx = arr.indexOf(scr.get(k));
				 double ttr = 0;
				 for (int t = 0 ; t < n ;t ++ ){
					 ttr += mat[t][idx];
				 }
				 
				 op+= (100*ttr / (double)tts) + " ";
			 }
			 op+="\n";
		}
		fos.write(op.getBytes());
		fos.close();
	}
	

	
}
