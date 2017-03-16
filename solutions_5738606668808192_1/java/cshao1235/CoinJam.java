import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CoinJam {
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("coinjam.out");
			for(int i = 1; i <= t; i++)
			{
				StringTokenizer st = new StringTokenizer(f.readLine());
				int n = Integer.parseInt(st.nextToken());
				int j = Integer.parseInt(st.nextToken());
				boolean done = false;
				System.out.println("Case #" + t + ":");
				fout.write("Case #" + t + ":\n");
				if(n == 16)
				{
					int numOutput = 0;
					for(int i1 = 0; i1 <= n - 4; i1++)
					{
						for(int i2 = i1 + 2; i2 <= n - 4; i2++)
						{
							int counter = 0;
							String jamcoin = "";
							while(counter < n - 2)
							{
								if(counter == i1)
								{
									jamcoin = "11" + jamcoin;
									counter++;
								}
								else if(counter == i2)
								{
									jamcoin = "11" + jamcoin;
									counter++;
								}
								else
								{
									jamcoin = "0" + jamcoin;
								}
								counter++;
							}
							jamcoin = "1" + jamcoin + "1";
							StringBuffer line = new StringBuffer(jamcoin);
							for(int b = 2; b <= 10; b++)
								line.append(" " + (b + 1));
							System.out.println(line.toString());
							fout.write(line.toString() + "\n");
							numOutput++;
							if(numOutput == j)
							{
								done = true;
								break;
							}
						}
						if(done)
							break;
					}
				}
				else
				{
					int numOutput = 0;
					for(int i1 = 0; i1 <= n - 4; i1++)
					{
						for(int i2 = i1 + 2; i2 <= n - 4; i2++)
						{
							for(int i3 = i2 + 2; i3 <= n - 4; i3++)
							{
								int counter = 0;
								String jamcoin = "";
								while(counter < n - 2)
								{
									if((counter == i1) || (counter == i2) || (counter == i3))
									{
										jamcoin = "11" + jamcoin;
										counter++;
									}
									else
									{
										jamcoin = "0" + jamcoin;
									}
									counter++;
								}
								jamcoin = "1" + jamcoin + "1";
								StringBuffer line = new StringBuffer(jamcoin);
								for(int b = 2; b <= 10; b++)
									line.append(" " + (b + 1));
								System.out.println(line.toString());
								fout.write(line.toString() + "\n");
								numOutput++;
								if(numOutput == j)
								{
									done = true;
									break;
								}
							}
							if(done)
								break;
						}
						if(done)
							break;
					}
				}
			}
			f.close();
			fout.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}


	}

}
