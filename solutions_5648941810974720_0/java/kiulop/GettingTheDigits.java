import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class GettingTheDigits {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		String zero = "ZERO"; //Z k
		String one = "ONE";
		String two = "TWO"; //W k
		String three = "THREE";  // H k
		String four = "FOUR"; //R k
		String five = "FIVE"; //V k
		String six = "SIX"; //X k 
		String seven = "SEVEN"; //S k
		String eight = "EIGHT"; //G k
		String nine = "NINE"; //I k
		for(int caseNr = 1; caseNr <= T; caseNr++){
			String numbers = sc.next();
			Map<Character, Integer> mapping = new HashMap<Character, Integer>();
			for(int i = 0; i< numbers.length(); i++){
				Character c = numbers.charAt(i);
				if(mapping.containsKey(c)){
					mapping.put(c, mapping.get(c)+1);
				}
				else
					mapping.put(c, 1);
			}
			List<Integer> AnswerNumbers = new ArrayList<Integer>();
			if(mapping.containsKey('Z')){
				int k = mapping.get('Z');
				for(int i = 0; i<k; i++){
					AnswerNumbers.add(0);
				}
				for(int j = 0; j<zero.length(); j++){
					char thisChar = zero.charAt(j);
					if(mapping.containsKey(thisChar)){
						int currVal = mapping.get(thisChar);
						mapping.put(thisChar, currVal-k);
					}
				}
			}
			if(mapping.containsKey('W')){
				int k = mapping.get('W');
				for(int i = 0; i<k; i++){
					AnswerNumbers.add(2);
				}
				for(int j = 0; j<two.length(); j++){
					char thisChar = two.charAt(j);
					if(mapping.containsKey(thisChar)){
						int currVal = mapping.get(thisChar);
						mapping.put(thisChar, currVal-k);
					}
				}
			}
			if(mapping.containsKey('X')){
				int k = mapping.get('X');
				for(int i = 0; i<k; i++){
					AnswerNumbers.add(6);
				}
				for(int j = 0; j<six.length(); j++){
					char thisChar = six.charAt(j);
					if(mapping.containsKey(thisChar)){
						int currVal = mapping.get(thisChar);
						mapping.put(thisChar, currVal-k);
					}
				}
			}
			if(mapping.containsKey('G')){
				int k = mapping.get('G');
				for(int i = 0; i<k; i++){
					AnswerNumbers.add(8);
				}
				for(int j = 0; j<eight.length(); j++){
					char thisChar = eight.charAt(j);
					if(mapping.containsKey(thisChar)){
						int currVal = mapping.get(thisChar);
						mapping.put(thisChar, currVal-k);
					}
				}
			}
			if(mapping.containsKey('S')){
				int k = mapping.get('S');
				for(int i = 0; i<k; i++){
					AnswerNumbers.add(7);
				}
				for(int j = 0; j<seven.length(); j++){
					char thisChar = seven.charAt(j);
					if(mapping.containsKey(thisChar)){
						int currVal = mapping.get(thisChar);
						mapping.put(thisChar, currVal-k);
					}
				}
			}
			if(mapping.containsKey('H')){
				int k = mapping.get('H');
				for(int i = 0; i<k; i++){
					AnswerNumbers.add(3);
				}
				for(int j = 0; j<three.length(); j++){
					char thisChar = three.charAt(j);
					if(mapping.containsKey(thisChar)){
						int currVal = mapping.get(thisChar);
						mapping.put(thisChar, currVal-k);
					}
				}
			}
			if(mapping.containsKey('R')){
				int k = mapping.get('R');
				for(int i = 0; i<k; i++){
					AnswerNumbers.add(4);
				}
				for(int j = 0; j<four.length(); j++){
					char thisChar = four.charAt(j);
					if(mapping.containsKey(thisChar)){
						int currVal = mapping.get(thisChar);
						mapping.put(thisChar, currVal-k);
					}
				}
			}
			if(mapping.containsKey('V')){
				int k = mapping.get('V');
				for(int i = 0; i<k; i++){
					AnswerNumbers.add(5);
				}
				for(int j = 0; j<five.length(); j++){
					char thisChar = five.charAt(j);
					if(mapping.containsKey(thisChar)){
						int currVal = mapping.get(thisChar);
						mapping.put(thisChar, currVal-k);
					}
				}
			}
			if(mapping.containsKey('I')){
				int k = mapping.get('I');
				for(int i = 0; i<k; i++){
					AnswerNumbers.add(9);
				}
				for(int j = 0; j<nine.length(); j++){
					char thisChar = nine.charAt(j);
					if(mapping.containsKey(thisChar)){
						int currVal = mapping.get(thisChar);
						mapping.put(thisChar, currVal-k);
					}
				}
			}
			if(mapping.containsKey('O')){
				int k = mapping.get('O');
				for(int i = 0; i<k; i++){
					AnswerNumbers.add(1);
				}
				for(int j = 0; j<one.length(); j++){
					char thisChar = one.charAt(j);
					if(mapping.containsKey(thisChar)){
						int currVal = mapping.get(thisChar);
						mapping.put(thisChar, currVal-k);
					}
				}
			}
			
			Collections.sort(AnswerNumbers);
			String answer = "";
			for(int i = 0; i<AnswerNumbers.size(); i++){
				answer += AnswerNumbers.get(i);
			}
			
			System.out.println("Case #"+caseNr+": " + answer);
		}

	}

}
