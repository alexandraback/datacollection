import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class GoogleCodeJam20141C {

	ArrayList<String> inputLines = new ArrayList<String>();
	ArrayList<String> outputLines = new ArrayList<String>();
	private static final String PATH ="/Users/koichisakumoto/Documents/GoogleCodeJam/";
	private static final String inputFileName =  "1C/C-small-attempt1.in.txt";
	private static final String outputFileName = "1C/answer.txt";
	
	int totalNum = 0;
	ArrayList<Problem> problems = new ArrayList<Problem>();
	
	class Problem {
		int n = 0;
		int m = 0;
		int k = 0;
	}
	
	public static void main(String[] args) {
		GoogleCodeJam20141C inst = new GoogleCodeJam20141C();
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
		for(int i = 0; i < totalNum; i++){
			if(!itr.hasNext()) break;
			line = itr.next();
			String[] nmk = line.split(" ");
			Problem problem = new Problem();
			problem.n = Integer.parseInt(nmk[0]);
			problem.m = Integer.parseInt(nmk[1]);
			problem.k = Integer.parseInt(nmk[2]);
			problems.add(problem);
		}
		
		if (problems.size() != totalNum){
			System.out.println("error");
			return;
		}
		
		// 問題を解く
		for (int i = 0; i < totalNum; i++){
			Problem problem = problems.get(i);
			int result = solve(problem);
			if (result >= 0) {
				outputLines.add("Case #" + (i+1) + ": " + result);
			} else {
				outputLines.add("Case #" + (i+1) + ": impossible");
			}
		}
	}

	private int solve(Problem problem){
		if ((problem.n < 3) || (problem.m < 3)){
			return problem.k;
		}
		
		int n = problem.n - 2;
		int m = problem.m - 2;
		int k = problem.k;
		
		int eMax = n * 2 + m * 2 + n * m;
		if (k == eMax + 1){
			return n * 2 + m * 2 + 1;
		}
		if (k == eMax + 2){
			return n * 2 + m * 2 + 2;
		}
		if (k == eMax + 3){
			return n * 2 + m * 2 + 3;
		}
		if (k == eMax + 4){
			return n * 2 + m * 2 + 4;
		}
		
		int minK = problem.n * problem.m;
		for (int s = 1; s <= n; s++){
			for (int t = 1; t <= m; t++){
				int enc = 2*s + 2*t  + s*t;
				int use = 2*s + 2*t;
				if( enc >= k){
					if (minK > use){
						minK = use;
					}
				}
				if( enc + 1 >= k){
					if (minK > use + 1){
						minK = use + 1;
					}
				}
				if( enc + 2 >= k){
					if (minK > use + 2){
						minK = use + 2;
					}
				}
			}
		}
		
		return minK;
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
