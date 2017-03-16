package round1;
/**
 * May use open source library jgrapht available at http://jgrapht.org
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;


public class Password {
	BufferedReader _in;
	PrintWriter _out;
	
	int _numTestCases;
	Input[] _inputs;
	
	int levelsNeeded = 0;
	
	Comparator<Tuple> comparatorTwoStar = new Comparator<Password.Tuple>() {
		@Override
		public int compare(Tuple o1, Tuple o2) {
			// TODO Auto-generated method stub
			if(o1.oneStar == o2.oneStar && o1.twoStar == o2.twoStar)
				return 0;
			if(o1.twoStar < o2.twoStar) {
				return -1;
			} else if(o1.twoStar > o2.twoStar) {
				return 1;
			} else {
				return o2.oneStar - o1.oneStar;
			}
		}
	};
	
	public Password(BufferedReader in) throws Exception {
		this._in = in;
		this._out = new PrintWriter("answers.out");
	}

	public void calculate() throws Exception {
		this._inputs = readInputs();
		
		for(int i=0; i < _inputs.length; i++) {
			processInput(_inputs[i], i+1);
		}
		_out.flush();
		_out.close();
	}
	
	
	private void processInput(Input input, int caseIndex) {

		int points = 0;
		levelsNeeded = 0;
		ArrayList<Tuple> levelOneStar = new ArrayList<Tuple>(Arrays.asList(input.levels));
		Comparator<Tuple> comparatorOneStar = new Comparator<Password.Tuple>() {
			@Override
			public int compare(Tuple o1, Tuple o2) {
				// TODO Auto-generated method stub
				if(o1.oneStar == o2.oneStar && o1.twoStar == o2.twoStar)
					return 0;
				
				if(o1.oneStar < o2.oneStar) {
					return -1;
				} else if (o1.oneStar > o2.oneStar) {
					return 1;
				} else {
					return o2.twoStar - o1.twoStar;
				}
			}
		};
		Collections.sort(levelOneStar,comparatorOneStar);
		
		ArrayList<Tuple> levelTwoStar = new ArrayList<Tuple>(Arrays.asList(input.levels));
		
		Collections.sort(levelTwoStar,comparatorTwoStar);
		
		ArrayList<Tuple> levelTwoStarCopy = new ArrayList<Tuple>(levelTwoStar);
		
		//Iterate over levelTwoStar
		boolean success = true;
		for(Iterator<Tuple> iter = levelTwoStar.iterator(); iter.hasNext();) {
			Tuple level = iter.next();	
			if(level.twoStarAchieved)
				continue;
			points = reachPoints(levelOneStar, levelTwoStarCopy, level.twoStar, points);
			if(points >= level.twoStar) {
				points += completeLevel(level);
				levelsNeeded++;
				levelOneStar.remove(level);
			} else {
				success = false;
				break;
			}
			
		}
		
		String outcome = success? levelsNeeded + "" : "Too Bad";
		
		_out.println("Case #" + caseIndex +": " + outcome);
	}
	
	private int reachPoints(ArrayList<Tuple> levelOneStar, ArrayList<Tuple> levelTwoStarCopy,int pointsNeeded, int pointsCurrent) {
		Iterator<Tuple> iter = levelOneStar.iterator();
		while(pointsCurrent < pointsNeeded && iter.hasNext()) {
			//complete any levels that already have level one completed
			for(Iterator<Tuple> iter2 = levelTwoStarCopy.iterator(); iter2.hasNext();) {
				Tuple level = iter2.next();
				if(level.oneStarAchieved && !level.twoStarAchieved && pointsCurrent >= level.twoStar) {
					levelsNeeded++;
					pointsCurrent += 1;
					level.twoStarAchieved = true;
				}
				if(level.twoStarAchieved)
					iter2.remove();
			}
			
			Tuple level = iter.next();
			ArrayList<Tuple> consumableTuples = new ArrayList<Password.Tuple>();
			Tuple currentlyAddedLevel = null;
			if(pointsCurrent >= level.oneStar) {
				while(pointsCurrent >= level.oneStar && iter.hasNext()) {	
					currentlyAddedLevel = level;
					consumableTuples.add(level);
					level = iter.next();
				}
				level = currentlyAddedLevel;
				Collections.sort(consumableTuples, comparatorTwoStar);
			}
			if(consumableTuples.size() > 0) {
				level = consumableTuples.get(consumableTuples.size() -1);
				levelsNeeded++;
				pointsCurrent += 1;
				level.oneStarAchieved = true;
				levelOneStar.remove(level);
				iter = levelOneStar.iterator();
			} else {
				break;
			}
		}
		
		return pointsCurrent;
	}
	
	private int completeLevel(Tuple level) {
		if(level.oneStarAchieved)
			return 1;
		else 
			return 2;
			
	}
	
	
	private Input[] readInputs() throws Exception {
		
		Scanner scanner = new Scanner(_in);
		_numTestCases = scanner.nextInt();
		Input[] inputs = new Input[_numTestCases];
		for(int i=0; i < _numTestCases; i++) {
			int N = scanner.nextInt();
			Tuple t[] = new Tuple[N];
			for(int j =0; j < N; j++) {
				t[j] = new Tuple(scanner.nextInt(), scanner.nextInt());
			}

			inputs[i] = new Input(t);
		}
		_in.close();
		return inputs;
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		new Password(in).calculate();
	}
	
	private class Tuple {
		int oneStar;
		int twoStar;
		
		boolean oneStarAchieved = false;
		boolean twoStarAchieved = false;
		
		public Tuple (int n, int m) {
			this.oneStar = n;
			this.twoStar = m;
		}
		@Override
		public int hashCode() {
			return twoStar + oneStar;
		}
		@Override
		public boolean equals(Object obj) {
			Tuple other = (Tuple)obj;
			if (twoStar != other.twoStar)
				return false;
			if (oneStar != other.oneStar)
				return false;
			return true;
		}
		
		public String toString() {
			return "one="+oneStar +",two=" + twoStar + "," + oneStarAchieved;
		}
	}
	
	private class Input {
		Tuple[] levels;
		
		public Input(Tuple[] levels) {
			this.levels = levels;
		}
	}
}
