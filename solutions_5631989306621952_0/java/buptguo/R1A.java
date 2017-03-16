package googleCodeJam;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;
public class R1A {
	

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		LinkedList<Character> queue = new LinkedList<Character>();
		for(int i=1;i<=n;i++){
				char[] str = in.next().toCharArray();
				queue.add(str[0]);
				for(int j=1; j< str.length; j++){
					if(str[j] >= queue.getFirst()) queue.push(str[j]);
					else queue.add(str[j]);
				}
				System.out.print("Case #" + i + ": ");
				for(Character c : queue){
					System.out.print(c);
				}
				System.out.println();
				queue.clear();
		}
	}

}
