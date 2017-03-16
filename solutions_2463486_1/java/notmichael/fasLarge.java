import java.util.*;

public class fasLarge {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		ArrayList<Long> al = new ArrayList<Long>();
		for (long i=0; i<10000001; i++) {
			String num = "" + i;
			if (pal(num)) {
				long num_2 = i*i;
				String num2 = "" + num_2;
				if (pal(num2)) {
					al.add(num_2);
				}
			}
		}
		for (int i=0; i<cases; i++) {
			long min = in.nextLong();
			long max = in.nextLong();
			int pals = 0;
			for (Long ind: al) {
				if (ind>=min && ind<=max) {
					pals++;
				}
				else if (ind>max) {
					break;
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
