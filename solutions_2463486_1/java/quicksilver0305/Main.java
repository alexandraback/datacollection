package gcj2013;

import java.io.*;

public class Main {

	public static void main(String args[]){
		try{
			BufferedReader br = new BufferedReader(new FileReader("input.txt"));
			BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));

//			ProblemA pa = new ProblemA(br, bw);
//			pa.exec();

//			ProblemB pb = new ProblemB(br, bw);
//			pb.exec();

			ProblemC pc = new ProblemC(br, bw);
			pc.exec();
			
		}	catch(IOException e) {
		
			e.printStackTrace();
		
		}
	}
}
