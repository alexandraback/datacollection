import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class TaskC {
	class Loc{
		private int row;
		private int col;
		public Loc (int row, int col) {
			this.row = row;
			this.col = col;
		}
		public int getRow(){
			return row;
		}
		public int getCol() {
			return col;
		}
	}
	
	private BufferedReader br;
	private BufferedWriter bw;
	private char[][] map;
	private int R;
	private int C;
	private int M;
	private int mineToClear;
	private List<Loc> queue;
	
	public static void main(String args[]) throws IOException {
		System.out.println("Task C");
		System.out.println(System.getProperty("user.dir"));
		TaskC taskC = new TaskC("C-small-attempt2.in","out.txt");
		//TaskC taskC = new TaskC("in3.txt","out.txt");
		
		try {
			
		    int numOfTestCases = taskC.readNumOfTestCases();
		    for (int i = 1; i <= numOfTestCases; i++) {
		    	int[] params = taskC.readRCM();
		    	taskC.R = params[0];
		    	taskC.C = params[1];
		    	taskC.M = params[2];
		    	boolean isPossible = taskC.process();
		    	taskC.writeOutput(isPossible, i);
		    	
		    }

		     //   while (line != null) {
		     //   }
		}
		finally {
			taskC.closeRead();
		}
		        
	}
	public void writeOutput(boolean isPossible, int caseNumber) throws IOException {
		writeALine("Case #" + caseNumber + ":");
		if (!isPossible) {
			writeALine("Impossible");
		}
		else {
			for (int i = 0; i < R; i++) {
				String rowStr = "";
				for (int j = 0 ; j < C; j++) {
					rowStr += map[i][j];
				}
				writeALine(rowStr);
			}
		}
		
	}
	
	public TaskC(String inputFile, String outputFile) throws IOException {
		
		br = new BufferedReader(new FileReader(inputFile));
		bw = new BufferedWriter(new FileWriter(outputFile));
		queue = new ArrayList<Loc>();
	}
	
	public void closeRead() throws IOException{
		br.close();
		bw.close();
	}
	
	private int readNumOfTestCases() throws NumberFormatException, IOException{
		return Integer.valueOf(br.readLine());
	}
	
/*	private int readInput() throws NumberFormatException, IOException{
		return Integer.valueOf(br.readLine());
	}
*/	
	private int[] readRCM() throws IOException{
		int[] result = new int[3];
		String[] resultStr = br.readLine().split("\\s+");
		for (int j = 0; j < 3; j++) {
			result[j] = Integer.valueOf(resultStr[j]);
		}
		return result;
	}
	
	private void markNoMine(Loc loc) {
		map[loc.getRow()][loc.getCol()] = '.';
		mineToClear--;
	}
	
	private boolean process() {
		map = new char[R][C];
		for (int i = 0; i < R; i = i+1) {
			for (int j = 0; j < C; j = j+1) {
				resetMap();
				Loc cloc = new Loc (i, j);
				if (mineToClear == 0) return false;
				markC(cloc);
				if (mineToClear == 0) return true;
				if (markNearBy()) return true;
			}
		}
		return false;
	}
	
	private void resetMap(){
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] = '*';
			}
		}
		queue.clear();		
		mineToClear = R*C - M;
	}
	
	private void markC(Loc cloc){
		map[cloc.getRow()][cloc.getCol()] = 'c';
		mineToClear--;
		queue.add(cloc);

	}
	
	private boolean markNearBy() {
		while (!queue.isEmpty()) {
			int largestSize = 0;
			Loc candidate = queue.get(0);
			for (int i = 0 ; i < queue.size(); i++) {
				if (findAdjacentUnmarked(queue.get(i)).size() > largestSize) {
					candidate = queue.get(i);
				}
			}
			
			queue.remove(candidate);

			List <Loc> markable = findAdjacentUnmarked(candidate);
			
			if (markable.size() == mineToClear) {
				for (Loc _loc : markable) {
					markNoMine(_loc);
				}
				return true;
			}
			else if (markable.size() < mineToClear) {
				for (Loc _loc : markable) {
					markNoMine(_loc);
					queue.add(_loc);
				}
			}
			else {
				markable.clear();
			}
			if (mineToClear == 0) return true;
		}
		return false;
	}


	
	private List<Loc> findAdjacentUnmarked(Loc cur) {
		List <Loc> markable = new ArrayList<Loc>();
		if (cur.getRow() - 1 >= 0 && cur.getCol() - 1 >= 0 && map[cur.getRow()-1][cur.getCol()-1] == '*') {
			markable.add(new Loc(cur.getRow()-1, cur.getCol() - 1));
		}
		if (cur.getCol() - 1 >= 0 && map[cur.getRow()][cur.getCol()-1] == '*') {
			markable.add(new Loc(cur.getRow(), cur.getCol() - 1));
		}
		if (cur.getRow() + 1 < R && cur.getCol() - 1 >= 0 && map[cur.getRow()+1][cur.getCol()-1] == '*') {
			markable.add(new Loc(cur.getRow()+1, cur.getCol() - 1));
		}
		if (cur.getRow() - 1 >= 0 && map[cur.getRow()-1][cur.getCol()] == '*') {
			markable.add(new Loc(cur.getRow()-1, cur.getCol()));
		}
		if (cur.getRow() + 1 < R && map[cur.getRow()+1][cur.getCol()] == '*') {
			markable.add(new Loc(cur.getRow()+1, cur.getCol()));
		}
		if (cur.getRow() - 1 >= 0 && cur.getCol() + 1 < C && map[cur.getRow()-1][cur.getCol()+1] == '*') {
			markable.add(new Loc(cur.getRow()-1, cur.getCol() + 1));
		}
		if (cur.getCol() + 1 < C && map[cur.getRow()][cur.getCol()+1] == '*') {
			markable.add(new Loc(cur.getRow(), cur.getCol() + 1));
		}
		if (cur.getRow() + 1 < R && cur.getCol() + 1 < C && map[cur.getRow()+1][cur.getCol()+1] == '*') {
			markable.add(new Loc(cur.getRow()+1, cur.getCol() + 1));
		}
		return markable;
	}

	
	private void writeALine(String str) throws IOException {
		bw.write(str);
		bw.newLine();
	}

}
