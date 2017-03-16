import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;


public class Brattleship {

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        String fileName = "A-small-attempt0.in";
        PrintWriter writer = new PrintWriter("A-small-attempt0.out", "UTF-8");
        try {
            List<String> lines = Files.readAllLines(Paths.get(fileName), Charset.defaultCharset());
            int t = Integer.parseInt(lines.get(0));
            for (int i = 1; i <= t; i++) {
            	String[] line = lines.get(i).split(" ");
            	int r = Integer.parseInt(line[0]);
            	int c = Integer.parseInt(line[1]);
            	int w = Integer.parseInt(line[2]);
                writer.println("Case #"+(i)+": "+brattleship(r,c,w));
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
	}
	
	public static int brattleship(int r, int c, int w){
		if(w == 1) return r*c;
		if(w == c) return r+c-1;
		double part = (c*1.0)/w;
		return (int)(Math.ceil(part) + w - 1);
	}

}
