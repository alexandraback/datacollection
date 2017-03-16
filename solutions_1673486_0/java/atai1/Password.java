import java.io.*;
import java.util.*;

public class Password {
	public static void main(String[] args) throws IOException {		
		BufferedReader br = new BufferedReader(new FileReader(new File("/Users/atai/Play/Codejam/input.txt")));
		PrintWriter prn = new PrintWriter(new FileWriter("output.txt"));
		
		int numTests = Integer.parseInt(br.readLine().trim());
		for (int i = 0; i < numTests; i++) {
			String[] arg = br.readLine().trim().split(" ");
			int A = Integer.parseInt(arg[0]);
			int B = Integer.parseInt(arg[1]);
			arg = br.readLine().trim().split(" "); // arg now has length B
			double[] probs = new double[A];
			for (int j = 0; j < probs.length; j ++) {
				probs[j] = Double.parseDouble(arg[j]);
			}
			double returnMe = 0;
			double temp1;
			double temp2;
			double temp3;
			double temp4;
			double temp5;
			switch(A) {
			case 1:
				// Keeping typing
				temp1 = B*probs[0] + (1-probs[0])*(2*B+1);
				temp2 = B+2;
				temp3 = B+2;
				returnMe = Math.min(temp1, temp2);
				break;
			case 2:
				temp1 = (B-1)*probs[0]*probs[1] + (2*B*(1-probs[0]*probs[1]));
				temp2 = (B+1)*(probs[0]) + (2*B+2)*(1-probs[0]);
				//temp3 = B+3;
				temp4 = B+2;
				returnMe = Math.min(temp4,(Math.min(temp1, temp2)));
				break;
			case 3:
				temp1 = (B-2)*(probs[0]*probs[1]*probs[2]) + (2*B-1)*(1-probs[0]*probs[1]*probs[2]);
				temp2 = B*(probs[0]*probs[1]) + (2*B+1)*(1-probs[0]*probs[1]);
				temp3 = (B+2)*probs[0] + (2*B+3)*(1-probs[0]);
				//temp4 = B+4;
				temp5= B+2;
				returnMe = Math.min(temp5, Math.min(temp3, Math.min(temp2, temp1)));
				break;
			}
			prn.printf("Case #%d: %f\n", i+1, returnMe);
		}
		
		prn.close();
	}
}
