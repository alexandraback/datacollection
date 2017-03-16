import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;


public class LaDanceGoogler {

	public static void main(String[] args) throws IOException {
		Path input = Paths.get("/Users/mdymczyk/google-codejam/Tongues/src/input.in");
		List<String> lines = Files.readAllLines(input, Charset.forName("UTF-8"));
		lines.remove(0);
		int i = 1;
		for(String line : lines) {
			StringBuilder sb = new StringBuilder();
			sb.append("Case #"+i+": ");
			String[] numbers = line.split(" ");
			int specials = Integer.parseInt(numbers[1]);
			int searchedValue = Integer.parseInt(numbers[2]);
			int results = 0;
			for(int j = 3 ; j < numbers.length ; j++) {
				int score = Integer.parseInt(numbers[j]);
				for(int s = searchedValue ; s <= 10 ; s++){
					int rest = score-s;
					if(rest-2*s == 0 ||
					   (rest-2*s+1 == 0 && score-1 >= 0) ||
					   (rest-2*s+2 == 0 && score-1 >= 0)) {
						results++;
						break;
					} else if(specials > 0 && ((rest-2*s+3 == 0 && score-1 >= 0) ||
							   				   (rest-2*s+4 == 0 && score-2 >= 0))) {
						results++;
						specials--;
						break;
					}
				}
			}
			sb.append(results);
			System.out.println(sb);
			i++;
		}
	}
	
}
