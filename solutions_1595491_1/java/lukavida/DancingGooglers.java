import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;


public class DancingGooglers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		BufferedReader inFile = null;
		try {
			inFile = new BufferedReader(
				    new InputStreamReader(
				        new BufferedInputStream(new FileInputStream("B-large.in")),
				        "UTF-8"
				    )
				);
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		int numCases = 0;
		List<Integer> goodDancersInCase = new ArrayList<Integer>();
		try {
			numCases = Integer.parseInt(inFile.readLine());
			for (int caseNum = 0; caseNum < numCases; caseNum++) {	
				
				String[] words;
					words = inFile.readLine().split(" ");
				List<Integer> inputNums = new ArrayList<Integer>();
				for (String word : words) {
					inputNums.add(Integer.parseInt(word));
				}
				
				int nDancers = inputNums.remove(0);
				int nSurprisingTriplets = inputNums.remove(0);
				int bestResultLimit = inputNums.remove(0);
				List<Integer> totalPoints = new ArrayList<Integer>(inputNums);
				
				int maxDancersAboveResultLimit = 0;
				for (Integer dancerTotalPoints : totalPoints) {
					if((dancerTotalPoints + 2) >= 3 * bestResultLimit) {
						maxDancersAboveResultLimit += 1;
					} else if ((dancerTotalPoints + 4) >= 3 * bestResultLimit &&
							nSurprisingTriplets > 0 &&
							dancerTotalPoints >= bestResultLimit
							) {
						maxDancersAboveResultLimit += 1;
						nSurprisingTriplets--;
					}
				}
				goodDancersInCase.add(maxDancersAboveResultLimit);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		try {
			BufferedWriter bw = new BufferedWriter(
					new OutputStreamWriter(
							new FileOutputStream("B-large.out.txt"), "UTF-8"
							)
					);
			
			for (int caseNum = 0; caseNum < numCases; caseNum++) {
				bw.append("Case #" + (caseNum+1) + ": " + goodDancersInCase.get(caseNum));				
				bw.newLine();
			}
			bw.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	
	}

}
