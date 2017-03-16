import java.util.Scanner;


public class ca_2015 {

	public static void main(String[] args) {
		int x=0,T=0;
		Scanner s1= new Scanner(System.in);
		T = s1.nextInt();
		while(T!=0)
		{
			T--;
			x++;
			int row = s1.nextInt();
			int col = s1.nextInt();
			int width = s1.nextInt();
			int y = ((col-1)/width)+width;
			if(row != 1)
				y += ((row-1)*(col/width));
			if(width > col)
				y = 0;
			System.out.println("Case #" + x + ": " + y);
		}

	}

}
