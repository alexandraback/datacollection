import java.util.*;

public class A {

	public static void main(String[] args) {		
		Scanner in = new Scanner(System.in);
		char[] map = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
		int n = Integer.parseInt(in.nextLine());
		int i,j;
		for (i=0;i<n;i++) {
			String line = in.nextLine();
			System.out.print("Case #"+(i+1)+": ");
			for (j=0;j<line.length();j++) {
				if (line.charAt(j)!=' ')
					System.out.print(map[line.charAt(j)-97]);
				else
					System.out.print(" ");
			}
			System.out.println();
		}
	}

}
