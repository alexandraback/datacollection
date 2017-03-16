
public class CaseReader {
	public static String[][] getCases(String s, int linesPerCase) {
		int cases = Integer.parseInt(s.split("\n")[0]);
		String[][] ret = new String[cases][linesPerCase];
		String[] v = s.split("\n");
		for (int i = 0;i < cases;i++)
		{
			for (int j = 0;j < linesPerCase;j++) {
				ret[i][j] = v[i * linesPerCase + j + 1];
			}
		}
		return ret;
	}
}
