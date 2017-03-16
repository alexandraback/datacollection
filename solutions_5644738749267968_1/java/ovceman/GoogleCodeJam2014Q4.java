import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;


public class GoogleCodeJam2014Q4 {

	ArrayList<String> inputLines = new ArrayList<String>();
	ArrayList<String> outputLines = new ArrayList<String>();
	private static final String PATH ="/Users/koichisakumoto/Documents/GoogleCodeJam/";
	
	public static void main(String[] args) {
		GoogleCodeJam2014Q4 inst = new GoogleCodeJam2014Q4();
		inst.getLines(PATH + "Q4/D-large.in.txt");
		inst.solveProblem();
		inst.putLines(PATH + "Q4/answer2.txt");
	}

	private void solveProblem(){
		int currentLine = 0;
		int totalNum = Integer.parseInt(inputLines.get(currentLine++));
		
		for (int problemNum = 1; problemNum <= totalNum; problemNum++ ) {
			
			// input problem
			int stoneNum = Integer.parseInt(inputLines.get(currentLine++));
			String[] naomiLine = inputLines.get(currentLine++).split(" ");
			String[] kenLine = inputLines.get(currentLine++).split(" ");
			ArrayList<Double> naomiStones = new ArrayList<Double>();
			ArrayList<Double> kenStones = new ArrayList<Double>();
			for (int i = 0; i < stoneNum; i++){
				naomiStones.add(Double.parseDouble(naomiLine[i]));
				kenStones.add(Double.parseDouble(kenLine[i]));
			}
			
			// solve problem
			Collections.sort(naomiStones);
			Collections.sort(kenStones);
			int kaoriWarWinCount = stoneNum - kenWarWins(naomiStones, kenStones);
			int kaoriDeceitfulWarWinCount = kenWarWins(kenStones, naomiStones);

			// make answer
			outputLines.add("Case #" + problemNum + ": "
							+ kaoriDeceitfulWarWinCount + " "
							+ kaoriWarWinCount
							);
			
		}
	}
	
	private int kenWarWins(ArrayList<Double> naomiStones, ArrayList<Double> kenStones){
		int stoneNum = naomiStones.size();
		int kenWinCount = 0;
		int i = 0;
		for (Double naomiStone : naomiStones) {
			while (true) {
				if ( i >= stoneNum ) return kenWinCount;
				if ( naomiStone.doubleValue() < kenStones.get(i).doubleValue() ) {
					i++;
					break;
				}
				i++;
			}
			kenWinCount++;
		}
		return kenWinCount;
	}


	private void getLines(String fileName){
		try {
            FileReader in = new FileReader(fileName);
            BufferedReader br = new BufferedReader(in);
            String line;
            while ((line = br.readLine()) != null) {
            	inputLines.add(line);
            }
            br.close();
            in.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
	private void putLines(String fileName){
		try {
			FileWriter out = new FileWriter(fileName); // new file
			BufferedWriter bw = new BufferedWriter(out);
            for ( String line : outputLines ){
            	bw.write(line + "\r\n");
            }
            bw.close();
            out.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
}
