import java.util.*;

public class C{
	long[] boxNum;
	int[] boxType;
	long[] toyNum;
	int[] toyType;
	int[] boxes;
	int[] toys;
	int N;
	int M;
	public void run(){
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int n=0; n<T; n++){
			System.out.print("Case #"+(n+1)+": ");
			N = sc.nextInt();
			M = sc.nextInt();
			boxNum = new long[N];
			boxType = new int[N];
			toyNum = new long[M];
			toyType = new int[M];
			for(int j=0; j<N; j++){
				boxNum[j]= sc.nextLong();
				boxType[j]=sc.nextInt();
			}
			for(int j=0; j<M; j++){
				toyNum[j]= sc.nextLong();
				toyType[j]=sc.nextInt();
			}
			//execute();
			System.out.println(count(boxNum, 0, toyNum, 0));
		}
	}
	
	
	public long count(long[] boxNum, int boxI, long[] toyNum, int toyI){
		// printArray(boxNum);
		// printArray(toyNum);
		//throw box
		long throwBox=0;
		long throwToy=0;
		long throwBoth=0;
		if(boxI!=N && toyI!=M && boxType[boxI]!=toyType[toyI]){
			long[] newBoxNum = copyArray(boxNum);
			newBoxNum[boxI]=0;
			int newBoxI = boxI;
			if(newBoxNum[newBoxI]==0){
				newBoxI++;
			}
			throwBox=count(newBoxNum, newBoxI, toyNum, toyI);
			
		}
		//throw toy
		if(toyI!=M && boxI!=N && boxType[boxI]!=toyType[toyI]){
			long[] newToyNum = copyArray(toyNum);
			int newToyI=toyI;
			newToyNum[newToyI]=0;
			if(newToyNum[newToyI]==0){
				newToyI++;
			}
			throwToy=count(boxNum, boxI, newToyNum, newToyI);
		}
		//if same type use and throw both increment count
		if(boxI!=N && toyI != M){
			if(boxType[boxI]==toyType[toyI]){
				long min = min(boxNum[boxI], toyNum[toyI]);
			long[] newBoxNum = copyArray(boxNum);
			newBoxNum[boxI]-=min;
			int newBoxI = boxI;
			if(newBoxNum[newBoxI]==0){
				newBoxI++;
			}
			long[] newToyNum = copyArray(toyNum);
			int newToyI=toyI;
			newToyNum[newToyI]-=min;
			if(newToyNum[newToyI]==0){
				newToyI++;
			}
			
				throwBoth = min +count(newBoxNum, newBoxI, newToyNum, newToyI);
			}
		}
		return max3(throwBox, throwToy, throwBoth);
	}
	
	public int[] copyArray(int[] array){
		int[] array2= new int[array.length];
		for(int i=0; i<array.length; i++){
			array2[i]=array[i];
		}
		return array2;
	}
	public long[] copyArray(long[] array){
		long[] array2= new long[array.length];
		for(int i=0; i<array.length; i++){
			array2[i]=array[i];
		}
		return array2;
	}
	public void printArray(int[] array){
		for(int i=0; i<array.length; i++){
			System.out.print(array[i]+" ");
		}
		System.out.println();
	}
	public int max3(int x, int y, int z){
		if(x>= y && x >= z)
			return x;
		if(y>=x && y>=z)
			return y;
		else
			return z;
	}
	public long max3(long x, long y, long z){
		if(x>= y && x >= z)
			return x;
		if(y>=x && y>=z)
			return y;
		else
			return z;
	}
	public void execute(){
		// long boxSum=0;
		// long toySum=0;
		// for(int i=0; i<N; i++)
		// 	boxSum+=boxNum[i];
		// for(int i=0; i<M; i++){
		// 	toySum+=toyNum[i];
		// }
		// boxes=new int[boxSum];
		// int count=0;
		// toys=new int[toySum];
		// for(int i=0; i<N; i++){
		// 	for(int j=0; j<boxNum[i]; j++){
		// 		boxes[count++]=boxType[i];
		// 	}
		// }
		// for(int i=0; i<count; i++){
		// 	System.out.print(boxes[i]+" ");
		// }
		int maxSum=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				int sum = 0;
				if(boxType[i]==toyType[j]){
					
					int x=N-i;
					int y=M-j;
					int z=min(x,y);
					for(int k=0; k<z; k++ ){
						if(boxType[i+k]==toyType[j+k])
							sum+=min(boxNum[i+k], toyNum[j+k]);
					}
				}
			if(sum>maxSum)
				maxSum=sum;
			}
		}
		System.out.println(maxSum);

	}
	public int min(int x, int y){
		if(x<y)
			return x;
		else
			return y;
	}
	public long min(long x, long y){
		if(x<y)
			return x;
		else
			return y;
	}
	public static void main(String[] args){
	 	C c= new C();
		c.run();
	}
}