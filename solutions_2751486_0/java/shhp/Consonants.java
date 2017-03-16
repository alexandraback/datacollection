import java.io.*;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;

class Consonants{
	public static void main(String[] args){
		Scanner scanner = null;
		FileOutputStream outputFile = null;
		ArrayList<Character> vowels = new ArrayList<Character>();
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');
		try{
			File inputData = new File("small.in");
			scanner = new Scanner(inputData);
			/* Firstly, read the case counts N */
			int caseNumber = scanner.nextInt();
			/* Solve cases one by one */			
			StringBuilder output = new StringBuilder();
			for(int i = 1; i <= caseNumber; i++){
				System.out.println("--------Case #" + i + "---------");				
				String name = scanner.next();
				int n = scanner.nextInt();
				boolean[] hasConsecutive = new boolean[name.length()];
				for(int j = 0; j < hasConsecutive.length; j++)
					hasConsecutive[j] = false;				
				
				if(n == 1){
					for(int j = 0; j < hasConsecutive.length; j++)
						if(!vowels.contains(name.charAt(j)))
							hasConsecutive[j] = true;
				}
				else{
					int p1 = 0;
					while(p1 < name.length() && vowels.contains(name.charAt(p1)))
						p1++;
					//System.out.println(p1);
					int p2 = p1 + 1;
					int consonantsNumber = 1;
					if(p2 == name.length() && consonantsNumber == n)
						hasConsecutive[p1] = true;
					while(p2 < name.length()){
						if(!vowels.contains(name.charAt(p2))){
							consonantsNumber++;
							if(consonantsNumber == n){
								hasConsecutive[p1] = true;
								p1++;
								p2++;
								consonantsNumber--;
							}
							else{
								p2++;
							}
						}
						else{
							p1 = p2 + 1;
							while(p1 < name.length() && vowels.contains(name.charAt(p1)))
								p1++;
							p2 = p1 + 1;
							consonantsNumber = 1;
						}
					}
				}
				
				
				System.out.println(Arrays.toString(hasConsecutive));
				int nValue = 0;
				int previous = 0;
				for(int j = 0; j < hasConsecutive.length; j++){
					if(hasConsecutive[j]){
						nValue += (j - previous + 1) * (hasConsecutive.length - n - j + 1);
						previous = j+1;
						/*if(j-1 >= 0 && !hasConsecutive[j-1]){
							nValue += (j - 0 + 1) * (hasConsecutive.length - n - j + 1);
							//System.out.println(nValue);
						}
						else if(j - 1 >= 0){
							nValue += (hasConsecutive.length - n - j + 1);
						}
						else{
							nValue += (j - 0 + 1) * (hasConsecutive.length - n - j + 1);
						}*/
					}
				}
				output.append("Case #").append(i).append(": ").append(nValue).append("\n");
			}
			outputFile = new FileOutputStream(new File("output_small.txt"));
			outputFile.write(output.toString().getBytes(),0,output.toString().length());
			System.out.println(output.toString());
						
		}		
		catch(Exception e){
			e.printStackTrace();
		}
		finally{
			try{
				if(scanner != null)
					scanner.close();
				if(outputFile != null)
					outputFile.close();
			}catch(Exception e){
			e.printStackTrace();
			}
			
		}
	}
}

