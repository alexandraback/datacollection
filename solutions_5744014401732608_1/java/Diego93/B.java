import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class B {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("b.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("b.out"));
		int T = s.nextInt();
		for (int t = 1; t <= T; t++) {
			out.write("Case #"+t+": "); 
			int B  = s.nextInt();
			long M = s.nextLong();
			long max = 1<<(B-2);
			if(M>max){
				out.write("IMPOSSIBLE\n");
			}else{
				if(M==max){
					out.write("POSSIBLE\n");
					for(int i=0; i<B; i++){
						for(int j=0; j<B; j++){
							if(i>=j){
								out.write("0");
							}else{
								out.write("1");
							}
						}
						out.write("\n");
					}
				}else{
					out.write("POSSIBLE\n0");
					for(int i=0;i<B-2;i++){
						if(getB(M, B-i-3)){
							out.write("1");
						}else{
							out.write("0");
						}
					}
					out.write("0\n");
					for(int i=1; i<B; i++){
						for(int j=0; j<B; j++){
							if(i>=j){
								out.write("0");
							}else{
								out.write("1");
							}
						}
						out.write("\n");
					}
				}
			}
		}
		out.close();
	}
	
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
    public static boolean getB(long value, int index){
    	return (value>>index)%2==1;
    }
}
