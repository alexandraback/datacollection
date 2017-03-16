import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Dancing {

	public static PrintWriter pw;
	
	public static void main(String[] args) throws FileNotFoundException {
		
		//Scanner in = new Scanner (System.in);
		try{
			File f = new File("\\\\filesrv/stufiles$/matt.tough/out.txt");
			f.createNewFile();
			pw = new PrintWriter(f);
		}catch(Exception e){
			
		}
		Scanner in = new Scanner(new File("\\\\filesrv/stufiles$/matt.tough/B-small-attempt0.in"));
		String line = in.nextLine();
		int cases = Integer.parseInt(line);
		for (int t=0; t < cases; t++){
			line = in.nextLine();
			Scanner thisLine = new Scanner (line);
			int dancers = thisLine.nextInt();
			int surprises = thisLine.nextInt();
			int p = thisLine.nextInt();
			int p3 = p*3;
			int count =0;
			int totalScores[] = new int[dancers];
			for (int index = 0; index < dancers; index++){
				totalScores[index] = thisLine.nextInt();
			}
			for ( int i = 0; i < dancers; i++){
				if(p ==0){
					count++;
					continue;
				}else if(p ==1){
					if (totalScores[i]>0)
						count++;
					continue;
						
				}
				
				if (totalScores[i]>= p3-2){
					count++;
				}
				else if(totalScores[i]>= p3-4){
					if (surprises>0){
						surprises--;
						count++;
					}
				}
				
			}
			pw.printf("Case #%d: %d\n", t+1, count);
		}
		pw.flush();
	}
	
}
