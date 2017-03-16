package qualifierFun;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class GuessItBetter {
	public static void main(String[] args) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter("output3.txt")); 
			BufferedReader in  = new BufferedReader(new FileReader("input.txt"));
			int answer =1;
			System.out.print(String.format("Case #%s:\n", answer));
			out.write(String.format("Case #%s:\n", answer));
			String strLine = in.readLine();
			strLine = in.readLine();
			String inputs[] = strLine.split(" ");
			int totalCases = Integer.parseInt(inputs[0]);
			int totCards = Integer.parseInt(inputs[1]);
			int max = Integer.parseInt(inputs[2]);
			int numProducts = Integer.parseInt(inputs[3]);
			for(int i = 0; i < totalCases; i++) {
				strLine = in.readLine();
				inputs = strLine.split(" ");
				List<Integer> products = new ArrayList<Integer>();
				for(String input : inputs) {
					products.add(Integer.parseInt(input));
				}
				Collections.sort(products);
				int cardsUsed = 0;
				Map<Integer, Integer> cardsUsedMap = new HashMap<Integer, Integer>();
				initMap(cardsUsedMap, max);
				for(int j = products.size() - 1; j>=0 && cardsUsed < totCards;j--) {
					int product = products.get(j);
					if (product == 1) {
						break;
					}
					Map<Integer, Integer> thisProdCards = new HashMap<Integer, Integer>();
					initMap(thisProdCards, max);
					for(int k = max; k >= 2 && product != 1; k--) {
						while(product % k == 0) {
							thisProdCards.put(k, thisProdCards.get(k) +1);
						    product /= k;
						}
					}
					for (Entry<Integer, Integer> entry : thisProdCards.entrySet()) {
						int prev = cardsUsedMap.get(entry.getKey());
						int diff = entry.getValue() - prev;
						if (diff > 0) {
							cardsUsed += diff;
							cardsUsedMap.put(entry.getKey(), entry.getValue());
						}
					}
				}
				String guess = getStringForm(cardsUsedMap, totCards);
				System.out.print(String.format("%s\n", guess));
				out.write(String.format("%s\n", guess));
				answer++;
			}
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("I'd want to know");
		} catch (IOException e) {
			System.out.println("I'd want to know io");
		}
		System.out.println("done");

	}
	
	private static String getStringForm(Map<Integer, Integer> cardsUsedMap, int totCards) {
		StringBuilder theAnswer = new StringBuilder();
		for (Entry<Integer, Integer> entry : cardsUsedMap.entrySet()) {
			for(int i = 0; i < entry.getValue(); i++) {
				theAnswer.append(entry.getKey());
			}
		}
		while (theAnswer.length() < totCards) {
			theAnswer.append(2);
		}
		return theAnswer.substring(0, totCards);
	}

	private static void initMap(Map<Integer, Integer> map, int max) {
		for (int i = 2; i <= max; i++) {
			map.put(i, 0);
		}
	}
}
