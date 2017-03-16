package round;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;


public class CodeJamRoundElf {

	private static final String INPUT = "D:\\input.txt";
	private static final String OUTPUT = "D:\\output.txt";
	
	public static void main(String[] args) {
		try{
			List<ElfLot> Elf = new ElfProvider().retrieve(INPUT);
			List<String> result = new ElfService().game(Elf);
			new ElfView().printListResult(OUTPUT, result);
		
		} catch(Exception exception){
			exception.printStackTrace();
		}

	}

}

class ElfLot{
	long a; 
	long b;
}

class ElfService{
	private static final String FAILURE = "impossible";
	public List<String> game (List<ElfLot> Elf){
		List<String> listResult = new ArrayList<String>();
		for (ElfLot lot : Elf){
			listResult.add(gameOne(lot.a, lot.b));
		}
		return listResult;
	}
	
	private String gameOne(long a, long b){
		 BigInteger abi = new BigInteger("" + a); 
		 BigInteger bbi = new BigInteger(""+b);
		 
		 BigInteger gcdbi = abi.gcd(bbi);
		 a = abi.divide(gcdbi).longValue();
		 b = bbi.divide(gcdbi).longValue();
	
		 long resb = pow2(b);
		 long resa = powMax(a);
		 String res = "" +(resb>0 ? (resb - resa) : FAILURE);
		 return res;
	}
	
	private long pow2 (long num){
		long pow = 1;
		long it = 0;
		while (pow < num){
			pow <<= 1;
			it++;
		}
	 return (pow == num) ? it :0;
	}
	
	private long powMax (long num){
		long pow = 1;
		long it = 0;
		while (pow < num){
			long temp = pow <<1;
			if (temp <num){
				pow <<= 1;
				it++;
			} else {
				break;
			}
		}
	 return it;
	}

}
	
class ElfProvider{
	private static final String SLASH = "/";
	public List<ElfLot> retrieve(String filename) throws IOException{
		List<ElfLot> Elf = new ArrayList<ElfLot>();
		try(BufferedReader br = new BufferedReader(new FileReader(filename))) {
	        int n = Integer.parseInt(br.readLine());
	        for (int i = 0; i< n; i++){
	        	 String[] lotLine = br.readLine().split(SLASH);
		            long a = Long.parseLong(lotLine[0]);
		            long b = Long.parseLong(lotLine[1]);
	            ElfLot lot = new ElfLot();
	            lot.a = a;
	            lot.b = b;
	        	Elf.add(lot);            
	        }
	    }
		return Elf;
	}

}

class ElfView{
	private static final String UTF_8 = "UTF-8";
	public void printListResult(String filename, List<String> listResult) throws IOException{
		try(PrintWriter writer = new PrintWriter(filename, UTF_8)) {
			int i = 0;
			for (String result : listResult){
				++i;
				writer.println("Case #" + i+ ": " + result);
			}
			writer.close();
		}
	}
}
