import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class C {
	
	//ArrayList<Integer> squareNumbers = new ArrayList<Integer>(); 
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		for(int i =1; i<=n; i++){
			int count =0;
			String[] range = br.readLine().split(" ");
			long lower = Long.parseLong(range[0]);
			long upper = Long.parseLong(range[1]);
			
			for(long num: findSquares(lower, upper))
				if(checkPalin(num)) count++;
			
			
			System.out.format("Case #%d: %d\n", i,count);
		}

	}
	
	private static boolean checkPalin(long number){
		String num = String.valueOf(number);
		for(int i=0; i<num.length()/2; i++){
			if(num.charAt(i)!=num.charAt(num.length()-1-i)) return false;
		}
		//System.out.println("Yes " + number);
		return true;
	}
	
	private static ArrayList<Long> findSquares(Long lower, Long upper){
		ArrayList<Long> sqNumbers = new ArrayList<Long>();
		for(long i = (long)Math.ceil(Math.sqrt(lower)) ;i<=(long)Math.floor(Math.sqrt(upper)); i++ ){
			if(!(i%10==0) && checkPalin(i)) sqNumbers.add(i*i);
		}
		return sqNumbers;
	}
}
