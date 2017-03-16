import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	public static void main(String [] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new FileWriter("out"));
		int numTests = Integer.parseInt(br.readLine());
		for(int i=0; i<numTests; i++){
			long result = cal(br);
			String outPut = "Case #"+(i+1)+": "+result;
			bw.write(outPut);
			bw.newLine();
			System.out.println(outPut);
		}
		bw.close();
	}

	private static long cal(BufferedReader br) throws IOException {
		String[] input = br.readLine().split(" ");
		long r = Long.parseLong(input[0]);
		long t = Long.parseLong(input[1]);
		
		long count = 1;
		long OldCount = 0;
		while(true){
			 if(expectedL(r, t, count)){
				 OldCount = count;
				 count = count*2;
				 //System.out.println(count);
			 }
			 else
				 break;
		}
		
		//System.out.println(count);
		
		//if(OldCount==0||OldCount==1)
		//	return OldCount;
		
		long ret_count = binarySearch(r, t, OldCount, count);
		
		return ret_count;
	}

	private static long binarySearch(long r, long t, long left, long right) {
		if(left+1==right)
		{
			if(expectedL(r,t,right))
				return right;
			return left; 
		}
		long mid = (left+right)/2;
		if(expectedL(r,t,mid))
			return binarySearch(r,t,mid,right);
		return binarySearch(r,t,left,mid);
	}

	private static boolean expectedL(long r, long t, long expectedC){
		if(t>=2*expectedC*expectedC-expectedC+2*expectedC*r)
			return true;
		return false;
	}
	
}
