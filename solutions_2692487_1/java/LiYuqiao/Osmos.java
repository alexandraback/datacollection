import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Osmos {
	public int solve(long A, int[] Others) {
		int res = Others.length;
		Arrays.sort(Others);
		int i = 0;
		int ins = 0;
		if(1==A)return Others.length;
		while (true) {
			if (i >= Others.length) {
				return res;
			}
			while (A <= Others[i]) {
				A += (A - 1);
				ins++;
			}
			while (i < Others.length && A > Others[i]) {
				A += Others[i];
				i++;
			}
			if (ins + Others.length - i < res) {
				res = ins + Others.length - i;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("A-large.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("out.txt"));
		int T=Integer.parseInt(reader.readLine());
		int k=1;
		Osmos os=new Osmos();
		StringTokenizer st;
		while(k<=T){
			st=new StringTokenizer(reader.readLine());
			int A=Integer.parseInt(st.nextToken());
			int N=Integer.parseInt(st.nextToken());
			int []Others=new int[N];
			st=new StringTokenizer(reader.readLine());
			for(int i=0;i<N;i++){
				Others[i]=Integer.parseInt(st.nextToken());
			}
			writer.write("Case #"+k+": "+os.solve(A, Others));
			writer.newLine();
			k++;
		}
		reader.close();
		writer.close();
	}
}
