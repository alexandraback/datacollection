import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class TrainCar {

	public String _desc;

	public TrainCar(String desc) {
		_desc = desc;
	}

	public static String SINGLE = "SINGLE";
	public static String START = "START";
	public static String END = "END";
	public static String ENCLOSED = "ENCLOSED";

	public static Map<String, List<TrainCar>> getInitializedMap() {
		Map<String, List<TrainCar>> map = new HashMap<String, List<TrainCar>>();
		map.put(SINGLE, new ArrayList<TrainCar>());
		map.put(START, new ArrayList<TrainCar>());
		map.put(END, new ArrayList<TrainCar>());
		map.put(ENCLOSED, new ArrayList<TrainCar>());
		return map;
	}

	public static boolean sameChar(String line) {
		String lineMod = line.replace(line.charAt(0) + "", "");
		return (lineMod.length() == 0);
	}

	public static String cleanString(String s) {
		return s.replaceAll("(.)\\1+", "$1");
	}

	public static int nC2(int n) {
		if (n == 1)
			return 1;
		return n * (n - 1) / 2;
	}

	public static long analyze(String[] cars) {
		Set<TrainCar> trainCarSet = new HashSet<TrainCar>();
		Map<Character, Map<String, List<TrainCar>>> charToTrainMap = new HashMap<Character, Map<String, List<TrainCar>>>();
		Map<TrainCar, Character> trainToStartCharMap = new HashMap<TrainCar, Character>();
		Map<TrainCar, Character> trainToEndCharMap = new HashMap<TrainCar, Character>();
		for (String carOrig : cars) {
			String car = cleanString(carOrig);
			TrainCar trainCar = new TrainCar(car);
			trainCarSet.add(trainCar);
			boolean sameChar = sameChar(car);
			for (char c : car.toCharArray()) {
				if (!charToTrainMap.containsKey(c)) {
					charToTrainMap.put(c, TrainCar.getInitializedMap());
				}
			}
			if (sameChar) {
				charToTrainMap.get(car.charAt(0)).get(SINGLE).add(trainCar);
			} else {
				for (int index = 0; index < car.length(); index++) {
					char charAtI = car.charAt(index);
					if (index == 0) {
						charToTrainMap.get(charAtI).get(START).add(trainCar);
						if (charToTrainMap.get(charAtI).get(START).size() > 1) {
							return 0;
						}
						trainToStartCharMap.put(trainCar, charAtI);
					} else if (index == car.length() - 1) {
						charToTrainMap.get(charAtI).get(END).add(trainCar);
						if (charToTrainMap.get(charAtI).get(END).size() > 1) {
							return 0;
						}
						trainToEndCharMap.put(trainCar, charAtI);
					} else {
						charToTrainMap.get(charAtI).get(ENCLOSED).add(trainCar);
						if (charToTrainMap.get(charAtI).get(ENCLOSED).size() > 1) {
							return 0;
						}
					}
				}
			}
		}

		// all the maps are setup - calculate possibilities
		HashSet<TrainCar> alreadyCovered = new HashSet<TrainCar>();
		int possibilities = 1;
		for (TrainCar trainCar : trainCarSet) {
			if (!alreadyCovered.contains(trainCar)) {
				alreadyCovered.add(trainCar);
				alreadyCovered.addAll(charToTrainMap.get(
						trainCar._desc.charAt(0)).get(SINGLE));
				possibilities *= nC2(charToTrainMap
						.get(trainCar._desc.charAt(0)).get(SINGLE).size());
			}
		}
		double answerSquareRoot = Math.sqrt(possibilities);
		return Math.round(answerSquareRoot);
	}

	public static void main(String[] args) {
		try {
			BufferedReader bufferRead = new BufferedReader(
					new InputStreamReader(System.in));
			String s = bufferRead.readLine();
			int numCases = Integer.parseInt(s);
			for (int i = 1; i <= numCases; i++) {
				String line = bufferRead.readLine();
				line = bufferRead.readLine();
				String[] lineSplit = line.split(" ");
				long output = analyze(lineSplit);
				System.out.println("Case #" + i + ": " + output);
			}
		} catch (IOException e) {
		}

	}

}
