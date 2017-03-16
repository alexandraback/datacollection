import java.io.*;


public class KingdomRush {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			FileReader fileReader = new FileReader("B-large.in");
			FileWriter fileWriter = new FileWriter("out.txt");
			BufferedReader reader = new BufferedReader(fileReader);
			BufferedWriter writer = new BufferedWriter(fileWriter);
			int testCaseCount = Integer.parseInt(reader.readLine());
			for (int testCase = 1; testCase <= testCaseCount; testCase++)
			{
				String output = "Case #" + testCase + ": ";
				int n = Integer.parseInt(reader.readLine());
				int a[] = new int[n];
				int b[] = new int[n];
				int check[] = new int[n];
				for (int i = 0; i < n; i++)
				{
					String[] s = reader.readLine().split(" ");
					a[i] = Integer.parseInt(s[0]);
					b[i] = Integer.parseInt(s[1]);
				}
				boolean flag = true;
				int count = 0;
				int res = 0;
				while(flag)
				{
					flag = false;
					for (int i = 0; i < n; i++)
					{
						if (check[i] < 2 && count >= b[i])
						{
							flag = true;
							count += 2 - check[i];
							check[i] = 2;
							res++;
						}
					}
					if (flag) continue;
					int max = -1;
					for (int i = 0; i < n; i++)
					{
						if (check[i] == 0 && count >=a[i] && (max == -1 || b[max] < b[i]))
						{
							max = i;
						}
					}
					if (max > -1)
					{
						flag = true;
						count++;
						res++;
						check[max] = 1;
					}
				}
				if (count == 2 * n) output += res;
				else output += "Too Bad";
				output += "\n";
				writer.write(output);
				System.out.print(output);
			}
			reader.close();
			writer.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
