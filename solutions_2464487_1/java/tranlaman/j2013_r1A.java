import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;


public class j2013_r1A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T, index=0, j;
		long r, t, n, n1, n2;
		String normal_str, reverse_str;
		boolean flag;
		String str_rA, str_rB;
		try{
			//read file
			String[] input;
			String line=null;
			FileReader in = new FileReader("A-large (1).in");
			BufferedReader readerBuff = new BufferedReader(in);
			FileWriter fw = new FileWriter("output.txt");
			BufferedWriter outBuff = new BufferedWriter(fw);
			//process
			line = readerBuff.readLine();
			T=Integer.parseInt(line);
			while((line = readerBuff.readLine())!=null)
			{
				input = line.split(" ");
				r = Long.parseLong(input[0]);
				t = Long.parseLong(input[1]);
				n1 = (long)((t-2*r-1)/(2*r+3));
				n2 = (long)Math.sqrt((t-2*r-1)/2) + 1;
				n = Math.min(n1, n2);
				while((n+1)*(2*n+2*r+1) > t)
					n--;
				outBuff.write("Case #"+ ++index +": "+(n+1)+"\n");
					
				
			}
			readerBuff.close();
			in.close();
			outBuff.close();
			fw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

}
