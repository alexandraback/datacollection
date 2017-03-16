import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class GoogleCodeJam2015Q2 {

	ArrayList<String> inputLines = new ArrayList<String>();
	ArrayList<String> outputLines = new ArrayList<String>();
	private static final String PATH ="/Users/koichisakumoto/Documents/GoogleCodeJam/2015/Q2/";
	
	public static void main(String[] args) {
		GoogleCodeJam2015Q2 inst = new GoogleCodeJam2015Q2();
		//inst.getLines(PATH + "test.txt");
		inst.getLines(PATH + "B-small-attempt2.in.txt");
		//inst.getLines(PATH + "A-large.in.txt");
		inst.solveProblem();
		//inst.putLines(PATH + "answer_test.txt");
		inst.putLines(PATH + "answer_small.txt");
		//inst.putLines(PATH + "answer_large.txt");
	}

	private void solveProblem(){
		int currentLine = 0;
		int totalNum = Integer.parseInt(inputLines.get(currentLine++));
		
		for (int problemNum = 1; problemNum <= totalNum; problemNum++ ) {
			
			// input problem
			int D = Integer.parseInt(inputLines.get(currentLine++));
			String[] plates = inputLines.get(currentLine++).split(" ");
			int[] P = new int[plates.length];
			for(int i = 0; i < P.length; i++){
				P[i] = Integer.valueOf(plates[i]);
			}
			
			// solve problem
			int maxValue = maxValue(P);
			int[] cost = new int[maxValue];
			for(int r = 0; r < cost.length; r++){
				int normal_round = r+1;
				int special_round = 0;
				for(int i = 0; i < P.length; i++){
					special_round += (P[i]/normal_round - ((P[i] % normal_round == 0)? 1 : 0));
				}
				cost[r] = normal_round + special_round;
			}
			int answer = minValue(cost);

			// 解答を作る
			outputLines.add("Case #" + problemNum + ": " + answer);
		}
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
	
	private int maxIndex(int array[]){
		int max = 0;
		for(int i = 0; i < array.length; i++){
			if(array[max] < array[i]){
				max = i;
			}
		}
		return max;
	}
	
	private int maxValue(int array[]){
		int index = maxIndex(array);
		return array[index];
	}
	
	private int minIndex(int array[]){
		int min = 0;
		for(int i = 0; i < array.length; i++){
			if(array[min] > array[i]){
				min = i;
			}
		}
		return min;
	}
	
	private int minValue(int array[]){
		int index = minIndex(array);
		return array[index];
	}
	

}
