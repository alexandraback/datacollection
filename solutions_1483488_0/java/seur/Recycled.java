
public class Recycled {
	static String test = "4\n1 9\n10 40\n100 500\n1111 2222";
	static String val = "50\n187 934\n138 960\n117 921\n1 2\n171 919\n152 967\n903 903\n137 953\n144 984\n182 988\n144 955\n169 993\n186 920\n143 918\n154 923\n154 959\n577 592\n146 944\n149 981\n128 979\n176 910\n251 674\n136 967\n169 976\n48 82\n100 100\n160 982\n325 325\n10 99\n139 981\n119 927\n189 922\n10 99\n183 922\n150 963\n133 997\n133 980\n166 991\n29 82\n123 967\n116 933\n171 968\n180 928\n171 944\n155 940\n164 941\n175 939\n133 926\n1 7\n129 327\n";
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
