import java.util.Scanner;

public class TheLastWord {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = Integer.parseInt(in.nextLine());
		for (int t = 0; t < T; t++) {
			char[] inp = in.nextLine().toCharArray();
			StringBuilder sb = new StringBuilder("");
			sb.append(inp[0]);
			for (int i = 1; i < inp.length; i++) {
				if(sb.charAt(0)<=inp[i])
					sb.insert(0, inp[i]);
				else
					sb.append(inp[i]);
			}
			System.out.println("Case #"+(t+1)+": "+sb);
		}
		
	}

}
