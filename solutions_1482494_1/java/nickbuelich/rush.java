import java.util.*;
import java.io.*;
public class rush {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("rush.in"));
		PrintWriter out = new PrintWriter("rush.out");
		int C = sc.nextInt();
		for(int i=1;i<=C;i++){
			int N = sc.nextInt();
			thing[] array = new thing[N];
			for(int a=0;a<N;a++){
				array[a]=new thing(sc.nextInt(), sc.nextInt());
			}
			//Arrays.sort(array);

			int have = 0;
			int games = 0;
			loop: while(true){
				

			for(int a=0;a<N;a++){
				
				if(array[a].second<=have&&!array[a].s){
					games++;
					array[a].s=true;
					if(!array[a].f){
						array[a].f=true;
						have++;
					}
					have++;
					continue loop;
				}
				else{
					
				}
				
			}
			int diff = -1;
			int take = -1;
			for(int a=0;a<N;a++){
				if(array[a].first<=have&&!array[a].f){
					if(diff<array[a].second-array[a].first){
						diff=array[a].second-array[a].first;
						take = a;
					}
					
					
				}
			
			
			}
			if(take==-1)break;
			else{
				array[take].f=true;
				have++;
				games++;
			}
			
		}
			out.print("Case #"+i+": ");
			if(have==N<<1){
				out.println(games);
			}
			else out.println("Too Bad");
			
			


	}
		out.close();
}
}
class thing implements Comparable<thing>{
	int first;
	boolean f;
	boolean s;
	int second;
	thing(int a,int b){
		this.first=a;
		this.second=b;
		this.f=false;
		this.s=false;
	}
	@Override
	public int compareTo(thing o) {
		if(this.second==o.second){
			return (this.second-this.first)-(o.second-o.first);
		}
		return this.second-o.second;
		
	
	}
	
}

