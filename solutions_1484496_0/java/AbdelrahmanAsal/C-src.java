import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;


public class C {
	HashMap<Integer, Integer[]> hm;
	boolean solved;

	void run(){
		try{
		BufferedReader bfd = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(bfd.readLine()), i, arr[], t;
		String sp[];
		for(t=0; t<tc; ++t){
			sp = bfd.readLine().trim().split(" +");
			arr = new int[sp.length-1];
			for(i=1; i<sp.length; ++i)
				arr[i-1] = Integer.parseInt(sp[i]);
			solved = false;
			hm = new HashMap<Integer, Integer[]>();
			System.out.println("Case #"+(t+1)+":");
			genC(arr);
			if(!solved)	System.out.println("Impossible");
		}
		} catch(Exception e){}
	}
	
    public void genC(int[] numbers){
    	int n = numbers.length, sum;
    	Integer[] cache;
	    for(long i = 0; i < (1<<n); i++){
	        ArrayList<Integer> subset = new ArrayList<Integer>();
	        for(int j = 0; j < n; j++){
	            if(((i>>j) & 1) == 1)
	                subset.add(numbers[j]);
	        }
	        sum = 0;
	        for(int nn: subset)
	        	sum += nn;
	        if(hm.containsKey(sum)){
	        	solved = true;
	        	cache = hm.get(sum);
	        	for(int k=0; k<cache.length-1; ++k)
	        		System.out.print(cache[k] + " ");
	        	System.out.println(cache[cache.length-1]);
	        	for(int k=0; k<subset.size()-1; ++k)
	        		System.out.print(subset.get(k) + " ");
	        	System.out.println(subset.get(subset.size()-1));
	        	return;
	        } else {
	        	Integer[] arrr = new Integer[subset.size()];
	        	for(int p =0; p<subset.size(); ++p)
	        		arrr[p] = subset.get(p);
	        	hm.put(sum, arrr);
	        }
	    }
    }
    
	public static void main(String[] args) {
		new C().run();
	}
}
