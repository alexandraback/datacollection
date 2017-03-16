import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class OviationSmall {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		FileWriter writer = new FileWriter("output.txt", false);
		writer.write("");
		writer.close();
		
		writer = new FileWriter("output.txt", true);
		
		int num_case = 0;
		int nbr_case = Integer.parseInt(br.readLine());
		
		String sCurrentLine;
		for (int k = 0; k < nbr_case; k++) {
			sCurrentLine = br.readLine();
			String tmp[] = sCurrentLine.split(" ");
			int smax = Integer.parseInt(tmp[0]);
			int[] distri = new int[smax+1];
			for(int i = 0; i < smax+1; i++){
				distri[i] = Integer.parseInt(String.valueOf(tmp[1].charAt(i)));
			}
			int cumsum = 0;
			int nbr = 0;
			for(int i = 0; i < smax+1; i++){
				if(cumsum < i){
					nbr++;
					cumsum += distri[i]+1;
				}
				else
					cumsum += distri[i];
			}
			num_case++;
			writer.write("Case #"+num_case+": "+nbr+"\n");
			
		}
		writer.close();
	}

}
