import java.util.Scanner;

public class LastWord {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = Integer.parseInt(in.nextLine());
		
		for(int caseNum = 1; caseNum<=t; caseNum++){
			String word = in.nextLine();
			String newWord = String.valueOf(word.charAt(0));
			int i = 1;
			for(i = 1; i<word.length(); i++){
				char c = word.charAt(i);
				if(c >= newWord.charAt(0)){
					newWord = c + newWord;
				}else{
					newWord = newWord + c;
				}
			}
			
			
			
			
			
			
			System.out.println("Case #" + caseNum+": " + newWord);
		}

	}
	
}
