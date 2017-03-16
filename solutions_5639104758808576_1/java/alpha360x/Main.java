import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
	
	
	
	public int solve(int length, String audiences) {
		int [] as = new int [length + 1];
		for (int i = 0; i < length + 1; i ++) {
			as[i] = (int)(audiences.charAt(i) - '0');
		}
		
		if (length == 0) {
			return 0;
		}
		
		int currentStands = as[0];
		int invite = 0;
		for (int i = 1; i < length + 1; i ++) {
			int p = as[i];
			if (p == 0) continue;
			if (currentStands < i) {
				int diff = i - currentStands;
				invite += diff;
				currentStands += diff + as[i];
			} else {
				currentStands += as[i];
			}
		}
		
		return invite;
	}
	
	
	public Main() throws IOException {
		
		Scanner scanner = new Scanner(System.in);
		FileWriter fWriter = new FileWriter(new File("C:\\Users\\Ye\\result.txt"));
		
		int count = scanner.nextInt();
		StringBuilder content = new StringBuilder();
		for (int i = 0; i < count; i++) {
			int result = solve(scanner.nextInt(), scanner.next());
			content.append("Case #").append(i + 1).append(": ")
				.append(result).append("\r\n");
		}
		
		// System.out.print(content.toString());
		
		fWriter.write(content.toString());
		fWriter.flush();
		fWriter.close();
	}
	
	public static void main(String [] args) {
		try {
			new Main();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
