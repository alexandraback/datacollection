import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;


public class A {
	final static String  in="A-small-attempt2.in";
	final static String  out=in.replace(".in",".out");
	final static boolean stdOut=true;
	public static void main(String[] args)throws Exception{
		if(stdOut)System.setOut(new PrintStream(out));
		BufferedReader br=new BufferedReader(new FileReader(in));
		int T=Integer.parseInt(br.readLine());
		for(int t=0;t<T;t++){
			String[] j=br.readLine().split(" ");
			int A=Integer.parseInt(j[0]),N=Integer.parseInt(j[1]);
			j=br.readLine().split(" ");
			int[] motes=new int[N];
			int[] operations=new int[N];
			for(int e=0;e<N;e++)motes[e]=Integer.parseInt(j[e]);
			Arrays.sort(motes);
			if(A==1)System.out.println("Case #"+(t+1)+": "+N);
			else{
				for(int e=0;e<N;e++){
					while(A<=motes[e]){
						A+=(A-1);
						operations[e]++;
					}
					A+=motes[e];
					if(e>0)operations[e]+=operations[e-1];
				}
				int min=N;
				for(int e=0;e<N;e++)min=Math.min(operations[e]+(N-e-1),min);
				System.out.println("Case #"+(t+1)+": "+min);
			}
		}
		br.close();
		//Scanner sc=new Scanner(new File(in));
	}
}
