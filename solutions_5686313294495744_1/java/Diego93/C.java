import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("c.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("c.out"));
		int N = s.nextInt();
		for(int i=0; i<N; i++){
			int M = s.nextInt();
			s.nextLine();
			String[][] topics = new String[M][2];
			Map<String, Integer> first = new HashMap<String, Integer>();
			Map<String, Integer> second = new HashMap<String, Integer>();
			for(int j=0; j<M; j++){
				topics[j]=s.nextLine().split(" ");
				if(first.get(topics[j][0])==null) first.put(topics[j][0], 0);
				first.put(topics[j][0],first.get(topics[j][0])+1);
				if(second.get(topics[j][1])==null) second.put(topics[j][1], 0);
				second.put(topics[j][1],second.get(topics[j][1])+1);
			}
			int ans=0;
			for(int j=0; j<M; j++){
				if(first.get(topics[j][0])>1 && second.get(topics[j][1])>1){
					ans++;
					first.put(topics[j][0],first.get(topics[j][0])-1);
					second.put(topics[j][1],second.get(topics[j][1])-1);
				}
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