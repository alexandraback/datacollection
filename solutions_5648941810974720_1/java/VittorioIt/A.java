import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) throws Exception{
		Scanner input = new Scanner(new File(new File("").getAbsolutePath() + "/input.in"));
		input.useLocale(Locale.US);
		PrintWriter output = new PrintWriter(new File("").getAbsolutePath() + "/output.out", "UTF-8");
		int T = input.nextInt() + 1;
		
		for( int i = 1; i < T; i++ ) {
			output.print("Case #" + i + ": ");
			solve(input, output);
		}
		
		output.flush();
		output.close();
		input.close();
	}
	
	public static void solve(Scanner input, PrintWriter output){
		String S = input.next();
		HashMap<Character, Integer> s = new HashMap<Character, Integer>();
		
		for (int i = 0; i < S.length(); i++){
			Integer n = s.get(S.charAt(i));
			if ( n == null ){
				s.put(S.charAt(i), 1);
			}
			else {
				s.put(S.charAt(i), n+1);
			}
		}
		
		int[] num = new int[10];
		
		while (s.get('Z') != null && s.get('Z') != 0){
			num[0]++;
			s.put('Z', s.get('Z') - 1);
			s.put('E', s.get('E') - 1);
			s.put('R', s.get('R') - 1);
			s.put('O', s.get('O') - 1);
		}
		while (s.get('W') != null && s.get('W') != 0){
			num[2]++;
			s.put('T', s.get('T') - 1);
			s.put('W', s.get('W') - 1);
			s.put('O', s.get('O') - 1);
		}
		while (s.get('X') != null && s.get('X') != 0){
			num[6]++;
			s.put('S', s.get('S') - 1);
			s.put('I', s.get('I') - 1);
			s.put('X', s.get('X') - 1);
		}
		while (s.get('U') != null && s.get('U') != 0){
			num[4]++;
			s.put('F', s.get('F') - 1);
			s.put('O', s.get('O') - 1);
			s.put('U', s.get('U') - 1);
			s.put('R', s.get('R') - 1);
		}
		while (s.get('R') != null && s.get('R') != 0){
			num[3]++;
			s.put('T', s.get('T') - 1);
			s.put('H', s.get('H') - 1);
			s.put('R', s.get('R') - 1);
			s.put('E', s.get('E') - 2);
		}
		while (s.get('T') != null && s.get('T') != 0){
			num[8]++;
			s.put('E', s.get('E') - 1);
			s.put('I', s.get('I') - 1);
			s.put('G', s.get('G') - 1);
			s.put('H', s.get('H') - 1);
			s.put('T', s.get('T') - 1);
		}

		while (s.get('O') != null && s.get('O') != 0){
			num[1]++;
			s.put('O', s.get('O') - 1);
			s.put('N', s.get('N') - 1);
			s.put('E', s.get('E') - 1);
		}

		while (s.get('F') != null && s.get('F') != 0){
			num[5]++;
			s.put('F', s.get('F') - 1);
			s.put('I', s.get('I') - 1);
			s.put('V', s.get('V') - 1);
			s.put('E', s.get('E') - 1);
		}
		while (s.get('S') != null && s.get('S') != 0){
			num[7]++;
			s.put('S', s.get('S') - 1);
			s.put('E', s.get('E') - 2);
			s.put('V', s.get('V') - 1);
			s.put('N', s.get('N') - 1);
		}
		while (s.get('I') != null && s.get('I') != 0){
			num[9]++;
			s.put('N', s.get('N') - 2);
			s.put('I', s.get('I') - 1);
			s.put('E', s.get('E') - 1);
		}
		
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < num[i]; j++){
				output.print(""+i);
			}
		}
		output.println();
	}
}
