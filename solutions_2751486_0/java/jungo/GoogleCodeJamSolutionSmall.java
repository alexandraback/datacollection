package R1C2013QA;



import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class GoogleCodeJamSolutionSmall {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		final String filePath = "src/R1C2013QA/";
		final String inputFileName = "input";
		final String outputFileName = "output";
		final BufferedReader in = new BufferedReader(new InputStreamReader(new DataInputStream(new FileInputStream(filePath+inputFileName))));
		final BufferedWriter out = new BufferedWriter(new FileWriter(filePath+outputFileName));
		final InputHandler inputHandler = new InputHandler(in);		
		final int T = inputHandler.readInt();
		final Algo algo = new Algo(inputHandler);
		for (int i = 0; i < T; i++) {
			out.write("Case #"+(i+1)+": "+algo.solveNext()+"\n");
		}
		in.close();
		out.close();
	}
	public static class InputHandler{
		BufferedReader in;
		InputHandler(BufferedReader in){
			this.in = in;
		}
		String readLine(){
			try {
				return in.readLine();
			} catch (Exception e) {e.printStackTrace();return null;}
		}
		int readInt(){
			try {
				return Integer.parseInt(in.readLine());
			} catch (Exception e) {e.printStackTrace();return 0;}
		}
		long readLong(){
			try {
				return Long.parseLong(in.readLine());
			} catch (Exception e) {e.printStackTrace();return 0;}
		}
		double readDouble(){
			try {
				return Double.parseDouble(in.readLine());
			} catch (Exception e) {e.printStackTrace();return 0;}
		}
		int[] readIntArray(){
			String s[] = null;
			try {
				s = in.readLine().split(" ");
			} catch (Exception e1) {e1.printStackTrace();}
			int [] arr = new int[s.length];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = Integer.parseInt(s[i]);
			}
			return arr;
		}
		long[] readLongArray(){
			String s[] = null;
			try {
				s = in.readLine().split(" ");
			} catch (Exception e1) {e1.printStackTrace();}
			long [] arr = new long[s.length];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = Long.parseLong(s[i]);
			}
			return arr;
		}
		double[] readDoubleArray(){
			String s[] = null;
			try {
				s = in.readLine().split(" ");
			} catch (Exception e1) {e1.printStackTrace();}
			double [] arr = new double[s.length];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = Double.parseDouble(s[i]);
			}
			return arr;
		}
	}
	
	public static class Algo{
		InputHandler inputHandler;
		Algo(InputHandler inputHandler){
			this.inputHandler = inputHandler;
		}
		String solveNext(){
			String[] br = inputHandler.readLine().split(" ");
			String s = br[0];
			int n = Integer.parseInt(br[1]);
			int res = 0;
			for (int i = 0; i < s.length(); i++) {
				for (int j = i; j < s.length(); j++) {
					if(j - i +1 >= n){
						int t = 0;
						boolean good = false;
						for (int k = i; k <= j; k++) {
							if(f(s.charAt(k))){
								t++;
								if(t >= n){
									good = true;
								}
							}
							else{
								t=0;
							}
						}
						if(good){
							res++;
						}
					}
				}
			}
			return ""+res;
		}
		
		boolean f(char c){
			switch (c) {
			case 'a':
			case 'u':
			case 'i':
			case 'o':
			case 'e':
				return false;

			default:
				return true;
			}
		}
	}
	
	
		
	
}