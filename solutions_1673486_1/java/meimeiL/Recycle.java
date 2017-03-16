import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;


public class Recycle {

	public static void main(String[] args) throws IOException{
		FileInputStream inFile = new FileInputStream("A-large.in");
		// Get the object of DataInputStream
		DataInputStream in = new DataInputStream(inFile);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		String inputCnt = br.readLine();
		FileOutputStream outFile = new FileOutputStream("output.txt");
		DataOutputStream out = new DataOutputStream(outFile);
		BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(out));

		int cnt = Integer.parseInt(inputCnt);
		for(int line=1;line<=cnt;line++){
			String inputString = br.readLine();
			String[] splited = inputString.split(" ");
			int A = Integer.parseInt(splited[0]);
			int B = Integer.parseInt(splited[1]);
			inputString = br.readLine();
			Scanner sc = new Scanner(inputString);
			Double[] p = new Double[A+1];
			for(int i=1; i <=A; i++){
				p[i] = sc.nextDouble();
			}
			double giveUp = 2.0+B;
			double best = giveUp;
			for(int i=1; i<A; i++){
				double pN = 1;
				for(int j=1;j <=(A-i);j++){
					pN = pN * p[j];
				}
				double result = pN*(i+B-A+i+1) + (1-pN)*(i+B-A+i+2+B);
				best = Math.min(result, best);
			}
			double result = A+B+2;
			best = Math.min(result, best);
			
			double pN = 1;
			for(int j=1;j <=A;j++){
				pN = pN * p[j];
			}
			result = pN*(B-A+1) + (1-pN)*(B-A+2+B);
			best = Math.min(result, best);
			String outputString = "Case #"+line+": ";
			outputString += best+"";
			wr.write(outputString);
			wr.newLine();
			wr.flush();

		}
		wr.close();
		out.close();
		br.close();
		in.close();
		inFile.close();
		outFile.close();
	}
}
