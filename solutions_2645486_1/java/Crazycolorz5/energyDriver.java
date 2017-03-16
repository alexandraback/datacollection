import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class energyDriver {

	public static void main(String[] args) {
		try {
			File f = new File("energy.in");
			File out = new File("energy.out");
			FileInputStream fin;
			Scanner sin = null;
			fin = new FileInputStream(f);
			FileWriter fout = new FileWriter(out);
			try {
				sin = new Scanner(fin);
				int numOfCases = sin.nextInt();
				for(int casenum = 0; casenum<numOfCases; casenum++)
				{
					int e = sin.nextInt();
					int r = sin.nextInt();
					int n = sin.nextInt();
					long[] v = new long[n];
					int curE = e;
					for(int c=0; c<n;c++)
					{
						v[c] = sin.nextLong();
					}
					BigInteger value = BigInteger.valueOf(0);
					for(int c=0; c<n; c++)
					{
						if(c==n-1)
						{
							value = value.add(BigInteger.valueOf(curE*v[c]));
							curE = 0;
						}
						else
						{
							//check the next e/r tasks for things worth saving energy for
							int closestOfMoreVal = c;
							for(int d=c+1; d<n; d++)
							{
								if(v[d]>v[closestOfMoreVal])
								{
									if(closestOfMoreVal==c)
									{
										closestOfMoreVal = d;
									}
								}
							}
							//We want to save a full tank for closest
							//We can spend will we have up to
							//e-(closest-c)*r
							if(closestOfMoreVal!=c)
								//theres a task worth more
							{
								if(curE>e-(closestOfMoreVal-c)*r)
								{
									if(e-(closestOfMoreVal-c)*r<0)
									{
										value = value.add(BigInteger.valueOf(curE*v[c]));
										curE = 0;
									}
									else
									{
										value = value.add(BigInteger.valueOf((curE-(e-(closestOfMoreVal-c)*r))*v[c]));
										curE -= (curE-(e-(closestOfMoreVal-c)*r));
									}
								}
								//else don't spend any energy
							}
							else
								//spend all energy on this task
							{
								value = value.add(BigInteger.valueOf(curE*v[c]));
								curE = 0;
							}
						}
						curE+=r;
						if(curE>e)
							curE = e;
					}
					try {
						fout.write("Case #" + (casenum+1) + ": " + value.toString() + "\n");
					} catch (IOException e1) {e1.printStackTrace();}
				}
			} finally {
				fout.flush();
				sin.close();
				fout.close();
			}
		} catch(IOException e) {}
	}

}
