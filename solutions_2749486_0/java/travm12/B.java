import java.util.*;
public class b {
	public static void main(String[] Args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int k =0;k<n;k++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			System.out.printf("Case #%d: ",k+1);
			for(int j =0;j<x;j++)
				System.out.print("WE");
			for(int j =0;j<-x;j++)
				System.out.print("EW");
			for(int j =0;j<y;j++)
				System.out.print("SN");
			for(int j =0;j<-y;j++)
				System.out.print("NS");
			System.out.println();
		}
	}
}
