import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class OviationSmall {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		String filename = "A-large";
		BufferedReader br = new BufferedReader(new FileReader(filename+".in"));
		FileWriter writer = new FileWriter(filename+".out", false);
		writer.write("");
		writer.close();
		
		writer = new FileWriter(filename+".out", true);
		
		int nbr_case = Integer.parseInt(br.readLine());
		
		String sCurrentLine;
		for (int num_case = 1; num_case <= nbr_case; num_case ++) {
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
				if(distri[i] != 0){
					if(cumsum < i){
						nbr += i-cumsum;
						cumsum += distri[i]+i-cumsum;
					}
					else
						cumsum += distri[i];
				}
			}
			writer.write("Case #"+num_case+": "+nbr+"\n");
			
		}
		writer.close();
	}

}
