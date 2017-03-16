import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class C 
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 1; i <= t; i++)
		{
			System.out.println("Case #" + i + ":");
			HashMap <Integer, String> valores = new HashMap <Integer, String> ();
			HashMap <Integer, String> valoresNuevos = new HashMap <Integer, String> ();
			int[] entrada = new int[20];
			sc.nextInt();
			for(int j = 0; j < 20; j++)
				entrada[j] = sc.nextInt();
			valores.put(entrada[0], entrada[0] + "");
			boolean pudo = false;
			outer:
			for(int j = 1; j < 20; j++)
			{
				for(Map.Entry<Integer, String> e : valores.entrySet())
				{
					int nuevo = e.getKey() + entrada[j];
					if(valores.containsKey(nuevo))
					{
						System.out.println(valores.get(nuevo));
						System.out.println(e.getValue() + " " + entrada[j]);
						pudo = true;
						break outer;
					}
					else
						valoresNuevos.put(nuevo, e.getValue() + " " + entrada[j]);
				}
				if(valores.containsKey(entrada[j]))
				{
					System.out.println(valores.get(entrada[j]));
					System.out.println(entrada[j]);
					pudo = true;
					break outer;
				}
				else
					valoresNuevos.put(entrada[j], entrada[j] + "");
				valores.putAll(valoresNuevos);
				valoresNuevos.clear();
			}
			if(!pudo)
				System.out.println("Impossible");
		}
	}

}
