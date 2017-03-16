package round1C2016;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashSet;

public class C {
	
	static class Combi{
		int j,p,s;
		Combi(int j, int p, int s){
			this.j=j;
			this.p=p;
			this.s=s;
		}
	}
	
	static boolean isValid(Combi c, HashSet<Combi> combis, int K){
		int k1=0, k2=0, k3=0;
		for(Combi com:combis){
			if(c.j==com.j&&c.p==com.p&&c.s==com.s)
				return false;
			if(c.j==com.j&&c.p==com.p)
				k1++;
			if(c.s==com.s&&c.p==com.p)
				k2++;
			if(c.j==com.j&&c.s==com.s)
				k3++;
			if(k1>K-1||k2>K-1||k3>K-1)
				return false;
		}
		return true;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt1.in"));
        PrintWriter pw = new PrintWriter(new File("C-small.out"));
//        BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
//        PrintWriter pw = new PrintWriter(new File("C-large.out"));
        int T = Integer.parseInt(br.readLine());
        for(int i=1;i<=T;i++){
        	String[] l = br.readLine().split(" ");
        	int J = Integer.parseInt(l[0]);
        	int P = Integer.parseInt(l[1]);
        	int S = Integer.parseInt(l[2]);
        	int K = Integer.parseInt(l[3]);
        	HashSet<Combi> combisG = new HashSet<C.Combi>();
        	for(int t=0;t<10;t++){
        		HashSet<Combi> combis = new HashSet<C.Combi>();
	        	for(int c=0;c<10000;c++){
	        		int j = (int)(Math.random()*J)+1;
	        		int p = (int)(Math.random()*P)+1;
	        		int s = (int)(Math.random()*S)+1;
	        		Combi com = new Combi(j,p,s);
	        		if(isValid(com, combis, K))
	        			combis.add(com);
	        	}
	        	if(combis.size()>combisG.size())
	        		combisG = combis;
        	}
        	pw.println("Case #"+i+": "+combisG.size());
        	for(Combi com:combisG)
        		pw.println(com.j+" "+com.p+" "+com.s);
        }
        pw.close();
        br.close();
	}
}
