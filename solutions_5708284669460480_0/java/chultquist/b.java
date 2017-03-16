import java.util.Scanner;

public class b {
	private static StringBuilder sb = new StringBuilder();
	private static int total = 0;
	private static int max = 0;
	private static int count = 0;
	private static String keyboard;
	private static String target;
	private static int s = 0;
	
	private static void go()
	{
		if (sb.length() < s) {
			for (int i = 0; i < keyboard.length(); i++) {
				sb.append(keyboard.charAt(i));
				go();
				sb.deleteCharAt(sb.length() - 1);
			}
		}
		else {
			count++;
			int num = 0;
			int i = sb.indexOf(target);
			while (i != -1) {
				num++;
				i = sb.indexOf(target, i + 1);
			}
			if (num > max) {
				max = num;
			}
			total += num;
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int caseNum = 1; caseNum <= t; caseNum++) {
			int k = sc.nextInt();
			int l = sc.nextInt();
			s = sc.nextInt();
			keyboard = sc.next();
			target = sc.next();
			count = max = total = 0;
			go();
			//System.err.println(count + " " + total + " " + max);
			System.out.println("Case #" + caseNum + ": " + (((double) max) - ((double) total) / ((double) count)));
		}
	}
}
