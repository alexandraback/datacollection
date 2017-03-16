import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class PasswordProblem {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			PrintWriter pw = new PrintWriter(args[1]);
			String line = br.readLine();
			System.out.println(line);
			int T = Integer.valueOf(line.trim());
			for (int i=0; i<T; i++)
			{
				line = br.readLine();
				System.out.println(line);
				String[] nk = line.trim().split(" ");
				int A = Integer.valueOf(nk[0].trim());
				int B = Integer.valueOf(nk[1].trim());
				double expection = 0;
				line = br.readLine();
				System.out.println(line);
				String[] p = line.trim().split(" ");
				double[] correct = new double[A];
				for(int j=0; j<A; j++)
				{
					if(j==0)
					{
						correct[0] = Double.valueOf(p[0]);
					}
					else
					{
						correct[j]=correct[j-1]*Double.valueOf(p[j]);
					}
				}
				
				expection = 2+B;
				
				for(int j=0; j<A; j++)
				{
					double tmp_expection = (A-1-j);
					tmp_expection += ((B-j) + (1-correct[j])*(B+1));
					expection = expection<tmp_expection?expection:tmp_expection;
				}
				
				pw.println("Case #"+(i+1)+": "+expection);
				System.out.println("Case #"+(i+1)+": "+expection);
			}
			pw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
