import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Stack;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;


public class Problem1B {
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
		Problem1B r = new Problem1B();
		String result = "";
		try{
			FileInputStream fstream = new FileInputStream("input.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine = br.readLine();
			int cases = Integer.parseInt(strLine);
			for (int i = 0 ; i < cases ; i++){
				int x1 = Integer.parseInt(br.readLine());
				int [][] x = new int [x1][3];
				for (int k = 0 ; k < x1 ; k++){
					String[] m = br.readLine().split(" ");
					x[k][0] = Integer.parseInt(m[0]);
					x[k][1] = Integer.parseInt(m[1]);
					x[k][2] = 0;
					
				}
				
				result += "Case #"+(i+1)+": "+r.solve(x)+"\n";
			}
			
			in.close();
		}
		catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
	    }
		r.write(result);
	}
	private String solve(int [][]a) {
		int stars = 0;
		int level = 0;
		int complete = 0;
		while (level < a.length){
			boolean con = true;
			for (int i = 0 ; i < a.length && con; i++){
				if (a[i][2] < 2 && a[i][1] <= stars){
					con = false;
					level++;
					if (a[i][2] == 1)
						stars++;
					else
						stars +=2;
					a[i][2] = 2;
					complete++;
				}
			}
			if (con){
				int index = -1;
				int element = -1;
				for (int i = 0 ; i < a.length ; i++){
					if (a[i][2] < 1 && a[i][0] <= stars){
						con = false;
						if (a[i][1] > element){
							element = a[i][1];
							index = i;
						}
					}
				}
				if (!con){
					stars++;
					a[index][2] = 1;
					complete++;
				}
			}
			if (con){
				return "Too Bad";
			}
		}
		return complete+"";
	}
}
