import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;


public class Fractiles {
	public static void main(String[] args){
		File a = new File("D-large.in");
		Scanner input = null;
		try {
			input = new Scanner(a);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//Scanner input = new Scanner(System.in);
		
		File b = new File("D-output.txt");
		FileWriter fw = null;
		try {
			fw = new FileWriter(b);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int number = input.nextInt();
		input.nextLine();
		int cases = number;
		
		while(number > 0){
			int k = input.nextInt();
			int c = input.nextInt();
			int s = input.nextInt();
			
			long[] list = new long[s];
			
			boolean result = true;
			if (k != s){
				if (c == 1){
					if (s < k){
						 result = false;
					}
				} else {
					int count = 0;
					int kcount = 0;
					long index = 2;
					while (count < s && kcount < k){
						list[count] = index;
						if (kcount + 2 > k){
							index += 2*k + 1;
							kcount += 1;
						} else {
							index += 2*k + 2;
							kcount += 2;
						}
						count++;
					}
					if (kcount < k){
						result = false;
					}
				}
			} else {
				for (int i = 0; i < list.length; i ++){
					list[i] = i + 1;
				}
			}
			
			try {
				if(result){
					fw.write("Case #" + (cases - number + 1) + ": ");
					for (int i = 0; i < list.length; i++){
						if(list[i] != 0){
							fw.write(list[i] + " ");
						}
					}
					fw.write("\n");
				} else {
					fw.write("Case #" + (cases - number + 1) + ": IMPOSSIBLE\n");
				}
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			number--;
		}
		
		try {
			fw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
