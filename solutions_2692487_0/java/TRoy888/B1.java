import java.io.File;
import java.io.FileNotFoundException;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class B1 {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File("input.txt"));
		int tCase = scanner.nextInt();
		for (int i = 1; i <= tCase; i++) {
			System.out.println("Case #"+i+": "+solved(tCase, scanner));
		}
	}
	
	public static int solved(int tCase, Scanner scanner){
		int A = scanner.nextInt();
		int N = scanner.nextInt();
		List<Integer> others = new LinkedList<Integer>();
		for (int j = 0; j < N; j++) {
			others.add(scanner.nextInt());
		}
		Collections.sort(others);
		//System.out.println(others);
		int count = 0;
		for (int j = 0; j < others.size();j++) {
			int other = others.get(j);
			if(A>other){
				A+=other;
			}
			else{
				int countTmp=0;
				while(A<=other){
					if(A-1==0){
						return others.size();
					}
					A+=A-1;
					countTmp++;
				}
				if(countTmp>others.size() || count+countTmp>others.size() || countTmp>others.size()-j){
					if(others.size()>count+others.size()-j){
						return count+others.size()-j;
					}
					else{
						return others.size();
					}
				}
				else{
					count+=countTmp;
					A+=other;
				}
			}
		}
		return count;
	}
}
