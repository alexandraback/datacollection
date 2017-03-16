import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class GCJDsmall {
	
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		//Scanner scan = new Scanner(new File("C-small-practice.in"));
		GCJDsmall main = new GCJDsmall();
		main.answer();
	}
	
	
	public void answer()throws FileNotFoundException, UnsupportedEncodingException{
		Scanner scan = new Scanner(new File("D-small-attempt3.in"));
		//Scanner scan = new Scanner(System.in);
		int cases = Integer.parseInt(scan.nextLine()); 
		PrintWriter writer = new PrintWriter("D4.out", "UTF-8");
		for(int i=1; i<=cases; i++){
			int N=Integer.parseInt(scan.nextLine());
			String[] NaomiS = scan.nextLine().split(" ");
			String[] KenS = scan.nextLine().split(" ");
			double[] Naomi = new double[N];
			double[] Ken = new double[N];
			//System.out.println(N);
			//Ken = false;
			//Naomi=true;
			//ArrayList<Boolean> isNaomi = new ArrayList<Boolean>();
			
			for(int j=0; j<N; j++){
				Naomi[j]=Double.parseDouble(NaomiS[j]);
				Ken[j]=Double.parseDouble(KenS[j]);
			}
			
			
			Arrays.sort(Naomi);
			Arrays.sort(Ken);
		
			/*int nCounter=0;
			int kCounter=0;
			for(int j=0; j<2*N; j++){
				if(nCounter==N){
					isNaomi.add(false);
				}else if(kCounter==N){
					isNaomi.add(true);
				}else if(Naomi[nCounter]>Ken[kCounter]){
					isNaomi.add(false);
					kCounter++;
				}else{
					isNaomi.add(true);
					nCounter++;
				}
			}*/
			
			//Deceitful war
			/*int tooLow=0;
			for(; isNaomi.get(tooLow); tooLow++){}
			int tooHigh=0;
			for(; !isNaomi.get(2*N-tooHigh-1); tooHigh++){}
			int maxDeceitfulWar = N-Math.max(tooLow,tooHigh);*/
			
			int tooLow=0;
			//System.out.println(Naomi.length + " "+Ken.length);
			for(; tooLow<N&&Naomi[tooLow]<Ken[0]; tooLow++){}
			int tooHigh=0;
			for(; tooHigh<N&&Naomi[N-1]<Ken[N-1-tooHigh]; tooHigh++){}
			int maxDeceitfulWar = N-Math.max(tooLow,tooHigh);
			
			//War
			int maxWar =0;
			double kensChoice = 0;
			print(Ken);
			for(int j=0; j<N; j++){
				System.out.println(Naomi[j]);
				kensChoice=kensChoice(Ken, Naomi[j]);				
				if(kensChoice<Naomi[j]){
					maxWar++;
				}
				Ken=removeBlock(Ken, kensChoice);
				print(Ken);
			}
			
			
				
			writer.println("Case #"+i+": "+maxDeceitfulWar+" "+maxWar);	
			System.out.println("Case #"+i+": "+maxDeceitfulWar+" "+maxWar);	
			//System.out.println(N);
			//print(isNaomi);
			
		}
		writer.close();
	}
	
	public void print(ArrayList<Boolean> list){
		for(int i=0; i<list.size(); i++){
			System.out.println(list.get(i));
		}
	}
	
	public double[] removeBlock(double[] blocks, double chosenBlock){
		boolean chosen = false;
		double[] newBlocks = new double[blocks.length-1];
		for(int i=0; i<blocks.length; i++){
			if(blocks[i]==chosenBlock&&!chosen){
				chosen = true;
			}else if(!chosen){
				newBlocks[i]=blocks[i];
			}else{
				newBlocks[i-1]=blocks[i];
			}
		}		
		return newBlocks;
	}
	
	public double kensChoice(double[] kensBlocks, double chosenN){
		for(int i=0; i<kensBlocks.length; i++){
			if(kensBlocks[i]>chosenN){
				return kensBlocks[i];
			}
		}
		return kensBlocks[0];
	}
	
	public void print(double[] A){
		for(int i=0; i<A.length; i++){
			System.out.print(A[i]+"\t");
		}
		System.out.println();
	}
}
