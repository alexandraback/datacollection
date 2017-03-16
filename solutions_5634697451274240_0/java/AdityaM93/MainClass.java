package pack;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class MainClass {
	
	public static int recur(boolean[] stack, boolean req){
		if(stack.length == 0)
			return 0;
		boolean[] newStack = new boolean[stack.length - 1];
		for(int i = 1;i < stack.length; i++)
			newStack[i - 1] = stack[i];
		if(stack[0] == req)
			return recur(newStack, req);
		else
			return 1 + recur(newStack, !req);
	}

	public static void main(String[] args) throws FileNotFoundException {

		File fin = new File("input.in");
		File fout = new File("output.out");

		Scanner in = new Scanner(fin);
		PrintWriter out = new PrintWriter(fout);

		int T = in.nextInt();
		in.nextLine();
		boolean[] stack, compactStack;
		int actualLength;

		String inputStack;
		for (int cT = 1; cT <= T; cT++) {
			inputStack = in.nextLine();
			stack = new boolean[inputStack.length()];
			for (int i = inputStack.length() - 1; i >= 0; i--)
				stack[inputStack.length() - (i + 1)] = inputStack.charAt(i) == '+';
			actualLength = 1;
			for (int i = 1; i < stack.length; i++)
				if (stack[i] != stack[i - 1])
					actualLength++;
			compactStack = new boolean[actualLength];
			compactStack[0] = stack[0];
			int c = 1;
			for (int i = 1; i < stack.length; i++)
				if (stack[i] != stack[i - 1])
					compactStack[c++] = stack[i];
			out.println("Case #" + cT + ": " + recur(compactStack, true));
		}
		in.close();
		out.close();
	}

}
