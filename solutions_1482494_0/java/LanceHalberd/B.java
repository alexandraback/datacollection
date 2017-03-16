package j2012r1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class B {
	public static String inputDirectory="src/j2012r1a/";
	public static String inputFile="B.in";
	public static String outputFile="B.out";
	public static PrintWriter output;
	public static int levels;
	public static int[][] stars;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));
		int cases = s.nextInt();
		s.nextLine();
		for(int Case=1;Case<=cases;Case++){
			levels = s.nextInt();
			s.nextLine();
			stars = new int[levels][2];
			State start = new State();
			start.completed = new char[levels];
			for(int i=0;i<levels;i++){
				start.completed[i] = '0';
				stars[i][0] = s.nextInt();
				stars[i][1] = s.nextInt();
				s.nextLine();
			}
			Map<String, State> seen = new HashMap<String, State>();
			seen.put(start.getKey(), start);
			ArrayList<State> states = new ArrayList<State>();
			states.add(start);
			int answer = 1000000;
			while(states.size() > 0) {
				
				State nextState = states.remove(0);
				State otherState = seen.get(nextState.getKey());
				if (otherState != null && otherState.moves < nextState.moves) {
					continue;
				}
				//out(nextState.getKey() + " : " + nextState.moves);
				if (nextState.myStars == levels * 2) {
					answer = Math.min(answer, nextState.moves);
					continue;
				}
				for(int i=0;i<levels;i++){
					if(nextState.completed[i] == '2') {
						continue;
					}
					if(nextState.completed[i] == '1' && nextState.myStars < stars[i][1]) {
						continue;
					}
					if(nextState.myStars < stars[i][0]) {
						continue;
					}
					State newState = nextState.copy();
					newState.move(i);
					String key = newState.getKey();
					otherState = seen.get(key);
					if (otherState == null || newState.moves < otherState.moves) {
						seen.put(key, newState);
						states.add(newState);
					}
				}
			}
			
			if(answer <= 2*levels){
				out("Case #"+Case+": "+answer);
			} else {
				out("Case #"+Case+": Too Bad");
			}
				
		}
		output.flush();
	}
	
	public static class State {
		
		public int moves = 0;
		public int myStars = 0;
		public char[] completed;
		
		public State copy() {
			State copy = new State();
			copy.moves = moves;
			copy.myStars = myStars;
			copy.completed = new String(completed).toCharArray();
			return copy;
		}
		
		public void move(int level) {
			moves++;
			if (myStars >= stars[level][1]) {
				twoStar(level);
			} else {
				oneStar(level);
			}
			//go ahead and complete any 2 star quests that are doable
			for (int i=0;i<levels;i++) {
				if(completed[i] != '2' && myStars >= stars[i][1]) {
					move(i);
					return;
				}
			}
		}
		
		public String getKey() {
			return new String(completed);
		}
		
		public void oneStar(int level) {
			if(completed[level] == '0' || completed[level] == '2') {
				completed[level] = '1';
				myStars++;
			}
		}
		public void twoStar(int level) {
			if(completed[level] == '2') {
				return;
			}
			if(completed[level] == '0') {
				myStars+=2;
			}else if(completed[level] == '1') {
				myStars++;
			}
			completed[level] = '2';
		}
	}
	
	public static void out(String s){
		output.println(s);
		System.out.println(s);
	}
}