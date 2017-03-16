import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class main {

	public static void write(PrintWriter file, int idx, String str){
		file.println("Case #"+idx+": "+str);
	}
	public static void write(PrintWriter file, int idx, int ans){
		file.println("Case #"+idx+": "+ans);
	}
	
	public static void main(String[] args) throws IOException {
		String epreuve="A-large.in";
		File entry = new File(epreuve);
		Scanner scin= new Scanner(entry);
		File out = new File("Output"+epreuve);
		out.createNewFile();
		PrintWriter scout= new PrintWriter(out);	
		// Set up of the problem
		int T = scin.nextInt();
		int Sm;
		String S;
		char[] SS;
		int toInvite;
		int currentClapper;
		for (int i=1; i<= T; i++){
			Sm=scin.nextInt(); S=scin.next(); SS=S.toCharArray(); toInvite=0;
			currentClapper=Integer.parseInt(String.valueOf(SS[0]));
			for (int j=1; j<=Sm; j++){
				if(currentClapper<j){
					currentClapper++;
					toInvite++;
				}
				currentClapper+=Integer.parseInt(String.valueOf(SS[j]));
			}
			write(scout, i, toInvite);
		}
		scin.close();
		scout.close();
	}

}
