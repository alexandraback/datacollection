import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import javax.swing.text.html.HTMLDocument.Iterator;


public class GoogleCodeJam20141A {

	ArrayList<String> inputLines = new ArrayList<String>();
	ArrayList<String> outputLines = new ArrayList<String>();
	private static final String PATH ="/Users/koichisakumoto/Documents/GoogleCodeJam/";
	private static final String inputFileName =  "1A/A-large.in.txt";
	private static final String outputFileName = "1A/answer_large.txt";
	
	int totalNum = 0;
	ArrayList<Problem> problems = new ArrayList<Problem>();
	
	class Problem {
		long p = 0;
		long q = 0;
	}
	
	public static void main(String[] args) {
		GoogleCodeJam20141A inst = new GoogleCodeJam20141A();
		// ファイルを読み込む
		inst.getLines(PATH + inputFileName);
		// 実際の処理
		inst.run();
		// ファイルに書き出す
		inst.putLines(PATH + outputFileName);
	}

	private void run(){
		java.util.Iterator<String> itr = inputLines.iterator();
		
		// 問題数
		String line = itr.next();
		totalNum = Integer.parseInt(line);
		
		// 問題を作る
		Problem problem = null;
		for(int i = 0; i < totalNum; i++){
			if(!itr.hasNext()) break;
			line = itr.next();
			String[] pq =line.split("/");
			problem = new Problem();
			problem.p = Long.parseLong(pq[0]);
			problem.q = Long.parseLong(pq[1]);
			problems.add(problem);

		}
		
		if (problems.size() != totalNum){
			System.out.println("error");
			return;
		}
		
		// 問題を解く
		for (int i = 0; i < totalNum; i++){
			problem = problems.get(i);
			long result = solve(problem);
			if (result >= 0) {
				outputLines.add("Case #" + (i+1) + ": " + result);
			} else {
				outputLines.add("Case #" + (i+1) + ": impossible");
			}
		}
	}

	private long solve(Problem problem){
		double rate = ((double)problem.p) / ((double)problem.q);
		final long LIMIT = 100000;
		final double UNDER_LIMIT = 0.1/Math.pow(10, 12);
		double current = 1.0;
		long candidate = -1;
		boolean cDecided = false;
		boolean isOK = false;
		for(long i = 1; i <= LIMIT; i++){
			current *= 0.5;
			if ( current < UNDER_LIMIT ) break; 
			if (!cDecided && (rate >= current)){
				cDecided = true;
				candidate = i;
			}
			if (rate >= current){
				rate -= current;
				if(rate == 0){
					isOK = true;
					break;
				}
			}

		}
		
		return isOK? candidate : -1;
	}
	

	/*
	 * ファイルの入出力
	 */
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
