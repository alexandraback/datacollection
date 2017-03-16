import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class PartElf {
	
	public static void main(String[] args) throws IOException {
		System.out.println(args[0]);
		System.out.println(args[1]);
		
		Set<Long> powersOfTwo = new HashSet<Long>();
		long i =1;
		powersOfTwo.add(i);
		for(int j=0; j<39; j++) {
			i*=2;
			powersOfTwo.add(i);
		}
		
		
		Scanner s = new Scanner(new File(args[0]));
		File out = new File(args[1]);
		if(!out.exists()) {
			out.createNewFile();
		} else {
			out.delete();
			out.createNewFile();
		}
		FileWriter fw = new FileWriter(out);
		
		int numCases = s.nextInt();
		for(int j=1; j<=numCases; j++) {
			String fraction = s.next();
			String[] fractionParts = fraction.split("/");
			long num = Long.parseLong(fractionParts[0]);
			long den = Long.parseLong(fractionParts[1]);
			
			if(!powersOfTwo.contains(den)) {
				fw.write("Case #"+j+": impossible\n");
				continue;
			}
			
			int count = 0;
			while(num < den) {
				num = (num*2);
				count++;
			}
			
			fw.write("Case #"+j+": " + count +"\n");
			
		}
		fw.close();
	}

}
