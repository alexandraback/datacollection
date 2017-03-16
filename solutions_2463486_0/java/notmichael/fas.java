import java.util.*;

public class fas {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in); 
		int cases = Integer.parseInt(in.nextLine());
		for (int i=0; i<cases; i++) {
			int min = in.nextInt();
			int max = in.nextInt();
			int pals = 0;
			for (int j=(int)Math.sqrt(min)-1; j<=max; j++) {
				String num = "" + j;
				if (pal(num)) {
					int num_2 = j*j;
					String num2 = "" + num_2;
					if (num_2>=min && num_2<=max && pal(num2)) {
						pals++;
					}
				}
			}
			System.out.println("Case #" + (i+1) + ": " + pals);
			if (i!=cases-1) {
				in.nextLine();
			}
		}
	}
	
	private static boolean pal(String arg0) {
		char[] arr = arg0.toCharArray();
		for (int i=0; i<(arr.length/2)+1; i++) {
			if (arr[i]!=arr[arr.length-1-i]) {
				return false;
			}
		}
		return true;
	}

}
