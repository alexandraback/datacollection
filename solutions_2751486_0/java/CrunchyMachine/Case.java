package abc;

import java.util.Set;

import abc.template.AbstractCase;

public class Case extends AbstractCase {

	private final char[] text;
	private final long n;
	private final Set<Character> vowels;

	public Case(int caseNumber, Set<Character> vowels, String text, long number) {
		super(caseNumber);
		this.vowels = vowels;
		this.text = text.toCharArray();
		this.n = number;
	}

	@Override
	protected String doCalculation() {
		long total = 0;
		for (int i = text.length; i >= 0; i--) {
			long result = tryWithRearOffset(i);
			if (result == 0) {
				break;
			}
			total += result;
		}
		return String.valueOf(total);
	}

	private long tryWithRearOffset(int rearOffset) {
		long total = 0;
		for (int i = 0; i < rearOffset; i++) {
			if (!hasConsecutiveConsonants(i, rearOffset)) {
				return total;
			}
			total++;
		}
		return total;
	}

	private boolean hasConsecutiveConsonants(int frontOffset, int rearOffset) {
		long currentSequence = 0;
		for (int i = frontOffset; i < rearOffset; i++) {
			if (vowels.contains(text[i])) {
				currentSequence = 0;
			}
			else {
				currentSequence++;
				if (currentSequence == n) {
					return true;
				}
			}
		}
		return false;
	}
}
