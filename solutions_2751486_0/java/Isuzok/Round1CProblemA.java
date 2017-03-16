import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;


public class Round1CProblemA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Round1CProblemA hi = new Round1CProblemA();
	}
	
	public Round1CProblemA(){
		parser();
	}

	public void parser(){
		try{
			FileInputStream fstream = new FileInputStream("A-small-attempt0.in");
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
				int n = Integer.parseInt(split[1]);
				String name = split[0];
				
				int numberOfSubStrs = 0;
				for(int i1 = 0; i1 < name.length(); ++i1){
					for(int j = i1+1; j < name.length()+1; ++j){
						//System.out.println(name.substring(i1, j));
						if(checkSubString(name.substring(i1, j), n)){
							numberOfSubStrs++;
							//System.out.println(name.substring(i1, j));
						}
					}
				}
				
				
				System.out.println(numberOfSubStrs);
				out.write("Case #" + (i+1) + ": " + numberOfSubStrs);
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
	
	private boolean checkSubString(String str, int numberOfConsNeeded){
		int consInARow = 0;
		for(int i = 0; i < str.length(); ++i){
			if(str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o' || str.charAt(i) == 'u'){
				consInARow = 0;
			} else {
				consInARow++;
				if(consInARow >= numberOfConsNeeded){
					return true;
				}
			}
		}
		return false;
	}
}
