import java.util.*;
import java.io.*;
public class B {
	
	int[][] ctable;

	/**************************************/
	void run(String inputfile){
	try{
		Scanner s;
		File file=new File("output.txt");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
		if(inputfile.equals("test")) s=new Scanner(System.in);
		else s=new Scanner(new FileInputStream(new File(inputfile)));
		int cases=s.nextInt();
		for(int X=0;X<cases;X++){
			pw.print("Case #"+(X+1)+": ");
			/**************************************/
			int n=s.nextInt();
			int x=s.nextInt();
			int y=s.nextInt();
			int count=1;
			int completestep=-1;
			while(n-count>=0){
				n-=count;
				completestep++;
				count+=4;
			}
			if(Math.abs(x)+y<=2*completestep) pw.println(1.0);
			else if(Math.abs(x)+y>2*(completestep+1)) pw.println(0.0);
			else{
				int dp=y+1;
				completestep++;
				ctable=new int[4*completestep+1][4*completestep+1];
				ctable[0][0]=1;
				for(int i=1;i<ctable.length;i++){
					ctable[i][0]=1;
					for(int j=1;j<i;j++){
						ctable[i][j]=ctable[i-1][j-1]+ctable[i-1][j];
					}
					ctable[i][i]=1;
				}
				double ret=0.0;
				for(int i=Math.max(dp,n-2*completestep);i<=2*completestep&&i<=n;i++){
					ret+=calcp(2*completestep,i,n-i);
				}
				pw.println(ret);
			}
			
			
			/**************************************/
		}
		pw.close();
	}catch(IOException e){
		System.out.println(e);
		System.exit(0);
	}}
	/**************************************/
	
	double calcp(int lim,int tg,int opp){
		System.out.println("for "+lim+" "+tg+" "+opp);
		double ret=0.0;
		if(lim==tg&&lim==opp) ret=1.0;
		else if(lim!=tg&&lim!=opp) ret=Math.pow(0.5,tg+opp)*ctable[tg+opp][tg];
		else{
			int count=0;
			for(int i=tg+opp;i>=lim;i--){
				count+=ctable[i][lim];
				System.out.println(count);
			}
			ret=Math.pow(0.5,tg+opp)*count;
		}
		System.out.println(ret);
		return ret;
	}
	
	
	public static void main(String[] args){
		
		new B().run(args[0]);
	}
}
