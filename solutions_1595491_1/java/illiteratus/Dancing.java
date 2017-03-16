import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;


public class Dancing {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			System.setIn(new FileInputStream("../B-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.exit(0);
		}
		
		InputStreamReader inp = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(inp);
		  
		String line = "";
		int inputs = 0;
	  
		try{
			line = br.readLine();
			inputs = Integer.parseInt( line );
		} catch(Exception x){
			System.err.println(x);
			System.exit(1);
		}
		
		String[] stringdata = {};
		for(int i=0; i < inputs; i++){
						
			try{
				line = br.readLine();
				stringdata = line.split(" ");
			} catch(Exception x){
				System.err.println(x);
				System.exit(1);
			}
			
			int[] data = new int[stringdata.length];
			for(int j=0; j < stringdata.length; j++){
				data[j] = Integer.parseInt(stringdata[j]);
			}
			
			int n = data[0];
			int s = data[1];
			int p = data[2];			
			int count = 0;
			
			for(int k=3; k < data.length; k++){
				
				int score = data[k];
				//double x = Math.ceil(score / 3.0);
				
				if(score >= p && score >= (p*3)-2){
					count++;
				} else if(score >= p && score >= (p*3)-4 && s > 0){
					s--;
					count++;
				}
			}
			
			System.out.println("Case #" + (i+1) + ": " + count);
		}
	}

}
