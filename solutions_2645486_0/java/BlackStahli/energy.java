import java.util.*;
import java.io.*;
public class energy {
	static int[] activities; //gain per activity
	static int gain; //total gain
	static int max; //max energy
	static int reg; //energy regained
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader (new FileReader ("B-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("energy.out")));
		int n = Integer.parseInt(in.readLine());
		for(int i = 0;i<n;i++) {
			//solve here
			StringTokenizer s = new StringTokenizer(in.readLine());
			gain = 0;
			max = Integer.parseInt(s.nextToken());
			reg = Integer.parseInt(s.nextToken());
			int acts = Integer.parseInt(s.nextToken());
			activities = new int[acts];
			s = new StringTokenizer(in.readLine());
			for(int j = 0;j<acts;j++) {
				activities[j] = Integer.parseInt(s.nextToken());
			}
			//solve here
			test(0,max,0);
			System.out.println(Arrays.toString(activities) + " " + max + " " + reg +" " + gain);
			out.println("Case #" + (i+1) + ": " + gain);
			
		}
		out.close();
		in.close();
		
	}
	public static void test(int place, int energy, int tgain) { //place indicates which activity
		if(place == activities.length) { //done with all activities
			//return stuff here
			gain = Math.max(gain, tgain);
			return;
		}
		//either continue doing activity, or go on to next activity
		for(int i = energy;i>=0;i--) { //for each possible amount of energy spent on an activity
			test(place+1, Math.min(max, i+reg), tgain+(energy-i)*activities[place]); //go to next activity, regain energy, gain at that point
		}
	}
}
