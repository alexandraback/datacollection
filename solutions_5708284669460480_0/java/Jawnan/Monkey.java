import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;


public class Monkey {
	private static int total=0;
	private static int count=0;
	private static int max=0;
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
		String[] line = br.readLine().split(" ");
		int K = Integer.parseInt(line[0]);
		int L = Integer.parseInt(line[1]);
		int S = Integer.parseInt(line[2]);
		String keyboard = br.readLine();
		String target = br.readLine();
		total=0;
		count=0;
		max=0;
		doit(K,L,S, keyboard, target);
		double avg=1.0*count/total;
		double result=1.0*max-avg;
		bw.write("Case #"+(t+1)+": "+result);
		bw.newLine();
	}
	
	private static void doit(int K, int L, int S, String keyboard, String target){
		int index[]= new int[S];
		for(int s=0; s<S; s++)index[s]=0;
		while(true){
			String word="";
			for(int s=0; s<S; s++){
				word+=keyboard.charAt(index[s]);
			}
			int c=0;
			for(int i=0; i<S-L+1; i++){
				boolean check=true;
				for(int j=0; j<L; j++){
					if(target.charAt(j)!=word.charAt(j+i))check=false;
				}
				if(check)c++;
			}
			count+=c;
			if(c>max)max=c;
			total++;
			index[S-1]++;
			for(int i=S-1;i>=0;i--){
				if(i==0){
					if(index[i]==K)return;
				}
				else{
					if(index[i]==K){
						index[i-1]++;
						index[i]=0;
					}
				}
			}
		}
	}

}
