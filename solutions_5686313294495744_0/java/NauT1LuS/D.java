
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class D {

	public static void main(String[] args) {
		// for(int i = 0; i <= 1000000; i++){
		// solveTest(i, i);
		// }
		// return;
		D temp =  new D();
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for (int i = 0; i < tests; i++) {
			int seed = in.nextInt();
			
			temp.solveTest(seed, i + 1, in);
		}
		in.close();
	}
	
	public class Topic implements Comparable<Topic>{
		public String first = "";
		public String second = "";
		public Topic(String first, String second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int compareTo(Topic o) {
			// TODO Auto-generated method stub
			if( !first.equals(o.first) ){
				return first.compareTo(o.first);
			}
			return second.compareTo(o.second);
		}
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return "("+ first + " " + second + ")";
		}
		
	}
	private void solveTest(int seed, int caseNumber, Scanner in) {

		Map<String, Integer> firstWord = new HashMap<>();
		Map<String, Integer> secondWord = new HashMap<>();
		
		Set<Topic> topics = new TreeSet();

		Set<Topic> dublicates = new TreeSet();
		Set<Topic> unique = new TreeSet();
		
		Set<String> uniqueFirst = new TreeSet();
		Set<String> uniqueSecond = new TreeSet();
		
		for(int i = 0 ; i < seed; i++){
			String first  = in.next();
			String second = in.next();
			Integer firstcount = 0;
			if(firstWord.containsKey(first)){
				firstcount = firstWord.get(first);
			}
			firstcount++;
			firstWord.put(first, firstcount);
			
			
			Integer secondCount = 0;
			if(secondWord.containsKey(second)){
				secondCount = secondWord.get(second);
			}
			secondCount++;		
			secondWord.put(second, secondCount);
			Topic topic = new Topic(first, second);
			topics.add(topic);
		}
		
		for(Topic topic : topics ){
			if(firstWord.get(topic.first) == 1 || secondWord.get(topic.second) == 1){
				uniqueFirst.add(topic.first);
				uniqueSecond.add(topic.second);
				unique.add(topic);
				
				
			}
		}
		topics.removeAll(unique);
		
		
		for (Topic topic : topics) {
			if (uniqueFirst.contains(topic.first) && uniqueSecond.contains(topic.second)) {
				dublicates.add(topic);
			}
		}
		topics.removeAll(dublicates);
		
//		System.out.println("Print unique:");
//		printList(unique);
//		System.out.println("Print Duplicates:");
//		printList(dublicates);
//		System.out.println("Print Rest:");
//		printList(topics);
		
		int addition = trymorth(uniqueFirst, uniqueSecond, topics.toArray(new Topic[topics.size()]));
		
		System.out.println("Case #" + caseNumber + ": " + (dublicates.size() + topics.size() - addition) );

	}

	private int trymorth(Set<String> uniqueFirstGlobal, Set<String> uniqueSecondGlobal, Topic[] objects) {
		for (int i = 1; i < objects.length; i++) {
			int limit = 1 << objects.length;

			for (int j = 0; j <= limit; j++) {
				if (Integer.bitCount(j) == i) {
					Topic[] choosen = new Topic[i];
					Set<String> uniqueFirst = new TreeSet();
					Set<String> uniqueSecond = new TreeSet();
					uniqueFirst.addAll(uniqueFirstGlobal);
					uniqueSecond.addAll(uniqueSecondGlobal);

					int f = 0;
					// check bits for each bit select topics
					for (int k = 0; k < objects.length; k++) {
						if (BigInteger.valueOf(j).testBit(k)) {
							uniqueFirst.add(objects[k].first);
							uniqueSecond.add(objects[k].second);
							choosen[f] = objects[k];
							f++;
						}
					}
					boolean flag = true;

					for (int k = 0; k < objects.length; k++) {
						if (!uniqueFirst.contains(objects[k].first) || !uniqueSecond.contains(objects[k].second)) {
							flag = false;
							break;
						}

					}
					if (flag) {
						return i;
					}

				}
			}

		}

		return objects.length;

	}
	private void printList(Set<Topic> unique) {
		for(Topic topic: unique){
			System.out.println(topic);
		}
		
	}
	

}
