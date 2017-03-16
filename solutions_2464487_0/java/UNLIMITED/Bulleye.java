import java.io.*;
import java.net.URL;
import java.util.*;;


public class Bulleye {
	private static Scanner reader;
	private static BufferedWriter writer;
	
	public static void main(String[] args) throws IOException {
		reader = new Scanner(new File(new URL(FairAndSquare.class.
				getResource("."), "../input/test.in").getPath()));
		writer = new BufferedWriter(new FileWriter(new URL(FairAndSquare.class.
				getResource("."), "../output/test.out").getPath()));
		
		int numOfCases = reader.nextInt();
		reader.nextLine();
		for(int c = 1; c <= numOfCases; c++){
			long r = reader.nextLong();
			long t = reader.nextLong();
			long radius = r + 1;
			long accumu = 0;
			int round = 0;
			while(true){
				accumu += radius * radius - (radius - 1) * (radius - 1);
				if(accumu <= t){
					radius += 2;
					round ++;
				}
				else 
					break;
			}
			System.out.println("Case #" + c + ": " + round);
			writer.write("Case #" + c + ": " + round + "\n");
		}
		reader.close();
		writer.close();
	}

}
