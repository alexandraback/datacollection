import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class R1_ProblemB {

	public static String name="problemB";
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader(name+".txt"));
		PrintWriter printer=new PrintWriter(name+"_out.txt");
		int N=Integer.parseInt(buf.readLine());

		for(int i=1;i<=N;i++){
			printer.print("Case #"+i+": ");
			String[] str=buf.readLine().split(" ");
			long E=Integer.parseInt(str[0]);
			long ec=E;
			long R=Integer.parseInt(str[1]);
			int n=Integer.parseInt(str[2]);
			long[] ints=new long[n];
			str=buf.readLine().split(" ");
			for(int j=0;j<n;j++)
				ints[j]=Integer.parseInt(str[j]);
			int at=0;
			long score=0;
			while(at!=n){
				int add=1;
				while(add+at!=n&&ints[add+at]<ints[at])
					add++;
				if(add+at==n){
					//System.out.println("&"+ec);
					score+=ints[at]*ec;
					ec=0;
				}else if(ec+R*add>E)
				{
				//	if((E-ec)/R>add){
				//		System.out.println("!"+(ec+add*R-E));
				//		score+=ints[at]*(ec+add*R-E);
				//		ec-=ec+add*R-E;
				//	}else{
						long p=Math.max(0, (ec+R*add)-E);
						
						p=Math.min(E, p);
					//	System.out.println("^"+(p));
						score+=ints[at]*(p);
						ec-=p;
				//	}
				}else{

				}
				//System.out.println(i+"end:"+ec);
				ec+=R;
				//System.out.println(i+"max:"+ec+":"+E);
				at++;
			}
			printer.println(score);
		}
		printer.close();
	}


}
