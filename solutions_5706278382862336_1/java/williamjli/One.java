import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class One {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader myReader = new BufferedReader(new FileReader("C:\\Users\\William Li\\Desktop\\A-small-attempt0.in"));
		PrintWriter myWriter = new PrintWriter(new FileWriter("C:\\Users\\William Li\\Desktop\\output.out"));
		
		int T = Integer.parseInt(myReader.readLine());
		
		for (int t = 1; t <= T; t++){
			
			String[] input = myReader.readLine().split("/");
			double[] fraction = new double[2];
			fraction[0] = Long.parseLong(input[0]);
			fraction[1] = Long.parseLong(input[1]);
			
			boolean impossible = calculateImpossible(fraction);
			
			if (impossible){
				
				myWriter.println("Case #" + t + ": impossible");
				
			}else{
			
				myWriter.println("Case #" + t + ": " + calculateAncestry(fraction));
			
			}
			
		}
		
		myReader.close();
		myWriter.close();
		
	}
	
	public static boolean calculateImpossible(double[] arr){
		
		ArrayList<Double> factorizationOne = new ArrayList<Double>();
		ArrayList<Double> factorizationTwo = new ArrayList<Double>();
		
		for (int i = 2; i <= Math.sqrt(arr[0]); i++){
			
			if (arr[0] % i == 0){
				
				factorizationOne.add((double) i);
				arr[0] /= i;
				i--;
				
			}
			
		}
		
		for (int i = 2; i <= Math.sqrt(arr[1]); i++){
			
			if (arr[1] % i == 0){
				
				factorizationTwo.add((double) i);
				arr[1] /= i;
				i--;
				
			}
			
		}
		
		factorizationOne.add(arr[0]);
		factorizationTwo.add(arr[1]);
		
		for (int i = factorizationOne.size() - 1; i >= 0; i--){
			
			if (factorizationTwo.contains(factorizationOne.get(i))){
				
				factorizationTwo.remove(factorizationOne.get(i));
				factorizationOne.set(i, 1.0);
				
			}
			
		}
		
		double a1 = 1;
		double a2 = 1;
		
		for (int i = 0; i < factorizationOne.size(); i++){
			
			a1 *= factorizationOne.get(i);
			
		}
		
		for (int i = 0; i < factorizationTwo.size(); i++){
			
			a2 *= factorizationTwo.get(i);
			
		}
		
		arr[0] = a1;
		arr[1] = a2;
		
		for (int i = 0; i < factorizationTwo.size(); i++){
			
			if (factorizationTwo.get(i) != 2.0){
				
				return true;
				
			}
			
		}
		
		return false;
		
	}
	
	public static int calculateAncestry(double[] arr){
		
		if (arr[0] / arr[1] >= 1.0 / 2.0){
			
			return 1;
			
		}else{
			
			arr[1] = arr[1] / 2.0;
			return 1 + calculateAncestry(arr);
			
		}
		
	}
	
}