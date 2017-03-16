import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Solution {
	static void solve(InputStream in) {
		Scanner scn = new Scanner(in);
		int numcases = scn.nextInt();
		for(int i = 1; i <= numcases; ++i) {
			solveCase(scn, i);
		}
	}

	static ArrayList<Double> deepCopy(ArrayList<Double> src) {
		ArrayList<Double> r = new ArrayList<Double>();
		for(int i = 0; i < src.size(); ++i) {
			r.add(new Double(src.get(i)));
		}
		return r;
	}

	static int kenSelect(ArrayList<Double> kenList, double naomiTold) {
		for(int i = 0; i < kenList.size(); ++i) {
			if(kenList.get(i) > naomiTold) {
				return i;
			}
		}
		return 0;
	}

	static void solveCase(Scanner in, int casenumber) {
		int count = in.nextInt();
		ArrayList<Double> nl = new ArrayList<Double>();
		for(int i = 0; i < count; ++i) {
			String s = in.next();
			nl.add(Double.parseDouble(s));
		}
		ArrayList<Double> kl = new ArrayList<Double>();
		for(int i = 0; i < count; ++i) {
			String s = in.next();
			kl.add(Double.parseDouble(s));
		}

		Collections.sort(nl);
		Collections.sort(kl);

		int normal_war_wins = 0;
		ArrayList<Double> nlt = new ArrayList<Double>(nl);
		ArrayList<Double> klt = new ArrayList<Double>(kl);
		
		// Strategy for normal war
		// Pretty simple, if we know nothing else about distribution or something
		// all strategy I see possible is to start with small logs, so Ken has to
		// match his small logs with our small ones to start with.
		while(!nlt.isEmpty()) {
			double nv = nlt.get(0);
			nlt.remove(0);
			int kenChoice = kenSelect(klt, nv);
			double kv = klt.get(kenChoice);
			klt.remove(kenChoice);
			if(nv > kv) {
				normal_war_wins++;
			}
		}

		/*
		 * The deceit strategy becomes a little more complex
		 * 
		 * Basically, I started by thinking that the best strategy was to match
		 * my logs that are minimally much heavier than his lightest one and pretending
		 * that they are extremely heavy.
		 * 
		 * This wasn't quite true though, as doing this would eventually mean that I would run out
		 * of logs that are heavier than his all together. In that scenario, I would have to
		 * sacrifice my lightest log to get rid of his heaviest. But in that case, it would've been better
		 * to do this at the start, so I could trade my lightest log for his heaviest.
		 * 
		 * I solved this by doing a very lazy iteration of basically the same algorithm as before.
		 * Simply put, I added a number to keep track of how many of my lightest logs I wanted to trade for his
		 * heaviest in the beginning, and then I just ran that algorithm over and over, increasing the aforementioned
		 * number whenever I ran into a case where I had to concede a log and then started over from the top (with the
		 * number increased as the only state change).
		 */
		
		boolean imHappy;
		int deceit_war_wins;
		int skips = 0;

		while(true) {
			imHappy = true;
			deceit_war_wins = 0;

			nlt = new ArrayList<Double>(nl);
			klt = new ArrayList<Double>(kl);

			for(int i = 0; i < skips; ++i) {
				nlt.remove(0);
				klt.remove(klt.size() - 1);
			}

			while(!nlt.isEmpty()) {
				boolean beatable = true;
				for(int i = 0; i < nlt.size(); ++i) {
					if(nlt.get(i) > klt.get(0)) {
						deceit_war_wins++;
						nlt.remove(i);
						klt.remove(0);
						beatable = false;
						break;
					}	
				}

				if(beatable) {
					skips++;
					imHappy = false;
					break;
				}
			}

			if(imHappy) break;
		}
		
		System.out.println("Case #" + casenumber + ": " + deceit_war_wins + " " + normal_war_wins);
	}

	public static void main(String[] args) {
		String infile;
		if(args.length == 0) {
			Scanner scn = new Scanner(System.in);
			infile = scn.nextLine();
		} else {
			infile = args[0];
		}

		InputStream is;

		try {
			is = new FileInputStream(infile);

			solve(is);

			is.close(); 
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
