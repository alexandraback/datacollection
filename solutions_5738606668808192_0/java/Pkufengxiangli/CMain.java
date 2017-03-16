import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
public class CMain {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
		Set<LinkedList<Integer>> recordSet  = new HashSet<>();
		Random random = new Random();
		for (int i = 1; i <= t; ++i) {
			int n = in.nextInt();
			int j = in.nextInt();
			int recordNum = 0;
			LinkedList<Integer> recordList = new LinkedList<Integer>(); 
			while (j!= 0) {
				for (int k = 1; k < n - 1; k++) {
					int rand = random.nextInt(2); 
					recordList.add(rand);
					if (rand == 1) {
						recordNum += (k)%2 == 0?1:-1;
					}
				}
				if ((recordNum + (n%2 == 0?0:2)) ==0 && !recordSet.contains(recordList)) {
					recordSet.add(recordList);
					j--;
				}
				recordList = new LinkedList<Integer>();
				recordNum = 0;
			}
			System.out.println("Case #" + i + ": ");
			printResult(recordSet, i);
			recordSet.clear();
		}
	}
	public static void printResult(Set<LinkedList<Integer>> recordSet, int i){
		for (LinkedList<Integer> linkedList : recordSet) {
			System.out.print(1);
			for (int j = linkedList.size() - 1; j >= 0; j--) {
				System.out.print(linkedList.get(j));
			}
			System.out.print(1+" ");
			for (int j = 0; j < 8; j++) {
				System.out.print((j+3)+" ");
			}
			System.out.println(11);
		}
	}
}
