import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("c.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("c.out"));
		int N = s.nextInt();
		for(int i=0; i<N; i++){
			int M = s.nextInt();
			s.nextLine();
			String[][] topics = new String[M][2];
			for(int j=0; j<M; j++){
				topics[j]=s.nextLine().split(" ");
			}
			int max = (1<<M);
			int ans=0;
			for(int mask=0; mask<max; mask++){
				Set<String> firsts = new HashSet<String>();
				Set<String> seconds = new HashSet<String>();
				for(int u=0; u<M; u++){
					if(!BitOperations.getB(mask, u)){
						firsts.add(topics[u][0]);
						seconds.add(topics[u][1]);
					}
				}
				int aux=0;
				boolean valid=true;
				for(int u=0; u<M && valid; u++){
					if(BitOperations.getB(mask, u)){
						aux++;
						if(!firsts.contains(topics[u][0]) || !seconds.contains(topics[u][1])) valid=false;	
					}
				}
				if(valid && aux>ans) ans=aux;
			}
			out.write("Case #"+(i+1)+": "+ans+"\n");
		}
		out.close();
	}
	
	static public class BitOperations {

		/**
		 * 
		 * @param value - array of bits to modified
		 * @param index - index of the bit to turn on
		 * @return array modified
		 */
		public static int onB(int value, int index){
	    	return value|(1<<index);
	    }
	    
		/**
		 * 
		 * @param value - array of bits to modified
		 * @param index - index of the bit to turn off
		 * @return array modified
		 */
	    public static int offB(int value, int index){
	    	int aux = (1<<index);
	    	return value & (~aux);
	    }
	    
	    /**
	     * 
	     * @param value - array of bits
	     * @param index - index of the bit to return
	     * @return true if the bit is on, false otherwise
	     */
	    public static boolean getB(int value, int index){
	    	return (value>>index)%2==1;
	    }
	}
}