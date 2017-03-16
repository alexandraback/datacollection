import java.util.Scanner;
import java.util.Arrays;

public class A {

	static Scanner scan;
	
	public static void main(String[] args) {
		scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		int caseNum = 0;
		while(testCases>0){
			testCases--;
			caseNum++;
			
			long A = scan.nextInt();
			int N = scan.nextInt();
			
			long arr[] = new long[N];
			for(int i=0; i<N; i++){
				arr[i] = scan.nextInt();
			}
			Arrays.sort(arr);
			
			int remaining = N;
			int startIndex = -1;
			for(int i=0; i<N; i++){
				if(arr[i]<A){
					A+= arr[i];
					arr[i] = 0;
					remaining--;
				}
				else{
					startIndex = i;
					break;
				}
			}
			
			if(startIndex==-1){
				//no need change; output 0
				System.out.println("Case #"+(caseNum)+": 0");
			}
			else{
				//System.out.println(A);
				int count = 0;
				for(int i=0; i<N-1; i++){
					if(arr[i]==0)
						continue;
					if(arr[i]<A){
						A+=arr[i];
						arr[i] = 0;
					}
					else{
						if(A==1){
							break;
						}
						A = A*2-1;
						count++;
						i--;
					}
				}
				
				if(arr[N-1]>=A && A!=1){
					//remove the last element
					count++;
				}
					
				
				if(count<remaining && A!=1){
					System.out.println("Case #"+(caseNum)+": "+count);
				}
				else{
					System.out.println("Case #"+(caseNum)+": "+remaining);
				}
			}
			
			
			
		}
	}

}
