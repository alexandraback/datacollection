import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Two {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader myReader = new BufferedReader(new FileReader("C:\\Users\\William Li\\Desktop\\B-small-attempt3.in"));
		PrintWriter myWriter = new PrintWriter(new FileWriter("C:\\Users\\William Li\\Desktop\\output.out"));
		
		int T = Integer.parseInt(myReader.readLine());
		System.out.println(T);
		for (int t = 1; t <= T; t++){
			
			int N = Integer.parseInt(myReader.readLine());
			String[] cars = myReader.readLine().split(" ");
			
			System.out.println(t + " " + cars.length);
			
			int validConfigurations = 0;
			
			validConfigurations = calculate(cars);
			
			myWriter.println("Case #" + t + ": " + validConfigurations);
			
		}
		
		myReader.close();
		myWriter.close();
		
	}
	
	public static int calculate(String[] cars){
		
		ArrayList<String> sections = new ArrayList<String>();
		
		int[] multipliers = new int[cars.length];
		
		for (int i = 0; i < cars.length; i++){
			
			multipliers[i] = 1;
			
		}
		
		for (int i = 0; i < cars.length; i++){
			
			for (int str = 0; str < cars[i].length(); str++){
				
				for (int i2 = 0; i2 < cars.length; i2++){
					
					if (i2 == i){
						
						i2++;
						
					}
					
					if (i2 == cars.length){
						
						break;
						
					}
					
					boolean b = true;
					boolean c = true;
					
					String first = "";
					
					if (cars[i2].length() > 0){
					
						first = cars[i2].substring(0, 1);
					
					}
					
					for (int ind = 0; ind < cars[i2].length(); ind++){
						
						if (cars[i2].substring(ind, ind + 1).equals(first)){
							
							
							
						}else{
							
							b = false;
							
						}
						
					}
					
					first = "";
					
					if (cars[i].length() > 0){
					
						first = cars[i].substring(0, 1);
					
					}
					
					for (int ind = 0; ind < cars[i].length(); ind++){
						
						if (cars[i].substring(ind, ind + 1).equals(first)){
							
							
							
						}else{
							
							c = false;
							
						}
						
					}
					
					if (cars[i].length() > 0 && cars[i2].contains(cars[i].substring(str, str + 1))){
					
					if (!cars[i2].equals("") && !cars[i].equals("") && b && c){
						System.out.println(cars[i] + " " + cars[i2]);
						multipliers[i]++;
						cars[i] += cars[i2];
						cars[i2] = "";
						
					}else if (!cars[i].equals("") && !cars[i2].equals("") && str == 0 && cars[i].substring(str, str + 1).equals(cars[i2].substring(cars[i2].length() - 1))){
						
						cars[i2] += cars[i];
						cars[i] = "";
						
					}else if (!cars[i].equals("") && !cars[i2].equals("") && str == cars[i].length() - 1 && cars[i].substring(str, str + 1).equals(cars[i2].substring(0, 1))){
						
						cars[i] += cars[i2];
						cars[i2] = "";
						
					}else{
						
						return 0;
						
					}
					
					}
					
				}
				
			}
			
		}
		
		for (int i = 0; i < cars.length; i++){
			
			if (cars[i].equals("")){
				
			}else{
				
				sections.add(cars[i]);
				
			}
			
		}
		
		double answer = factorial(sections.size());
		
		for (int i = 0; i < multipliers.length; i++){
			
			if (answer > 1000000007){
				
				answer %= 1000000007;
				
			}
				
			answer *= factorial(multipliers[i]);
			
		}
		
		return (int) answer;
		
	}
	
	public static double factorial(double n){
		
		double lol = 1;
		
		for (int i = 1; i <= n; i++){
			
			lol *= i;
			
		}
		
		return lol;
		
	}
	
}