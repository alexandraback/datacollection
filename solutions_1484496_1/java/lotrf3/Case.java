package equalSums.codejam;

import java.util.*;
import java.util.Map.Entry;

public class Case {
	class Pair{
		String x;
		long sum;
		public Pair(String a, long b){
			x = a;
			sum = b;
		}
	}
	int N;
	long[] S;
	//HashSet<Pair> S;
	List<HashMap<Long,Long[]>> map;
	HashMap<Long,Long[]> map2; 
	public Case(Scanner s){
		N = s.nextInt();
		//S = new HashSet<Pair>(N*3);
		S = new long[N];
		map = new ArrayList<HashMap<Long,Long[]>>();
		map.add(new HashMap<Long,Long[]>(N));
		map2 = new HashMap<Long,Long[]>(N*4);
		for(int i=0; i<N; i++){
			Long x = s.nextLong();
			S[i] = x;
			Long[] temp = new Long[1];
			temp[0] = x;
			map.get(0).put(x, temp);
			map2.put(x,temp);
		}

	}
	
	public String solve(){
		for(int i=2; i<N/2; i++){
			map.add(new HashMap<Long,Long[]>(N));
			Iterator<Entry<Long, Long[]>> it = map.get(i-2).entrySet().iterator();
			while(it.hasNext()){
				Entry<Long, Long[]> x = it.next();
				for(int j=0; j<N; j++){
					Long[] y= Arrays.copyOf(x.getValue(), x.getValue().length+1);
					boolean flag = false;
					for(int k=0;k<y.length-1;k++){
						if(y[k]==S[j]){
							flag = true;
							break;
						}
					}
					if(flag)
						break;
					y[y.length-1] = S[j];
					long z = x.getKey() + S[j];
					map.get(i-1).put(z, y);
					Long[] q = map2.put(z, y);					
					if(q != null){
						String str = "";
						for(int k=0; k<q.length; k++){
							str += q[k] + " ";
						}
						str += "\n";
						for(int l=0; l<y.length; l++){
							str += y[l] + " ";
						}
						return str;
					}
					
				}
			}
		}
		return "Impossible";
	}
}
