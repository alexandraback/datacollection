import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class C {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("C:/Users/Nejc/Desktop/input.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File("C:/Users/Nejc/Desktop/output.txt")));
		int T=Integer.parseInt(br.readLine());
		for(int t=0; t<T; t++){
			solve(br,bw,t);
		}
		br.close();
		bw.close();
		System.out.println("done");
	}
	
	private static void solve(BufferedReader br, BufferedWriter bw, int t) throws Exception{
		int result =0;
		String[]line=br.readLine().split(" ");
		int C=1;
		int D=Integer.parseInt(line[1]);
		int V=Integer.parseInt(line[2]);
		line=br.readLine().split(" ");
		ArrayList<Integer> den = new ArrayList<Integer>();
		for(int d=0; d<D; d++){
			den.add(Integer.parseInt(line[d]));
		}
		for(int i=1; i<=V; i++){
			ArrayList<Integer> possible = possible(den);
			if(!possible.contains(i)){
				den.add(i);
				result++;
			}
		}
		bw.write("Case #"+(t+1)+": "+result);
		bw.newLine();
	}
	
	private static ArrayList<Integer> possible(ArrayList<Integer> den){
		ArrayList<Integer> result = new ArrayList<Integer>();
		for(int i=1; i<=den.size();i++){
			ArrayList<Integer> combs = combs(den, i);
			for(int j=0; j<combs.size();j++){
				if(!result.contains(combs.get(j)))result.add(combs.get(j));
			}
		}
		return result;
	}
	
	private static ArrayList<Integer> combs(ArrayList<Integer> den, int multis){
		int index[] = new int[multis];
		ArrayList<Integer> result= new ArrayList<Integer>();
		for(int i=0; i<multis; i++){
			index[i]=i;
		}
		while(true){
			int sum=0;
			for(int i=0; i<multis; i++)sum+=den.get(index[i]);
			result.add(sum);
			index[multis-1]++;
			int size=den.size();
			for(int i=multis-1;i>=0;i--){
				if(i==0){
					if(index[i]>size-(multis-i))return result;
				}
				else{
					if(index[i]>size-(multis-i)){
						index[i-1]++;
						for(int j=i; j<multis; j++)
						index[j]=index[j-1]+1;
					}
				}
			}
		}
	}
}
