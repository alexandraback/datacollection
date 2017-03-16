

public class Exo01 {

	
	public static void main(String[] args) {
		
		int numberTest = Integer.parseInt(args[0]);
		int cursor = 1;
		
		for(int i = 0; i < numberTest; i++){
			String s = args[cursor];
			cursor++;
			
			int n =  Integer.parseInt(args[cursor]);
			
			cursor ++;
			
			System.out.println("Case #" + (i+1) + ": " + countNumberCase(s,n));
		}
		
		
		
	}

	private static int countNumberCase(String s, int n){
		int count = 0;
		for(int x = 0; x < s.length() ; x++){
			for(int y = x; y <s.length(); y++){
				//System.out.println(s.substring(x, y+1));
				if(checkNConsecutiveConsonant(s.substring(x, y+1),n)) count++;
			}
		}
		
		return count;
	}
	
	private static boolean checkNConsecutiveConsonant(String s, int n){
		
		for(int i = 0; i< s.length(); i++){
			int currentN = 0;
			while(i < s.length()&& isConsonant(s.charAt(i))){
				i++;
				currentN++;
				if(currentN == n) return true;
			}
		}

		return false;
	}
	
	private static boolean isConsonant(char c){
		return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	}
}
