package codejam0102;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static int solve(boolean[] str, int index, int count){
		if(str[0]){
			for(int i = 0; i < index; ++i){
				if(str[i])
					str[i] = false;
				else
					break;
			}
			return solve(str, index, ++count);
		}
		else{
			for(int i = 0; i <= index / 2; ++i){
				boolean tmp = str[i];
				str[i] = !str[index - i];
				str[index - i] = !tmp;
			}
			boolean tag = false;
			for(int i = index; i >= 0; --i){
				index = i;
				if(!str[i]){
					tag = true;
					break;
				}
			}
			if(tag)
				return solve(str, index, ++count);
			else
				return count;
		}
	}
	
	public static int solve(boolean[] str){
		int index = str.length - 1;
		boolean tag = false;
		for(int i = str.length - 1; i >= 0; --i){
			index = i;
			if(!str[i]){
				tag = true;
				break;
			}
		}
		if(tag)
			return solve(str, index, 1);
		else
			return 0;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new FileInputStream(new File("B-large.in")));
		FileOutputStream fo = new FileOutputStream(new File("output.out"));
		int t = scanner.nextInt();
		for(int i = 1; i <= t; ++i){
			String input = scanner.next();
			boolean[] str = new boolean[input.length()];
			for(int j = 0; j < input.length(); ++j){
				if(input.charAt(j) == '+')
					str[j] = true;
			}
			int result = solve(str);
			fo.write(("Case #"+i+": "+result+"\n").getBytes());
		}
		fo.flush();
		fo.close();
	}

}
