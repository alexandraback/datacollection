import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;


public class QualifiRound2012B {

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
				String[] input = line.trim().split(" ");
				int N = Integer.valueOf(input[0]);
				int S = Integer.valueOf(input[1]);
				int p = Integer.valueOf(input[2]);
				
				int good = 0;
				for(int j=0; j<N; j++)
				{
					int score = Integer.valueOf(input[3+j]);
					if(Math.ceil((double)score/3)>=p)
						good++;
					else if(S>0)
					{
						if(score==0)
						{
							if(p==0)
								good++;
						}
						else if((score%3 != 2)&&(score/3+1>=p)
								||(score%3 == 2)&&(score/3+2>=p))
						{
							good++;
							S--;
						}
							
					}
				}
				
				pw.println("Case #"+(i+1)+": "+good);
				System.out.println("Case #"+(i+1)+": "+good);
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
