import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;


public class B implements Runnable{
	
	BufferedReader in;
	BufferedWriter out;
	static String inputFile="";
	static String outputFile="";
	static {
		inputFile = B.class.getName()+".in";
		outputFile = B.class.getName()+".out";
	}
	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}
	public long lread() throws Exception {
		return Long.parseLong(readword());
	}
	public Double dread() throws Exception {
		return Double.parseDouble(readword());
	}
	public String readword() throws Exception {
		int k = in.read();
		if(k < 0) return "";
		while(k >= 0 && k <= ' ') k=in.read();
		StringBuilder bld = new StringBuilder();
		while(k > ' ') {
			bld.append((char)k);
			k = in.read();
		}
		return bld.toString();
	}
	public static void reverseArrayInt(int[] array) {
	    int temp;

	    for (int i = 0; i < array.length / 2; i++) {
	      temp = array[i];
	      array[i] = array[(array.length - 1) - i];
	      array[(array.length - 1) - i] = temp;
	    }
	  }
	
	public void solve() throws Exception {
		int tests = iread();
		for (int T=0; T<tests; T++) {
			int N = iread();
			int A[] = new int[N];
			int B[] = new int[N];
			int present = 0;
			int future = 1;
			int tmp = 0;
			int count = 0;
			String fail = "Too Bad";
			for(int i = 0; i < N ; i++) {
				A[i]= iread();
				B[i]= iread();
				
				tmp = Math.max(tmp, B[i]);
				future = Math.max(future,B[i]);
			}
		
			if(tmp == 0){
				
				out.write("Case #"+(T+1)+": "+N+"\n");
				continue;
				
			}
			
			int Aused[] = new int[N];
			int Bused[] = new int[N];
			Arrays.fill(Aused, 0);
			Arrays.fill(Bused, 0);
			while(present < future) {
				int flag = 0;
				for(int j = 0; j<=present; j++) {
					for(int i = 0; i < N ; i++){
						if(Aused[i]==0 && Bused[i]==0 && B[i]==(present-j)) {
							present += 2;
							count++;
							flag = 1;
							Bused[i]=1;
							Aused[i]=1;
							
							break;
						}
					}
					if(flag ==1) break;
					
					
					for(int i = 0; i < N ; i++){
						if(Aused[i]==1 && Bused[i]==0 && B[i]==(present-j)){
							present += 1;
							count++;
							flag = 1;
							Bused[i]=1;
							
							break;						
						}
					}
					if(flag ==1) break;
					
					for(int i = 0; i < N ; i++){
						if(Aused[i]==0 && A[i]==(present-j)) {
							present += 1;
							count++;
							flag = 1;
							Aused[i]=1;
							
							break;
						}
					}
					if(flag ==1) break;
					
				}
				if(flag == 0) {
					count = -1;
					break;					
				}				
			}
			
			if(count == -1) {
				out.write("Case #"+(T+1)+": "+fail+"\n");
				continue;
			}
			
			for(int k = 0; k < N ; k++) {
				if(Bused[k]==0) count++;
			}
			
			
			out.write("Case #"+(T+1)+": "+count+"\n");
		}		
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader(inputFile));
			out = new BufferedWriter(new FileWriter(outputFile));
			solve();
			out.flush();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		
		new Thread(new B()).start();
	}
}



