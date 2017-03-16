import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Problem1CB {
	
	
	/*
	public static List<Integer> getInterlaps(String str) {
		
		ArrayList<Integer> interLaps = new ArrayList<Integer>();
		
		for (int i=1;i<str.length();++i) {
			if (str.substring(i,str.length()-i).equals(str.substring(0,str.length()-i))) {
				interLaps.add(i);
			}
		}
		
		return interLaps;
	}
	*/
	
	static class Typewriter {
		
		public int keyNum;
		public HashMap<Character,Integer> keyFrequency;
		
		public Typewriter(String s) {
			
			keyNum = s.length();
			keyFrequency = new HashMap<Character,Integer>();
			
			for (int i=0;i<s.length();++i) {
				char key = s.charAt(i);
				if (keyFrequency.containsKey(key)) {
					keyFrequency.put(key,keyFrequency.get(key)+1);
				} else {
					keyFrequency.put(key,1);
				}
			}
		}
		
		public double getProbality(char key) {
			
			if (!keyFrequency.containsKey(key)) {
				return 0;
			}
			
			return (double)keyFrequency.get(key)/(double)keyNum;
		}
		
		public Set<Character> charSet() {
			return keyFrequency.keySet();
		}
	}
	
	static class Result {
		public Result(String w, int k) {
			word = w;
			maxKeys = k;
			maxHit = 0;
			expectedHit = 0;
		}
		public String word;
		public int maxKeys;
		public int maxHit;
		public double expectedHit;
	}
	
	
	static int countHits(String typed, String word) {
		
		int count = 0;
		
		for (int i=0;i<typed.length()-word.length()+1;++i) {
			
			if (typed.substring(i,i+word.length()).equals(word)) {
				++count;
			}
		}
		
		return count;
	}
	
	
	static void getResult(String typed, double p, Result r, Typewriter t) {
		
		if (typed.length() == r.maxKeys) {
			int hits = countHits(typed,r.word);
			if (hits > r.maxHit) {
				r.maxHit = hits;
			}
			r.expectedHit += (double)hits * p;
			return;
		}
		
		for (char c : t.charSet()) {
			getResult(typed + c, p * t.getProbality(c), r, t);
		}
	}
	
	/*
	class Steps {
		public int keys;
		public double probability;
		public int words;
	}
	
	
	public static List<Steps> getSteps(String word, Typewriter typewriter) {
		
		List<Steps> steps = new ArrayList<Steps>();
		List<Integer> interlaps = getInterlaps(word);
		
		for (int i=0;i<word.length()-1;++i) {
			if (word.substring(word.length()-i).equals(word.substring(0,i))) {
				Steps s = new Steps();
				s.keys = word.length()-i;
				s.probability = 1;
				for (int j=0; j<i; ++j) {
					s.probability *= typewriter.getProbality(word.charAt(j));
				}
				s.words = 0;
				String bigword = word + word.substring(i);
				for (int j=1;j<word.length()-i;++j) {
					if (bigword.substring(j,j+word.length()).equals(word)) {
						++s.words;
					}
				}
				steps.add(s);
			}
		}
		
		
		
		for (Steps s : steps) {
			
		}
	}
	*/
	
	

	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(new File(args[0]));
        File outFile = new File(args[1]);
        FileOutputStream os = new FileOutputStream(outFile);
        OutputStreamWriter osw = new OutputStreamWriter(os); 
        Writer w = new BufferedWriter(osw);
		        
		int cases = sc.nextInt();

		for (int i=0; i<cases; ++i) {
			
			int K = sc.nextInt();
			int L = sc.nextInt();
			int S = sc.nextInt();
			
			sc.nextLine();
			String tStr = sc.nextLine();
			String wStr = sc.nextLine();
			
			Result r = new Result(wStr,S);
			getResult("",1,r,new Typewriter(tStr));
			
			w.write("Case #" + Integer.toString(i+1) + ": " + Double.toString((double)r.maxHit - r.expectedHit) + "\n");
		}

		w.close();
		sc.close();
	}
}
