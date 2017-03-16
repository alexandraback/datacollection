package codejam2016;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;

import tools.Tools;

public class BFFs {
	int N;
	kid[] kids;
	public static void main(String[] args) throws IOException {
		BFFs t = new BFFs();
		t.solve();
	}
	public void solve() throws IOException{
		String inputFile = Tools.chooseFile();
		long startTime = System.currentTimeMillis();
		String outputFile = Tools.getOutputName(inputFile);
		BufferedReader in = new BufferedReader(new FileReader(inputFile));
		PrintWriter out = new PrintWriter(outputFile);
		int T = Integer.parseInt(in.readLine());//first line
		for(int caseN=1; caseN<=T;caseN++){
			N = Integer.parseInt(in.readLine());
			kids = new kid[N+1];
			for(int i=1;i<=N;i++){
				kids[i] = new kid(i);
			}
			int[] F = Tools.intArray(in.readLine(), " ");
			for(int i=1;i<=N;i++){
				int Fi = F[i-1];
				kids[i].bff = Fi;
				kids[Fi].bffed.add(i);
			}
			
			String output = "Case #"+caseN + ": "+Math.max(countClosed(), countPair());
			System.out.println(output);
			out.println(output);
		}
		in.close();
		out.close();
		long timeUsed = System.currentTimeMillis()-startTime;
		Tools.println("total execution time is "+timeUsed);
	}
	int countClosed(){
		int count = 0;
		boolean[] choosen = new boolean[N+1];
		for(int i=1;i<=N;i++){
			if(choosen[i])
				continue;
			LinkedList<kid> ki = new LinkedList<kid>();
			ki.add(kids[i]);
			choosen[i] = true;
			kid kilast = ki.getLast();
			while(!ki.contains(kids[kilast.bff])){
				 kilast = kids[kilast.bff];
			     ki.add(kilast);
			     choosen[kilast.id] = true;
			}
			kid bfoflast = kids[kilast.bff];
			
			for(int j=0;j<ki.size();j++){
				if(ki.get(j)==bfoflast){
					int counti = ki.size() - j ;
					if(counti > count)
						count = counti;
					break;
				}
			}
		}
		return count;
	}
	int countPair(){
		int count = 0;
		LinkedList<int[]> pairs = new LinkedList<int[]>();
		boolean[] choosen = new boolean[N+1];
		for(int i=1;i<=N;i++){
			if(choosen[i])
				continue;
			kid kidi = kids[i];
			choosen[i] = true;
		    kid ibf = kids[kidi.bff];
		    if(ibf.bff == i){
		    	pairs.add(new int[]{kidi.id,kidi.bff});
		    	choosen[kidi.bff]= true; 
		    }
		}
		//Tools.println(pairs.size());
		for(int[] ab:pairs){
			kid a = kids[ab[0]];
			kid b = kids[ab[1]];
			count += getMaxCount(a,b);
			count += getMaxCount(b,a);
			count += 2;
		}
		
		return count;
	}
	int getMaxCount(kid A, kid B){
		int max = 0;
		for(int i:A.bffed){
			if(i==B.id)
				continue;
			kid kidi = kids[i];
			int ci = getMaxCount(kidi,A);
			if(max < ci+1)
				max = ci+1;
		}
		return max;
	}
}
class kid{
	int id;
	int bff;
	kid(int id1){
		id = id1;
	}
	LinkedList<Integer> bffed = new LinkedList<Integer>();
}
