package round2;

import java.util.*;

public class LastWord {
	public static void main(String[] args){		
		Scanner scanner = new Scanner(System.in);
		int testcases = Integer.parseInt(scanner.nextLine());
		for(int i=1; i<=testcases; i++){
			String string = scanner.nextLine();
			System.out.print(String.format("Case #%d: ", i));
			System.out.println(lastWord(string));
		}
		scanner.close();
	}
	
	public static String lastWord(String string){
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<string.length(); i++){
			char c = string.charAt(i);
			if(i < 1){
				sb.append(c);
			}else{
				char first = sb.charAt(0);
				if(c >= first){
					sb.insert(0, c);
				}else{
					sb.append(c);
				}
			}
		}
		
		return sb.toString();
	}
}
