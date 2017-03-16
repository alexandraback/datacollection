import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class LastWord {
	
	Scanner in;	public static void main(String[] args){
		LastWord myClass = new LastWord();
		myClass.solve();
	}
	
	FileWriter writer;
	
		private void solve() {
		try {			
			
			in =  new Scanner(new BufferedReader(new FileReader("A-large.in")));
			//in = new Scanner(System.in);
		//in =  new Scanner(new BufferedReader(new FileReader("D-small-attempt0.in")));
		writer = new FileWriter("the-file-name.txt");
		
		int T = in.nextInt();
			for(int i = 1; i <= T; i++){
				
			String C = in.next();
			
			String ans = C.charAt(0) + "";
			
			for(int j = 1; j < C.length(); j++){
			
			      ans = constructAns(C, ans, j, 0);
				
			}
							
			StringBuilder s = new StringBuilder();

			s.append("Case #");
			s.append(i);
			s.append(": ");
			
				s.append(ans);
			
			s.append("\n");
			
	writer.write(s.toString());
			
					}
		writer.close();			
		}
			catch (IOException e) {
			}
			
			
		}

		private String constructAns(String C, String ans, int j, int i) {
			if(i >= ans.length()){
				ans = C.charAt(j) + ans;
				return ans;
			}
			
			
			if(C.charAt(j) > ans.charAt(i)){
				ans = C.charAt(j) + ans;
				return ans;
			}
			if(C.charAt(j) == ans.charAt(i)){
				//check next character
				return constructAns(C, ans, j, i+1);
				
			}
			
			if(C.charAt(j) < ans.charAt(i)){
				ans = ans + C.charAt(j);
				return ans;
			}
			
			System.out.println("ERROR!!!!!! STOP!!!!");
			return "";
			
		}
		
		
		
	}
	

