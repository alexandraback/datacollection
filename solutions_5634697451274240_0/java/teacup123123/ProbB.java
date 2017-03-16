package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class ProbB extends Prob{

	public static void main(String[] args) {
		ProbB pb= new ProbB();
		pb.fromFile("C:\\Users\\user\\Downloads\\B-small-attempt0(1).in");
	}

	@Override
	public void load(BufferedReader br,BufferedWriter bw) {
		try{
			int T=Integer.parseInt(br.readLine());
			for(int i=0;i<T;i++)
			{
				int bitswaps=0,j;
				String line=br.readLine();
				for(j=0;j<line.length()-1;j++)
					bitswaps+=(line.charAt(j+1)!=line.charAt(j))?1:0;
				bitswaps+=(line.charAt(j)=='-')?1:0;
				String str="INSOMNIA";
				bw.write("Case #"+(i+1)+": "+bitswaps);
				bw.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
