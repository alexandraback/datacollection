import java.util.*;

class B{

	static long mod = 1000000007;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int kases = sc.nextInt();
		sc.nextLine();
		for(int k = 1; k<=kases; k++){
			int cars = sc.nextInt();
			sc.nextLine();
			int[][] aM = new int[cars][cars];
			String[] carstr = sc.nextLine().split("\\s");
			HashMap<Character,Integer> count = new HashMap();
			HashMap<Character,Character> prev = new HashMap();
			HashMap<Character,Character> next = new HashMap();
			HashSet<Character> in  = new HashSet();
			HashSet<Character> starts = new HashSet();
			HashSet<Character> ends = new HashSet();
			boolean FAIL = false; 
			for(int i = 0; i<cars; i++){
				String car = carstr[i];
				char pr = car.charAt(0);
				if (starts.contains(pr)) FAIL = true;
				starts.add(pr);
				boolean same = true;
				for(int j = 1; j<car.length();j++){
					in.add(pr);
					if(car.charAt(j)!=pr){
						same = false;
						if(prev.containsKey(car.charAt(j))) FAIL = true;
						else if(next.containsKey(pr)) FAIL = true;
						else{prev.put(car.charAt(j),pr); next.put(pr,car.charAt(j));}
						pr = car.charAt(j);
					}
				}
				if(ends.contains(pr)&&!same) FAIL = true;
				ends.add(pr);
				if(same){count.put(pr,(!count.containsKey(pr)?1:count.get(pr)+1));
					starts.remove(pr);
				}
			}
			long ans = 0;
			if(!FAIL){
				int paths = 0;
				long mult= 1;
				for(char c: in){
					if(!prev.containsKey(c)) paths++;
					if(count.containsKey(c)) mult = (mult * fac(count.get(c)))%mod;
				}
				ans = (fac(paths)*mult)%mod;
			}
			System.out.println("Case #"+k+": "+ans);
		}
	}

	public static long fac(int p){
		long a = 1;
		for(long i = 1; i<=p; i++) a=(a*i)%mod;
		return a;
	}

}
