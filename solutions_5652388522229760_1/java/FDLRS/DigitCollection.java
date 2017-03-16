package be.filip.gcj2016;

public class DigitCollection {

	private boolean[] digits;

	private DigitCollection(boolean[] _digits) {
		assert (_digits.length == 10);
		this.digits = createEmptyDigits(10, false);

		for (int i = 0; i < 10; i++) {
			digits[i] = _digits[i];
		}
	}

	private static boolean[] createEmptyDigits(int numberOf, boolean value) {
		boolean digits[] = new boolean[numberOf];

		for (int i = 0; i < digits.length; i++) {
			digits[i] = value;
		}

		return digits;
	}

	public static DigitCollection createEmpty() {
		return new DigitCollection(createEmptyDigits(10, false));
	}
	
	public static DigitCollection createFromNumber(long number) {
		boolean tempDigits[] = createEmptyDigits(10, false);

		long moduloNumber = 10;
		long remainderNumber = number;

		
		while (remainderNumber > 0) {
			
			long tempNumber = remainderNumber % moduloNumber;
			assert tempNumber < 10;
			
			tempDigits[(int) tempNumber] = true;

			remainderNumber = remainderNumber - tempNumber;
			assert (remainderNumber % 10) == 0;

			remainderNumber = remainderNumber / 10;
		}

		return new DigitCollection(tempDigits);
	}

	public DigitCollection combine(DigitCollection col) {
		boolean combinedDigits[] = new boolean[10];

		for (int i = 0; i < 10; i++) {
			combinedDigits[i] = this.digits[i] || col.digits[i];
		}
		return new DigitCollection(combinedDigits);
	}

	public boolean isFull() {
		
		for (int i = 0; i < digits.length; i++) {
			if(digits[i] == false)
			{
				return false;
			}
		}
		
		return true;
	}

}
