import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Tools<T>
{

	public static ArrayList<String[]> getInput(String filename) throws IOException
	{
		BufferedReader br = new BufferedReader(new FileReader(filename));

		ArrayList<String[]> output = new ArrayList<String[]>();

		String line;
		while ((line = br.readLine()) != null)
			output.add(line.split(" "));

		br.close();
		return output;
	}
	
	public static ArrayList<String> getInputSingle(String filename) throws IOException
	{
		BufferedReader br = new BufferedReader(new FileReader(filename));

		ArrayList<String> output = new ArrayList<String>();

		String line;
		while ((line = br.readLine()) != null)
			output.add(line);

		br.close();
		return output;
	}

	public static void saveOutput(String filename, ArrayList<String[]> output) throws IOException
	{
		BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
		
		for(int i=0; i<output.size();i++)
		{
			if(i!=0) bw.newLine();
			for(int j=0;j<output.get(i).length;j++)
			{
				if(j!=0) bw.write(" ");
				bw.write(output.get(i)[j]);				
			}
		}
		
		bw.close();
	}
	
	public static void saveOutputSingle(String filename, ArrayList<String> output) throws IOException
	{
		BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
		
		for(int i=0; i<output.size();i++)
		{
			if(i!=0) bw.newLine();
			bw.write(output.get(i));	
		}
		
		bw.close();
	}
}
