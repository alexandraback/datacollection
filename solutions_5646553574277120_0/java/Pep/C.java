import java.util.ArrayList;
import java.util.List;

import com.joseprio.codejam.Solver;


public class C extends Solver {

	@Override
	public void solve(int numCase) {
		int[] params = readInts();
		int maxCoins = params[0];
		int differentDenominations = params[1];
		int maxValue = params[2];
		int[] denominations = readInts();

		// Construct first

		List<DenominationAmount> denominationAmounts = new ArrayList<DenominationAmount>();
		int currentDenominationsMax = 0;
		for (int c=0;c<denominations.length;c++) {
			DenominationAmount current = new DenominationAmount();
			current.denomination = denominations[c];
			denominationAmounts.add(current);
			currentDenominationsMax += denominations[c]*maxCoins;
		}
		
		if (currentDenominationsMax > maxValue) {
			currentDenominationsMax = maxValue;
		}
		
		for (int c=1;c<=maxValue;c++) {
			// Try building
			
			boolean found = false;
			
			int currentAmount = 0;
			boolean foundEnd = false;
			
			while (!found && !foundEnd) {
				currentAmount += incrementDenominations(denominationAmounts, 0, maxCoins);
				if (currentAmount == c) {
					found = true;
				} else {
					// See if we reached the end
					foundEnd = true;
					for (int d=0;d<denominationAmounts.size()&&foundEnd;d++) {
						if (denominationAmounts.get(d).amount > 0) {
							foundEnd = false;
							
							if (denominationAmounts.get(d).denomination > c) {
								// We're currently checking larger numbers
								foundEnd = true;
								break;
							}
						}
					}				
				}
			}
			
			if (!found) {
				// Add this value!
				DenominationAmount newDenomination = new DenominationAmount();
				newDenomination.denomination = c;
				if (c> denominationAmounts.get(denominationAmounts.size()-1).denomination) {
					denominationAmounts.add(newDenomination);
				} else {
					// Find inserting
					int pos = 0;
					while (denominationAmounts.get(pos).denomination < c) {
						pos++;
					}
					denominationAmounts.add(pos, newDenomination);
				}
			}
			
			// Reset amounts
			for (int d=0;d<denominationAmounts.size();d++) {
				denominationAmounts.get(d).amount = 0;
			}
		}
		
		printLine(denominationAmounts.size()-differentDenominations);
	}
	
	int incrementDenominations(List<DenominationAmount> denominationAmounts, int pos, int maxCoins) {
		int result = 0;
		denominationAmounts.get(pos).amount++;
		result += denominationAmounts.get(pos).denomination;
		if (denominationAmounts.get(pos).amount > maxCoins) {
			result -= denominationAmounts.get(pos).amount * denominationAmounts.get(pos).denomination;
			denominationAmounts.get(pos).amount = 0;
			if (pos < denominationAmounts.size() - 1) {
				result += incrementDenominations(denominationAmounts, pos+1, maxCoins);
			}
		}
		
		return result;
	}
}

class DenominationAmount {
	int denomination;
	int amount = 0;
}