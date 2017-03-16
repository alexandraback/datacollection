import java.io.*;
import java.util.*;

public class question
{
	public static void main(String[] args) throws IOException
	{
		File f = new File("test.txt");
		Scanner in = new Scanner(f);
		PrintWriter out = new PrintWriter(new FileWriter("testout.txt"));
		int numCases = in.nextInt();
		in.nextLine();
		String show;
		int maxShyness;
		int sum;
		int maxDif;
		int curDif;
		int people;
		for(int i = 0; i < numCases; i++){
			maxShyness = in.nextInt();
			show = in.nextLine();
			show = show.substring(1);
			sum = 0; maxDif = 0;
			
			//now compute max difference
			for( int shy = 0; shy <= maxShyness; shy++){	//for each shyness level
				people = show.charAt(shy) - '0';
				//System.out.println(people);
				if ( people > 0 && shy > sum ){	//not enough people up
					curDif = shy - sum;	//how many more needed
					//System.out.println( curDif );
					maxDif = Math.max(curDif, maxDif);
					//System.out.println( curDif );
				}
				sum += people;
			}
			//PrintWriter out = new PrintWriter(new FileWriter("filename"));
			if (i == numCases - 1){ //last case
				out.print("Case #" + (i + 1) + ": " + maxDif);
			} else {
				out.println("Case #" + (i + 1) + ": " + maxDif);			
			}
			//System.out.println(maxDif);
		}
		/*
		while( in.hasNextLine()){
			String s = in.nextLine();
			System.out.println(s);
		}*/
		out.close();
	}
}
