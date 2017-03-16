
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static String solve(int num, int index){
		String result = "Case #" + (index+1) + ": ";
		if(num == 0)
			return result + "INSOMNIA";
		boolean[] hash = new boolean[10];
		int n = num, i = 1, count = 0;
		while(count < 10){
			while(n > 0){
				int mod = n % 10;
				n /= 10;
				if(!hash[mod]){
					hash[mod] = true;
					++count;
					if(count == 10){
						return result + num * i;
					}
				}
			}
			n = num * ++i;
		}
		return "";
	}
	
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new FileInputStream(new File("A-small-attempt1.in")));
		FileOutputStream fo = new FileOutputStream(new File("output.out"));
		int t = scanner.nextInt();
		for(int i = 0; i < t; ++i){
			String result = solve(scanner.nextInt(), i);
			fo.write((result+"\n").getBytes());
		}
		fo.flush();
		fo.close();
	}

}
