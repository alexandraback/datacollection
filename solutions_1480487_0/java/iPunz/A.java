import java.util.*;

public class A{
	
	int[] nums;
	double[] values;
	
	public void run(){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		// System.out.println(T);
		for(int i=0; i<T; i++){
			int N = sc.nextInt();
			nums=new int[N];
			values=new double[N];
			
			for(int j=0; j<N; j++){
				nums[j]=sc.nextInt();
				values[j]=-1;
			}
			System.out.print("Case #"+(i+1)+": ");
			execute();
		}
		
		
	}
	
	public void execute(){
		int total=0;
		for(int i=0; i<nums.length; i++){
			total+=nums[i];
		}
		int avg = (total*2)/nums.length;
		int newTotal =total;
		int newCount =0;
		int numOf = 0;
		for(int i=0; i<nums.length; i++){
			if(nums[i]>=avg){
				values[i]=0.0;
				numOf++;
			}
			else{
				newTotal+=nums[i];
				newCount++;
			}
		}
		// System.out.println(newTotal);
		int newAvg = (newTotal)/newCount;
		int extra = newTotal%newCount;
		int each=0;
		if(numOf!=0){
			each = extra/numOf;
		}
		
		for(int i=0; i<nums.length; i++){
			if(values[i]<0){
				values[i]= (100.0*(newAvg-nums[i]))/total;
			}
			else{
				if(numOf!=0)
					values[i]=(100.0*each/total);
			}
		}
		for(int i=0; i<nums.length; i++){
			System.out.printf("%.6f ",values[i]);
		}
		System.out.println();
		
	}
	
	public static void main(String[] args){
		A a = new A();
		a.run();
	}
}