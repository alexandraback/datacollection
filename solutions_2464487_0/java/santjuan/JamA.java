import java.math.BigInteger;
import java.util.Scanner;


public class JamA 
{
	
	static long r;

	static BigInteger pinturaMenos(BigInteger i)
	{
		return (sumatoriaCuadrada(i).multiply(BigInteger.valueOf(4))).add(sumatoria(i).multiply(BigInteger.valueOf(4)).multiply(BigInteger.valueOf(r))).add(i.add(BigInteger.ONE).multiply(BigInteger.valueOf(r).multiply(BigInteger.valueOf(r))));
	}
	
	static BigInteger sumatoria(BigInteger i)
	{
		return i.multiply(i.add(BigInteger.ONE)).divide(BigInteger.valueOf(2));
	}
	static BigInteger sumatoriaCuadrada(BigInteger i)
	{
		return i.multiply(i.add(BigInteger.ONE)).multiply(i.multiply(BigInteger.valueOf(2)).add(BigInteger.ONE)).divide(BigInteger.valueOf(6));
	}
	
	static BigInteger pinturaMas(BigInteger i)
	{
		return sumatoriaCuadrada(i).multiply(BigInteger.valueOf(4)).add(sumatoria(i).multiply(BigInteger.valueOf(4)).multiply(BigInteger.valueOf(r + 1))).add(i.add(BigInteger.ONE).multiply(BigInteger.valueOf(r + 1).multiply(BigInteger.valueOf(r + 1))));
	}
	
	static BigInteger valor(long i)
	{
		return pinturaMas(BigInteger.valueOf(i)).subtract(pinturaMenos(BigInteger.valueOf(i)));
	}

	
	static long busquedaBinaria(long a, long b, long disponible)
	{
		if(a + 1 >= b)
			return valor(b).compareTo(BigInteger.valueOf(disponible)) <= 0 ? b : a;
		long mid = (a + b) >>> 1;
		BigInteger v = valor(mid);
		int cmp = v.compareTo(BigInteger.valueOf(disponible));
		if(cmp > 0)
			return busquedaBinaria(a, mid, disponible);
		else if(cmp == 0)
			return mid;
		else
			return busquedaBinaria(mid, b, disponible);
	}
	
	public static void main(String[] args)
	{
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int caso = 1; caso <= T; caso++)
		{
			r = sc.nextLong();
			long t = sc.nextLong();
			System.out.println("Case #" + caso + ": " + (busquedaBinaria(0, Long.MAX_VALUE, t) + 1));
		}
	}
}
