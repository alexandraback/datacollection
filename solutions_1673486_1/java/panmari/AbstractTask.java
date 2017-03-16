import java.util.ArrayList;
import java.util.List;


public abstract class AbstractTask {

	protected static Casifier casifier;
	protected String[] cases;
	protected static List<String> result = new ArrayList<String>();
	
	/**
	 * A task always consists of an input file, which must be read & split into cases.
	 * This Class provides easy access to the casifier, which handles this task & the resulting cases.
	 * It also automatically writes the output & calls the compute method
	 * @param inputFile the file with the input
	 */
	public AbstractTask(String inputFile) {
		casifier = new Casifier(inputFile);
		cases = casifier.getInputAsArray();
		compute();
		writeOutput(result);
	}
	
	abstract protected void compute();
	
	/**
	 * Writes the result to {inputFile}.out
	 * @param result
	 */
	protected void writeOutput(List result) {
		casifier.writeOutput(result);
	}
}
