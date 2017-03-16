import java.math.BigInteger;
import java.io.*;
import java.util.*;
class Source1 
{
	public static void main(String[] args) throws IOException 
	{
		String s,word,buffer;
		String[][] board;

		FileReader input = new FileReader("C-large.in");
		Scanner in = new Scanner(input);
		File file = new File("C-large.out");
		BufferedWriter out = new BufferedWriter(new FileWriter(file));

		s = in.nextLine();
		int count= Integer.parseInt(s);

		int i=1;
		 while (in.hasNext())
		{

			 out.write("Case #"+(i++)+": ");
			 out.newLine();

			 if(in.hasNext())s = in.nextLine();
			
			 String[] num = s.split(" ");
			 int N = Integer.parseInt(num[0]);
			 int J = Integer.parseInt(num[1]);

			 String[] jamcoin = getjamcoin(N,J);
			 
			 for(int j=0;j<jamcoin.length;j++)
			 {
				out.write(jamcoin[j]);
				out.newLine();
			 }

				out.newLine();

		}


		 out.close();
	}

	public static String[] getjamcoin(int N,int J)
	{
		String[] jamcoin = new String[J];
		
		int nodigit =N -2;
		int count=0;
		for (int i=0;i<Math.pow(2,nodigit);i++ )
		{
			String coin = Integer.toString(i,2);
			int len =coin.length();
			if(len <nodigit)
			{
				for (int j=0; j<nodigit-len ;j++ )
					coin="0"+coin;
			}
			
			coin = "1"+coin+"1"; //pad jam coin

			// check if it is a jamcoin
			// prime in all base
			boolean isprime=false;
			BigInteger[] div = new BigInteger[9];
			for (int b=2;b<=10;b++ )
			{
				BigInteger basex = new BigInteger(coin,b);
				//System.out.println(count+"  "+b);
				//System.out.println(basex);
				BigInteger divisor;
				divisor =isPrime(basex);
				

				if(divisor.compareTo(new BigInteger("-1"))==0)
					{
						isprime=true;
						break;
					}
				else
					{
						div[b-2]=divisor;
					}
				
			}

			if(!isprime)
			{

				jamcoin[count]=coin;
				
				for (int d=0;d<=8;d++ )
				{
					jamcoin[count]+=" "+div[d];
				}
				//System.out.println("count ="+count+" "+jamcoin[count]);
				count++;
				if(count>=J)
				{
					break;
				}
			}


		}

		return jamcoin;
	}


	public static BigInteger isPrime(BigInteger n) {
		BigInteger two=new BigInteger("2");
		BigInteger three=new BigInteger("3");


		if (n.compareTo(BigInteger.ONE) == 0 || n.compareTo(two) == 0) {
			return new BigInteger("-1");
		}
		
		if (n.mod(two).equals(BigInteger.ZERO)) {
				return two;
		}
		BigInteger root = appxRoot(n);


		/*
		for (BigInteger i = three; i.compareTo(root) <= 0; i = i
				.nextProbablePrime()) {

			if (n.mod(i).equals(BigInteger.ZERO)) {
				return i;
			}

		}

		*/
		int cnt=0;
		for (BigInteger i = three; i.compareTo(root) <= 0; i = i.add(two)) {

			if (n.mod(i).equals(BigInteger.ZERO)) {
				return i;
			}
			cnt++;
			if(cnt>5000)
				return new BigInteger("-1");
		}

		return new BigInteger("-1");

	}

	public static BigInteger appxRoot(final BigInteger n) {
		BigInteger half = n.shiftRight(1);
		while (half.multiply(half).compareTo(n) > 0) {
			half = half.shiftRight(1);
		}
		return half.shiftLeft(1);
	}


}
