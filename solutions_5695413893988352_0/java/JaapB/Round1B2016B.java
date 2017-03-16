
// jaap@beetstra-it.nl

import static org.junit.Assert.assertEquals;

import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

public class Round1B2016B {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void tests() throws Exception {
		assertEquals("19 20", solve("1? 2?"));
		assertEquals("023 023", solve("?2? ??3"));
		assertEquals("0 0", solve("? ?"));
	}

	@Test
	public void testsD() throws Exception {
		assertEquals("05 00", solve("?5 ?0"));
		assertEquals("01929 02003", solve("?1?2? ?2??3"));
	}

	@Test
	public void tests1a() throws Exception {
		assertEquals("299 300", solve("?99 300"));
	}

	@Test
	public void tests1b() throws Exception {
		assertEquals("359 360", solve("?59 3?0"));
		assertEquals("360 359", solve("3?0 ?59"));
	}

	@Test
	public void tests1c() throws Exception {
		assertEquals("251 300", solve("?51 300"));
		assertEquals("250 300", solve("?50 300"));
	}

	@Test
	public void tests2() throws Exception {
		assertEquals("2999 3000", solve("??99 3?00"));
		assertEquals("3499 3500", solve("??99 3500"));
	}

	@Test
	public void tests2b() throws Exception {
		assertEquals("301 350", solve("301 ?50"));
		assertEquals("311 360", solve("311 ?60"));
	}

	@Test
	public void tests3a() throws Exception {
		assertEquals("300 250", solve("300 ?50"));
		assertEquals("250 300", solve("?50 300"));
	}

	@Test
	public void tests3b() throws Exception {
		assertEquals("260 310", solve("?60 310"));
		assertEquals("310 260", solve("310 ?60"));
	}

	@Test
	public void tests3c() throws Exception {
		assertEquals("311 261", solve("311 ?61"));
	}

	@Test
	public void tests3d() throws Exception {
		assertEquals("399 390", solve("?99 3?0"));
		assertEquals("390 399", solve("3?0 ?99"));
		assertEquals("309 300", solve("?09 300"));
	}

	@Test
	public void tests4a() throws Exception {
		assertEquals("1500 2000", solve("?500 2000"));
		assertEquals("1590 2000", solve("?5?0 20?0")); // 410
	}

	@Test
	public void tests4b() throws Exception {
		assertEquals("2500 2090", solve("?500 20?0")); // 410
	}

	@Test
	public void tests4c() throws Exception {
		assertEquals("2000 1590", solve("20?0 ?5?0")); // 410
		assertEquals("2090 2500", solve("20?0 ?500")); // 410
		assertEquals("2500 2099", solve("?500 20??"));
	}

	@Test
	public void tests5() throws Exception {
		assertEquals("910 909", solve("??0 9?9"));
	}

	@Test
	public void tests6() throws Exception {
		assertEquals("09 10", solve("?9 ?0"));
	}

	static String solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private final String cp, jp;

		public Solver(Scanner scanner) {
			this.cp = scanner.next();
			this.jp = scanner.next();
		}

		public String solve() {
			StringBuilder ct = new StringBuilder();
			StringBuilder jt = new StringBuilder();
			int compare = 0;
			for (int i = 0; i < cp.length(); i++) {
				final char chC = cp.charAt(i);
				final char chJ = jp.charAt(i);
				if (chC != '?' && chJ != '?') {
					ct.append(chC);
					jt.append(chJ);
					if (compare == 0 && chC != chJ)
						compare = (chC < chJ) ? -1 : +1;
					continue;
				}
				if (chC == '?' && chJ == '?') {
					if (compare != 0) {
						ct.append(compare >= 0 ? '0' : '9');
						jt.append(compare <= 0 ? '0' : '9');
					} else {
						switch (previewCompare(i, 0)) {
						case -1:
							compare = +1;
							ct.append('1');
							jt.append('0');
							break;
						case 0:
							ct.append('0');
							jt.append('0');
							break;
						case +1:
							compare = -1;
							ct.append('0');
							jt.append('1');
							break;
						}
					}
					continue;
				}
				if (chC == '?' && chJ != '?') {
					jt.append(chJ);
					if (compare != 0) {
						ct.append(compare > 0 ? '0' : '9');
						continue;
					}
					switch (previewCompare(i, +1)) {
					case 0:
						ct.append(chJ);
						break;
					case +1:
						if (chJ == '0')
							ct.append(chJ);
						else {
							compare = -1;
							ct.append(((char) (chJ - 1)));
						}
						break;
					case -1:
						if (chJ == '9')
							ct.append(chJ);
						else {
							compare = +1;
							ct.append(((char) (chJ + 1)));
						}
						break;
					}
				}
				if (chC != '?' && chJ == '?') {
					ct.append(chC);
					if (compare != 0) {
						jt.append(compare < 0 ? '0' : '9');
						continue;
					}
					switch (previewCompare(i, -1)) {
					case -1:
						if (chJ == '0')
							jt.append(chC);
						else {
							compare = +1;
							jt.append(((char) (chC - 1)));
						}
						break;
					case 0:
						jt.append(chC);
						break;
					case +1:
						if (chC == '9')
							jt.append(chC);
						else {
							compare = -1;
							jt.append(((char) (chC + 1)));
						}
						break;
					}
				}
			}
			return ct.append(' ').append(jt).toString();
		}

		protected int previewCompare(int i, int def) {
			int j = i + 1;
			while (j < cp.length() && cp.charAt(j) == '?' && jp.charAt(j) == '?')
				j++;
			if (j >= cp.length())
				return 0;
			if (cp.charAt(j) == '?' || jp.charAt(j) == '?')
				return 0;
			int dc = cp.charAt(j) - '0';
			int dj = jp.charAt(j) - '0';
			if (Math.abs(dc - dj) < 5)
				return 0;
			//
			if (Math.abs(dc - dj) != 5)
				return dc < dj ? -1 : +1;
			while (++j < cp.length()) {
				if (cp.charAt(j) == '?') {
					if (jp.charAt(j) == '?')
						return dc < dj ? -1 : +1;
					else
						return 0;
				} else if (jp.charAt(j) == '?')
					return 0;
				if (cp.charAt(j) != jp.charAt(j))
					return dc < dj ? 0 : +1;
			}
			return dc < dj ? -1 : def;
		}

	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			Object solution = new Solver(scanner).solve();
			System.out.println("Case #" + caseNr + ": " + solution);
		}
		if (scanner.hasNext())
			System.err.println("Warning! not at end of file");
	}
}
