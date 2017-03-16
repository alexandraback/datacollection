import java.util.*;

public class B {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int z = input.nextInt();
		for (int y=1; y<=z; y++){
			System.out.print("Case #"+y+": ");
			int a = input.nextInt();
			int b = input.nextInt();
			int k = input.nextInt();
			int ans = 0;
			for (int i=0; i<a; i++)
				for (int j=0; j<b; j++)
					if ((i&j)<k) ans++;
			System.out.println(ans);
		}
	}
}
