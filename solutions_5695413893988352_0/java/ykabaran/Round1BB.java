package googlecodejam2016;

import googlecodejam2016.GoogleCodeJam2016.Problem;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 *
 * @author YILDIZ KABARAN
 */
public class Round1BB implements Problem {
	
	private static final char UNKNOWN = '?';
	private static final char ZERO = '0';
	private static final char NINE = '9';
	
	private String coders;
	private String jammers;
	private String answer;

  @Override
  public void setup(BufferedReader input) throws IOException {
		String[] args = input.readLine().split(" ");
		coders = args[0];
		jammers = args[1];
  }
	
	private void solveIncorrectButFast(){
		int numDigits = coders.length();
		int smaller = -1;
		int lastDigit = -1;
		
		char[] codersResolved = new char[numDigits];
		char[] jammersResolved = new char[numDigits];
		for(int i=0; i<numDigits; ++i){
			char codersChar = coders.charAt(i);
			char jammersChar = jammers.charAt(i);
			if(codersChar == UNKNOWN && jammersChar == UNKNOWN){
				codersResolved[i] = ZERO;
				jammersResolved[i] = ZERO;
			} else if(codersChar != UNKNOWN && jammersChar == UNKNOWN){
				codersResolved[i] = codersChar;
				jammersResolved[i] = codersChar;
			} else if(codersChar == UNKNOWN && jammersChar != UNKNOWN){
				codersResolved[i] = jammersChar;
				jammersResolved[i] = jammersChar;
			} else if(codersChar == jammersChar){
				codersResolved[i] = codersChar;
				jammersResolved[i] = codersChar;
			} else {
				lastDigit = i;
				codersResolved[i] = codersChar;
				jammersResolved[i] = jammersChar;
				int codersNum = Integer.parseInt(Character.toString(codersChar));
				int jammersNum = Integer.parseInt(Character.toString(jammersChar));
				if(codersNum < jammersNum){
					smaller = 0;
				} else {
					smaller = 1;
				}
				break;
			}
		}
		
		if(lastDigit >= 0){
			for(int i=lastDigit + 1; i<numDigits; ++i){
				char codersChar = coders.charAt(i);
				char jammersChar = jammers.charAt(i);
				if(smaller == 0){
					codersResolved[i] = codersChar == UNKNOWN ? NINE : codersChar;
					jammersResolved[i] = jammersChar == UNKNOWN ? ZERO : jammersChar;;
				} else {
					codersResolved[i] = codersChar == UNKNOWN ? ZERO : codersChar;
					jammersResolved[i] = jammersChar == UNKNOWN ? NINE : jammersChar;;
				}
			}
		}
		
		answer = new String(codersResolved) + " " + new String(jammersResolved);
	}
	
	private boolean incrementTry(int[] currTry){
		for(int i=currTry.length - 1; i>=0; --i){
			++currTry[i];
			if(currTry[i] > 9){
				currTry[i] = 0;
				if(i == 0){
					return false;
				}
			} else {
				break;
			}
		}
		return true;
	}
	
	private int combineAndGetNumber(String score, int length, boolean[] missingDigits, int[] digits){
		StringBuilder combinedBuilder = new StringBuilder();
		int currDigit = 0;
		for(int i=0; i<length; ++i){
			if(missingDigits[i]){
				combinedBuilder.append(Integer.toString(digits[currDigit]));
				++currDigit;
			} else {
				combinedBuilder.append(score.charAt(i));
			}
		}
		
		return Integer.parseInt(combinedBuilder.toString());
	}
	
	private List<Integer> generateAllPossibilities(String score){
		int numMissing = 0;
		int numDigits = score.length();
		boolean[] missingDigits = new boolean[numDigits];
		for(int i=0; i<numDigits; ++i){
			if(score.charAt(i) == UNKNOWN){
				++numMissing;
				missingDigits[i] = true;
			} else {
				missingDigits[i] = false;
			}
		}
		
		List<Integer> possibilities = new ArrayList<>();
		if(numMissing == 0){
			possibilities.add(Integer.parseInt(score));
		} else {
			int[] currTry = new int[numMissing];
			for(int i=0; i<numMissing; ++i){
				currTry[i] = 0;
			}

			do {
				possibilities.add(combineAndGetNumber(score, numDigits, missingDigits, currTry));
			} while(incrementTry(currTry));
		}
		
		return possibilities;
	}

  @Override
  public void solve() {
		List<Integer> codersPossibilities = generateAllPossibilities(coders);
		List<Integer> jammersPossibilities = generateAllPossibilities(jammers);
		
		int minDifference = -1;
		int codersMinScore = 0;
		int jammersMinScore = 0;
		for(Integer codersScore : codersPossibilities){
			for(Integer jammersScore : jammersPossibilities){
				int currDifference = Math.abs(codersScore - jammersScore);
				if(minDifference < 0 || currDifference < minDifference){
					minDifference = currDifference;
					codersMinScore = codersScore;
					jammersMinScore = jammersScore;
				}
			}
		}
		
		int numDigits = coders.length();
		String codersStr = Integer.toString(codersMinScore);
		String jammersStr = Integer.toString(jammersMinScore);
		
		while(codersStr.length() < numDigits){
			codersStr = "0" + codersStr;
		}
		
		while(jammersStr.length() < numDigits){
			jammersStr = "0" + jammersStr;
		}
		
		answer = codersStr + " " + jammersStr;
  }

  @Override
  public String getSolution() {
    return answer;
  }

}
