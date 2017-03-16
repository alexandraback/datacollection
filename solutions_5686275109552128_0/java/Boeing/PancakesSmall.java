import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.LinkedList;


public class PancakesSmall {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt1.in"));
		FileWriter writer = new FileWriter("output.txt", false);
		writer.write("");
		writer.close();
		
		writer = new FileWriter("output.txt", true);
		
		int nbr_case = Integer.parseInt(br.readLine());
		
		String sCurrentLine;
		
		for (int num_case = 1; num_case <= nbr_case; num_case ++) {
			int nbr_plate = Integer.parseInt(br.readLine());
			
			sCurrentLine = br.readLine();
			String tmp[] = sCurrentLine.split(" ");
			
			//LinkedList<Integer>  list = new LinkedList<Integer> () ;
			
			int[] list = new int[nbr_plate];
			
			for(int i = 0; i < tmp.length; i++)
				list[i]=Integer.parseInt(tmp[i]);
			
			int max = list[0];
			for(int i = 1; i < list.length; i++){
				if(list[i] > max)
					max = list[i];
			}
			
			int[] time = new int[max];
			for(int m = 0; m < max; m++){
				time[m] = m+1;
				for(int i = 0; i < list.length; i++){
					int nbr_deplacement;
					if(list[i] < m+1)
						nbr_deplacement = 0;
					else if(list[i] % (m+1) == 0)
						nbr_deplacement = list[i] / (m+1) - 1;
					else
						nbr_deplacement = list[i] / (m+1);
					time[m] += nbr_deplacement;
				}
			}
			
			int min = time[0];
			for(int i = 1; i < time.length; i++){
				if(time[i] < min)
					min = time[i];
			}
			writer.write("Case #" + num_case + ": " + min +"\n");
		}
		writer.close();
	}

}
