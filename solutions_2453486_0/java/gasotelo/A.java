import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.io.PrintWriter;


public class A {
	final static char[] chars={'O','X'};
	public static void main(String[] args)throws Exception{
		System.setOut(new PrintStream("A.out"));
		BufferedReader br=new BufferedReader(new FileReader("A-small-attempt0.in"));
		final int T = Integer.parseInt(br.readLine());
		ciclo:for(int t=0;t<T;t++){
			System.out.print("Case #"+(t+1)+": ");
			char[][] ttt=new char[4][];
			for(int e=0;e<4;e++)ttt[e]=br.readLine().toCharArray();
			char ganador=0;
			t:for(char w:chars)for(int e=0;e<4;e++){
				boolean win=true;
				for(int i=0;i<4;i++)win&=(ttt[e][i]==w||ttt[e][i]=='T');
				if(win){
					ganador=w;
					break t;
				}
				win=true;
				for(int i=0;i<4;i++)win&=(ttt[i][e]==w||ttt[i][e]=='T');
				if(win){
					ganador=w;
					break t;
				}
			}
			if(ganador==0){
				t:for(char w:chars){
					boolean win=true;
					for(int e=0;e<4;e++)win&=(ttt[e][e]==w||ttt[e][e]=='T');
					if(win){
						ganador=w;
						break t;
					}
					win=true;
					for(int e=0;e<4;e++)win&=(ttt[3-e][e]==w||ttt[3-e][e]=='T');
					if(win){
						ganador=w;
						break t;
					}
				}
			}
			if(ganador==0){
				for(int e=0;e<4;e++)for(int i=0;i<4;i++)if(ttt[e][i]=='.'){
					System.out.println("Game has not completed");
					br.readLine();
					continue ciclo;
				}
				System.out.println("Draw");
			}else{
				System.out.print(ganador);
				System.out.println(" won");
			}
			br.readLine();
		}
		br.close();
		System.out.close();
	}
}
