import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;


public class R1_ProblemB {

	public static String name="problemB";
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader(name+".txt"));
		PrintWriter printer=new PrintWriter(name+"_out.txt");
		int numTrial=Integer.parseInt(buf.readLine());
		for(int i=1;i<=numTrial;i++){
			printer.print("Case #"+i+": ");
			String[] s=buf.readLine().split(" ");
			int N=Integer.parseInt(s[0]);
			int X=Math.abs(Integer.parseInt(s[1]));
			int Y=Integer.parseInt(s[2]);
			int p=1;
			if(X+Y>1000000||Y<0)
			{
				printer.println("0.0");
				continue;
			}
			while(p*(2*p-1)<=N)p++;
			p--;
			if((X+Y)%2==1){
				printer.println("0.0");
				continue;
			}
			if(X+Y<=2*p-2){
				System.out.println(i+":"+p*(2*p-1)+","+p);
				printer.println("1.0");
				continue;
			}
			if(X+Y>2*p){
				printer.println("0.0");
				continue;
			}
			if(X==0){
				printer.println("0.0");
				continue;
			}
			//last row.
			//need Y drops on side of choice so
			int drops=N-p*(2*p-1);
			if(drops-2*p<=0){
				BigInteger prob=BigInteger.ZERO;
				for(int j=Y+1;j<=drops;j++)
					prob=prob.add(choose(drops,j));
				System.out.println(i+":"+prob.longValue());
				prob=prob.multiply(BigInteger.valueOf(10000000));
				BigInteger pr=BigInteger.valueOf(2).pow(drops);
				System.out.println(i+":"+pr.toString());
				System.out.println(drops);
				BigDecimal bd=new BigDecimal(prob).divideToIntegralValue(new BigDecimal(pr));
				printer.println(bd.doubleValue()/10000000);
			}else{
				if(drops-Y-2*p>0)
					printer.println("1.0");
				else
					printer.println("0.5");
			}
			//(drops choose Y)
		}
		printer.close();
	}
	public static BigInteger[][] c = new BigInteger[3000][3000];
	public static BigInteger choose(int a,int b){
		if (a == 0 && b > 0) {
			return BigInteger.ZERO;
		} else if (b == 0 && a >= 0) {
			return BigInteger.ONE;
		}
		if (c[a][b] != null) {
			return c[a][b];
		} else {
			c[a][b] = choose(a-1, b-1).add(choose(a-1, b));
		}
		return c[a][b];
	}
}
