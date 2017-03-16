import java.io.*;
import java.util.*;


public class energy {
	public static void main(String args[]) throws IOException{
		long testCases, max, current, regain,activities, nextLarge, difference,totalSat;
		long[] reward;
		BufferedReader f = new BufferedReader(new FileReader("B-large (1).in"));
		PrintWriter p = new PrintWriter(new BufferedWriter(new FileWriter("en.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		testCases = Long.parseLong(st.nextToken());
		for(int i = 0; i < testCases; i++){
			totalSat  = 0;
			nextLarge = 0;
			st = new StringTokenizer(f.readLine());
			max = Long.parseLong(st.nextToken());
			regain = Long.parseLong(st.nextToken());
			activities = Long.parseLong(st.nextToken());
			reward = new long[(int) activities];
			current = max;
			st = new StringTokenizer(f.readLine());
			for(int j = 0; j < activities; j++){
				reward[j] = Long.parseLong(st.nextToken());
				}
			for(int j = 0; j < activities; j++){
				if(current>max){
					current = max;
				}
				nextLarge = getLarge(reward, j);
				difference = max - (nextLarge - j)*regain;
				if(nextLarge == -1 || difference <=0){
				totalSat += reward[j]*current;
				current = regain;
				}else{
					if(current-difference<0){
					current += regain;
					}else{
					totalSat += reward[j]*(current-difference);
					current = difference + regain;
					}
					
				}
				
			}
			p.append("Case #" + (i+1) + ": " + totalSat + "\n");
		}
		p.close();
		System.exit(0);
		
		}
	public static long getLarge(long[] reward, int  index){
		long val = reward[index];
		for(int i = index+1; i  <reward.length; i++){
			if(reward[i]>val){
				return i;
			}
		}
		return -1;
		
	}
}