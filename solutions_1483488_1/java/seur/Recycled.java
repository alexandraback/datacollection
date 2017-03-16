
public class Recycled {
	static String test = "4\n1 9\n10 40\n100 500\n1111 2222";
	static String val = "50\n1049802 1946314\n1019242 1999787\n332841 815293\n1443938 1907548\n5125 9748\n1037227 1960407\n1053187 1952673\n1043225 1910832\n100000 100000\n351349 556470\n68 80\n116204 961036\n504 844\n1086291 1964681\n100000 999999\n21207 36868\n38 50\n54134 64312\n1526010 1747987\n1736162 1783904\n100000 100001\n10486 11651\n1820549 1880905\n1097653 1971323\n1087139 1993152\n1090695 1961364\n4541 8166\n1046409 1315179\n897387 957090\n1024733 1940114\n1000415 1945733\n534 685\n1019180 1921115\n1076227 1860470\n502 748\n10000 99999\n7821 9852\n353200 479493\n3 8\n4977 7152\n36645 46007\n1166938 1166938\n45802 72650\n1085149 1982470\n1037947 1935060\n1634839 1802893\n1056643 1989496\n1001424 1975827\n752384 752384\n778195 833983\n";
	public static void main(String[] args) {
		String[][] cases = CaseReader.getCases(val, 1);
		for (int i = 0;i < cases.length;i++)
		{
			parseCase(i + 1, cases[i][0]);
		}
	}

	static void parseCase(int caseNum, String caseString) {
		String[] args = caseString.split(" ");
		int current, recycles = 0;
		int leftMin = Integer.parseInt(args[0]);
		int rightMax = Integer.parseInt(args[1]);
		current = leftMin;
		int currentLen = (int) Math.pow(10,(int)(Math.log10(leftMin)));
		int nextLen = currentLen * 10;
		while (current <= rightMax)
		{
			recycles += recycledCount(current, leftMin, rightMax, currentLen);
			current++;
			if (current == nextLen) {
				nextLen *= 10;currentLen *= 10;
			}
		}
		System.out.println("Case #" + caseNum + ": " + recycles);
	}

	static int recycledCount(int current, int leftMin, int rightMax, int len) {
		int working = moveIt(current, len);
		int c = 0;/*
		if (current == 29 && antimax == 10)
			return -1;*/
		while (working != current) {
			if (working >= leftMin && current <= rightMax && working < current) {
				c++;
			}
			working = moveIt(working, len);
		}
		return c;
	}

	static int moveIt(int v, int e10) {
		return v / 10 + (e10 * (v % 10));
	}
}
