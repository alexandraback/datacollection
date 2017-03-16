import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class Dancing {
	
	public static void main(String[] args) throws IOException {
		File file = new File("c:\\java\\DancingResults.txt");
		File inFile = new File("c:\\java\\");
		file.createNewFile();
		PrintStream out = new PrintStream(file);
		Scanner scanIn = new Scanner(inFile);
		
		int T = 0;
		int n = 0;
		int p = 0;
		int score = 0;
		
		int s = 0;
		int total = 0;
		
		T = scanIn.nextInt();//number of cases
		
		for(int i = 0; i < T; i++, total = 0){
			n = scanIn.nextInt();//Number of dancers in case
			s = scanIn.nextInt();//number of surprising scores
			p = scanIn.nextInt();//score to be obtained
			for(int j = 0; j < n; j++){
				score = scanIn.nextInt();
				
				if(p == 0){
					total++;
					continue;
				}
				
				if(score >= minPossible1(p)){
					total++;
				}
				else if(score >= minPossible2(p) && s>0){
					total++;
					s--;
				}
				
			}//End of n loop
			
			out.println("Case #"+(i+1)+": "+total);
			
		}//End of Case-loop
	}
	
	public static int minPossible1(int pt){
		if((pt*3)-2 <= 0) return 1;
		
		return (pt*3)-2;
	}
	
	public static int minPossible2(int pt){
		if((pt*3)-4 <= 0) return 1;
		
		return (pt*3)-4;
	}

}
