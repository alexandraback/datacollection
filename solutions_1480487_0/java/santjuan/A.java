import java.util.Scanner;


public class A 
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 0; i  < t; i++)
		{
			System.out.print("Case #" + (i + 1) + ": ");
			int n = sc.nextInt();
			int[] valores = new int[n];
			int suma = 0;
			for(int j = 0; j < n; j++)
				suma += (valores[j] = sc.nextInt());
			for(int j = 0; j < n; j++)
			{
				double low = 0;
				double high = 100;
				while(high - low > 1e-8)
				{
					double mid = (low + high) / 2;
					double midV = valores[j] + (mid / 100) * suma;
					double porcentaje = 0;
					for(int k = 0; k < n; k++)
					{
						if(valores[k] >= midV)
							continue;
						else
							porcentaje += (midV - valores[k]) / suma;
					}
					if(porcentaje < 1)
						low = mid;
					else
						high = mid;
				}
				System.out.print(low + (j == n - 1 ? "" : " "));
			}
			System.out.println();
		}
	}

}
