package knucle.y2012.C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Set;

public class C {
	
	public static void main(String[] args) throws Exception {
		
		FileReader fr = new FileReader("C-large.in");
		BufferedReader br = new BufferedReader(fr);
		
		BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));

		int currentCase = 1;
		int caseNum = Integer.parseInt(br.readLine());
		
		for(currentCase=1; currentCase<=caseNum; currentCase++){
			String line = br.readLine();

			bw.write("Case #");
			bw.write(Integer.toString(currentCase));
			bw.write(": ");
			
			String[] inputs = line.split(" ");
			String minStr = inputs[0];
			int min = Integer.parseInt(minStr);
			int max = Integer.parseInt(inputs[1]);
			
			
			int count = 0;
			
			for(int i=min+1; i<=max; i++){
				String target = Integer.toString(i);
				
				int len = target.length();
				Set<String> possibles = new HashSet<String>();
				for(int splitPos=1; splitPos<len; splitPos++){
					if(target.charAt(splitPos) == '0') continue;
					
					String possible = target.substring(splitPos) + target.substring(0, splitPos);
					if(possible.compareTo(minStr) < 0) continue;
					
					if(possible.compareTo(target) < 0){
						possibles.add(possible);
						
						//System.out.println(possible + " " + target);
					}
				}
				
				count += possibles.size();
			}
			
			bw.write(Integer.toString(count));
			
			bw.write('\n');
		}
		
		br.close();
		bw.close();
	}
}
