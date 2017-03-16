package googlecodejam2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.util.ArrayList;

public class Pogo {
public static String getMoves(int x, int y){
	int totalMovesInXDir = 2*Math.abs(x);
	
	String moves = "";
	
	String nextMove = "";
	if (x > 0)
	{
		nextMove = "W";
	}
	else 
	{
		nextMove = "E";
	}
	
	for (int i =0; i< totalMovesInXDir; i++)
	{
		moves = moves + nextMove;
		nextMove = nextMove.equals("W") ? "E" : "W";
	}
	
	int totalMovesInYDir = 2*(Math.abs(y)) ;
	nextMove = "";
	
	if (y > 0)
	{
		nextMove = "S";
	}
	else 
	{
		nextMove = "N";
	}
	
	for (int i =0; i< totalMovesInYDir; i++)
	{
		moves = moves + nextMove;
		nextMove = nextMove.equals("N") ? "S" : "N";
	}
	
	return moves;
}
	
	public static void main(String[] argv) {
		try {
			long startTime = System.currentTimeMillis();
			Reader reader = new FileReader("C:\\Users\\AvinashS\\Desktop\\google\\pogo\\small.in");
			BufferedReader bufReader = new BufferedReader(reader);
			String x = bufReader.readLine();
			int numOfTestCases = Integer.parseInt(x);
			int count = 0;
	
			File file = new File("C:\\Users\\AvinashS\\Desktop\\google\\pogo\\small.out");
			FileWriter writer = new FileWriter(file);
			for(count =1; count<= numOfTestCases; count++) {
				ArrayList<Integer> secondLine = getIntegerList(bufReader.readLine());
				String output = getMoves(secondLine.get(0), secondLine.get(1))+"";
				writer.write("Case #" + count + ": " + output+"\n");
				System.out.println("Case #" + count + ": " + output);
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
