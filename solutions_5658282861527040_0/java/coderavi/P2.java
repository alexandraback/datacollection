package codejam2014.round1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.util.ArrayList;

import codejam2014.MinesweeperMaster;

public class P2 {
	
	public String solve(int A, int B, int K){
		int count =0;
		for(int i = 0; i < A; i++){
			for(int j=0; j < B; j++){
				if((i&j) < K ){
					count++;
				}
			}
		}
		return ""+count;
	}
	
	public static void main(String[] argv) {
		try {
			long startTime = System.currentTimeMillis();
			Reader reader = new FileReader("C:\\Users\\AvinashS\\Desktop\\google\\lottery\\small.in");
			BufferedReader bufReader = new BufferedReader(reader);
			String x = bufReader.readLine();
			int numOfTestCases = Integer.parseInt(x);
			int count = 0;
	
			File file = new File("C:\\Users\\AvinashS\\Desktop\\google\\lottery\\small.out");
			FileWriter writer = new FileWriter(file);
			for(count =1; count<= numOfTestCases; count++) {
				ArrayList<Integer> list = getIntegerList(bufReader.readLine());
				String res = new P2().solve(list.get(0), list.get(1), list.get(2));
				writer.write("Case #" + count + ": "+res+"\n");
				System.out.println("Case #" + count + ": "+res );
			}
			writer.close();
			System.out.println("Total time = " + (System.currentTimeMillis() - startTime));
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private static ArrayList<Integer> getIntegerList(String s) {
		ArrayList<Integer> intList = new ArrayList<Integer>();
		String[] strArr = s.split(" ");
		for (String str : strArr) {
			intList.add(Integer.parseInt(str.trim()));
		}
		return intList;
	}
}
