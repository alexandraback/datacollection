import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class Lottery {

	
	public static void main(String[] args) throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader("/Users/ray/Desktop/Bin.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("/Users/ray/Desktop/Bout.out"));
		String line = null;
		ArrayList<Integer> list = new ArrayList<Integer>();
		int N = 1;
		line = reader.readLine();
		while ((line = reader.readLine()) != null) {
		    String[] s = line.split(" ");
		    int x = Integer.valueOf(s[0]);
		    int y = Integer.valueOf(s[1]);
		    int z = Integer.valueOf(s[2]);
		    int wins = lottery(x,y,z);
		    writer.write("Case #"+N+": "+wins+"\r\n");
		    N++;
		}
		writer.close();
		
	}
	public static int lottery(int x, int y, int z){
		int count = 0;
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				for(int k = 0; k < z;k++){
					if((i&j)==k) count++;
				}
			}
		}
		return count;
	}
}
