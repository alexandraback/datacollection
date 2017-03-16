import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class KingdomRush {
	
	public static void main(String[] args) throws IOException{
		
		String path = "C:\\Users\\Rapol Tongchenchitt\\Documents\\CodeJam\\";
		String year = "1A2012\\";
		
		String input = "B-small-attempt2.in"; String output = "B-small-attempt2.out";
		
		String inName = path+year+input;
		String outName = path+year+output;
		
		Scanner in = new Scanner(new FileInputStream(inName));
		BufferedWriter out = new BufferedWriter(new FileWriter(outName));
		
		int caseCount = in.nextInt(); int currentCase = 0;
		
		while(currentCase++ < caseCount){
			
			int levelCount = in.nextInt();
			
			ArrayList<Integer> levelOneOrig = new ArrayList<Integer>();
			ArrayList<Integer> levelTwoOrig = new ArrayList<Integer>();
			
			for(int i = 0; i < levelCount; i++){
				levelOneOrig.add(in.nextInt());
				levelTwoOrig.add(in.nextInt());
			}
			
			ArrayList<Integer> clearList = new ArrayList<Integer>();
			
			for(int j = 0; j < levelCount; j++){
				
				ArrayList<Integer> levelOne = new ArrayList<Integer>();
				ArrayList<Integer> levelTwo = new ArrayList<Integer>();
				
				for(int k = 0; k < levelCount; k++){
					levelOne.add(levelOneOrig.get((j+k)%levelCount));
					levelTwo.add(levelTwoOrig.get((j+k)%levelCount));
				}
				
				System.out.println(levelOne);
				System.out.println(levelTwo);
				
				int star = 0;
				int clear = -1;
				
				while(true){
					clear++;
					
					int foundStage = 0; int starPlus = 0;
					
					for(int i = 0; i < levelTwo.size(); i++){
						if(levelTwo.get(i) <= star){
							foundStage = i;
							starPlus = 2;
							break;
						}
					}
					if(starPlus > 0){
						if(levelOne.get(foundStage) != 10000){
							levelTwo.set(foundStage, 10000);
							levelOne.set(foundStage, 10000);
							star += starPlus;
						}else{
							levelTwo.set(foundStage, 10000);
							star += starPlus-1;
						}
						
						
						System.out.println(levelOne);
						System.out.println(levelTwo);
						
						continue;
					}
					
					for(int i = 0; i < levelOne.size(); i++){
						if(levelOne.get(i) <= star){
							foundStage = i;
							starPlus = 1;
							break;
						}
					}
					if(starPlus > 0){
						levelOne.set(foundStage, 10000);
						star += starPlus;
						
						System.out.println(levelOne);
						System.out.println(levelTwo);
						
						continue;
					}
					
					break;
				}
				
				for(int i : levelTwo){
					if(i < 10000){
						clear += 10000;
					}
				}
				
				clearList.add(clear);
			}
			
			System.out.println(clearList);
			Collections.sort(clearList);
			int det = clearList.get(0);
			
			if(det < levelCount || det > 9999){
				out.write("Case #" + currentCase + ": " + "Too Bad");
			}else{
				out.write("Case #" + currentCase + ": " + det);
			}
			out.newLine();
		}
		
		out.close();
		
	}

}
