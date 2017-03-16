import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static int getNumOfMoves(String name, int count) {
		int result = 0,altResult=0;
		//int[] vMax = new int[w];
		//int[] hMax = new int[h];
		
		ArrayList<String> list = new ArrayList<String>();
	    list.add("a");
	    list.add("e");
	    list.add("i");
	    list.add("o");
	    list.add("u");
		boolean possible = true;

		for(int i = 0; i<name.length(); i++){
			for(int j = i+count-1; j<name.length(); j++){
				String str = name.substring(i, j+1);
				int num = 0;
				
				for(int k = 0; k<str.length(); k++){
					
					char c =str.charAt(k);
					if(!list.contains(""+c)){
						num++;
						if(num == count){
							result++;
							break;
						}
					}else{
						num=0;
					}
				}
			}
		 }
		
		
		return result;
	}

	public static boolean isSolveable(int moteSize, int moteCount,List<Integer> motes) {
		for(int i = 0; i<motes.size(); i++){
			if(moteSize > motes.get(i)){
				moteSize += motes.get(i);
			}else{
				return false;
			}
		 }
		return true;
	}
	
	public static void main(String args[]) {

		try {
			FileWriter foutstream = new FileWriter("A-small.out");
			BufferedWriter out = new BufferedWriter(foutstream);

			FileInputStream fstream = new FileInputStream("input.txt");
			DataInputStream in = new DataInputStream(fstream);
			Scanner sc = new Scanner(new File("input.txt"));

			int caseNumber = 1;
			int totalCaseNumber = sc.nextInt();
			int count = 0,moteSize=0;
			String name="";
			//int[] motes;
			List<Integer> motes = new ArrayList<Integer>();
			while (caseNumber <= totalCaseNumber) {
				out.write("Case #");
				out.write(String.valueOf(caseNumber++));
				out.write(": ");
				
				name = sc.next();
				count = sc.nextInt();

				out.write(""+getNumOfMoves(name,count));
				out.newLine();
			}
			in.close();
			sc.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
