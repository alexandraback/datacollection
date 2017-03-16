import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Recycled {
	public static void main(String args[]) {
		try{
		     BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			 BufferedWriter out = new BufferedWriter(new FileWriter("C-small.out"));
			
			 String line = in.readLine();
			 int caseCount = Integer.parseInt(line);
			 
			 StringBuffer outputWriter = new StringBuffer();
			 
			 int lowCap, hiCap, digitCt, recycled, resultCount;
			 ArrayList<String> collisionHelper; 
			 
			 //caseCount = 3;
			 for(int i = 1; i <= caseCount; i++){
				 line = in.readLine();
				 Scanner s = new Scanner(line);
				 lowCap = s.nextInt();
				 hiCap = s.nextInt();

				 digitCt = ("" + lowCap).length();

				 resultCount = 0;
				 
				 for(int j = lowCap; j <= hiCap; j++){
					 collisionHelper = null;
					 for(int k = 1; k < digitCt; k++){
						 recycled = cutAndSwap(j, k);
						 if(recycled > j && recycled <= hiCap){
							 if(collisionHelper == null){
								 collisionHelper = new ArrayList<String>();
								 collisionHelper.add("" + recycled);
								 resultCount++;
							 } else if(!collisionHelper.contains("" + recycled)){
								 collisionHelper.add("" + recycled);
								 resultCount++;
							 }
							 
							 //System.out.println(resultCount + " " + j + " " + recycled + " " + k);
						 }
					 }
				 }
				 
				 outputWriter.append("Case #" + i + ": ");
				 outputWriter.append(resultCount);
				 if(i != caseCount)
					 outputWriter.append("\n");
			 }

			 out.write(outputWriter.toString()); 
			 System.out.println(outputWriter.toString());
			 
			 in.close();
			 out.close();
		} catch(Exception e){
			//swallow the exception
		}		
	}
	
	//assumes 0 < position < digits in number
	public static int cutAndSwap(int number, int position){
		String s = "" + number;
		String halfOne = s.substring(0, position);
		String halfTwo = s.substring(position);
		
		return Integer.parseInt(halfTwo + halfOne);
	}
}
