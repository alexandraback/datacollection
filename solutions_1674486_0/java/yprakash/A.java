import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Scanner;

public class A
{
	private static String output, newline = System.getProperty("line.separator");
	private static int n;
	private static boolean[][] arr;

	private static void fun() throws IOException
	{
		int m, i, j, clas;
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		int ntc = sc.nextInt();

		for(int w=1; w<=ntc; w++) {
			n = sc.nextInt();
			arr = new boolean[n][n];
			for(i=0; i<n; i++) {
				m = sc.nextInt();
				for(j=0; j<m; j++) {
					clas = sc.nextInt();
					arr[i][clas-1] = true;
				}
			}
			output += "Case #" + w + (fun3() ? ": Yes" : ": No") + newline;
		}
		sc.close();
	}

	private static boolean fun3()
	{
		int i, j, k;
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++)
				if(arr[i][j])
					for(k=j+1; k<n; k++)
						if(arr[i][k])
							if(fun2(j, k))
								return true;
		}
		return false;
	}

	private static boolean fun2(int x, int y)
	{
		if(arr[x][y] || arr[y][x])
			return true;
		for(int i=0; i<n; i++) {
			if(arr[x][i] && arr[y][i])
				return true;
		}
		for(int i=0; i<n; i++) {
			if(arr[x][i]) {
				if(fun2(i, y))
					return true;
			}
			if(arr[y][i]) {
				if(fun2(x, i))
					return true;
			}
		}
		return false;
	}

	public static void main(String[] args) throws IOException
	{
		output = "";
		fun();
		OutputStream fo = new FileOutputStream("A-small-attempt0.out");
		fo.write(output.getBytes());
		fo.close();
	}
}
