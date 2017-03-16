import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class B {
	final static String  in="B-small-attempt2 (1).in";
	final static String  out=in.replace(".in",".out");
	final static boolean stdOut=true;
	public static void main(String[] args)throws Exception{
		if(stdOut)System.setOut(new PrintStream(out));
		BufferedReader br=new BufferedReader(new FileReader(in));
		//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		final int T=Integer.parseInt(br.readLine());
		for(int t=1;t<=T;t++){
			System.out.print("Case #"+t+": ");
			String[]j=br.readLine().split(" ");
			int N=Integer.parseInt(j[0]);int x=Math.abs(Integer.parseInt(j[1])),y=Integer.parseInt(j[2]);
			int necesarias=calcPiramideCompleta(x+y);
			if(x==0){
				necesarias+=2*y;
				if(N<=necesarias)System.out.println(0.0);
				else System.out.println(1.0);
			}else{
				//System.out.println("x:"+x+" y:"+y+" n:"+necesarias+" N:"+N);
				if(N<necesarias+y+1)System.out.println(0.0);
				else if(necesarias+y+(x+y)<N){
					//System.out.println(necesarias+" "+(necesarias+y+(x+y)));
					System.out.println(1.0);
				}else{
//					System.out.println("no se");
//					System.out.println((N-necesarias)+" "+y);
					double resp=0.0;
					for(int r=y+1;r<=N-necesarias;r++){
						double i=combinatoria(N-necesarias,r);
//						System.out.println((N-necesarias)+"/"+r+" "+i);
						resp+=i;
					}
					System.out.println(resp/Math.pow(2,N-necesarias));
					///System.out.println(combinatoria(N-necesarias,y+1)/Math.pow(2,N-necesarias));
					
				}
			}
			
		}
		br.close();
		//Scanner sc=new Scanner(new File(in));
	}
	static int calcPiramideCompleta(int x){
		return ((x-1)*x)/2;
	}
	static double combinatoria(int N,int r){
		return fact(N)/((fact(N-r))*fact(r));
	}
	static double fact(int N){
		double r=1;
		for(int e=2;e<=N;e++)r*=e;
		return r;
	}
}
