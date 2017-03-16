import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;


public class j2013_r1A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T, index=0, i,j;
		int E, R, N, x, e;
		long gain;
		String normal_str, reverse_str;
		boolean flag;
		String str_rA, str_rB;
		try{
			//read file
			String[] input;
			String line=null;
			FileReader in = new FileReader("B-small-attempt1.in");
			BufferedReader readerBuff = new BufferedReader(in);
			FileWriter fw = new FileWriter("output.txt");
			BufferedWriter outBuff = new BufferedWriter(fw);
			//process
			line = readerBuff.readLine();
			T=Integer.parseInt(line);
			while((line = readerBuff.readLine())!=null)
			{
				gain = 0;
				input = line.split(" ");
				E = Integer.parseInt(input[0]);
				R = Integer.parseInt(input[1]);
				N = Integer.parseInt(input[2]);
				line = readerBuff.readLine();
				input = line.split(" ");
				int[] V = new int[N];
				for(i=0; i<N; i++){
					V[i] = Integer.parseInt(input[i]);
				}
				e = E;
				for(i=0; i<N; i++){
					if (i == N-1) 
						x = e;
					else {
						if(V[i] < V[i+1]){
							x = Math.min(R, e);
						}
						else
							x = e;
					}
					e = E-x+R;
					gain += x*V[i];
				}
				
				outBuff.write("Case #"+ ++index +": "+gain+"\n");
			}
			readerBuff.close();
			in.close();
			outBuff.close();
			fw.close();
		}
		catch(Exception exc)
		{
			exc.printStackTrace();
		}
	}

}
