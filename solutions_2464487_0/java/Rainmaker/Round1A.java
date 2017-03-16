import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;



public class Round1A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
	
		Round1A r=new Round1A();
		r.printSolution();
	}
	public long getBlackCount(long r,long t)
	{
		r=r+1;
		long curArea=2*r-1;
		long count=0;
		while(curArea<=t)
		{
			count++;
			t=t-curArea;
			r=r+2;
			curArea=2*r-1;
		}
		
		return count;
	}
	public void printSolution()
	{
		String inputFile,outputFile;
		
		inputFile="C:\\CodeJam\\A-small-attempt1.in";
		outputFile="C:\\CodeJam\\BullsEyeSmallOut.txt";
		int cases;
		BufferedReader br;
		BufferedWriter bw;
		String line;
		String[] input;
		
		
		
		
		long rad, paint;
		
		int i;
		long count=0;
		
		
		try{
			br=new BufferedReader(new FileReader(inputFile));
			bw=new BufferedWriter(new FileWriter(outputFile));
			cases=Integer.parseInt(br.readLine());
			
			for(i=0;i<cases;i++)
			{
				
				line=br.readLine();
				input=line.split(" ");
				rad=Long.parseLong(input[0]);
				
				paint=Long.parseLong(input[1]);
				
			
			   
				//System.out.println("Case "+(i+1));
				count=getBlackCount(rad,paint);
				System.out.println("Case #"+(i+1));
				bw.write("Case #"+(i+1)+": "+(count)+"\n");
				
				//+": "+gStatus[gameStatus]);
				
			}
			br.close();
			bw.close();

		}catch(Exception ex)
		{
			System.out.println(ex);
			ex.printStackTrace();
		}
	}

}
