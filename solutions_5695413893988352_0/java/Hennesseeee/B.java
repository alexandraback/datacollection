import java.io.*;
import java.math.*;
import java.util.*;

public class B{
	public static void main(String[] args) throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter writer = new PrintWriter("out.txt", "UTF-8");
		int T = Integer.parseInt(reader.readLine());
		for(int i = 1; i<=T; i++){

			System.out.println(i);
			String[] inputs = reader.readLine().split("\\s+");
			
			int[] solved = solve(inputs[0], inputs[1]);
			String s1 = ""+solved[0];
			String s2 = ""+solved[1];
			while(s1.length() < inputs[1].length()){
				s1 = "0" + s1;
			}
			while(s2.length() < inputs[1].length()){
				s2 = "0" + s2;
			}


			writer.println("Case #" + i + ": " + s1 + " " + s2);
		}
		writer.close();
	}


	static int[] solve(String a, String b){
		int[] sol = new int[2];
		int smallest = -1;
		for(int c = 0; c < Math.pow(10,a.length()); c++){
			for(int k = 0; k < Math.pow(10,b.length()); k++){
				if(valid(a,b,c,k)){
					if(smallest < 0){
						sol[0] = c;
						sol[1] = k;
						smallest = Math.abs(c-k);
					}
					if(Math.abs(c-k) < smallest){
						sol[0] = c;
						sol[1] = k;
						smallest = Math.abs(c-k);

					}
					
				}
			}
		}
		return(sol);
	}

	static boolean valid(String p1, String p2, int a, int b){
		String s1 = "" + a;
		String s2 = "" + b;
		while(s1.length() < p1.length()){
			s1 = "0" + s1;
		} 
		while(s2.length() < p2.length()){
			s2 = "0" + s2;
		}
		boolean valid = true;
		for(int i = 0 ;i < p1.length(); i++){
			if(p1.charAt(i) != '?'){
				if(p1.charAt(i) != s1.charAt(i)){
					valid = false;
				}
			}
			if(p2.charAt(i) != '?'){
				if(p2.charAt(i) != s2.charAt(i)){
					valid = false;
				}
			}
		}
		return(valid);
	}

}