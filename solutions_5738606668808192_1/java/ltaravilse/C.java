import java.math.*;
import java.util.Random;

public class C {
	public static void main(String[] args) {
		int bits = 32;
		int count = 0;
		BigInteger[] bases = new BigInteger[9];
		BigInteger[] mult = new BigInteger[9];
		BigInteger one = new BigInteger("1");
		for(int i=2;i<=10;i++)
		{
			bases[i-2] = new BigInteger(Integer.toString(i));
			mult[i-2] = new BigInteger("1");
			for(int j=0;j<bits/2;j++)
				mult[i-2] = mult[i-2].multiply(bases[i-2]);
			mult[i-2] = mult[i-2].add(one);
		}
		System.out.println("Case #1:");
		for(int i=0;i<500;i++)
		{
			System.out.print("1");
			for(int j=0;j<bits/2-2;j++)
				System.out.print((i>>j)%2);
			System.out.print("11");
			for(int j=0;j<bits/2-2;j++)
				System.out.print((i>>j)%2);
			System.out.print("1");
			for(int j=0;j<9;j++)
				System.out.print(" "+mult[j].toString());
			System.out.print("\n");
		}
    }
}