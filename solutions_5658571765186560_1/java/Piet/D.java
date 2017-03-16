package problems;

import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

import codeBook.GCJProblem;
import codeBook.GCJProblemHandler;

/**
 * @author piet
 *
 *	GCJ: Qualification 2015 Problem D
 */
public class D implements GCJProblem{
	int X, R, C;
	
	public static void main(String[] args) {
		new GCJProblemHandler("D-large-0", D.class).run();
	}

	@Override
	public void readTestcase(Scanner in) {
		X = in.nextInt();
		R = in.nextInt();
		C = in.nextInt();
	}

	@Override
	public void solve(Writer out) throws IOException {
		if((R*C % X != 0)
		|| (X > Math.max(R, C)) 
		|| (X/2+X%2 > Math.min(R, C))
		|| (X == 4 && Math.min(R, C) == 2) 
		|| (X == 6 && Math.min(R, C) == 3) 
		|| (X >= 7) )
			out.write(" RICHARD");
		else
			out.write(" GABRIEL");
	}
}
