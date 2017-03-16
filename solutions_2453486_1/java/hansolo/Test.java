package parta;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Date;
import java.util.Scanner;

public class Test {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		long beginTime = new Date().getTime();
		
		Parse();
				
		System.out.println("" + (new Date().getTime() - beginTime) + " milliseconds.");
		
	}

	private static void Parse() throws IOException {
		// TODO Auto-generated method stub
		FileInputStream inFile = new FileInputStream("parta//A-large.in");
		//FileOutputStream outFile = new FileOutputStream("A-small-practice.out");
		Scanner scanner = new Scanner(inFile);
		BufferedWriter writer = Files.newBufferedWriter(Paths.get("parta//A-large.out"), StandardCharsets.UTF_8);
	
		int expAmt = scanner.nextInt();
		for(int expNo=1; expNo<= expAmt; expNo++)
		{
			Experiment exp = new Experiment();
			int row,col;
			for(row=0 ; row<4; row++)
			{
				String tmpStr = scanner.next();
				for(col=0; col<4; col++)
					exp.board[row][col] = tmpStr.charAt(col);
			}
			
			//System.out.println("Case #"+ expNo +": "+ exp.Solve() +"\n");
			writer.write("Case #"+ expNo +": "+ exp.Solve() +"\n");
		}
		
		scanner.close();
		inFile.close();
		writer.close();	
	}

}
