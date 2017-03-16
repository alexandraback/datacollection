import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Vector;


public class BoxToy {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader input = null;
		BufferedWriter output = null;
		try {
			input = new BufferedReader(new FileReader("C:\\Users\\cerberus\\eclipse-workspace\\1C-C\\src\\C-small-attempt1.in"));
			output = new BufferedWriter(new FileWriter("C:\\Users\\cerberus\\eclipse-workspace\\1C-C\\src\\outp"));
						
			int T = Integer.valueOf(input.readLine());
		    for(int i=1; i<=T; i++) {
		    	String nums[] = input.readLine().split(" ");
		    	int N = Integer.valueOf(nums[0]);
		    	int M = Integer.valueOf(nums[1]);
		    	String box[] = input.readLine().split(" ");
		    	String toy[] = input.readLine().split(" ");
		    	output.write("Case #"+i+": ");
		    	int p=0, q=0;
		    	long total = 0;
		    	
		    	while(p<N && q<M) {
		    		if(Integer.parseInt(box[p*2 + 1]) < Integer.parseInt(toy[q*2 + 1])) {
		    			p++;
		    			continue;
		    		}
		    		if(Integer.parseInt(box[p*2 + 1]) > Integer.parseInt(toy[q*2 + 1])) {
		    			q++;
		    			continue;
		    		}
		    		if(Long.parseLong(box[p*2]) <= Long.parseLong(toy[q*2])) {
		    			total += Long.parseLong(box[p*2]);
		    			p++; q++;
		    		}
		    		else {
		    			total += Long.parseLong(toy[q*2]);
		    			p++; q++;
		    		}
		    	}
		    	
		    	output.write(Long.toString(total));
		    	if(i<T) output.write("\n");
		    }
		} catch (FileNotFoundException e) {
			System.out.println("input file not found: ");
			e.printStackTrace();
		} catch(IOException e) {
			System.out.println("Error opening files: ");
		    e.printStackTrace();
		    System.exit(1);
		} finally {
			try {
				input.close();
				output.close();
				System.out.println("Done !!");
			} catch (IOException e) {
				System.out.println("Error closing files: ");
				e.printStackTrace();
			}
		}
		    	
	}

}
