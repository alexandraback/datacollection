import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	public static void main(String [] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int numTests = Integer.parseInt(br.readLine());
		for(int i=0; i<numTests; i++){
			int result = cal(br);
			System.out.println("Case #"+(i+1)+": "+result);
		}
	}

	private static int cal(BufferedReader br) throws IOException {
		String[] input = br.readLine().split(" ");
		long r = Long.parseLong(input[0]);
		long t = Long.parseLong(input[1]);
		
		int count = 1;
		int OldCount = 0;
		while(true){
			 if(expectedL(r, t, count)){
				 OldCount = count;
				 count = count*2;
			 }
			 else
				 break;
		}
		
		//System.out.println(count);
		
		//if(OldCount==0||OldCount==1)
		//	return OldCount;
		
		int ret_count = binarySearch(r, t, OldCount, count);
		
		return ret_count;
	}

	private static int binarySearch(long r, long t, int left, int right) {
		if(left+1==right)
		{
			if(expectedL(r,t,right))
				return right;
			return left; 
		}
		int mid = (left+right)/2;
		if(expectedL(r,t,mid))
			return binarySearch(r,t,mid,right);
		return binarySearch(r,t,left,mid);
	}

	private static boolean expectedL(long r, long t, int expectedC){
		if(t>=2*expectedC*expectedC-expectedC+2*expectedC*r)
			return true;
		return false;
	}
	
}
