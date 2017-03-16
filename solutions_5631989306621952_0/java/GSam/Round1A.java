
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Scanner;


public class Round1A {
	public static void main(String[] args){
		Round1A t = new Round1A();
		t.readInput();
	}
	
	public void readInput(){
		Scanner scan;
		try {
			scan = new Scanner(new File("input.txt"));
			PrintStream p = new PrintStream("output.txt");
			long num = scan.nextLong();
			for(long i = 1; i <= num; i++){
				scan.nextLine();
				
				String line = scan.next();
				LinkedList<Character> result = new LinkedList<Character>();
				char first = line.charAt(0);
				result.addFirst(first);
				for (int k = 1; k < line.length(); k++) {
					char current = line.charAt(k);
					if (current >= first) {
						result.addFirst(current);
						first = current;
					} else {
						result.addLast(current);
					}
				}	
				
				String answer = "";
				for (char c : result) {
					answer += c;
				}
				p.println("Case #" + i + ": " + answer);
				System.out.println("Case #" + i + ": " + answer);

				
			}
			p.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}

}
