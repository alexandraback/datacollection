import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class Dancing {
	public static void main(String args[]) {
		try{
		     BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
			 BufferedWriter out = new BufferedWriter(new FileWriter("B-large.out"));
			
			 String line = in.readLine();
			 int caseCount = Integer.parseInt(line);
			 
			 StringBuffer outputWriter = new StringBuffer();
			 
			 int googlerCount, specialCount, bestCutoff, total, best, resultCount;
			 
			 for(int i = 1; i <= caseCount; i++){
				 line = in.readLine();
				 Scanner s = new Scanner(line);
				 googlerCount = s.nextInt();
				 specialCount = s.nextInt();
				 bestCutoff = s.nextInt();

				 resultCount = 0;
				 
				 for(int j = 0; j < googlerCount; j++){
					 total = s.nextInt();
					 best = (total + 2)/3;
					 
					 if(best >= bestCutoff)
						 resultCount++;
					 else if(best == (bestCutoff - 1) && total > 1 && total < 29 ){
						 if(specialCount > 0){
							 if( (total%3) != 1){//potential to specialize)
								 specialCount--;
								 resultCount++;
							 }
						 }
					 }
					 
					 //System.out.println(total + " " + best);
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
}
