
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StreamTokenizer;

public class CJ20141CA extends AbstractCodejamProblem {
	
	@Override
	protected void executeInput() {
		try {
			StreamTokenizer aStrTokoniser = new StreamTokenizer(getInput());
			aStrTokoniser.ordinaryChar('/');
			aStrTokoniser.nextToken();
			
			int aTN = (int)aStrTokoniser.nval;
			setCaseNoExpected(aTN);
			
			for (int aTC = 0 ; aTC < aTN ; ++aTC) {
				startCaseNo(aTC + 1);

				aStrTokoniser.nextToken();
				long p = (long)aStrTokoniser.nval;
				aStrTokoniser.nextToken();
				aStrTokoniser.nextToken();
				long q = (long)aStrTokoniser.nval;
				
				pushData(new BigFraction(p, q));
				
				printResult();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private int _res = -1;
	private int _last = -1;
	public void pushData(BigFraction f) {
		if (isVerbose()) System.out.println(f);
		
		computeLast(new BigFraction(f.getNumerator(), f.getDenominator()));
		if (_last < 0 || _last > 40) return;
		
		if (f.equals(BigFraction.ZERO)) return;
		_res = 0;
		while (_res <= 40) {
			int r = f.compareTo(BigFraction.ONE);
			if (r >= 0) return;
			f = f.multiply(2);
			++_res;
		}
	}

	private void computeLast(BigFraction f) {
		if (f.equals(BigFraction.ZERO)) return;
		_last = 0;
		while (_last <= 40) {
			if (f.equals(BigFraction.ONE)) return;
			f = f.multiply(2);
			int r = f.compareTo(BigFraction.ONE);
			if (r > 0) f = f.subtract(BigFraction.ONE);
			//else if (r < 0) f = f.add(BigFraction.ONE);
			++_last;
		}
	}

	public void startCaseNo(int iCaseNo) {
		setCaseNo(iCaseNo);
		_res = -1;
		_last = -1;
	}
	
	public void printResult() {
		if (getCaseNo() < 1) return;
				
		PrintWriter aOut = new PrintWriter(getOutput());
		aOut.print("Case #" + getCaseNo() + ':');
		if (isVerbose()) System.out.print("Case #" + getCaseNo() + ':');
		
		aOut.print(' ');
		if (isVerbose()) System.out.print(' ');
		if (_res < 0 || _res > 40) {
			aOut.print("impossible");
			if (isVerbose()) System.out.print("impossible");
		} else {
			aOut.print(_res);
			if (isVerbose()) System.out.print(_res);
		}
		
		aOut.println();
		if (isVerbose()) System.out.println();
	}

}

