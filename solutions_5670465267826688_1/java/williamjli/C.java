import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class C {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\William Li\\Desktop\\input.txt"));
		PrintWriter out = new PrintWriter(new FileWriter("C:\\Users\\William Li\\Desktop\\output.txt"));
		
		int T = Integer.parseInt(in.readLine());
		
		for (int t = 1; t <= T; t++){
			System.out.println("working on case " + t);
			String[] nextLine = in.readLine().split(" ");
			
			int L = Integer.parseInt(nextLine[0]);
			long X = Long.parseLong(nextLine[1]);
			
			String text = in.readLine();
			
			Quaternion current = new Quaternion(text.substring(0, 1));
			
			for (int i = 1; i < text.length(); i++){
				
				current = current.multiply(new Quaternion(text.substring(i, i + 1)));
				
			}
			
			String net = current.toString();
			
			boolean done = false;
			
			if (net.equals("1")){
				
				out.println("Case #" + t + ": NO");
				done = true;
				
			}else if (X > 2 && net.equals("-1")){
				
				X %= 2;
				X += 2;
				
			}else if (X > 4 && (net.equals("i") || net.equals("-i") || net.equals("j") || net.equals("-j") || net.equals("k") || net.equals("-k"))){
				
				X %= 4;
				X += 4;
				
			}
			
			if (!done){
			
				String total = "";
			
				for (int i = 0; i < X; i++){
					
					total += text;
					
				}
				
				
				current = new Quaternion(total.substring(0, 1));
				boolean ifound = false;
				boolean complete = false;
				
				for (int i = 1; i < total.length(); i++){
					
					if (!ifound){
						
						if (current.toString().equals("i")){
							
							current = new Quaternion("1");
							ifound = true;
							
						}
						
					}else{
						
						if (current.toString().equals("j") && !complete){
							
							complete = true;
							current = new Quaternion("1");
							
						}
						
					}
					
					current = current.multiply(new Quaternion(total.substring(i, i + 1)));
					
				}
				
				if (complete && current.toString().equals("k")){
					
					out.println("Case #" + t + ": YES");
					
				}else{
					
					out.println("Case #" + t + ": NO");
					
				}
			
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