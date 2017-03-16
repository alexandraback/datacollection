package abc.template;

import java.util.concurrent.Callable;

public abstract class AbstractCase implements Callable<String> {

	public final int caseNumber;
	private String result;

	public AbstractCase(int caseNumber) {
		this.caseNumber = caseNumber;
	}

	@Override
	public String call() throws Exception {
		StringBuilder sb = new StringBuilder();
		sb.append("Case #").append(caseNumber).append(": ").append(doCalculation());
		result = sb.toString();
		return result;
	}

	protected abstract String doCalculation();

	public String getResult() {
		return result;
	}
}
