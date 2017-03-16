import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class Main {
    private static final TreeSet<LetterWithProb> probability = new TreeSet<LetterWithProb>(){{
    	add(new LetterWithProb('a', 0.08167));
    	add(new LetterWithProb('b', 0.01492));
    	add(new LetterWithProb('c', 0.02782));
    	add(new LetterWithProb('d', 0.04253));
    	add(new LetterWithProb('e', 0.01702));
    	add(new LetterWithProb('f', 0.02228));
    	add(new LetterWithProb('g', 0.02015));    	 
    	add(new LetterWithProb('h', 0.06094));
    	add(new LetterWithProb('i', 0.06966));
    	add(new LetterWithProb('j', 0.00153));
    	add(new LetterWithProb('k', 0.00772));
    	add(new LetterWithProb('l', 0.04025));
    	add(new LetterWithProb('m', 0.02406));
    	add(new LetterWithProb('n', 0.06749));
    	add(new LetterWithProb('o', 0.07507));
    	add(new LetterWithProb('p', 0.01929));
    	add(new LetterWithProb('q', 0.00095));
    	add(new LetterWithProb('r', 0.05987));
    	add(new LetterWithProb('s', 0.06327));
    	add(new LetterWithProb('t', 0.09056));
    	add(new LetterWithProb('u', 0.02758));
    	add(new LetterWithProb('v', 0.00978));    	 
    	add(new LetterWithProb('w', 0.02360));
    	add(new LetterWithProb('x', 0.00150));
    	add(new LetterWithProb('y', 0.01974));
    	add(new LetterWithProb('z', 0.00074));

//    	add(new LetterWithProb('a', 11.602));	
//    	add(new LetterWithProb('b', 4.702));	
//    	add(new LetterWithProb('c', 3.511));	
//    	add(new LetterWithProb('d', 2.670));	
//    	add(new LetterWithProb('e', 2.000));	
//    	add(new LetterWithProb('f', 3.779));	
//    	add(new LetterWithProb('g', 1.950));	
//    	add(new LetterWithProb('h', 7.232));	
//    	add(new LetterWithProb('i', 6.286));	
//    	add(new LetterWithProb('j', 0.631));	
//    	add(new LetterWithProb('k', 0.690));	
//    	add(new LetterWithProb('l', 2.705));	
//    	add(new LetterWithProb('m', 4.374));	
//    	add(new LetterWithProb('n', 2.365));	
//    	add(new LetterWithProb('o', 6.264));	
//    	add(new LetterWithProb('p', 2.545));	
//    	add(new LetterWithProb('q', 0.173));	
//    	add(new LetterWithProb('r', 1.653));	
//    	add(new LetterWithProb('s', 7.755));	
//    	add(new LetterWithProb('t', 16.671));	
//    	add(new LetterWithProb('u', 1.487));	
//    	add(new LetterWithProb('v', 0.619));	
//    	add(new LetterWithProb('w', 6.661));	
//    	add(new LetterWithProb('x', 0.005));	
//    	add(new LetterWithProb('y', 1.620));	
//    	add(new LetterWithProb('z', 0.050));
    }};
	
	public static void main(String[] args) {
		String s1 = "qzejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String s2 = "zqour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
		Map<Character, Character> lettersMapping = new HashMap<Character, Character>();
		for (int i = 0; i < s1.length(); i++) {
			lettersMapping.put(s1.charAt(i), s2.charAt(i));
		}
		StringBuffer[][][] a = new StringBuffer[1][][];
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
				String line = br.readLine();
				BufferedWriter out = new BufferedWriter(new FileWriter("outadd.txt"));
				int tests = Integer.valueOf(line.trim());
				String[] inputs = new String[tests];
				int total = 0;
				Map<Character, Integer> count = new HashMap<Character, Integer>();
				
				for (int i = 0; i < tests; i++) {
					inputs[i] = br.readLine();
					for (int j = 0; j < inputs[i].length(); j++) {
						char curLetter = inputs[i].charAt(j);
						if (curLetter != ' ') {
							int prev = 0;
							if (count.containsKey(curLetter)) {
								prev = count.get(curLetter);
								total++;
							}
							count.put(curLetter, prev+1);
						}
//						if (curLetter != ' ' && (j == 0 || inputs[i].charAt(j - 1) == ' ')) {
//							int prev = 0;
//							if (count.containsKey(curLetter)) {
//								prev = count.get(curLetter);
//								total++;
//							}
//							count.put(curLetter, prev+1);
//						}
						
					}
				}
				TreeSet<LetterWithProb> newProbability = new TreeSet<LetterWithProb>();
				for (int i = (int)'a'; i <= (int)'z'; i++) {
					char letter = (char)i;
					double occur = 0;
					if (count.containsKey(letter)) {
						occur = count.get(letter);
					}
					newProbability.add(new LetterWithProb((char)i, occur/total));
				}
//				Map<Character, Character> lettersMapping = new HashMap<Character, Character>();
//				for (int i = (int)'a'; i <= (int)'z'; i++) {
//					char letter = (char)i;
//					double occur = 0;
//					if (count.containsKey(letter)) {
//						occur = count.get(letter);
//					}
//					newProbability.add(new LetterWithProb((char)i, occur/total));
//				}
//				int length = newProbability.size();
//				for (int i = 0; i < length; i++) {
//					LetterWithProb l1 = newProbability.pollFirst();
//					LetterWithProb l2 = probability.pollFirst();
//					
//					lettersMapping.put(l1.letter, l2.letter);
//				}
				
				for (int i = 0; i < tests; i++) {
					out.write("Case #"+ (i + 1) +": ");
					for (int j = 0; j < inputs[i].length(); j++) {
						char curLetter = inputs[i].charAt(j);
						if (curLetter == ' ') {
							out.write(curLetter);
						}
						else {
							out.write(lettersMapping.get(curLetter));
						}
					}
					out.write("\n");
				}
				out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
    
    static class LetterWithProb implements Comparable<LetterWithProb>{
    	private final char letter;
    	private final double prob;
    	
    	public LetterWithProb(char letter, double prob) {
    		this.letter = letter;
    		this.prob = prob;
		}

		@Override
		public int compareTo(LetterWithProb o) {
			int result = Double.compare(this.prob, o.prob);
			if (result == 0) {
				result = (int)this.letter - (int)o.letter;
			}
			return result;
		}
    }
}