import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.math.BigInteger;


public class B {

	public static void main(String[] args) throws Exception{
		FileOutputStream fop = null;
		File file;
		BufferedReader br = new BufferedReader(new FileReader("c:\\B-small-attempt0.in"));
		try {
			file = new File("c:\\B-small-attempt0.out");
			fop = new FileOutputStream(file);
		
			int testcase = Integer.parseInt(br.readLine());
			
			for(int i=0;i<testcase;i++){
				String[] params = br.readLine().split(" ");
				
				int A = Integer.parseInt(params[0]);
				int B = Integer.parseInt(params[1]);
				int K = Integer.parseInt(params[2]);
				
				BigInteger ans = BigInteger.ZERO;
				//ans.add(BigInteger.ONE);
				
				//int t = 1;
				//System.out.println(~t);
				
				for(int a=0;a<A;a++){
					for(int b=0;b<B;b++){
						if(Math.abs(a&b)<K){
							ans = ans.add(BigInteger.ONE);
						}
					}
				}
				
				String out = "Case #"+(i+1)+": "+ans.toString()+"\n";
				System.out.print(out);
				byte[] contentInBytes = out.getBytes();
				fop.write(contentInBytes);
			}
			
		} finally {
	        br.close();
	        fop.flush();
			fop.close();
	    }
	}

}
