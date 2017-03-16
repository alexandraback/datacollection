import java.io.*;
import java.util.*;

public class A {
	public static void main(String args[]) throws Exception {
		StringBuilder s = new StringBuilder();
		Scanner input = new Scanner(new File("1.txt"));
		while(input.hasNext()) {
			s.append(input.nextLine() + "\n");
		}
		System.out.println(s);
	}
}
