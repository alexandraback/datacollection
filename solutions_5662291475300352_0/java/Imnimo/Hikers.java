import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Hikers {
	public static void main(String[] args) throws Exception{
		Scanner s = new Scanner(new File("C-small-1-attempt1.in"));
		int numCases = Integer.parseInt(s.nextLine());
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			int numGroups = Integer.parseInt(s.nextLine());
			ArrayList<Hiker> hikers = new ArrayList<Hiker>();
			for(int group = 1;group<=numGroups;group++) {
				String groupString = s.nextLine();
				String[] groupArr = groupString.split("\\s+");
				int startPoint = Integer.parseInt(groupArr[0]);
				int groupSize = Integer.parseInt(groupArr[1]);
				int fastest = Integer.parseInt(groupArr[2]);
				for(int g = 0;g<groupSize;g++) {
					hikers.add(new Hiker(startPoint,360d/(fastest+g)));
				}
			}
			System.out.println("Case #" + currentCase + ": " + solve(hikers));
			
		}
	}
	
	
	public static int solve(ArrayList<Hiker> hikers) {
		//System.out.println(hikers.get(0));
		//System.out.println(hikers.get(1));
		if(hikers.get(0).speed == hikers.get(1).speed) {
			return 0;
		}
		//if faster is behind slower, let them catch up.
		Hiker slower,faster;
		if(hikers.get(0).speed < hikers.get(1).speed) {
			slower = hikers.get(0);
			faster = hikers.get(1);
		} else {
			faster = hikers.get(0);
			slower = hikers.get(1);
		}
		if(slower.start > faster.start) {
			double timeToMeet = (slower.start - faster.start)/(faster.speed - slower.speed);
			double meetingLocation = slower.start + timeToMeet*slower.speed;
			if(meetingLocation >=360) {
				return 0;
			} else {
				slower.start = meetingLocation;
				faster.start = meetingLocation;
			}
			//System.out.println("Hikers will meet in " + timeToMeet + " at " + (slower.start + timeToMeet*slower.speed));
		}
		
		double timeForSlowToFinish = (360-slower.start)/slower.speed;
		//System.out.println("From " + slower.start + " it will take hiker with speed " + slower.speed + " " + timeForSlowToFinish);
		double fasterLocation = faster.start + timeForSlowToFinish * faster.speed;
		//System.out.println("By then, " + faster.speed + " will get from " + faster.start + " to " + fasterLocation);
		if(fasterLocation>=720) {
			return 1;
		}
		
		return 0;
	}
}
class Hiker {
	double start, speed;
	public Hiker(double start, double speed) {
		this.start = start;
		this.speed = speed;
	}
	public String toString() {
		return "Hiker starting from " + start + " with speed " + speed;
	}
}
