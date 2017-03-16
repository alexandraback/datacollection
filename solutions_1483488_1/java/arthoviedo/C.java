import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class C {
	public static void main(String[] args) throws Exception{
		long tIni=System.currentTimeMillis();
		Scanner s=new Scanner(new File("./data/C.txt"));
		PrintWriter pw=new PrintWriter(new File("./data/C_sol.txt"));
		int ncases=s.nextInt();s.nextLine();
		for(int curr=0;curr<ncases;curr++){
			int ans=0;
			
			int A=s.nextInt(),B=s.nextInt();
			int len=(""+A).length();
			
			for(int j=A;j<B;j++){
					int [] used=new int[len]; int lastUsed=0; Arrays.fill(used, -1);
					int base=10;
					int exp=10;
					for(int i=1;i<len-1;i++)
						exp*=10;
					for(int k=1;k<len;k++){
						
						int r=j%base;
						int div=j/base;
						
						int resp=r*exp+div;
						
						
						if(resp>A && resp<=B && resp>j )
						{
							boolean ok=true;
							for(int i=0;i<len;i++)
								if(resp==used[i])
									ok=false;
							if(ok){
								ans++;
								//System.out.println(j+" "+resp);
								used[lastUsed++]=resp;
							}
						}
						
						base*=10;
						exp/=10;
				}
			}
			
			/**for(int i=A;i<B;i++){
				int [] used=new int[len]; int lastUsed=0; Arrays.fill(used, -1);
				
				String numS=i+"";
				for(int k=1;k<len;k++){
					String o = numS.substring(k)+numS.substring(0,k);
					if(Integer.parseInt(o)>i && Integer.parseInt(o)<=B ){
						boolean ok=true;
						int resp=Integer.parseInt(o);
						for(int j=0;j<len;j++)
							if(resp==used[j])
								ok=false;
						if(ok){
							ans++;
							//System.out.println(j+" "+resp);
							used[lastUsed++]=resp;
						}
					}
				}
			}*/
			
			pw.println("Case #"+(curr+1)+": " +ans);
			System.out.println("+++++++++++++++");
		}
		long tFin=System.currentTimeMillis();
		System.out.println("Time: "+ (tFin-tIni) +" msec");
		pw.close();
		
	}
	
}
