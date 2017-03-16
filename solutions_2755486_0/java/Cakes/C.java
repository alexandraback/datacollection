import java.io.*;
import java.awt.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class C {
	class tribe implements Comparable<tribe>{
		int di,ni,wi,ei,si,deldi,delpi,delsi;
		int pdi, pni, pwi, pei, psi;
		boolean attack(TreeMap<Integer,Integer> wall){
			boolean yes = false;
			for(int w = wi*2; w<=ei*2; w++){
				if(wall.get(w)==null||wall.get(w)<si){
					yes = true;
					break;
				}
			}
			psi = si;
			pwi = wi;
			pei = ei;
			di+=deldi;
			ni--;
			wi+=delpi;
			ei+=delpi;
			si+=delsi;
			return yes;
		}
		void raise(TreeMap<Integer,Integer> wall){
			for(int w = pwi*2; w<=pei*2; w++){
				if(wall.get(w)==null||wall.get(w)<psi){
					wall.put(w,psi);
				}
			}
		}
		tribe(String a){
			StringTokenizer b = new StringTokenizer(a);
			di = Integer.parseInt(b.nextToken());
			ni = Integer.parseInt(b.nextToken());
			wi = Integer.parseInt(b.nextToken());
			ei = Integer.parseInt(b.nextToken());
			si = Integer.parseInt(b.nextToken());
			deldi = Integer.parseInt(b.nextToken());
			delpi = Integer.parseInt(b.nextToken());
			delsi = Integer.parseInt(b.nextToken());
		}
		public int compareTo(tribe a){
			return di-a.di;
		}
	}
	PrintWriter out;
	BufferedReader f;

	public void run()throws Exception{
		f = new BufferedReader(new FileReader("C-small-attempt0.in"));
	    out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
	    int datasets = Integer.parseInt(f.readLine());
	    for(int x = 0; x<datasets; x++){
	    	out.print("Case #"+(x+1)+": "); 
	    	System.out.print("Case #"+(x+1)+": "); 
	    	int N = Integer.parseInt(f.readLine());
	    	PriorityQueue<tribe> order = new PriorityQueue<tribe>();
	   		for(int y =0; y<N; y++){
	   			order.add(new tribe(f.readLine()));
	   		}
	   		TreeMap<Integer,Integer> wall = new TreeMap<Integer,Integer>();
	   		int suc = 0;
	   		int hi = 0;
	   		while(!order.isEmpty()){
	   			hi = 0;
	   			tribe cur = order.remove();
	   			if(cur.attack(wall))suc++;

	   			if(!order.isEmpty()){
	   				ArrayList<tribe> temptri = new ArrayList<tribe>();
	   				while(!order.isEmpty()&&order.peek().di==cur.di-cur.deldi){
	   					tribe temp = order.remove();
	   					if(temp.attack(wall))suc++;

	   					temptri.add(temp);
	   				}
	   				for(tribe lol: temptri){
	   					lol.raise(wall);
	   					if(lol.ni>0)order.add(lol);
	   				}
	   				temptri.clear();
	   			}
   				cur.raise(wall);
   				if(cur.ni>0)order.add(cur);
	   		}
	   		System.out.println(suc);
	   		out.println(suc);
	    }
	    out.close();
	    System.exit(0);
	}

    public static void main (String [] args) throws Exception {
		new C().run();
    }
}
