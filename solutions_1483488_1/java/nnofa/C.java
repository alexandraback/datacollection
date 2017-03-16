import java.io.*;
import java.util.*;
public class C{
	public static void main(String[] args){
	  try{
		String inputFile = "C-large.in";
		String outputFile = "C-large.out";
		Scanner sc = new Scanner(new File(inputFile));
        FileWriter fwStream = new FileWriter( outputFile );
        BufferedWriter bwStream = new BufferedWriter( fwStream );
        PrintWriter pwStream = new PrintWriter( bwStream );
		int numCase = sc.nextInt();
		for(int i = 0; i < numCase; i++){
			int answer = 0;
			int min = sc.nextInt();
			int max = sc.nextInt();
			for(int j = min; j <= max; j++){
				String a = String.valueOf(j);
				int length = a.length();
				int temp = ((j % 10) * (int)(Math.pow(10,length-1))) + (j /10);
				while(temp != j){
					if(temp >= min && temp <= max && temp > j){
						answer++;
					}
					temp = ((temp % 10) * (int)(Math.pow(10,length-1))) + (temp /10);
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