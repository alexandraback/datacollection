import java.io.*;


public class Password {
	public static void main(String[] args) {
		try{
			BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
			BufferedReader input = new BufferedReader(new FileReader("A-large.in"));
			int i = 0;
			int j = Integer.parseInt(input.readLine());
			while(i < j) {
				String[] header = input.readLine().split(" ");
				int letters = Integer.parseInt(header[0]);
				//minimum is the number of keystrokes for case 3
				int maxletters = Integer.parseInt(header[1]);
				double minimum = maxletters +2.0;
				header = input.readLine().split(" ");
				double[] prob = new double[header.length];
				int foo = 0;
				for(String stringProb: header) {
					prob[foo] = Double.parseDouble(stringProb);
					foo++;
				}
				
				//check cases
				if(letters != 0){
					for(int k = 0;k<letters;k++) {
						double caseProb = 1;
						double current;
						for(int l = letters-k-1;l>-1;l--) {
							caseProb *= prob[l];
						}
						current = (maxletters - letters+1)*caseProb + (2*maxletters - letters+2)*(1-caseProb) + 2*k;
						if(minimum > current) {minimum = current;}
					}
				}
				
				output.write("Case #" + (i+1) + ": " + minimum);
				output.newLine();
				i++;
			}
			output.close();
			input.close();
		} catch(Exception e) {System.out.println(e);}
	}
}
