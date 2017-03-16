import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class DancingWithTheGooglers {
	ArrayList<String> result = new ArrayList<>();
	public void solve(int N, int S, int p, int[] ts){
		int max = 0; 
		if(p==0){
			max = ts.length;
			result.add(""+max);
			return;
		}
		//Filter of those how cannot have p based on total score
		ArrayList<Integer> totals = new ArrayList<>();
		for(int i=0;i<ts.length;i++){
			if(ts[i]>=3*p-4&&ts[i]>0){
				totals.add(ts[i]);
			}
		}
		//Count those that must have a score above p without surprise
		ArrayList<Integer> needSurprise = new ArrayList<>();
		for(int i=0;i<totals.size();i++){
			int val = totals.get(i);
			if(val>=3*p-2){
				max++;
			}else{
				needSurprise.add(val);
			}
		}
		if(S>=needSurprise.size()){
			max += needSurprise.size();
		}else{
			max += S;
		}
		result.add(""+max);
	}
	
	public void saveResults(String file){
		try {
			FileWriter fstream = new FileWriter(file);
			BufferedWriter out = new BufferedWriter(fstream);
			int count = 1;
			for(int i=0;i<result.size();i++){
				String s = "Case #" + count++ + ": " + result.get(i) + "\n";
				out.write(s);
			}

			out.close();			
		} catch (Exception e) {
			// TODO: handle exception
		}
	}

	public static void main(String[] args) {
		DancingWithTheGooglers dwtg = new DancingWithTheGooglers();
		String file = args[0];
		try{
			BufferedReader br = new BufferedReader(new FileReader(new File(file)));
			String line = br.readLine();
			int numRows = Integer.parseInt(line);
			while((line=br.readLine())!=null){
				String[] ss = line.split(" ");
				int N = Integer.parseInt(ss[0]);
				int S = Integer.parseInt(ss[1]);
				int p = Integer.parseInt(ss[2]);
				int[] ts = new int[N];
				for(int i=0;i<N;i++){
					ts[i] = Integer.parseInt(ss[3+i]);
				}
				dwtg.solve(N,S,p,ts);
			}
		}catch (Exception e) {
			System.out.println(e.getMessage());
		}
		dwtg.saveResults(args[1]);
	}

}
