package round1c;

import java.util.Scanner;

public class ProblemA {

	
	public static void main(String[] args) {
		
	Scanner sc = new Scanner(System.in);

	int cases = Integer.parseInt(sc.nextLine());

	for (int cs = 1; cs <= cases; cs++) {

		String []line = sc.nextLine().split(" ");
		
		int n = Integer.parseInt(line[1]);
		
		int count = 0;
		
		for(int i = 0; i < line[0].length(); i++){
			for(int j = i + 1; j <= line[0].length(); j++){
				
				//if(j > line[0].length() + 1)continue;
				
				char []substr = line[0].substring(i, j).toCharArray();
				
				if(substr.length < n) continue;
				
				int cons = 0;
				
				for(int k = 0; k < substr.length; k++ ){
					
					if((substr[k] == 'a') || (substr[k] == 'e') ||
							(substr[k] == 'i') || (substr[k] == 'o') || (substr[k] == 'u'))
					{
						cons = 0;
						
					} else {
						cons++;
					}
					
					if(cons >= n){
						count++;
						break;
					}
				}
			}
		}
		
		
		
		System.out.println("Case #" + cs + ": " + count);
		
	}
	}

}
