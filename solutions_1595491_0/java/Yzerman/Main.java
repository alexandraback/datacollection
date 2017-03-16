import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.StringTokenizer;



public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("c:\\input_B.txt")));
		int cases = Integer.parseInt(reader.readLine());
		for(int i=0; i<cases; i++){
			
			String inputString = reader.readLine();		
			StringTokenizer st = new StringTokenizer(inputString);			
			
			int numOfGooglers = Integer.parseInt(st.nextToken());
			int numOfSurprised = Integer.parseInt(st.nextToken());
			int threshold = Integer.parseInt(st.nextToken());
			
			ArrayList<Integer> total_points_list = new ArrayList<Integer>();
			for(int j=0; j<numOfGooglers; j++){
				total_points_list.add(Integer.parseInt(st.nextToken()));				
			}
			
			Collections.sort(total_points_list);
			Collections.reverse(total_points_list);
			//System.out.println(total_points_list);
			
			int numOfPassed = 0;
			
			outloop:
			for (Integer total_points : total_points_list) {
				int avg = total_points / 3;
				int remainder = total_points % 3;
				
				if(avg >= threshold) {
					++numOfPassed;
					continue;
				}
				
				switch(remainder) {
				case 0:
					if( (threshold - avg) == 1 && numOfSurprised > 0 && avg > 0) {						
						--numOfSurprised;	
						++numOfPassed;
					}
					break;
				case 1:
					if( (threshold - avg) == 1)
						++numOfPassed;
					break;
				case 2:
					if( (threshold - avg) == 1)
						++numOfPassed;
					
					if( (threshold - avg) == 2 && numOfSurprised > 0) {						
						--numOfSurprised;	
						++numOfPassed;
					}					
					break;
				}
			}
			
			System.out.println("Case #"+(i+1)+": "+numOfPassed);

			
		}

	}

}
