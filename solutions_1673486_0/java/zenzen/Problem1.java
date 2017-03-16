import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Problem1 {

	public static void main(String[] args) throws IOException {
		Path input = Paths.get("src/input.in");
		List<String> lines = Files
				.readAllLines(input, Charset.forName("UTF-8"));
		lines.remove(0);
		int counter = 1;
		for (int i = 0; i < lines.size(); i++) {
			String line = lines.get(i++);

			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + counter + ": ");

			String numbers[] = line.split(" ");
			int alreadyTyped = Integer.parseInt(numbers[0]);
			int total = Integer.parseInt(numbers[1]);

			line = lines.get(i);
			String probabilities[] = line.split(" ");
			double probs[] = new double[alreadyTyped];
			for (int j = 0; j < alreadyTyped; j++) {
				probs[j] = Double.parseDouble(probabilities[j]);
			}

			double pressEnterImmediately = total + 2;
			double keepTyping = keepTyping(alreadyTyped, total, probs);
			double min = Math.min(pressEnterImmediately, keepTyping);
			for(int j = 1; j <= alreadyTyped; j++) {
				min = Math.min(min, keepTyping(alreadyTyped-j,total, probs) + j);
			}

			sb.append(min);
			System.out.println(sb);
			counter++;
		}
	}

	private static double keepTyping(int alreadyTyped, int total, double[] probs) {
		double result = 0;
		Set<Integer> numbers = new HashSet<Integer>();
		for(int i = 0; i < alreadyTyped; i++) {
			numbers.add(i);
		}
		
		Set<Set<Integer>> powerSet = powerSet(numbers);
		
		for(Set<Integer> set : powerSet) {
			double temp = 1;
			for(int number : set) {
				temp *= (1-probs[number]);
			}
			
			Set<Integer> tempSet = numbers;
			tempSet.removeAll(set);
			for(int i : tempSet) {
				temp *= probs[i];
			}
			
			if(set.isEmpty()) {
				temp *= (total - alreadyTyped + 1);
			} else {
				temp *= (2*total - alreadyTyped + 2);
			}
			
			result += temp;
		}
		
		return result;
	}

	public static <T> Set<Set<T>> powerSet(Set<T> originalSet) {
	    Set<Set<T>> sets = new HashSet<Set<T>>();
	    if (originalSet.isEmpty()) {
	        sets.add(new HashSet<T>());
	        return sets;
	    }
	    List<T> list = new ArrayList<T>(originalSet);
	    T head = list.get(0);
	    Set<T> rest = new HashSet<T>(list.subList(1, list.size())); 
	    for (Set<T> set : powerSet(rest)) {
	        Set<T> newSet = new HashSet<T>();
	        newSet.add(head);
	        newSet.addAll(set);
	        sets.add(newSet);
	        sets.add(set);
	    }           
	    return sets;
	}
}
