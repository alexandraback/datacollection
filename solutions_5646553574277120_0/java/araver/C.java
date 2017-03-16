import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class C{
	
	static int t,c,d,v,a, max;
	static int[] b;
	static boolean[] e;
	static String line,str;
	static String[] row;
	static boolean debug = false;
	
	public static void main(String [ ] args) throws IOException{
		int i,j,k;
		
		
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt1.in"));
	    try {
	    	File file = new File("ccc.out");
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		
	        line = br.readLine();
	        t = Integer.valueOf(line); //1 <= T <= 100.

			
	        for(i = 0; i < t; i++){
				
				line = br.readLine();
				row = line.split("\\s");
				c = Integer.valueOf(row[0]);
				d = Integer.valueOf(row[1]);
				v = Integer.valueOf(row[2]);
				
				b = new int[d+v+1];
				e = new boolean[v+1];
				Arrays.fill(e,false);
				line = br.readLine();
				row = line.split("\\s");
				for(j = 0;j<d;j++){
					b[j] = Integer.valueOf(row[j]);
				}
				
	        	//1 <= n <= 10^6.
				debug = false;
				a=0;
				max = v+1;
				
				//C = 1
				int lastindex =d;
				while (max>0){
					
					if(lastindex ==d){
						//mark all comb < d
						back(0,d,0);
					} else {//only need to mark b[lastindex-1] + all other comb.
						back(0,lastindex-1,b[lastindex-1]);
					}
					
					//if max==0 we're done
					if(max>0){
						//add a new denomination
						for(j=0;j<d+v;j++){
							if(e[j]==false){
								a++;
								b[lastindex]=j;
								lastindex ++;
								//if(debug) System.out.println("--Add"+j);
								//e[j]=true;
								//max--;
								
								j=d+v;
							}
						}
					}
					
				}
				
				if(debug) System.out.println("-------");
    			bw.write("Case #"+(i+1)+": "+a+"\n");
	        }
	        
			bw.close();

	    } finally {
	        br.close();
	    }
	}
	
	private static void back(int index, int last, int count){
		if(index == last){
			//mark current count;
			if(count <=v && count >=0 && e[count]==false){
				e[count] = true;
				max--;
				//if(debug) System.out.println("-Mark"+count+" max"+max);
			}
		} else {
			//try w/o next
			back(index+1,last, count);
			//try with next
			back(index+1,last, count+b[index]);
		}
	}
	
}
