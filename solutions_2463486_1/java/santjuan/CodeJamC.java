import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.TreeMap;


public class CodeJamC 
{
	static boolean palindrome(long numero)
	{
		char[] val = (numero + "").toCharArray();
		int izq = 0;
		int der = val.length - 1;
		while(izq < der && izq != -1 && der != val.length)
		{
			if(val[izq] != val[der])
				return false;
			izq++;
			der--;
		}
		return true;
	}
	
	static TreeMap <Long, Integer> fairAndSquare = new TreeMap <Long, Integer> ();  
	
	static int contar(long a, long b)
	{
		Long valorUno = fairAndSquare.ceilingKey(a);
		if(valorUno == null || valorUno.longValue() > b)
			return 0;
		Long valorDos = fairAndSquare.floorKey(b);
		return fairAndSquare.get(valorDos) - fairAndSquare.get(valorUno) + 1;
	}

	static boolean debug = false;
	
	public static void main(String[] args) throws FileNotFoundException
	{
		int cuenta = 0;
		for(long i = 1; i <= 10000000; i++)
		{
			if(palindrome(i) && palindrome(i * i))
				fairAndSquare.put(i * i, cuenta++);
		}
		if(!debug)
		{
			System.setIn(new FileInputStream("C-large-1.in"));
			System.setOut(new PrintStream("C-large-1.out"));
		}
		Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		for(int caso = 1; caso <= t; caso++)
		{
			long a = sc.nextLong();
			long b = sc.nextLong();
			System.out.println("Case #" + caso + ": " + contar(a, b));
		}
		sc.close();
		if(debug)
		{
			System.out.flush();
			System.out.close();
		}
	}
}