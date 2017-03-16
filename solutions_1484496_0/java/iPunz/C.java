import java.util.*;

public class C{
	
	ArrayList<Long> items = new ArrayList<Long>();
	HashMap<Long, ArrayList<Long>> subSetSums = new HashMap<Long, ArrayList<Long>>();
	
	public void run(){
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		boolean found=false;
		for(int n=0; n<T; n++){
			found=false;
			System.out.println("Case #"+(n+1)+":");
			items=new ArrayList<Long>();
		 	subSetSums = new HashMap<Long, ArrayList<Long>>();
			int N = sc.nextInt();
			// System.out.println(N);
			for(int j=0; j<N; j++){
				long x = sc.nextLong();
				items.add(x);
				// System.out.println(x);
			}
		
		
		int max=1<<items.size();
		for(int i=0; i<max; i++){
			ArrayList<Long> subset = new ArrayList<Long>();
			int k=i;
			int index=0;
			while(k>0){
				if((k&1)>0){
					subset.add(items.get(index));
				}
				k>>=1;
				index++;
			}
			if(subSetSums.containsKey(subSetSum(subset))){
				ArrayList<Long> set1 = subSetSums.get(subSetSum(subset));
				if(!equalSet(set1, subset)){
					for(int j=0; j<set1.size(); j++){
						System.out.print(set1.get(j)+" ");
					}
					System.out.println();
				for(int j=0; j<subset.size(); j++){
					System.out.print(subset.get(j)+" ");
				}
				System.out.println();
				found=true;
					break;
				}	
			}
			else{
				subSetSums.put(subSetSum(subset), subset);
			}
			}
		}
		if(found==false)
			System.out.println("Impossible");
		
	}
	
	private boolean equalSet(ArrayList<Long> set1, ArrayList<Long> set2){
		if(set1.size() != set2.size())
			return false;
		for(int i=0; i<set1.size(); i++){
			if(set1.get(i)!=set2.get(i))
				return false;
		}
		return true;
	}
	private long subSetSum(ArrayList<Long> set){
		long sum=0;
		for(int i=0; i<set.size(); i++){
			sum+=set.get(i);
		}
		return sum;
	}
	
	public static void main(String[] args){
	 	C c= new C();
		c.run();
	}
}