import java.util.*;

class QA{
	
	static final String map = "ynficwlbkuomxsevzpdrjgthaq";

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int kases = sc.nextInt();
		sc.nextLine();
		for(int k = 1; k<=kases; k++){
			System.out.print("Case #"+k+": ");
			String[] s = sc.nextLine().split("\\s");
			for(String w:s){
				for(char c: w.toCharArray())
					System.out.print((char)(map.indexOf(c)+97));
				System.out.print(' ');
			}
			System.out.println("");
		}
	}
}

