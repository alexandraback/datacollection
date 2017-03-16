import java.io.*;
import java.util.*;
public class A{
	public static void main(String[] args){
	  try{
		String inputFile = "A-small-attempt1.in";
		String outputFile = "A-small-attempt1.out";
		Scanner sc = new Scanner(new File(inputFile));
        FileWriter fwStream = new FileWriter( outputFile );
        BufferedWriter bwStream = new BufferedWriter( fwStream );
        PrintWriter pwStream = new PrintWriter( bwStream );
		int numCase = sc.nextInt();
		for(int i = 0; i < numCase; i++){
			int numContestant = sc.nextInt();
			double[] point = new double[numContestant];
			double totalPoint = 0;
			for(int j =0; j < numContestant;j++){
				point[j] = sc.nextDouble();
				totalPoint+= point[j];
			}
			double min = totalPoint * 2 / numContestant;
			double belowMinContestant = numContestant;
			double totalPoint2 = totalPoint;
			for(int j = 0; j < numContestant; j++){
				if(point[j] < min){
					totalPoint2 += point[j];
				}
				else belowMinContestant--;
			}
			double min2 = totalPoint2 / belowMinContestant;
			double[] answer = new double[numContestant];
			double totalAnswer = 0;
			for(int j = 0; j < numContestant; j++){
				if(point[j] > min) answer[j] = 0;
				else answer[j] = (min2-point[j])/totalPoint * 100;
			}
			pwStream.printf("Case #"+(i+1)+ ": ");
			for(int j = 0; j < numContestant; j++){
				if(j!= numContestant -1)pwStream.printf("%.7f " , answer[j]);
				else pwStream.printf("%.7f" , answer[j]);
			}
			pwStream.println();
		}
		pwStream.close();
		sc.close();
		}
	  catch(Exception e){e.printStackTrace();}
	}
	
}