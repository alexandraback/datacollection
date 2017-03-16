import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class C {
	
		public static void main(String[] args) throws IOException
		{
			PrintWriter out = new PrintWriter(new FileWriter(new File("out.txt")));
			out.println("Case #1:");
			String x = "1";
			for(int i = 0;i<30;i++)
				x+="0";
			x+="1";
			System.out.println(x.length());
			BigInteger bi = new BigInteger(x,2);
			BigInteger two = new BigInteger("2");
			bi = bi.subtract(two);
			int found = 0;
		search:
			while(found<500)
			{
				bi = bi.add(two);
				BigInteger[] bis = new BigInteger[9];
				for(int i = 0;i<bis.length;i++)
				{
					bis[i] = new BigInteger(bi.toString(2),i+2);
					if(bis[i].isProbablePrime(600))
					{
						continue search;
					}
				}
				String[] ans = new String[10];
				ans[0] = bis[0].toString(2);
			loop:
				for(int i = 0;i<bis.length;i++)
				{
					for(int j = 2;j<10000000;j++)
					{
						if(bis[i].mod(new BigInteger(j+"")).equals(BigInteger.ZERO))
						{
							ans[i+1] = j+"";
							continue loop;
						}
					}
					continue search;
				}
				found++;
				System.out.println(found);
				for(int i = 0;i<ans.length;i++)
				{
					out.print(ans[i]+" ");
				}
				out.println();
			}
			out.close();
			test();
		}
		
		public static void test() throws FileNotFoundException
		{
			Scanner file = new Scanner(new File("out.txt"));
			file.nextLine();
			for(int i = 0;i<16;i++)
			{
				String next = file.next();
				BigInteger bi = new BigInteger(next,2);
				for(int j = 2;j<=10;j++)
				{
					BigInteger tester = new BigInteger(bi.toString(2),j);
					String nex = file.next();
					if(tester.mod(new BigInteger(nex))!=BigInteger.ZERO)
					{
						System.out.println(bi+" invalid in base "+j+" with  test number "+nex);
					}
				}
			}
			System.out.println("test complete");
		}
}
