import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;


public class A {
	private static final String INPUTFILE = "./A.in";
	private static final String OUTPUTFILE = "./A.out";
	private static FileReader in;
	private static FileWriter out;
	private static BufferedReader buffIn;
	private static BufferedWriter buffOut;
	private static Scanner s;

	public static String executeSingle(){
		int N = s.nextInt();
		int[]  scores= new int[N];
		int[] sortedscores;
		
		int X =0,sum=0;
		int min=300,second=1;

		double proba = 0;
		
		String out = "";
		for(int i = 0;i<N;i++){
			scores[i]=s.nextInt();
			X+=scores[i];
		}
		sum = X;
		sortedscores= scores.clone();
		Arrays.sort(sortedscores);
		
		//On recupere la target
		int nextindex = 1;
		int target = sortedscores[0];
		//distribuer les points
		while(nextindex<N){
			if(target == sortedscores[nextindex]){
				nextindex++;
			}
			else if((X-nextindex)>=0){
				X-=nextindex;
				target++;
			}
			else{
				break;
			}
		}
		double restepar = X*1.0/nextindex*1.0;
		for(int i = 0;i<N;i++){
			double resultat;
			if(target-scores[i]>=0){
			resultat = (restepar+target-scores[i])*100/sum;
			}
			else{
				resultat = 0;
			}
			out += resultat+" ";
		}
		return out;
	}


	public static void execute() throws IOException{
		int n = s.nextInt();
		s.nextLine();
		for(int i=1;i<=n;i++){
			buffOut.append("Case #"+i+": "+executeSingle());
			buffOut.newLine();
			//System.out.println("Case #"+i+": "+executeSingle());
		
		}
	}


	public static void main(String[] args) throws IOException {
		in = new FileReader(INPUTFILE);
		out = new FileWriter(OUTPUTFILE);
		buffIn = new BufferedReader(in);
		buffOut = new BufferedWriter(out);
		s = new Scanner(buffIn);
		execute();
		buffOut.flush();
		buffOut.close();
		buffIn.close();
		out.close();
		in.close();
	}

}