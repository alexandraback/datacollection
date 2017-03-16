import java.io.ObjectInputStream.GetField;
import java.util.Arrays;
import java.util.Scanner;


public class DeerInZooDivTwo {

	
	
	public static int min(int x,int y){
		return x < y ? x : y;
	}
	public static int answer(int[] input,int arman,int index){
		for(int x=index;x<input.length;x++){
			if(arman > input[x]){
				arman =  arman + input[x];
			}
			else {
				if(arman == 1)return input.length - x;
				return min(input.length - x,1+answer(input, arman+(arman-1), x));
			
			}
		}
		return 0;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*int a[] = getminmax(1, 20);
		System.out.println("getMin"+a[0]+"sd"+a[1]);
		System.out.println((int)Math.ceil((double)-10/2));*/
		Scanner in = new Scanner(System.in);
		int NoTestCases = in.nextInt();
		for(int i=0;i<NoTestCases;i++){
			int arman ,n;
			arman = in.nextInt();
			n = in.nextInt();
			int[] input = new int[n];
			for(int x=0;x<n;x++){
					input[x] = in.nextInt();
				
			}
			Arrays.sort(input);
			System.out.println("Case #"+(i+1)+": "+answer(input, arman, 0));
		}
	}
}
