import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashSet;


public class RecycledNumbers {
	ArrayList<String> result = new ArrayList<>();
	
	public void solve(int A, int B){
		HashSet<String> distinct = new HashSet<>();
		HashSet<String> testM = new HashSet<>();
		for(int n=A;n<B;n++){
			String nStr = ""+n;
			for(int i=1;i<nStr.length();i++){
				String sub = nStr.substring(nStr.length()-i);
				String base = nStr.substring(0,nStr.length()-i);
				String mStr = sub+base;
				int m = Integer.parseInt(mStr);
				if(m<=B&&m>n){
					distinct.add(nStr+mStr);
				}
			}
		}
		result.add(""+distinct.size());
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
		RecycledNumbers rn = new RecycledNumbers();
		String file = args[0];
		try{
			BufferedReader br = new BufferedReader(new FileReader(new File(file)));
			String line = br.readLine();
			int numRows = Integer.parseInt(line);
			while((line=br.readLine())!=null){
				String[] ss = line.split(" ");
				int A = Integer.parseInt(ss[0]);
				int B = Integer.parseInt(ss[1]);
				rn.solve(A,B);
			}
		}catch (Exception e) {
			System.out.println(e.getMessage());
		}
		rn.saveResults(args[1]);

	}

}
