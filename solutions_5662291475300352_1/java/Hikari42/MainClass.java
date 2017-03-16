import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;


public class MainClass {
	
	public static void main(String[] args) throws IOException, InterruptedException {
		BufferedReader fr = new BufferedReader(new FileReader(new File("input.txt")));
		FileWriter fw = new FileWriter(new File("result.txt"));
		String firstLine = fr.readLine();
		int nbCases = Integer.parseInt(firstLine);
		for (int i =0; i<nbCases; i++){

			String line = fr.readLine();
			
			long n = Long.parseLong(line);

			long[] D = new long[(int) n];
			long[] H = new long[(int) n];
			long[] M = new long[(int) n];
			
			for (int j = 0; j<n; j++){
				line = fr.readLine();
				D[j]=Long.parseLong(line.split(" ")[0]);
				H[j]=Long.parseLong(line.split(" ")[1]);
				M[j]=Long.parseLong(line.split(" ")[2]);
			}

			long nbHikers = 0;
			
			for (int j = 0; j<n; j++){
				nbHikers += H[j];
			}
			
			Hiker[] hikers = new Hiker[(int) nbHikers];
			int c =0;
			for (int j = 0; j<n; j++){
				for (int m =0; m<H[j]; m++){
					hikers[c]= new Hiker(m+M[j],D[j]);
							c++;
				}
			}
			//Arrays.sort(hikers);
			//System.out.println(Arrays.toString(hikers));
			
			long result = nbHikers;
			for (int j = 0; j<nbHikers; j++){
				result = Math.min(result, resultIfIArriveAfter(j,hikers));
			}
			
			
			fw.write("Case #"+(i+1)+": "+result+"\n");
			
		}
		fw.close();
		System.out.println("finished");
	}

	private static long resultIfIArriveAfter(int j, Hiker[] hikers) {
		int res = 0;
		
		for (int i = 0; i<hikers.length; i++){


				res+= hikers[i].crossingWith(hikers[j].timetofinish);

		}
		return res;
	}

}
