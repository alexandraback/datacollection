package problems;

import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

import codeBook.GCJProblem;
import codeBook.GCJProblemHandler;

/**
 * @author piet
 *
 *	GCJ: Qualification 2015 Problem A
 */
public class A implements GCJProblem{
	int smax;
	int[] s;
	
	public static void main(String[] args) {
		new GCJProblemHandler("A-small-0", A.class).run();
	}

	@Override
	public void readTestcase(Scanner in) {
		smax = in.nextInt();
		s = new int[smax+1];
		String str = in.next();
		for(int i=0;i<=smax;i++)
			s[i] = str.charAt(i) - 48;
	}

	@Override
	public void solve(Writer out) throws IOException {
		floop:for(int friends=0;;friends++){
			int clapping = friends;
			for(int i=0;i<=smax;i++){
				if(clapping >= i)
					clapping += s[i];
				else continue floop;
			}
			out.write(" " + friends);
			return;
		}
	}
}