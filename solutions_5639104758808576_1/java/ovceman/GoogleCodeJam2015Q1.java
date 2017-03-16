import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class GoogleCodeJam2015Q1 {

	ArrayList<String> inputLines = new ArrayList<String>();
	ArrayList<String> outputLines = new ArrayList<String>();
	private static final String PATH ="/Users/koichisakumoto/Documents/GoogleCodeJam/2015/Q1/";
	
	public static void main(String[] args) {
		GoogleCodeJam2015Q1 inst = new GoogleCodeJam2015Q1();
		//inst.getLines(PATH + "A-small-attempt0.in.txt");
		inst.getLines(PATH + "A-large.in.txt");
		//inst.getLines(PATH + "test.txt");
		inst.solveProblem();
		inst.putLines(PATH + "answer_large.txt");
	}

	private void solveProblem(){
		int currentLine = 0;
		int totalNum = Integer.parseInt(inputLines.get(currentLine++));
		
		for (int problemNum = 1; problemNum <= totalNum; problemNum++ ) {
			
			// input problem 
			String[] problem = inputLines.get(currentLine++).split(" ");
			int maxShyness = Integer.parseInt(problem[0]);
			int[] audience = new int[problem[1].length()];
			for(int i = 0; i < audience.length; i++){
				audience[i] = Character.getNumericValue(problem[1].charAt(i));
			}
			
			// solve problem
			int[] needed = new int[audience.length];
			for(int i = 0; i < needed.length; i++){
				needed[i] = i;
				for(int j = 0; j < i; j++){
					needed[i] -= audience[j];
				}
			}
			int answer = maxValue(needed);

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
	
}
