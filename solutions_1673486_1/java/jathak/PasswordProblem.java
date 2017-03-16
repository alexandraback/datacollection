import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.text.DecimalFormat;

//DancingGooglers.java
//Completes the Dancing with Googlers problem for Google Code Jam 2012
//By Jack Thakar
//Coded in Java using Eclipse 3.7
public class PasswordProblem {
	public static void main(String[] args){
		String input = readFile("A-large.in");
		String[] lines = input.split(System.lineSeparator());
		String output = "";
		int count =1;
		for(int i=1;i+1<lines.length;i+=2){
			String line = lines[i];
			String line2 = lines[i+1];
			Case c = (new PasswordProblem()).new Case(line,line2);
			output+="Case #"+count+": ";
			output+=c.getSolution();
			count++;
			if(i+1<lines.length-1) output+=System.lineSeparator();
		}
		writeFile("A-large.out",output);
	}
	class Case{
		int x;
		int y;
		double lowest;
		double[] probs;
		public Case(String line1,String line2){
			String[] splits = line1.split(" ");
			String[] splits2 = line2.split(" ");
			x = Integer.parseInt(splits[0]);
			y = Integer.parseInt(splits[1]);
			probs = new double[x];
			for(int i=0;i<probs.length;i++){
				probs[i] = Double.parseDouble(splits2[i]);
			}
		}
		public String getSolution(){
			double e = y+2;
			double trueProb = 1.0;
			for(double p:probs){
				trueProb*=(p);
			}
			double type = trueProb*(y-x+1)+(1-trueProb)*(2*y-x+2);
			double backAll = x+y+1;
			lowest = Math.min(type, e);
			lowest = Math.min(lowest, backAll);
			for(int i=1;i<x;i++){
				lowest = Math.min(lowest, getBacks(i));
			}
			return formatDouble(lowest);
		}
		private double getBacks(int backs) {
			double prob = 1;
			int chars = x-backs;
			for(int i=0;i<x-backs;i++){
				prob*=(probs[i]);
			}
			double result = prob*(backs+y-(chars)+1)+(1-prob)*(backs+y-(chars)+y+2);
			return result;
		}
		public String formatDouble(double d){
			DecimalFormat df = new DecimalFormat("0.000000");
			String string = (df.format(d));
			return string;
		}
	}

	private static String readFile(String name){
		File file = new File("input"+File.separator+name);
		Charset charset = Charset.forName("ASCII");
		String text = "";
		try (BufferedReader reader = Files.newBufferedReader(file.toPath(), charset)) {
			String line = null;
			while ((line = reader.readLine()) != null) {
				text+=line+System.lineSeparator();
			}
		} catch (IOException e) {
		}
		return text;
	}
	private static void writeFile(String name, String data){
		File file = new File("output"+File.separator+name);
		Charset charset = Charset.forName("ASCII");
		try (BufferedWriter writer = Files.newBufferedWriter(file.toPath(), charset)) {
			writer.write(data, 0, data.length());
		} catch (IOException e) {
		}
	}
}
