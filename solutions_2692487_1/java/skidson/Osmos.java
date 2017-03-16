package com.skidson.codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Osmos extends Test {

	public Osmos(BufferedReader in) {
		super(in);
	}

	@Override
	public String run() throws IOException {
		int numOps = 0;
		String[] args = in.readLine().split(" ");
		long a = Long.parseLong(args[0]);
//		int n = Integer.parseInt(args[1]);
		
		args = in.readLine().split(" ");
		List<Integer> motes = new ArrayList<Integer>();
		for (String mote : args) {
			motes.add(Integer.parseInt(mote));
		}
		Collections.sort(motes);
		
		int quitOps = Integer.MAX_VALUE; // the lowest removeScenario.ops so far
		// Go until Armin is stuck
		for (int i = 0; i < motes.size(); i++) {
//			System.out.print("Armin(" + a + ") ");
			if (a > motes.get(i)) {
				a += motes.get(i);
//				System.out.println("eats " + motes.get(i) + " --> Armin(" + a + ")");
			} else {
				// armin is stuck
//				System.out.print("blocked by " + motes.get(i) + ", ");
				
				Scenario feedScenario = tryFeed(a, motes.get(i));
				Scenario removeScenario = tryRemove(a, i, motes);
				
				quitOps = Math.min(quitOps, removeScenario.ops + numOps);
				
				if (feedScenario.possible && feedScenario.ops < removeScenario.ops) {
					numOps += feedScenario.ops;
					a = feedScenario.armin + motes.get(i);
//					System.out.println("feeding to Armin(" + feedScenario.armin + "), eats " + motes.get(i) + " --> " + "Armin(" + a + ")");
				} else {
//					System.out.println("removing rest of motes");
					numOps += removeScenario.ops;
					break;
				}
			}
			
			if (quitOps < numOps) {
				// so much feeding, would have been better to just remove all motes earlier
//				System.out.println("REVERTING TO QUIT SCENARIO");
				numOps = quitOps;
				break;
			}
		}
		
		if (quitOps < numOps) {
//			System.out.println("REVERTING TO QUIT SCENARIO");
			numOps = quitOps;
		}
		
//		System.out.println("# of ops: " + numOps + "\n");
		
		return String.valueOf(numOps);
	}
	
	private static Scenario tryFeed(long a, int next) {
		Scenario scenario = new Scenario(a);
		while (scenario.armin <= next) {
			long feed = scenario.armin - 1;
			if (feed < 1) {
				scenario.possible = false;
				break;
			}
			
			scenario.armin += feed;
			scenario.ops++;
		}
		return scenario;
	}
	
	private static Scenario tryRemove(long a, int i, List<Integer> motes) {
		Scenario scenario = new Scenario(a);
		scenario.ops = motes.size() - i;
		return scenario;
	}
	
	static class Scenario {
		long armin;
		int ops = 0;
		boolean possible = true;
		
		public Scenario(long armin) {
			this.armin = armin;
		}
	}

}
