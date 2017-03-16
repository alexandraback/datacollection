import java.util.*;
import java.io.*;

public class Main {

	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2014/io/D-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("../GoogleCodeJam2014/io/output.txt"));
		int n = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < n ; i++){
			int bk = Integer.parseInt(input.readLine());
        	String[] st = input.readLine().split(" ");
        	String[] st2 = input.readLine().split(" ");
        	double[] naomi = new double[bk];
        	double[] ken = new double[bk];
        	for(int j = 0 ; j < bk ; j++){
        		naomi[j] = Double.parseDouble(st[j]);
        		ken[j] = Double.parseDouble(st2[j]);
        	}
        	Arrays.sort(naomi);
        	Arrays.sort(ken);
	        pw.print("Case #"+(i+1)+": "+naoken(naomi,ken,bk));
	        pw.println();
			pw.flush();
		}
		input.close();
		pw.close();
	}
	
	public static String naoken(double[] naomi,double[] ken,int length){
		int windex = length-1;
		int lindex = 0;
		int wincount = 0;
		for(int i = length-1 ; i >= 0 ; i--){
			if(naomi[i] > ken[windex]){
				lindex++;
				wincount++;
			}else{
				windex--;
			}
		}
		windex = length-1;
		lindex = 0;
		int dwincount = 0;
		for(int i = 0 ; i < length ; i++){
			if(naomi[i] < ken[lindex]){
				windex--;
			}else{
				lindex++;
				dwincount++;
			}
		}
		return dwincount+" "+wincount;
	}
}