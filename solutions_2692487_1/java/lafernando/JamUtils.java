import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class JamUtils {

	public static Object[] getInput(String path) {
		try {
			FileInputStream fin = new FileInputStream(path);
			BufferedReader in = new BufferedReader(new InputStreamReader(fin));
			int count = Integer.parseInt(in.readLine());
			List<String> result = new ArrayList<String>();
			String line;
			while ((line = in.readLine()) != null) {
				result.add(line);
			}
			in.close();
			return new Object[] { count, result.toArray(new String[0]) };
		} catch (Exception e) {
			e.printStackTrace();
			throw new RuntimeException(e);
		}
	}
	
	public static void writeOutput(List<String> result, String path) {
		try {
			FileOutputStream fout = new FileOutputStream(path);
			BufferedWriter out = new BufferedWriter(new OutputStreamWriter(fout));
			for (int i = 0; i < result.size(); i++) {
				out.write("Case #" + (i + 1) + ": " + result.get(i) + "\n");
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			throw new RuntimeException(e);
		}
	}
	
}
