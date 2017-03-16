package round2014_1a;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.List;
import java.util.StringTokenizer;


public class problemB {

	private static int inst;
	private static char c;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
	    try {
			FileWriter w = new FileWriter("/home/nikos/output");
			BufferedWriter out = new BufferedWriter(w);
	    	//BufferedReader br = new BufferedReader(new FileReader("/home/nikos/input"));
	    	BufferedReader br = new BufferedReader(new FileReader("/home/nikos/Downloads/B-small-attempt0.in"));
	        StringBuilder sb = new StringBuilder();
	        String line;
	        line = br.readLine();
	        int size = Integer.parseInt(line);
	        for (inst = 1; inst < size+1; inst++) {
	        	checkBoard(out,br);
			}
			out.close();
	        br.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
	    }
	}

	private static void checkBoard(BufferedWriter out, BufferedReader br) throws IOException {
		List<String> l = new ArrayList<String>(); 
    	String line = br.readLine();
    	StringTokenizer tok = new StringTokenizer(line);
    	int a = Integer.parseInt(tok.nextToken());
    	int b = Integer.parseInt(tok.nextToken());
    	int c = Integer.parseInt(tok.nextToken());
    	int wins=0;
    	for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if((i&j)<c){
					wins++;
				}
			}
		}
    	System.out.println(wins);
		out.write("Case #"+inst+": "+wins+"\n" );
	}
}
