
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class ScorePair {
	public String score1;
	public String score2;
	
	public ScorePair(String score1, String score2) {
		this.score1 = score1;
		this.score2 = score2;
	}
}

public class A {
	
	private static ScorePair findPairGreater(String score1, String score2, int from) {
		StringBuffer buf1 = new StringBuffer();
		StringBuffer buf2 = new StringBuffer();
		
		for (int i = from; i < score1.length(); i++) {
			if (score1.charAt(i) == '?') {
				buf1.append('0');
			} else {
				buf1.append(score1.charAt(i));
			}
			
			if (score2.charAt(i) == '?') {
				buf2.append('9');
			} else {
				buf2.append(score2.charAt(i));
			}
		}
		
		return new ScorePair(buf1.toString(), buf2.toString());
	}
	
	private static ScorePair findPairLess(String score1, String score2, int from) {
		StringBuffer buf1 = new StringBuffer();
		StringBuffer buf2 = new StringBuffer();
		
		for (int i = from; i < score1.length(); i++) {
			if (score1.charAt(i) == '?') {
				buf1.append('9');
			} else {
				buf1.append(score1.charAt(i));
			}
			
			if (score2.charAt(i) == '?') {
				buf2.append('0');
			} else {
				buf2.append(score2.charAt(i));
			}
		}
		
		return new ScorePair(buf1.toString(), buf2.toString());
	}
	
	private static List<ScorePair> findPairs(String score1, String score2, int firstDiff) {
		StringBuffer buf = new StringBuffer();
		
		for (int i = 0; i < firstDiff; i++) {
			if (score1.charAt(i) == '?' && score2.charAt(i) == '?') {
				buf.append('0');
			} else if (score1.charAt(i) == '?') {
				buf.append(score2.charAt(i));
			} else if (score2.charAt(i) == '?') {
				buf.append(score1.charAt(i));
			} else if (score2.charAt(i) == score1.charAt(i)) {
				buf.append(score1.charAt(i));
			} else {
				return null;
			}
		}
		
		List<ScorePair> pairs = new ArrayList<ScorePair>();
		
		if (firstDiff == score1.length()) {
			pairs.add(new ScorePair(buf.toString(), buf.toString()));
		} else if (score1.charAt(firstDiff) == '?' && score2.charAt(firstDiff) == '?') {
			ScorePair abovePair = findPairGreater(score1, score2, firstDiff + 1);

			pairs.add(new ScorePair(buf.toString() + "1" + abovePair.score1, buf.toString() + "0" + abovePair.score2));
			
			ScorePair belowPair = findPairLess(score1, score2, firstDiff + 1);
			
			pairs.add(new ScorePair(buf.toString() + "0" + belowPair.score1, buf.toString() + "1" + belowPair.score2));
		} else if (score1.charAt(firstDiff) == '?') {
			char c = score2.charAt(firstDiff);
			
			if (c != '9') {
				ScorePair abovePair = findPairGreater(score1, score2, firstDiff + 1);

				pairs.add(new ScorePair(buf.toString() + (char)(c + 1) + abovePair.score1, buf.toString() + c + abovePair.score2));
			}
			
			if (c != '0') {
				ScorePair belowPair = findPairLess(score1, score2, firstDiff + 1);
				
				pairs.add(new ScorePair(buf.toString() + (char)(c - 1) + belowPair.score1, buf.toString() + c + belowPair.score2));
			}
		} else if (score2.charAt(firstDiff) == '?') {
			char c = score1.charAt(firstDiff);
			
			if (c != '0') {
				ScorePair abovePair = findPairGreater(score1, score2, firstDiff + 1);

				pairs.add(new ScorePair(buf.toString() + c + abovePair.score1, buf.toString() + (char)(c - 1) + abovePair.score2));
			}
			
			if (c != '9') {
				ScorePair belowPair = findPairLess(score1, score2, firstDiff + 1);
				
				pairs.add(new ScorePair(buf.toString() + c + belowPair.score1, buf.toString() + (char)(c + 1) + belowPair.score2));
			}
		} else if (score1.charAt(firstDiff) < score2.charAt(firstDiff)) {
			ScorePair belowPair = findPairLess(score1, score2, firstDiff + 1);
			
			pairs.add(new ScorePair(buf.toString() + score1.charAt(firstDiff) + belowPair.score1, buf.toString() + score2.charAt(firstDiff) + belowPair.score2));
		} else if (score1.charAt(firstDiff) > score2.charAt(firstDiff)) {
			ScorePair abovePair = findPairGreater(score1, score2, firstDiff + 1);
			
			pairs.add(new ScorePair(buf.toString() + score1.charAt(firstDiff) + abovePair.score1, buf.toString() + score2.charAt(firstDiff) + abovePair.score2));			
		}
		
		return pairs;
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		
		for (int Q = 1; Q <= T; Q++) {
			String score1 = scan.next();
			String score2 = scan.next();
			
			List<ScorePair> pairs = new ArrayList<ScorePair>();
			
			for (int i = 0; i <= score1.length(); i++) {
				List<ScorePair> shard = findPairs(score1, score2, i);
				
				if (shard != null) {
					for (ScorePair pair : shard) {
						//System.out.printf("-- %d -- %s %s\n", i, pair.score1, pair.score2);
					}
					
					pairs.addAll(shard);
				}
			}
			
			long bestDiff = Long.MAX_VALUE;
			long minScore1 = Long.MAX_VALUE;
			long minScore2 = Long.MAX_VALUE;
			ScorePair bestPair = null;
			
			for (ScorePair pair : pairs) {
				long num1 = Long.parseLong(pair.score1);
				long num2 = Long.parseLong(pair.score2);
				
				long diff = num1 <= num2 ? num2 - num1 : num1 - num2;
				
				if (diff < bestDiff || diff == bestDiff && num1 < minScore1 || diff == bestDiff && num1 == minScore1 && num2 < minScore2) {
					bestDiff = diff;
					minScore1 = num1;
					minScore2 = num2;
					bestPair = pair;
				}
			}
			
			if (bestPair == null) {
				System.out.printf("Case #%d: BADNESS\n", Q);
			} else {
				System.out.printf("Case #%d: %s %s\n", Q, bestPair.score1, bestPair.score2);
			}
		}
	}
}
