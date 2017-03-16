import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


class pairs implements Comparable<pairs>{
	String a;
	String b;
	
	public pairs(String c, String j){
		this.a = c;
		this.b = j;
	}
	
	public int compareTo(pairs other){
		if (Integer.valueOf(this.a) != Integer.valueOf(other.a) )
			return Integer.valueOf(other.a) - Integer.valueOf(this.a);
		else{
			if (Integer.valueOf(this.b) != Integer.valueOf(other.b) )
				return Integer.valueOf(other.b) - Integer.valueOf(this.b);
			else
				return -1;
		}
	}
}

public class round1_2 {

	public static void main(String[] args) throws IOException {
		String filename = "D:/B-small-attempt1.in";
		FileReader fr = new FileReader(filename);
		BufferedReader br =  new BufferedReader(fr);
		
		FileWriter fw = new FileWriter("D:/output.txt");
		BufferedWriter bw = new BufferedWriter(fw);
		
		String line;
		String inputs[] = new String[300];
		int N = 0;
		while ( (line = br.readLine()) != null){
			inputs[N] = line;
			System.out.println(inputs[N]);
			N++;
		}
		int T = Integer.valueOf(inputs[0]);
		
		for (int i=1; i<N; i++){
			String scores[] = inputs[i].split(" ");
			
			ArrayList<String> list_a = new ArrayList<String>();
			ArrayList<String> list_b = new ArrayList<String>();
			
			SetSocres(list_a, scores[0]);
			SetSocres(list_b, scores[1]);
			
			int difference = Integer.MAX_VALUE;
			for (int j=0; j<list_a.size(); j++){
				for (int k=0; k<list_b.size(); k++){
					difference = Math.min(difference, Math.abs(Integer.valueOf(list_a.get(j)) - 
															   Integer.valueOf(list_b.get(k))) );
				}
			}
			
			ArrayList<pairs> pair = new ArrayList<pairs>();
			for (int j=0; j<list_a.size(); j++){
				for (int k=0; k<list_b.size(); k++){
					if (Math.abs(Integer.valueOf(list_a.get(j)) - Integer.valueOf(list_b.get(k))) == difference){
						pairs obj = new pairs(list_a.get(j), list_b.get(k));
						pair.add(obj);
					}
						
				}
			}
			
			bw.write("Case #"+i+": ");
			bw.write(pair.get(0).a+" "+pair.get(0).b+"\n");
			/*
			for (int j=0; j<pair.size(); j++)
				System.out.println(pair.get(j).a +" "+pair.get(j).b);
			*/
		}
		bw.flush();
	}

	private static void SetSocres(ArrayList<String> list_a, String score) {
		int flag = 1;
		for (int i=0; i<score.length(); i++){
			if (score.charAt(i) == '?'){
				flag = 0;
				char temp[] = score.toCharArray();
				for (int j=0; j<=9; j++){
					temp[i] = (char)('0'+j);
					String newscore = String.valueOf(temp);
					SetSocres(list_a, newscore);
					
				}
			}
			
		}
		if (flag == 1)
			list_a.add(score);
		
	}

}
