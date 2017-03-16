import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Dijkstra {
	static final Quaternion ONE = new Quaternion(1,0,0,0);
	static final Quaternion i = new Quaternion(0,1,0,0);
	static final Quaternion j = new Quaternion(0,0,1,0);
	static final Quaternion k = new Quaternion(0,0,0,1);
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		String filename = "C-large";
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
			int L = Integer.parseInt(tmp[0]);
			long X = Long.parseLong(tmp[1]);
			
			sCurrentLine = br.readLine();
			Quaternion[] unite = new Quaternion[L];
			for(int s = 0;  s < L; s++){
				if(sCurrentLine.charAt(s)=='i')
					unite[s] = i;
				else if(sCurrentLine.charAt(s)=='j')
					unite[s] = j;
				else
					unite[s] = k;
			}
			
			boolean early_break = false;
			
			Quaternion value_uni = ONE;
			
			for(int s = 0; s < unite.length; s++)
				value_uni = value_uni.times(unite[s]);
			
			Quaternion product_i = ONE;
			Quaternion product_j = ONE;
			Quaternion product_k = ONE;
			
			long periode_complete_reste = X;
			int periode_complete_effectue = 0;
			int elements_parcouris = 0;
			int index=0;
			
			while(!product_i.egal(i)){
				if(periode_complete_effectue >= X || periode_complete_effectue >=4){
					writer.write("Case #"+num_case+": NO\n");
					early_break = true;
					break;
				}
				product_i = product_i.times(unite[index]);
				elements_parcouris++;
				index = (index+1) % L;
				periode_complete_effectue = elements_parcouris/L;
			}
			if(early_break)
				continue;
			
			int periode0 = periode_complete_effectue;
			while(!product_j.egal(j)){
				if(periode_complete_effectue >= X || periode_complete_effectue - periode0 >=4){
					writer.write("Case #"+num_case+": NO\n");
					early_break = true;
					break;
				}
				product_j = product_j.times(unite[index]);
				elements_parcouris++;
				index = (index+1) % L;
				periode_complete_effectue = elements_parcouris/L;
			}
			if(early_break)
				continue;
			
			if(elements_parcouris%L == 0)
				periode_complete_reste = X - periode_complete_effectue;
			else
				periode_complete_reste = X - periode_complete_effectue - 1;
			
			if(index == 0){
				product_k = value_uni.power((int) (periode_complete_reste%4));
			}
			else{
				for(int s = index; s < unite.length; s++)
					product_k = product_k.times(unite[s]);
				product_k = product_k.times(value_uni.power((int) (periode_complete_reste%4)));
			}
			
			if(product_k.egal(k))
				writer.write("Case #"+num_case+": YES\n");
			else
				writer.write("Case #"+num_case+": NO\n");
		}
		writer.close();
	}

}
