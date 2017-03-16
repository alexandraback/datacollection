import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;


public class Round1BProblemA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Round1BProblemA hi = new Round1BProblemA();
	}
	
	public Round1BProblemA(){
		parser();
	}

	public void parser(){
		try{
			FileInputStream fstream = new FileInputStream("A-small-attempt3.in");
			//FileInputStream fstream = new FileInputStream("textfile.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			FileWriter outstream = new FileWriter("output.txt");
			BufferedWriter out = new BufferedWriter(outstream);
			
			int length = Integer.parseInt(br.readLine());
			String split[];
			for(int i = 0; i < length; ++i){
				split = br.readLine().split(" ");
				//Get N and M
				int A = Integer.parseInt(split[0]);
				int numberOfMotes = Integer.parseInt(split[1]);
				int numberOfActions = 0;
				if(A == 1){
					numberOfActions = numberOfMotes;
					br.readLine();
				} else{
					split = br.readLine().split(" ");
					ArrayList<Integer> motes = new ArrayList<Integer>();
					for(int n = 0; n < numberOfMotes; ++n){
						motes.add(new Integer(split[n]));
					}
					Collections.sort(motes);
					
//					for(int n = 0; n < motes.size(); ++n){
//						if(motes.get(n)*2 < motes.get(n+1)){
//							numberOfActions++;
//							
//						}
//					}
					
					for(int n = 0; n < numberOfMotes; ++n){
						if(A > motes.get(n)){
							A = A + motes.get(n);
						} else {
							int temp = A;
							int numberOfMotesNeeded = 0;
							while(temp <= motes.get(n)){
								temp = temp + (temp-1);
								numberOfMotesNeeded++;
							}
							if(numberOfMotesNeeded >= (numberOfMotes - n)){
								numberOfActions += (numberOfMotes - n);
								break;
							} else{
								A = temp + motes.get(n);
								numberOfActions += numberOfMotesNeeded;
							}
						}
					}
				}
				if(numberOfActions > numberOfMotes){
					numberOfActions = numberOfMotes;
				}
				
				System.out.println(numberOfActions);
				out.write("Case #" + (i+1) + ": " + numberOfActions);
				out.newLine();
				out.flush();
				
			}
		}
		catch(Exception e){
			System.err.println("Error: " + e.getMessage());
			System.out.println("Bah!");
			e.printStackTrace();
		}
	}
	
	private int numberOfMotesNeeded(int A, int nextMote){
		int numberOfMotesNeeded = 0;
		while(A < nextMote){
			A = A + (A-1);
			numberOfMotesNeeded++;
		}
		return numberOfMotesNeeded;
	}
}
