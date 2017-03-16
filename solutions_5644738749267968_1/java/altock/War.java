package Qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class War{
	public War(){	
	}
	public void War(String filename) throws NumberFormatException, NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, IOException{
		BufferedReader greyparse = new BufferedReader(new FileReader(filename));
		greyparse.readLine();
		PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
		int thiscase = 1;
		String thisString;
	
		
		while(greyparse.ready()){
			thisString = "Case #" + thiscase + ":";
			Integer N = Integer.valueOf(greyparse.readLine());
			String[] naomiString = greyparse.readLine().split(" ");
			String[] kenString = greyparse.readLine().split(" ");
			Double[] naomi = new Double [N];
			Double[] ken = new Double[N];
			for(int i = 0; i < N; i++){
				naomi[i] = Double.valueOf(naomiString[i]);
				ken[i] = Double.valueOf(kenString[i]);	
			}
			Arrays.sort(ken);
			Arrays.sort(naomi);
			int kenBegin;
			int namBegin;
			int kenEnd;
			int namEnd;
			namBegin = kenBegin = 0;
			namEnd = kenEnd = N-1;
			int cheatwin = 0;
			for(int i = 0; i < N; i++){
				if( ken[kenBegin] > naomi[namBegin]){
					kenEnd--;
					namBegin++;	
				}
				else{
					namBegin++;
					kenBegin++;
					cheatwin++;
				}
					
				
			}
			thisString += " " + cheatwin +  " ";
			namBegin = kenBegin = 0;
			namEnd = kenEnd = N-1;
			int fairwin = 0;
			for(int i = 0; i < N; i++){
				if(naomi[namEnd] > ken[kenEnd]){
					fairwin++;
					namEnd--;
					kenBegin++;
				}
				else{
					kenEnd--;
					namEnd--;
				}
				
			}
			thisString += fairwin;
			
			thiscase++;
			writer.println(thisString);
		}
		writer.close();
	}
	
	/**
	public static void main(String[] args) throws NumberFormatException, NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, IOException{
		War c = new War();
		c.War("src/Qualification/D-large.in");
	}
	*/

}