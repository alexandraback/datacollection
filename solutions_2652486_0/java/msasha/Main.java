import java.io.*;
import java.util.*;


public class Main{
	
	
	private static Map<Integer, String> prepareAnswers(){
		int [] numbers = {2, 3, 4, 5};
		
		Map<Integer, String> answers = new HashMap<Integer, String>();
		
		for (int i1 = 0; i1 < numbers.length; i1++){
			for (int i2 = 0; i2 < numbers.length; i2++){
				for (int i3 = 0; i3 < numbers.length; i3++){
					String answer = "" + numbers[i1] + "" + numbers[i2] + "" + numbers[i3];
					answers.put(numbers[i1]*numbers[i2]*numbers[i3], answer);
				}
			}
		}
		
		return answers;	
	}
	
	

	public static void main(String [] args) throws IOException{
		Map<Integer, String> answers = prepareAnswers();
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		in.readLine();
		
		String [] line = in.readLine().split(" ");
		int r = Integer.parseInt(line[0]);
		int n = Integer.parseInt(line[1]);
		int m = Integer.parseInt(line[2]);
		int k = Integer.parseInt(line[3]);
		
		System.out.println("Case #1:");
		for (int i = 0; i < r; i++){
			line = in.readLine().split(" ");
			String answer = null;
			int bestProd = 0;
			for (int j = 0; j < k; j++){
				int prod = Integer.parseInt(line[j]);
				if ((prod > bestProd) && answers.containsKey(prod)){
					answer = answers.get(prod);
					bestProd = prod;
				}
			}
			System.out.println(answer == null ? "111" : answer);
		}
	}

}