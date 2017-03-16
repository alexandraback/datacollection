
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import com.sun.xml.internal.bind.v2.runtime.unmarshaller.XsiNilLoader.Array;
import com.sun.xml.internal.bind.v2.schemagen.xmlschema.List;
import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils.Collections;

public class A {

	public static void main(String[] args) {
		// for(int i = 0; i <= 1000000; i++){
		// solveTest(i, i);
		// }
		// return;
		//solveTest( "WEIGHFOXTOURIST", 1);
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for (int i = 0; i < tests; i++) {
			String seed = in.next();

			solveTest(seed, i + 1);
		}
		in.close();
	}

	private static void solveTest(String input, Integer caseNumber) {
		ArrayList<Integer> numbers = new ArrayList<Integer>();
		Map<String, Integer> letters = new HashMap<String, Integer>();
		
		for (char letter : input.toCharArray()) {
			String literal = String.valueOf(letter);
			Integer count = 0;
			if (letters.containsKey(literal)) {
				count = letters.get(literal);
			}
			count++;
			letters.put(literal, count);

		}
		if (letters.containsKey("Z")) {
			int count = letters.get("Z");
			while (count > 0) {
				numbers.add(0);
				count--;
			}

			descrease("Z", "E", letters);
			descrease("Z", "R", letters);
			descrease("Z", "O", letters);
			letters.remove("Z");
		}
		
		if (letters.containsKey("W")) {
			int count = letters.get("W");
			while (count > 0) {
				numbers.add(2);
				count--;
			}

			descrease("W", "T", letters);
			descrease("W", "O", letters);
			letters.remove("W");
		}

		if (letters.containsKey("U")) {
			int count = letters.get("U");
			while (count > 0) {
				numbers.add(4);
				count--;
			}

			descrease("U", "F", letters);
			descrease("U", "O", letters);
//			letters.remove("U");
			descrease("U", "R", letters);
			letters.remove("U");
		}

		if (letters.containsKey("X")) {
			int count = letters.get("X");
			while (count > 0) {
				numbers.add(6);
				count--;
			}

			descrease("X", "S", letters);
			descrease("X", "I", letters);
			letters.remove("X");
		}

		if (letters.containsKey("G")) {
			int count = letters.get("G");
			while (count > 0) {
				numbers.add(8);
				count--;
			}

			descrease("G", "E", letters);
			descrease("G", "I", letters);
//			letters.remove("G");
			descrease("G", "H", letters);
			descrease("G", "T", letters);
			letters.remove("G");
		}
		
		if (letters.containsKey("O")) {
			int count = letters.get("O");
			if(count > 0){
				while (count > 0) {
					numbers.add(1);
					count--;
				}
				
//				letters.remove("O");
				descrease("O", "N", letters);
				descrease("O", "E", letters);
				letters.remove("O");
			}		
		}
		if (letters.containsKey("T")) {
			int count = letters.get("T");
			if(count > 0){
				while (count > 0) {
					numbers.add(3);
					count--;
				}
				
//				letters.remove("T");
				descrease("T", "H", letters);
				descrease("T", "R", letters);
				descrease("T", "E", letters);
				descrease("T", "E", letters);
				letters.remove("T");
			}		
		}
		if (letters.containsKey("F")) {
			int count = letters.get("F");
			if(count > 0){
				while (count > 0) {
					numbers.add(5);
					count--;
				}
				
//				letters.remove("F");
				descrease("F", "I", letters);
				descrease("F", "V", letters);
				descrease("F", "E", letters);
				letters.remove("F");

			}		
		}
		if (letters.containsKey("S")) {
			int count = letters.get("S");
			if(count > 0){
				while (count > 0) {
					numbers.add(7);
					count--;
				}
				
//				letters.remove("S");
				descrease("S", "E", letters);
				descrease("S", "V", letters);
				descrease("S", "E", letters);
				descrease("S", "N", letters);
				letters.remove("S");

			}		
		}
		if (letters.containsKey("I")) {
			int count = letters.get("I");
			if(count > 0){
				while (count > 0) {
					numbers.add(9);
					count--;
				}
				
				descrease("I", "N", letters);
//				letters.remove("I");
				descrease("I", "N", letters);
				descrease("I", "E", letters);	
				letters.remove("I");

			}		
		}
		Integer[] array = numbers.toArray(new Integer[numbers.size()]);
		Arrays.sort(array);
		
		System.out.println("Case #" + caseNumber + ": " + printArr(array));

	}
	private static String printArr(Integer[] array) {
		StringBuilder stringBuilder = new StringBuilder();
		for(Integer a : array){
			stringBuilder.append(a);
		}
		
		return stringBuilder.toString();
	}

	private static void descrease(String literal ,String other, Map<String, Integer> letters){
		Integer count = letters.get(literal);
		Integer countOther = letters.get(other);
		countOther = countOther - count;
		letters.put(other, countOther);
	}
	private static void addToList(String literal ,ArrayList<Integer> numbers, Map<String, Integer> letters){
		if(letters.containsKey(literal)){
			int count = letters.get(literal);
			while(count > 0 ){
				numbers.add(2);
				count--;
			}
		}
	}

}
