import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;


public class Recycled {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			System.setIn(new FileInputStream("../C-large.in"));
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
		
		String[] data = {};
		for(int i=0; i < inputs; i++){
			int count = 0;
			
			try{
				line = br.readLine();
				data = line.split(" ");
			} catch(Exception x){
				System.err.println(x);
				System.exit(1);
			}
			
			int a = Integer.parseInt(data[0]);
			int b = Integer.parseInt(data[1]);

			
			for(int n=a; n < b; n++){
				String m = ""+n;
				String[] dup = new String[data[0].length()];
				int next = 0; //position to insert into dup
				
				for(int k=0; k < data[0].length(); k++){
					m = Recycled.shuffle(m);
					
					if(a <= n && n < Integer.parseInt(m) && Integer.parseInt(m) <= b){
						boolean found = false;
						for(int x=0; x<next; x++){
							if(dup[x].equals(m)){
								found = true;
							}
						}
						
						if(!found){
							count++;
							dup[next] = m;
							next++;
						}
					}
				}
			}
			
			System.out.println("Case #" + (i+1) + ": " + count);
		}
	}
	
	public static String shuffle(String in){
		return in.substring(1) + in.substring(0, 1);
	}

}
