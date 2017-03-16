import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class C {
	class hand{
		ArrayList<Integer> h;
		hand(ArrayList<Integer> temp){
			h = new ArrayList<Integer>();
			for(Integer t: temp)h.add(t);
		}
		public String toString(){
			return ""+h;
		}
	}
	PrintWriter out;
	BufferedReader f;
	public void run()throws Exception{
		f = new BufferedReader(new FileReader("C-small-2-attempt0.in"));
		//f = new BufferedReader(new FileReader("C.txt"));
	    out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
	    int datasets = Integer.parseInt(f.readLine());
	    for(int x = 0; x<datasets; x++){
	    	out.println("Case #1:");
		   	StringTokenizer a = new StringTokenizer(f.readLine());
	   		int R = Integer.parseInt(a.nextToken()),
	   		N = Integer.parseInt(a.nextToken()),
	   		M = Integer.parseInt(a.nextToken()),
	   		K = Integer.parseInt(a.nextToken());
	   		for(int y = 0; y<R; y++){
	   			int[] subsetprod = new int[K];
	   			a = new StringTokenizer(f.readLine());
	   			for(int z = 0; z<K; z++)subsetprod[z] = Integer.parseInt(a.nextToken());
	   			ArrayList<Integer> cards = new ArrayList<Integer>();
	   			List[] hands = new ArrayList[K];
	   			int ind = 0;
	   			for(Integer b: subsetprod){
	   				hands[ind] = new ArrayList<hand>();
	   				if(b==1){
	   					ind++;
	   					continue;
	   				}
	   				else{
	   					recur(hands[ind],new ArrayList<Integer>(),2,N,M,0,b,1,ind);
	   					
	   				}
	   				ind++;
	   			}
	   			Arrays.sort(hands,new Comparator<List>(){
	   				public int compare(List a, List b){
	   					if(a.size()==b.size()){
	   						int am = 0;
	   						for(hand c: (ArrayList<hand>)a)
	   							if(c.h.size()>am)am = c.h.size();
	   						int bm = 0;
	   						for(hand c: (ArrayList<hand>)b)
	   							if(c.h.size()>bm)bm = c.h.size();
	   						return bm-am;
	   					}
	   					return a.size()-b.size();
	   				}
	   			});
	   			for(List b: hands){
	   				ArrayList<hand> temp = (ArrayList<hand>)b;
	   				Collections.sort(temp,new Comparator<hand>(){
	   					public int compare(hand a, hand b){
	   						return b.h.size()-a.h.size();
	   					}
	   				});
	   				for(hand c: temp){
	   					contain(cards,c);
	   					for(Integer d: c.h){
	   						if(cards.size()<N){
	   							cards.add(d);
	   						}
	   					}
	   				}
	   				//System.out.println(b);
	   			}
	   			for(Integer b: cards){
	   				out.print(b);
	   			}
	   			if(cards.size()<N){
	   				for(int z = cards.size(); z<N; z++)out.print(2);
	   			}
	   			out.println();
	   		}
	    }
	    out.close();
	    System.exit(0);
	}
	void contain(ArrayList<Integer> cards, hand h){
		ArrayList<Integer> curH = h.h;
		for(Integer a: cards){
			if(curH.contains(a))
				curH.remove(curH.indexOf(a));
		}
	}
	void recur(List<hand> hands,ArrayList<Integer> curH, int z,int N, int M, int numC, int sum, int cur, int ind){
		if(numC>N||cur>sum)return;
		if(cur==sum){
			hands.add(new hand(curH));
		}
		for(;z<=M; z++){
			curH.add(z);
			recur(hands,curH,z,N,M,numC+1,sum,cur*z,ind);
			curH.remove(curH.size()-1);
		}
		
	}
    public static void main (String [] args) throws Exception {
		new C().run();
    }
}
