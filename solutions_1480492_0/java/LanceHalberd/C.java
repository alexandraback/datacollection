package j2012r1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

public class C {
	public static String inputDirectory="src/j2012r1a/";
	public static String inputFile="C.in";
	public static String outputFile="C.out";
	public static PrintWriter output;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));
		int cases = s.nextInt();
		s.nextLine();
		for(int Case=1;Case<=cases;Case++){
			int N = s.nextInt();
			s.nextLine();
			Car[] cars = new Car[N];
			State start = new State();
			start.time = 0;
			start.lane = new char[N];
			for(int i = 0; i < N; i++) {
				cars[i] = new Car();
				start.lane[i] = s.next().charAt(0);
				cars[i].speed = s.nextInt();
				cars[i].position = s.nextInt();
				s.nextLine();
			}
			Set<Double> times = new HashSet<Double>();
			times.add(0.0);
			for(int i=0; i<N;i++){
				for(int j = i+1; j<N; j++) {
					int deltaSpeed = (int)Math.abs(cars[j].speed - cars[i].speed);
					if (deltaSpeed == 0){
						continue;
					}
					Car fastCar = cars[i].speed > cars[j].speed ? cars[i] : cars[j];
					Car slowCar = cars[i].speed > cars[j].speed ? cars[j] : cars[i];
					double time;
					if(fastCar.position < slowCar.position - 5) {
						time = ((double)(slowCar.position - 5 - fastCar.position)) / deltaSpeed;
						times.add(time);
					}
					if(fastCar.position < cars[j].position + 5) {
						time = ((double)(slowCar.position + 5 - fastCar.position)) / deltaSpeed;
						times.add(time);
					}
				}
			}
			double[] sortedTimes = new double[times.size()];
			Iterator<Double> it = times.iterator();
			int i=0;
			while(it.hasNext()){
				sortedTimes[i++] = it.next();
			}
			Arrays.sort(sortedTimes);
			HashSet<String> used = new HashSet<String>();
			used.add(start.getKey());
			ArrayList<State> states = new ArrayList<State>();
			states.add(start);
			int bestTime = 0;
			while(states.size() > 0) {
				State next = states.remove(states.size() - 1);
				//out(next.getKey());
				bestTime = Math.max(next.time, bestTime);
				if(bestTime >= sortedTimes.length) {
					//success
					break;
				}
				double time = sortedTimes[next.time];
				double future = next.time < sortedTimes.length - 1 ? sortedTimes[next.time + 1] : time + 1;
				boolean crashed = false;
				boolean willCrash = false;
				for(i = 0; i<N && !crashed;i++){
					double p1 = cars[i].position + cars[i].speed * time;
					double p1f = cars[i].position + cars[i].speed * future;
					boolean blocked = false;
					for(int j = i+1; j<N;j++){
						double p2 = cars[j].position + cars[j].speed * time;
						double p2f = cars[j].position + cars[j].speed * future;
						willCrash = willCrash || Math.abs(p1f-p2f) < 5 && next.lane[i] == next.lane[j];
						blocked = Math.abs(p1-p2) < 5;
						if (blocked && next.lane[i] == next.lane[j]) {
							crashed = true;
							break;
						}
					}
					if (!crashed && !blocked) {
						State newState = next.copy();
						newState.change(i);
						if (!used.contains(newState.getKey())) {
							used.add(newState.getKey());
							states.add(newState);
						}
					}
				}
				if(willCrash || crashed){
					continue;
				}
				State newState = next.copy();
				newState.time++;
				if (!used.contains(newState.getKey())) {
					states.add(newState);
				}
			}
			
			long result = 0;
			if (bestTime >= sortedTimes.length) {
				out("Case #"+Case+": Possible");
			} else {
				output.printf("Case #%d: %f\n", Case, sortedTimes[bestTime]);
			}
		}
		output.flush();
	}
	
	public static class State {
		public int time;
		public char[] lane;
		
		public State copy () {
			State newState = new State();
			newState.time = time;
			newState.lane = new char[lane.length];
			for(int i=0;i<lane.length;i++){
				newState.lane[i] = lane[i];
			}
			return newState;
		}
		
		public void change(int car) {
			lane[car] = lane[car] == 'L' ? 'R' : 'L';
		}
		
		public String getKey() { 
			return time + new String(lane);
		}
	}
	
	public static class Car {
		public int speed;
		public long position;
	}
	
	public static void out(String s){
		output.println(s);
		System.out.println(s);
	}
}
