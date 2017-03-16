package com.nolmecolindor.gcj2012.round1c;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class Problem_B_0 {

	private static boolean DEBUG = false;
	
	private double getRequiredFreeFallTime(final double v0, final double d, final double a) {
		/*
		 * D = 		v0*t + 0.5*a*t^2 
		 * 0,5 * a * t^2 + v0 * t - D = 0
		 */
		
		final double aa = 0.5 * a;
		final double bb = v0;
		final double cc = -d;
		
		final double x1 = (0 - bb - Math.sqrt(bb*bb-4*aa*cc))/(2*aa);
		final double x2 = (0 - bb + Math.sqrt(bb*bb-4*aa*cc))/(2*aa);

		final double result;
		
		if (x1 >= 0) {
			if (x2 >= 0) {
				result = Math.min(x2, x1);
			} else {
				result = x1;
			}
		} else {
			result = x2;
		}

		if (DEBUG) System.err.println("FreeFall distance: v0=" + v0 + "; a=" + a + "; d=" + d + "; x1=" + x1 + "; x2=" + x2 + "; result=" + result);
		return result;

	}
	
	private double getRequiredTimeToCatchUp(final double distance0, final double targetV, final double v0, final double a) {
		/*
		 * v0*t + 0.5 * a * t^2 = distance0 + targetV * t
		 * 0,5 * a * t^2 + (v0-targetV) *t - distance0 = 0
		 */
		
		final double aa = 0.5 * a;
		final double bb = v0 - targetV;
		final double cc = -distance0;

		final double x1 = (0 - bb - Math.sqrt(bb*bb-4*aa*cc))/(2*aa);
		final double x2 = (0 - bb + Math.sqrt(bb*bb-4*aa*cc))/(2*aa);

		final double result;
		
		if (x1 >= 0) {
			if (x2 >= 0) {
				result = Math.max(x2, x1);
			} else {
				result = x1;
			}
		} else {
			result = x2;
		}

		if (DEBUG) System.err.println("Catch: d0=" + distance0 + "; targetV=" + targetV + "; v0=" + v0 + "; a=" + a + "; x1=" + x1 + "; x2=" + x2 + "; result=" + result);

		return result;
	}
	
	private void solve(final Scanner input, final PrintStream output, final PrintStream debug) {
		double D = input.nextDouble();
		int N = input.nextInt();
		int A = input.nextInt();
		if (DEBUG) debug.println("D is " + D + "; N is " + N + "; A is " + A + ".");
		double t[] = new double[N];
		double x[] = new double[N];
		for (int i = 0; i<N; i++) {
			t[i] = input.nextDouble();
			x[i] = input.nextDouble();
		}
		double a[] = new double[A];
		for (int i = 0; i<A; i++) {
			a[i] = input.nextDouble();
		}
//		debug.println("Read in data.");
		for (int i = 0; i<A; i++) {
		
			final double g = a[i];
			double myPosition = 0;
			double time = 0;
			double mySpeed = 0;
			
			double t0;
			double t1 = t[0];
			double dt;
			double blockX0;
			double blockX1 = x[0];
			boolean arrived = false;
			double blockV;
			
			double freeFallEndSpeed;
			double freeFallDistance;
			double freeFallEndPos;
			
			double linearEndPos;
			
			double dt1;
			
			for (int j = 0; !arrived && j < N-1; j++) {
				t0 = t1;
				t1 = t[j+1];
				dt = t1 - t0;
				blockX0 = blockX1;
				blockX1 = x[j+1];
				blockV = (blockX1 - blockX0) / dt;
				
				if (DEBUG) debug.println("Starting time slice " + j + ": t:[" + t0 + "->" + t1 + "]; dt=" + dt + "; blockX: [" + blockX0 + " -> " + blockX1 + "], blockV=" + blockV + "; I am at " + myPosition + "; rolling with " + mySpeed);
				
				if (myPosition < blockX0) { // I am starting from behind
					if (DEBUG) debug.println("Starting from behind.");
					freeFallEndSpeed = mySpeed + dt * g;
					freeFallDistance = (mySpeed + freeFallEndSpeed) / 2 * dt;
					freeFallEndPos = myPosition + freeFallDistance;
					if (freeFallEndPos <= blockX1) { // I can go with max speed
						if (DEBUG) debug.println("Can go with full speed; end will be at " + freeFallEndPos);
						if (myPosition + freeFallDistance >= D) { // Do I arrive home?
							arrived = true;
							time += getRequiredFreeFallTime(mySpeed, D - myPosition, g);
							myPosition = D;
							if (DEBUG) debug.println("I am arriving home by " + time);
						} else { // Have not yet arrived home
							time = t1;
							myPosition = freeFallEndPos;
							mySpeed = freeFallEndSpeed;
						}
					} else { // I must break at some point, because I reach the guy
						if (DEBUG) debug.println("I will have to break, because I reach the guy.");
						
						dt1 = getRequiredTimeToCatchUp(blockX0 - myPosition, blockV, mySpeed, g);
						
						freeFallEndSpeed = mySpeed + dt1 * g;
						freeFallDistance = (mySpeed + freeFallEndSpeed) / 2 * dt1;
						freeFallEndPos = myPosition + freeFallDistance;

						if (DEBUG) debug.println("I can go for " + dt1 + "secs; my position will be " + freeFallEndPos);

						
						if (freeFallEndPos >= D) { // Do I arrive home before breaking?
							arrived = true;
							time += getRequiredFreeFallTime(mySpeed, D - myPosition, g);
							myPosition = D;
							if (DEBUG) debug.println("I am arriving home by " + time + ", before breaking");
						} else {
							time += dt1;
							mySpeed = freeFallEndSpeed;
							myPosition = freeFallEndPos;
							
							linearEndPos = blockX1;
							
							if (DEBUG) debug.println("After breaking, I follow the guy to " + linearEndPos);
							
							if (linearEndPos >= D) { // Do I arrive home?
								time += (D - myPosition) / blockV;
								myPosition = D;
								arrived = true;
								if (DEBUG) debug.println("I am arriving home by " + time + ", following the guy");
							} else { // Nope, I keep going
								time = t1;
								myPosition = linearEndPos;
								mySpeed = blockV;
							}
						}
					}
					 
				} else { // I am already in the block's ass
					if (DEBUG) debug.println("I am starting in the block's ass");
					if (mySpeed >= blockV) { // am I already breaking
						if (DEBUG) debug.println("I am gloing with block's speed; I just keep breaking all along");
						linearEndPos = blockX1;
						if (linearEndPos >= D) { // Do I arrive home?
							time += (D - myPosition) / blockV;
							myPosition = D;
							arrived = true;
							if (DEBUG) debug.println("I am arriving home by " + time + ", following the block");
						} else {
							time = t1;
							myPosition = linearEndPos;
							mySpeed = blockV;
							if (DEBUG) debug.println("I follow the block to " + linearEndPos);
						}
					} else { // I can start with free-fall, and then break if and when I reach the guy
						
						freeFallEndSpeed = mySpeed + dt * g;
						freeFallDistance = (mySpeed + freeFallEndSpeed) / 2 * dt;
						freeFallEndPos = myPosition + freeFallDistance;
						if (freeFallEndPos <= blockX1) { // I can go with max speed
							if (DEBUG) debug.println("Block is so fast! I can go with full speed; end will be at " + freeFallEndPos);
							if (myPosition + freeFallDistance >= D) { // Do I arrive home?
								arrived = true;
								time += getRequiredFreeFallTime(mySpeed, D - myPosition, g);
								myPosition = D;
								if (DEBUG) debug.println("I am arriving home by " + time);
							} else { // Have not yet arrived home
								time = t1;
								myPosition = freeFallEndPos;
								mySpeed = freeFallEndSpeed;
							}
						} else {
							if (DEBUG) debug.println("The block is going faster, so I can start rolling, but will have to break, because I reach the guy.");

							dt1 = getRequiredTimeToCatchUp(0, blockV, mySpeed, g);
							
							freeFallEndSpeed = mySpeed + dt1 * g;
							freeFallDistance = (mySpeed + freeFallEndSpeed) / 2 * dt1;
							freeFallEndPos = myPosition + freeFallDistance;

							if (DEBUG) debug.println("I can go for " + dt1 + "secs; my position will be " + freeFallEndPos);

							if (freeFallEndPos >= D) { // Do I arrive home before breaking?
								arrived = true;
								time += getRequiredFreeFallTime(mySpeed, D - myPosition, g);
								myPosition = D;
								if (DEBUG) debug.println("I am arriving home by " + time);

							} else {
								time += dt1;
								mySpeed = freeFallEndSpeed;
								myPosition = freeFallEndPos;
								
								linearEndPos = blockX1;
								if (DEBUG) debug.println("After breaking, I follow the guy to " + linearEndPos);
								
								if (linearEndPos >= D) { // Do I arrive home?
									time += (D - myPosition) / blockV;
									myPosition = D;
									arrived = true;
									if (DEBUG) debug.println("I am arriving home by " + time + ", following the block");
								} else { // Nope, I keep going
									time = t1;
									myPosition = linearEndPos;
									mySpeed = blockV;
									if (DEBUG) debug.println("I follow the block to " + linearEndPos);
								}
							}
							
						}
					}
				}
				
			}

			if (!arrived) {
				if (DEBUG) debug.println("Has not arrived. Finishing with free fall.");
				time += getRequiredFreeFallTime(mySpeed, D - myPosition, g);
			}
			if (DEBUG) debug.println("Final result is " + time);
			
			output.println(time);
		}
	}
	
	
	private void solveAll(final Scanner input) throws NumberFormatException, IOException {
		final int cases = input.nextInt();
		input.nextLine();
		for (int caseNum = 1; caseNum <= cases; caseNum++) {
			System.out.println("Case #" + caseNum + ": ");
//			if (caseNum == 3) DEBUG = true;
			solve(input, System.out, System.err);
		}
	}
	
	public static void main(final String[] args) {
		try {
			final Scanner input = new Scanner(((args.length == 2) && args[0].equals("--input")) ? new FileInputStream(args[1]) : System.in);
			new Problem_B_0().solveAll(input);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
