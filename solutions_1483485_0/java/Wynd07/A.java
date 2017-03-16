import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class A {
	public static void main (String [] args) throws IOException {new A().run();}
	public void run() throws IOException{
		Scanner file = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
				   //abcdefghijklmnopqrstuvwxyz
		char[] in = "yhesocvxduiglbkrztnwjpfmaq".toCharArray();
		int times = Integer.parseInt(file.nextLine());
		for(int asdf = 0; asdf<times; asdf++){
			out.print("Case #" + (asdf+1)+ ": ");
			for(char c : file.nextLine().toCharArray())
				if( Character.isLetter(c) )
					out.print(in[c-'a']);
				else
					out.print(c);
			out.println();
		}
		out.close();
		System.exit(0);
	}
}