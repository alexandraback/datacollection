import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class TaskD {
	
	private BufferedReader br;
	private BufferedWriter bw;
	
	public static void main(String args[]) throws Exception {
		System.out.println("Task A");
		System.out.println(System.getProperty("user.dir"));
		//TaskD taskD = new TaskD("in.txt","out.txt");
		TaskD taskD = new TaskD("D-small-attempt1.in","out.txt");
		
		
		try {
			
		    int numOfTestCases = taskD.readNumOfTestCases();
		    for (int i = 1; i <= numOfTestCases; i++) {
		    	int numOfBlocks = taskD.readInput();
		    	List<Double> naomi = taskD.readBlocks();
		    	List<Double> ken = taskD.readBlocks();
		    	if (naomi.size() != numOfBlocks || ken.size() != numOfBlocks) throw new Exception("input not valid.");
		    	int war = taskD.playWar(naomi, ken);
		    	int deceitfulWar = taskD.playDeceitfulWar(naomi, ken);
		    	taskD.writeALine("Case #" + i+": " + deceitfulWar + " " + war);
		    }

		     //   while (line != null) {
		     //   }
		}
		finally {
			taskD.closeRead();
		}
		        
	}
	
	private int playDeceitfulWar(List<Double> naomi, List<Double> ken) {
		int naomiScore = 0;
		List <Double> naomiList = new ArrayList<Double> (naomi);
		List <Double> kenList = new ArrayList<Double> (ken);
		Collections.sort(naomiList);
		Collections.sort(kenList);
		while (naomiList.size() > 0) {
			Double curNaomi = findLeast(naomiList);
			Double curKen = findLeast(kenList);
			if (curNaomi < curKen) {
				naomiList.remove(curNaomi);
				kenList.remove(findLargest(kenList));
			}
			else {
				naomiList.remove(curNaomi);
				kenList.remove(curKen);
				naomiScore++;
			}
			
		}
		return naomiScore;
	}

	private int playWar(List<Double> naomi, List<Double> ken) {
		int naomiScore = 0;
		List <Double> naomiList = new ArrayList<Double> (naomi);
		List <Double> kenList = new ArrayList<Double> (ken);
		for (Double curNaomi: naomi) {
			naomiList.remove(curNaomi);
			Double curKen = findNextLarger(kenList, curNaomi);
			if (curKen == 1.0 ) {
				curKen = findLeast(kenList);
				kenList.remove(curKen);
				naomiScore++;
			}
			else { //curKen > curNaomi
				kenList.remove(curKen);
			}
		}
		return naomiScore;
	}
	
	private Double findNextLarger(List<Double> list, Double item) {
		Double result = 1.0;
		for (Double listItem : list) {
			if (listItem > item && listItem < result) {
				result = listItem;
			}
		}
		return result;
	}
	
	private Double findLeast(List<Double> list) {
		Double result = list.get(0);
		for (Double cur : list) {
			if (cur < result) {
				result = cur;
			}
		}
		return result;
	}
	
	private Double findLargest(List<Double> list) {
		Double result = list.get(0);
		for (Double cur : list) {
			if (cur > result) {
				result = cur;
			}
		}
		return result;
		
	}
	

	public TaskD(String inputFile, String outputFile) throws IOException {
		
		br = new BufferedReader(new FileReader(inputFile));
		bw = new BufferedWriter(new FileWriter(outputFile));
	}
	
	public void closeRead() throws IOException{
		br.close();
		bw.close();
	}
	
	private int readNumOfTestCases() throws NumberFormatException, IOException{
		return Integer.valueOf(br.readLine());
	}
	
	private int readInput() throws NumberFormatException, IOException{
		return Integer.valueOf(br.readLine());
	}
	
	private List<Double> readBlocks() throws IOException{
		List <Double> result = new ArrayList<Double>();
		String[] resultStr = br.readLine().split("\\s+");
		for (String str : resultStr) {
			result.add(Double.valueOf(str));
		}
		return result;
	}
	

	
	private void writeALine(String str) throws IOException {
		bw.write(str);
		bw.newLine();
	}

}
