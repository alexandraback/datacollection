import java.io.BufferedReader;
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Vector;

public class Solver {
	
	public static void main(String[] args) {
		Solver solver = new Solver();
		solver.readFromFile("src/C-small-attempt2.in");
	}

	private int nb_case = 0;
	private int R = 0;
	private int C = 0;
	private int M = 0;
	private ArrayList<ArrayList<Integer>> resultList;
	
	ArrayList<ArrayList<String>> game;

	private void initGame() {
		game = new ArrayList<ArrayList<String>>();
		for (int i = 0; i < R; i++) {
			game.add(new ArrayList<String>());
			for (int j = 0; j < C; j++) {
				game.get(i).add(".");
			}
		}
	}
	
	private ArrayList<int[]> getNeighbors(int cord[]) {
		ArrayList<int[]> my_neighbors = new ArrayList<>();
		int thisPosR = cord[0];
		int thisPosC = cord[1];
		//System.out.println("R = " + String.valueOf(cord[0]));
    	//System.out.println("C = " + String.valueOf(cord[1]));
		int MIN_R = 0;
		int MIN_C = 0;
		int MAX_R = R-1;
		int MAX_C = C-1;
		//System.out.println("Max R = " + String.valueOf(MAX_R));
    	//System.out.println("Max C = " + String.valueOf(MAX_C));
		int startPosR = (thisPosR - 1 < MIN_R) ? thisPosR : thisPosR-1;
		int startPosC = (thisPosC - 1 < MIN_C) ? thisPosC : thisPosC-1;
		int endPosR =   (thisPosR + 1 > MAX_R) ? thisPosR : thisPosR+1;
		int endPosC =   (thisPosC + 1 > MAX_C) ? thisPosC : thisPosC+1;
		// See how many are alive
		for (int rowNum=startPosR; rowNum<=endPosR; rowNum++) {
		    for (int colNum=startPosC; colNum<=endPosC; colNum++) {
		    	if(colNum != thisPosC || rowNum != thisPosR) {
			    	int[] neighbor = {rowNum, colNum};
			    	//System.out.println("Row = " + String.valueOf(rowNum));
			    	//System.out.println("Col = " + String.valueOf(colNum));
			    	my_neighbors.add(neighbor);
		    	}
		    }
		}
		return my_neighbors;
	}
	
	private void showCell(int cord[]) {

		ArrayList<int[]> my_neighbors = getNeighbors(cord);
		int mine_count = 0;
		for (int i = 0; i < my_neighbors.size(); i++) {
			if(game.get(my_neighbors.get(i)[0]).get(my_neighbors.get(i)[1]) == "*") {
				mine_count++;
			}
		}
		game.get(cord[0]).set(cord[1], String.valueOf(mine_count));
		if(mine_count == 0) {
			for (int i = 0; i < my_neighbors.size(); i++) {
				int[] next = { my_neighbors.get(i)[0], my_neighbors.get(i)[1] };
				if (game.get(my_neighbors.get(i)[0]).get(my_neighbors.get(i)[1]) == ".")
					showCell(next);
			}
		}
	}
	
	private void setMines(ArrayList<int[]> list) {
		for (int i = 0; i < list.size(); i++) {
			game.get(list.get(i)[0]).set(list.get(i)[1], "*");
		}
	}
	
	private void generateMineArrangement() {
		ZuHe robot = new ZuHe();
		resultList = new ArrayList<ArrayList<Integer>>(); 
		int[ ] num=new int[C*R];
		for (int i = 0; i < num.length; i++) {
			num[i] = i;
		}
		robot.combine(num,M, resultList);
	}
	
	private int[] intToCord(int num) {
		int count = 0;
		int[] cord = new int[2];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (count++ == num) {
					cord[0] = i;
					cord[1] = j;
				}
			}
		}
		return cord;
	}
	
	private boolean isWin() {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (game.get(i).get(j) == ".") {
					return false;
				}
			}	
		}
		return true;
	}
	
	private void solveACase() {
		if(M == 0) {
			initGame();
			game.get(0).set(0, "c");
			printGame();
			return;
		}
		generateMineArrangement();
		for(int i = 0; i < resultList.size(); i ++) { 
			ArrayList<Integer> set = resultList.get(i); 
			Iterator it = set.iterator(); 
			ArrayList<int[]> mine_conf = new ArrayList<int[]>();
			while(it.hasNext()) 
			{
				int value = (int) it.next();
				mine_conf.add(intToCord(value));
			}
			for (int j = 0; j < C*R; j++) {
				initGame();
				setMines(mine_conf);
				int[] cordi = intToCord(j);
				if (game.get(cordi[0]).get(cordi[1]) == ".") {
					game.get(cordi[0]).set(cordi[1], "c");
					showCell(cordi);
					if (isWin()) {
						initGame();
						setMines(mine_conf);
						game.get(cordi[0]).set(cordi[1], "c");
						printGame();
						return;
					}
				}
			}
		}
		System.out.println("Impossible");  
	}
	
	private void printGame(){
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				System.out.print(game.get(i).get(j));
			}
			System.out.println();
		}
	}
	
	public void readFromFile(String f) {
		BufferedReader br=null;
		String chaine = null;
		
	    try {
	    	try {
	    		br = new BufferedReader(new FileReader(f));
	    		nb_case = Integer.parseInt(br.readLine());
	    		if (nb_case > 0) {
	    			for (int i = 1; i <= nb_case; i++) {
	    				String three_case[] = new String[4];
	    				chaine = br.readLine();
	    				three_case = chaine.split(" ");
	    				System.out.println("Case #"+ i + ":");
						R = Integer.parseInt(three_case[0]);
						C = Integer.parseInt(three_case[1]);
						M = Integer.parseInt(three_case[2]);
	    				solveACase();
					}
	    		}
       		} catch(EOFException e) {
       			br.close();
       		}
	    } catch(FileNotFoundException e) {
	    	System.out.println("fichier inconnu : " + f);
	    } catch(IOException e) {
	    	System.out.println("IO Exception");
	    }
	}
}