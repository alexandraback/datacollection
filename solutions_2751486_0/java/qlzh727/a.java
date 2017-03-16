import java.util.Scanner;


public class Consonants {

	public void solve(int caseNo, String input, int n){
		long result = 0l;
		
		int previous = -1;
		for(int i = 0; i <= input.length() - n; i++){
			String sub = input.substring(i, i+n);
			if(!sub.contains("a") &&
					!sub.contains("e") &&
					!sub.contains("i") &&
					!sub.contains("o") &&
					!sub.contains("u")){
				int startPos = i - previous;
				int endPos = input.length() - (i+n) +1;
				result += startPos * endPos;
				previous = i;
			}
		}
		

		System.out.printf("Case #%d: %d\n", caseNo, result);
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Consonants f = new Consonants();
		Scanner sc = new Scanner(System.in);
		int totalCase = Integer.parseInt(sc.nextLine());
		for(int i =1; i <= totalCase; i++){
			String s = sc.nextLine();
			String input = s.split(" ")[0];
			int n = Integer.parseInt(s.split(" ")[1]);
			f.solve(i, input, n);
		}

	}

}
