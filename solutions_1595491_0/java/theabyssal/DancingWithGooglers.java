import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class DancingWithGooglers {

	public static void main(String[] args) throws IOException{
		
		String path = "C:\\Users\\Rapol Tongchenchitt\\Documents\\CodeJam\\";
		String year = "Qual2012\\";
		
		String test = "input.txt"; String outPath = "output.txt";
		String a = ""; String A = "";
		String b = "B-small-attempt0.in"; String B = "B-small-attempt0.out";
		String c = ""; String C = "";
		String d = ""; String D = "";
		
		String inName = path+year+b;
		String outName = path+year+B;
		
		Scanner in = new Scanner(new FileInputStream(inName));
		BufferedWriter out = new BufferedWriter(new FileWriter(outName));
		
		int caseCount = in.nextInt(); int currentCase = 0;
		
		while(currentCase++ < caseCount){
			
			int dancerCount = in.nextInt();
			int surpriseCount = in.nextInt();
			int minScore = in.nextInt();
			
			int goodCount = 0;
			int maybeCount = 0;
			
			for(int i = 0; i < dancerCount; i++){
				int now = in.nextInt();
				int min;
				
				switch(now%3){
				case 0:
					min = now/3;
					if(min == 0){
						if (minScore == 0){
							goodCount++;
						}
					}else if(min >= minScore){
						goodCount++;
					}else if(min + 1 == minScore){
						maybeCount++;
					}
					break;
					
				case 1:
					min = (now/3) + 1;
					if(min >= minScore){
						goodCount++;
					}
					break;
					
				case 2:
					min = (now/3) + 1;
					if(min >= minScore){
						goodCount++;
					}else if(min + 1 == minScore){
						maybeCount++;
					}
					break;
					
				}
			}
			
			goodCount += Math.min(maybeCount, surpriseCount);
			
			out.write("Case #" + currentCase + ": " + goodCount);
			out.newLine();
		}
		
		out.close();
		
	}
	
}
