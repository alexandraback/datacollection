import java.io.*;
import java.util.*;


public class Qual3 {
	private static Set<String> set = new HashSet<String>(); 
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("C-large.in"));
		FileWriter fw = new FileWriter("C-output.txt");
		int total = sc.nextInt();
		for(int i = 1; i <= total; i++) {
			set.clear();
			int count = 0, st = sc.nextInt(), end = sc.nextInt();
			for(int j = st; j < end; j++) process(j, end);
			fw.write("Case #" + i + ": " + set.size() + "\n");
			System.out.println("Case #" + i + ": " + set.size());
		}
		fw.close();
	}
	
	private static void process(int num, int max) {
		int digit = 10;
		while(digit < num) {
			int div = num / digit, rem = num % digit;
			int switched = Integer.parseInt("" + rem  + div);
			if(num < switched && switched <= max) {
				String s = num + ", " + switched;
				set.add(s);
			}
			digit *= 10;
		}
	}

}
