import java.io.*;
import java.util.*;
public class B{
	public static void main(String[] args){
	  try{
		String inputFile = "B-small-attempt0.in";
		String outputFile = "B-small-attempt0.out";
		Scanner sc = new Scanner(new File(inputFile));
        FileWriter fwStream = new FileWriter( outputFile );
        BufferedWriter bwStream = new BufferedWriter( fwStream );
        PrintWriter pwStream = new PrintWriter( bwStream );
		int numCase = sc.nextInt();
		
		for(int i = 0; i < numCase; i++){
			int numGoogler = sc.nextInt();
			int numSurprising = sc.nextInt();
			int lowLimit = sc.nextInt();
			int[] points = new int[numGoogler];
			for(int j = 0; j < numGoogler; j++){
				points[j] = sc.nextInt(); 
			}
			int answer = 0;
			int surprising = 0;
			for(int j = 0; j <numGoogler; j++){
				if(lowLimit * 3 - 2 <= points[j]) answer++;
				else if((lowLimit * 3) - 4 <= points[j] && surprising < numSurprising && points[j] != 0){
					answer++;
					surprising++;
				}
			}
			pwStream.print("Case #"+(i+1)+ ": ");
			pwStream.print(answer);
			pwStream.println();
		}
		pwStream.close();
		sc.close();
	  }
	  catch(Exception e){e.printStackTrace();}
	}
}