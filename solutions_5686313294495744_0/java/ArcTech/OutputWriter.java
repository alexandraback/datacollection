import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class OutputWriter {
	BufferedWriter r;
	public OutputWriter(String filename) throws IOException
	{
		r = new BufferedWriter(new FileWriter(filename));
	}
	
	public void write(String s) throws IOException
	{
		r.write(s);
	}
	
	public void writeCase(String s, int num) throws IOException
	{
		s = "Case #" + num+": " + s;
		r.write(s);
	}
	
	public void close() throws IOException
	{
		r.close();
	}
	
	
}
