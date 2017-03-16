package equalSums.codejam;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws IOException{

		FileWriter fw = new FileWriter("./output.txt");
		Scanner in = new Scanner(new File("/home/lotrf3/Downloads/C-small-attempt0.in"));
		int cases = in.nextInt();
		for (int i=0; i<cases; i++){
			Case x = new Case(in);
			fw.append("Case #"+(i+1) + ":\n" + x.solve() + "\n");
		}
		fw.close();
	}

}
