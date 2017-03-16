import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class D {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\William Li\\Desktop\\input.txt"));
		PrintWriter out = new PrintWriter(new FileWriter("C:\\Users\\William Li\\Desktop\\output.txt"));
		
		int T = Integer.parseInt(in.readLine());
		
		for (int t = 1; t <= T; t++){
			
			System.out.println("working on case " + t);
			String[] nextLine = in.readLine().split(" ");
			
			int X = Integer.parseInt(nextLine[0]);
			int R = Integer.parseInt(nextLine[1]);
			int C = Integer.parseInt(nextLine[2]);
			
			if (X >= 7 || (X > Math.max(R, C)) || (((R * C) % X) != 0) || (X > 2 * Math.min(R, C))){
				
				out.println("Case #" + t + ": RICHARD");
				
			}else if (X == 4){
				
				if (R <= 2 || C <= 2){
					
					out.println("Case #" + t + ": RICHARD");
					
				}else{
					
					out.println("Case #" + t + ": GABRIEL");
					
				}
				
			}else if (X == 5 || X == 6){
				
				if (R <= 3 || C <= 3){
					
					out.println("Case #" + t + ": RICHARD");
					
				}else{
					
					out.println("Case #" + t + ": GABRIEL");
					
				}
				
			}else{
				System.out.println(X + " " + R + " " + C);
				out.println("Case #" + t + ": GABRIEL");
				
			}
			
		}
		
		in.close();
		out.close();
		
		System.exit(0);
		
	}
	
	public static class Quaternion {
		
		int value;
		int negative = 1;
		String[][] multiply = {{"1", "i", "j", "k"},
								{"i", "-1", "k", "-j"},
								{"j", "-k", "-1", "i"},
								{"k", "j", "-i", "-1"}};
		
		public Quaternion(String value) {
			
			if (value.contains("1")){
				
				this.value = 0;
				
			}else if (value.contains("i")){
				
				this.value = 1;
				
			}else if (value.contains("j")){
				
				this.value = 2;
				
			}else if (value.contains("k")){
				
				this.value = 3;
				
			}
			
			if (value.contains("-")){
				
				negative = -1;
				
			}
			
		}
		
		public Quaternion multiply(Quaternion other) {
			
			int n = negative;
			n = n * other.negative;
			
			Quaternion returned = new Quaternion(multiply[value][other.value]);
			returned.negative *= n;
			
			return returned;
			
		}
		
		@Override
		public String toString() {
			
			String lel = negative == -1? "-" : "";
			
			if (value == 0){
				
				lel += 1;
			
			}else if (value == 1){
				
				lel += "i";
				
			}else if (value == 2){
				
				lel += "j";
				
			}else if (value == 3){
				
				lel += "k";
				
			}
			
			return lel;
			
		}
		
	}
	
}