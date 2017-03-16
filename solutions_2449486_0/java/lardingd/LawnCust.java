package qualifierFun;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class LawnCust {

	public static void main(String[] args) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter("output.txt")); 
			BufferedReader in  = new BufferedReader(new FileReader("input.txt"));
			int answer =1;
			String strLine = in.readLine();
			strLine = in.readLine();
			boolean newLane = true;
			int n = 0;
			int m = 0;
			List<List<Integer>> lawn = new ArrayList<List<Integer>>();
			int i = 0;
			while(strLine != null) {
				if(newLane) {
					String inputs[] = strLine.split(" ");
					n = Integer.parseInt(inputs[0]);
					m = Integer.parseInt(inputs[1]);
					i = 0;
					lawn.clear();
					newLane = false;
				} else {
					i++;
					lawn.add(getRow(strLine));
					if(i == n) {
						Lawn theLawn = new Lawn(lawn);
						out.print(String.format("Case #%s: %s\n", answer, theLawn.possible() ? "YES" : "NO"));
						answer++;
						newLane = true;
					}
				}
				
				strLine = in.readLine();
			}
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("I'd want to know");
		} catch (IOException e) {
			System.out.println("I'd want to know io");
		}
		System.out.println("done");
	}
	
	private static List<Integer> getRow(String rowString) {
		List<Integer> row = new ArrayList<Integer>();
		String[] split = rowString.split(" ");
		for(String num : split) {
			row.add(Integer.parseInt(num));
		}
		return row;
	}
	
	private static class Lawn {
		List<List<Integer>> lawn;
		public Lawn(List<List<Integer>> lawn) {
			this.lawn = lawn;
		}
		
		public boolean possible() {
			for(int i = 0; i < lawn.size(); i++) {
				for(int j = 0; j < lawn.get(i).size(); j++) {
					boolean possible = checkPos(i,j);
					if(!possible) {
						return false;
					}
				}
			}
			return true;
		}

		private boolean checkPos(int i, int j) {
			int max = lawn.get(i).get(j);
			boolean doable = true;
			for(int row = 0; row < lawn.size(); row++) {
				if(lawn.get(row).get(j) > max) {
					doable = false;
					break;
				}
			}
			if(doable) {
				return true;
			}
			doable = true;
			for(int col = 0; col < lawn.get(i).size(); col++) {
				if(lawn.get(i).get(col) > max) {
					doable = false;
					break;
				}
			}
			return doable;
		}
	}
}
