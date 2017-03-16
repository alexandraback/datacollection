import java.io.*;
import java.util.*;


public class energy {
	public static void main(String args[]) throws IOException{
		int testCases, max, current, regain,activities, nextLarge, difference,totalSat;
		int[] reward;
		BufferedReader f = new BufferedReader(new FileReader("B-small-attempt2.in"));
		PrintWriter p = new PrintWriter(new BufferedWriter(new FileWriter("en.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		testCases = Integer.parseInt(st.nextToken());
		for(int i = 0; i < testCases; i++){
			totalSat  = 0;
			nextLarge = 0;
			st = new StringTokenizer(f.readLine());
			max = Integer.parseInt(st.nextToken());
			regain = Integer.parseInt(st.nextToken());
			activities = Integer.parseInt(st.nextToken());
			reward = new int[activities];
			current = max;
			st = new StringTokenizer(f.readLine());
			for(int j = 0; j < activities; j++){
				reward[j] = Integer.parseInt(st.nextToken());
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
	public static int getLarge(int[] a, int  index){
		int val = a[index];
		for(int i = index+1; i  <a.length; i++){
			if(a[i]>val){
				return i;
			}
		}
		return -1;
		
	}
}