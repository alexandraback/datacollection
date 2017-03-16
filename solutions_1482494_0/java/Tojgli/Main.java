package szarfos;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {
	private static List<List<String[]>> input;
		
	public static void main(String[] args) throws IOException {
		readFile();
		BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
		for (int i = 0; i < input.size(); i++) {
			int stars = 0;
			Integer count = 0;			
			String result = "";
			List<String[]> levels = input.get(i);
			List<String[]> levelsDoneOnce = new ArrayList<String[]>(); 
			while (levels.size() > 0 || levelsDoneOnce.size() > 0) {
				boolean found = false;
				
				for (int j = 0; j < levels.size(); j++) {
					int A = Integer.parseInt(levels.get(j)[0]);
					int B = Integer.parseInt(levels.get(j)[1]);
					if (stars >= B) {
						levels.remove(j);
						j--;
						stars += 2;
						count++;
						found = true;
						break;
					}										
				}								
				if (!found) {
					for (int j = 0; j < levelsDoneOnce.size(); j++) {
						int A = Integer.parseInt(levelsDoneOnce.get(j)[0]);
						int B = Integer.parseInt(levelsDoneOnce.get(j)[1]);
						if (stars >= B) {							
							levelsDoneOnce.remove(j);
							j--;
							stars += 1;
							count++;
							found = true;							
							break;
						}										
					}		
				}
				
				int maxB = 0;
				int maxJ = 0;				
				if (!found) {
					for (int j = 0; j < levels.size(); j++) {
						int A = Integer.parseInt(levels.get(j)[0]);
						int B = Integer.parseInt(levels.get(j)[1]);
						if (stars >= A && maxB < B) {
							maxB = B;	
							maxJ = j;
						}										
					}								
				}
				if (maxB > 0) {
					levelsDoneOnce.add(levels.get(maxJ));
					levels.remove(maxJ);					
					stars += 1;
					count++;
					found = true;
				}
				
				if (!found) {
					result = "Too Bad";
					break;
				}
			}
			if (result == "") {
				result = count.toString();
			}			
			
			System.out.println("Number : " + result);
			int caseNum = i+1;
		    out.write("Case #" + caseNum + ": " + result);		
		    out.newLine();
		}	
		out.close();
	}		
	
	
	
	
	public static void readFile() {
		try {
			input = new ArrayList<List<String[]>>();
			
		    BufferedReader in = new BufferedReader(new FileReader("input.txt"));
		    String str;
		    in.readLine();
		    while ((str = in.readLine()) != null) {
		    	Integer count = Integer.parseInt(str);
		    	List<String[]> levels = new ArrayList<String[]>();
		    	for (int i = 0; i < count; i++) {
		    		str = in.readLine();
			    	String[] n = str.split(" ");			    	
			    	levels.add(n);			    		
		    	}
		    	input.add(levels);		    			    	
		    }
		    in.close();
		} catch (IOException e) {
		}
	}
	

	

}
