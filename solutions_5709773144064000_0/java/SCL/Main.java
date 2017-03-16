import java.util.*;
import java.io.*;

public class Main {

	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2014/io/B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("../GoogleCodeJam2014/io/output.txt"));
		int n = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < n ; i++){
        	String[] st = input.readLine().split(" ");
        	double C = Double.parseDouble(st[0]);
        	double F = Double.parseDouble(st[1]);
        	double X = Double.parseDouble(st[2]);
	        pw.print("Case #"+(i+1)+": "+cookie(C,F,X));
	        pw.println();
			pw.flush();
		}
		input.close();
		pw.close();
	}
	
	public static double cookie(double C, double F, double X){
		double pers = 2;
		double mintime = X/pers;
		double nowtime = 0;
		while(true){
			nowtime += C/pers;
			pers += F;
			double newtime = nowtime + X/pers;
			if(newtime < mintime){
				mintime = newtime;
			}else{
				break;
			}
		}
		return mintime;
	}
}