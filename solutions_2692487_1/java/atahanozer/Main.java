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
	public static int getNumOfMoves(int moteSize, int moteCount,List<Integer> motes) {
		int result = 0;
		//int[] vMax = new int[w];
		//int[] hMax = new int[h];
		boolean possible = true;
		
		Collections.sort(motes);
		
		while (motes.size()>0){
			if(isSolveable(moteSize,moteCount,motes))
				break;
			
			int tempSize=moteSize;
			for(int i = 0; i<motes.size(); i++){
				if(moteSize > motes.get(i)){
					moteSize += motes.get(i);
					motes.remove(i);
					break;
				}
			
			if(tempSize == moteSize){
				//all elements bigger or equal
				if (motes.get(i) - moteSize +1 >= moteSize){//can not add elements\
					result+=motes.size();
					motes.clear();
					break;
				}
				else{
					moteSize+= moteSize-1;
					result++;
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
			int moteCount = 0,moteSize=0;
			//int[] motes;
			List<Integer> motes = new ArrayList<Integer>();
			while (caseNumber <= totalCaseNumber) {
				out.write("Case #");
				out.write(String.valueOf(caseNumber++));
				out.write(": ");
				
				moteSize = sc.nextInt();
				moteCount = sc.nextInt();
				motes = new ArrayList<Integer>();
				for(int i = 0;i<moteCount; i++){
					motes.add(sc.nextInt());
						//out.write(garden[i][j]+" ");
					//out.newLine();
				}
				out.write(""+getNumOfMoves(moteSize,moteCount,motes));
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
