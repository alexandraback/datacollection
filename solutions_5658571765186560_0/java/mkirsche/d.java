import java.util.*;
public class d {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		int x = input.nextInt(), n = input.nextInt(), m = input.nextInt();
		if(n > m)
		{
			int temp = n; n = m; m = temp;
		}
		String res = "";
		if(x > 2*n ||  x > m + 1 || (n*m)%x != 0 || (x == 4 && n == 2 && m == 4))
		{
			res = "RICHARD";
		}
		else res = "GABRIEL";
		System.out.println("Case #" + (t+1)+": "+res);
	}
}
}
