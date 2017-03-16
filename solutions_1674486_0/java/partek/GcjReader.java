import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;


public class GcjReader extends BufferedReader {

	private List<String> bufferedInput = new LinkedList<String>();
	
	public GcjReader(Reader in) {
		super(in);
	}
	
	public String readWord() throws IOException {
		if(bufferedInput.size() == 0) {
			String line = readLine();
			if(line == null) {
				return null;
			}
			String[] words = line.split(" ");
			bufferedInput.addAll(Arrays.asList(words));
		}
		String toReturn = bufferedInput.remove(0);
		if(toReturn.length() == 0) {
			toReturn = readWord();
		}
		return toReturn;
	}
	
	public int readInt() throws IOException {
		return Integer.valueOf(readWord());
	}
	
	public double readDouble() throws IOException {
		return Double.valueOf(readWord());
	}

}
