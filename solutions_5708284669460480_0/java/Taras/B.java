import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;


public class B {

	public static void main(String[] args) {	
		Scanner in;
		try {
				//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/b.in"));
				in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/B-small-attempt0.in"));
				//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/B-large.in"));
				
				int t = in.nextInt();
				
				StringBuilder resultBuilder = new StringBuilder();
				
				char[] keyboard, target;
				
				for(int i = 0; i < t; i++){
					int k = in.nextInt();
					int l = in.nextInt();
					int s = in.nextInt();
					keyboard = new char[k];
					target = new char[l];
					in.nextLine();
					String keyboardString = in.nextLine();
					String targetString = in.nextLine();
					System.out.println("keyboard:"+keyboardString);
					System.out.println("targetString:"+targetString);
					for(int j=0;j<k; j++)
						keyboard[j] = keyboardString.charAt(j);
					for(int j=0;j<l; j++)
						target[j] = targetString.charAt(j);
					DecimalFormat format = new DecimalFormat("##0.0######");
					
					resultBuilder.append("Case #"+(i+1)+": "+format.format(findSolution(k,l,s, keyboard, target))+"\n");
				}
				
				String resultStringBuffer = resultBuilder.toString();
				resultStringBuffer = resultStringBuffer.replace(",", ".");
				resultBuilder.setLength(0);
				resultBuilder.append(resultStringBuffer);
				
				
				System.out.println(resultBuilder.toString());
				String content = resultBuilder.toString();
				 
				File file = new File("/home/taras/workspace/GoogleCodeJam_1C/src/b.out");
		
				// if file doesnt exists, then create it
				if (!file.exists()) {
					file.createNewFile();
				}
		
				FileWriter fw = new FileWriter(file.getAbsoluteFile());
				BufferedWriter bw = new BufferedWriter(fw);
				bw.write(content);
				bw.close();
		
				System.out.println("Done");
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}


	private static double findSolution(int k, int l, int s, char[] keyboard, char[] target){
		System.out.println("findSolution: k:"+k+" l:"+l+" s:"+s);
		double result = 0;
		int maxBananas = 0;
		long probabilitysum = 0;
		int cycleCount = 1;
		for(int i=0;i<s;i++)
			cycleCount*=k;
		
		char[] currentStr =new char[s];
		
		for(int i=0;i<cycleCount;i++){
			int currentNum = i;
			int currentPos = 0;
			while(currentPos<s){
				currentStr[currentPos] = keyboard[currentNum%k];
				currentNum/=k;
				currentPos++;
			}
			
			//System.out.println(currentStr);
			
			int usedBananas = 0;
			
			for(int j=0;j<=s-l; j++){
				boolean equalStr = true;
				for(int z=0;z<l;z++){
					if(currentStr[j+z]!=target[z]) equalStr = false;
				}
				
				if(equalStr){
					probabilitysum++;
					usedBananas++;
				}
			}
			
			if(usedBananas>maxBananas){
				maxBananas = usedBananas;
			}
		}
		
		result = (double)maxBananas - ((double)probabilitysum/(double)cycleCount);
		
		return result;
	}

	}
