import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Scanner;


public class A {
	public static void main(String[] args) {
		try {
			System.setIn(new FileInputStream(new File("in.txt")));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			System.setOut(new PrintStream(new File("out.txt")));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		Scanner s = new Scanner(System.in);
		
		int n = s.nextInt();
		
		for (int i = 0; i < n; i++) {
			ArrayDeque<Character> list = new ArrayDeque<Character>();
			String str = s.next();
			for (int j = 0;j < str.length(); j++) {
				char c = str.charAt(j);
				if (list.isEmpty() || c < list.peekFirst()) {
					list.addLast(c);
				}
				else {
					list.addFirst(c);
				}
			}
			StringBuilder sb = new StringBuilder();
			for (Character c : list) {
				sb.append(c);
			}
			System.out.println("Case #" + (i + 1) + ": " + sb);
		}
	}
}
