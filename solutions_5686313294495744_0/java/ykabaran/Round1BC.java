package googlecodejam2016;

import googlecodejam2016.GoogleCodeJam2016.Problem;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 *
 * @author YILDIZ KABARAN
 */
public class Round1BC implements Problem {
	
	private int numTopics;
	private String[][] topics;
	private int maxFakes;
	
	private boolean[] definitelyOriginals;
	private boolean[] definitelyFakes;

  @Override
  public void setup(BufferedReader input) throws IOException {
		numTopics = Integer.parseInt(input.readLine());
		topics = new String[numTopics][];
		for(int i=0; i<numTopics; ++i){
			topics[i] = input.readLine().split(" ");
		}
  }
	
	private boolean isDefinitelyOriginal(int n){
		boolean firstRepeats = false;
		boolean secondRepeats = false;
		for(int i=0; i<numTopics; ++i){
			if(i == n){
				continue;
			}
			if(!firstRepeats && topics[n][0].equals(topics[i][0])){
				firstRepeats = true;
			}
			if(!secondRepeats && topics[n][1].equals(topics[i][1])){
				secondRepeats = true;
			}
			if(firstRepeats && secondRepeats){
				return false;
			}
		}
		
		return true;
	}
	
	private boolean isDefinitelyFake(int n){
		boolean firstRepeats = false;
		boolean secondRepeats = false;
		for(int i=0; i<numTopics; ++i){
			if(i == n || !definitelyOriginals[i]){
				continue;
			}
			if(!firstRepeats && topics[n][0].equals(topics[i][0])){
				firstRepeats = true;
			}
			if(!secondRepeats && topics[n][1].equals(topics[i][1])){
				secondRepeats = true;
			}
			if(firstRepeats && secondRepeats){
				return true;
			}
		}
		
		return false;
	}

  @Override
  public void solve() {
		definitelyOriginals = new boolean[numTopics];
		definitelyFakes = new boolean[numTopics];
		for(int i=0; i<numTopics; ++i){
			definitelyOriginals[i] = isDefinitelyOriginal(i);
		}
		for(int i=0; i<numTopics; ++i){
			definitelyFakes[i] = isDefinitelyFake(i);
		}
		
		Map<String,Boolean> originalFirsts = new HashMap<>();
		Map<String,Boolean> originalSeconds = new HashMap<>();
		int questionableCount = 0;
		int originalFirstCount = 0;
		int originalSecondCount = 0;
		
		for(int i=0; i<numTopics; ++i){
			if(definitelyOriginals[i] || definitelyFakes[i]){
				continue;
			}
			++questionableCount;
			Boolean firstExists = originalFirsts.get(topics[i][0]);
			if(firstExists == null){
				originalFirsts.put(topics[i][0], true);
				++originalFirstCount;
			}
			Boolean secondExists = originalSeconds.get(topics[i][1]);
			if(secondExists == null){
				originalSeconds.put(topics[i][1], true);
				++originalSecondCount;
			}
		}
		
		maxFakes = 0;
		for(int i=0; i<numTopics; ++i){
			if(definitelyFakes[i]){
				++maxFakes;
			}
		}
		maxFakes += questionableCount;
		maxFakes -= Math.max(originalFirstCount, originalSecondCount);
  }

  @Override
  public String getSolution() {
    return Integer.toString(maxFakes);
  }

}
