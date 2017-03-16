import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;


public class Bullseye {
	public int solve(int r,int t){
		int res=0;
		t=t-(2*r+1);
		while(t>=0){
			res++;
			r+=2;
			t=t-(2*r+1);
		}
		return res;
	}
	
	public static void main(String[] args)throws Exception {
		BufferedReader reader =new BufferedReader(new FileReader("A-small-attempt0.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("out.txt"));
		Bullseye bs=new Bullseye();
		int T=Integer.parseInt(reader.readLine());
		int k=1;
		while(k<=T){
			StringTokenizer st = new StringTokenizer(reader.readLine());
			int r=Integer.parseInt(st.nextToken());
			int t=Integer.parseInt(st.nextToken());
			writer.write("Case #"+k+": "+bs.solve(r, t));
			writer.newLine();
			k++;
		}
		reader.close();
		writer.close();
	}
}
