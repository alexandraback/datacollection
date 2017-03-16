import java.io.*;
import java.lang.*;
import java.util.*;
class Solution {
	public static void main (String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int cases = Integer.parseInt(br.readLine());
			int plates;
			String pancakeData[];
			int[] pancakes;
			int maxPancakes;
			int time;
			int minTime;
			for (int i = 1; i <= cases; i++) {
				plates = Integer.parseInt(br.readLine());
				pancakeData = br.readLine().trim().split(" ");
				pancakes = new int[plates];
				maxPancakes=0;
				
				for (int j = 0; j < plates; j++) {
					pancakes[j] = Integer.parseInt(pancakeData[j]);
					if (pancakes[j] > maxPancakes) {
						maxPancakes = pancakes[j];
					}
				}
				minTime=maxPancakes;
				Arrays.sort(pancakes);
				//System.out.println("maxPancakes: "+maxPancakes);
				for (int j = maxPancakes; j >1;j--) {
					//System.out.println("testing level "+j);
					time = j;
					for (int k = (plates - 1); k>=0; k--) {
						//System.out.println(pancakes[k]+" pancakes at plate "+k+" compared to level "+j);
						if (pancakes[k] > j) {
							time += ((int) Math.ceil(((double) pancakes[k])/((double) j))) - 1;
							//System.out.println("pancakes: "+pancakes[k]+" level: "+j+" time: "+time);
						}
						else {
							break;
						}
					}
					if (time < minTime) {
						minTime = time;
					}
				}
				System.out.println("Case #"+i+": "+minTime);
			}
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

}