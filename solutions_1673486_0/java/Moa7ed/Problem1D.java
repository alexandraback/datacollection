import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;


public class Problem1D {
	public void write(String m){
		try{
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(m);
			out.close();
		}
		catch (Exception e){//Catch exception if any
			System.err.println("Error: in writing" + e.getMessage());
		}
	}
	public static void main(String[] args) {
		Problem1D r = new Problem1D();
		String result = "";
		try{
			FileInputStream fstream = new FileInputStream("input.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine = br.readLine();
			int cases = Integer.parseInt(strLine);
			for (int i = 0 ; i < cases ; i++){
				String []m = br.readLine().split(" ");
				int x1 = Integer.parseInt(m[0]);
				int x2 = Integer.parseInt(m[1]);
				String []m2 = br.readLine().split(" ");
				double[] numbers = new double [x1];
				for (int k = 0 ; k < x1 ; k++){
					numbers[k] = Double.parseDouble(m2[k]);
				}
				result += "Case #"+(i+1)+": "+r.solve(x1,x2,numbers)+"\n";
			}
			
			in.close();
		}
		catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
	    }
		r.write(result);
	}
	private String solve(int x1 , int x2,double  []numbers) {
		double min = Integer.MAX_VALUE;
		for (int i = 0 ; i <= x1 ; i++){
			double prob = 1;
			for (int j = 0 ; j < i ; j++){
				prob *= numbers[j];
			}
			double exp1 = 0;
			if (i == 0)
				exp1 = x1-i+x2+1;
			else
				exp1 = ((prob*(x2-i+1+(x1-i)))+((1-prob)*(x2-i+1+x2+1+(x1-i)))) ;
			if (exp1 < min)
				min = exp1;
			if (i == x1){
				double exp2 = 0;
				if (x1 < x2)
					exp2 = 1+x2+1;
				else
					exp2= prob*1+(1-prob)*(1+x2+1);
				if (exp2 < min)
					min = exp2;
			}
		}
		
		return min+"";
	}
}
