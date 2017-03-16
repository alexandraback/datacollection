import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class User {
	
	private static final String FILENAME = "A-small-attempt3.in";

	public static void main(String[] args) {
		String OUTFILENAME = FILENAME + ".out";
		
		File inFile = new File (FILENAME);
		Scanner fileInput = null;
		try {
			fileInput = new Scanner(inFile);
		} catch (FileNotFoundException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}
		
		
		//PrintStream out;
		PrintWriter out = null;
		try {
			out = new PrintWriter(new FileWriter(OUTFILENAME));
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}

		
		int T = 0;
		try {
			T = (fileInput.nextInt());
		} catch (NumberFormatException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		for (int i=0; i<T; i++){
			
			
			int playerMote = 0;
			int moteCount = 0;
			playerMote = fileInput.nextInt(); System.out.println("Playermote = " + playerMote);
			moteCount = fileInput.nextInt();System.out.println("MoteCount = " + moteCount);

			int movesRequired = 0;
			int maxMovesRequired = 0;
			
			List<Integer> largerMotes = new ArrayList<Integer>();
			List<Integer> smallerMotes = new ArrayList<Integer>();
			
			for (int n = 0 ; n<moteCount; n++){
				int newMote = 0;
				newMote = fileInput.nextInt();System.out.println("NewMote = " + newMote);
				if (newMote < playerMote) smallerMotes.add(newMote);
				else largerMotes.add(newMote);
			}
			
			Collections.sort(largerMotes);
			
			for (int newMote : smallerMotes){
				playerMote = newMote + playerMote;
			}
			maxMovesRequired = largerMotes.size();

			
			while(!largerMotes.isEmpty()){
				if (playerMote > largerMotes.get(0)){
					playerMote += largerMotes.remove(0);
				}
				else{
					if ((playerMote + playerMote-1) > largerMotes.get(0)){
						movesRequired++;
						playerMote += playerMote-1;
						playerMote += largerMotes.remove(0);
					}
					else {
						if (playerMote == 1){
							movesRequired += largerMotes.size();
							largerMotes = new ArrayList<Integer>();
						}
						else{
							maxMovesRequired = Math.min(maxMovesRequired, movesRequired+largerMotes.size());
							movesRequired++;
							playerMote += playerMote-1;
						}
					}
				}
			}
			
			out.print("Case #" + (i+1) + ": " + Math.min(movesRequired, maxMovesRequired) + "\n");
	
		}
		out.close();
	}
}
