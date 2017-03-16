package war;

import java.io.*;
import java.util.*;

public class War {
	public static void main(String[] args) throws FileNotFoundException, IOException{
		// TODO Auto-generated method stubScanner 
	Scanner sc=new Scanner(new BufferedReader(new InputStreamReader (new FileInputStream("CodeJam2014/war/D-large.in"))));
		//Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter ou=new PrintWriter(new FileWriter("CodeJam2014/war/war.out"));
		ArrayList nao=new ArrayList<Double>();
		ArrayList ken=new ArrayList<Double>();
		int res,rep,i,j,n,po1,po2;
		List na=new ArrayList<Double>();
		List ke=new ArrayList<Double>();
		String out="";
		
		res=sc.nextInt();
		for(rep=1;rep<=res;rep++){
			nao.clear(); ken.clear();
			n=sc.nextInt();
			for(i=1;i<=n;i++) nao.add(sc.nextDouble());
			for(i=1;i<=n;i++) ken.add(sc.nextDouble());
			Collections.sort(nao);
			Collections.sort(ken);
			for(i=0;i<n;i++) na.add(nao.get(i));
			for(i=0;i<n;i++) ke.add(ken.get(i));
/*			for(i=0;i<n;i++) System.out.print(na.get(i)+" ");
			System.out.println();
			for(i=0;i<n;i++) System.out.print(ke.get(i)+" ");
			System.out.println(); */
			
			po1=0;
			for(i=1;i<=n;i++)
				if ((double)nao.get(n-i)<(double)ken.get(n-i)) {
					nao.remove(n-i); ken.remove(n-i);
				}
				else{
					nao.remove(n-i); ken.remove(0);
					po1++;
				}
			//System.out.println(po1);
			//System.out.println(na.size());
			po2=0;
			for(i=1;i<=n;i++)
				if ((double)na.get(0)<(double)ke.get(0)) {
					na.remove(0); ke.remove(n-i);
				}
				else{
					na.remove(0); ke.remove(0);
					po2++;
				}
			//System.out.println(po2);
			out+=out.format("Case #%d: %d %d",rep,po2,po1);
			if (rep!=res) out+="\n";
		}
		System.out.print(out);
		ou.print(out);
		ou.close();
	}
}