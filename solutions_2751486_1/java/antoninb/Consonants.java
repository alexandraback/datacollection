import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;


public class Consonants {
	
	public static int nextGroup(int[] groups, int pos, int length){
		for(int i = pos; i < length; i++){
			if(groups[i] == 1) return i;
		}
		return -1;
	}

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		String fileName = "../A-large.in";
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int L = 1000000;
		
		int n = 0;
		
		int T = Integer.parseInt(br.readLine());
		int length = 0;
		char[] array = new char[L];
		for(int i = 0; i < T; i++){
			char c = (char) br.read();
			length = 0;
			while (c != ' '){
				array[length] = c;
				length++;
				c = (char) br.read();
			}
			n = Integer.parseInt(br.readLine());
			//System.out.println(n);
			
			int[] groups = new int[length];
			int win = 0;
			for(int j = 0; j < length; j++){
				groups[j] = 0;
				c = array[j];
				if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
					win++;
					if(win >= n){
						groups[j - n + 1] = 1;
					}
				}
				else win = 0;
			}
			
			long total = 0L;
			int nextgroup = -1;
			int j = 0;
			while(j < length){
				if(nextgroup >= j){
					total += (length - nextgroup - n + 1) * (nextgroup - j + 1);
					j = nextgroup + 1;
					continue;
				}
				nextgroup = nextGroup(groups, j, length);
				//System.out.println("new next " + nextgroup);
				if(nextgroup == -1) break;
			}
			//System.out.println(total);
			
			System.out.println("Case #" + (i + 1) + ": " + total);
		}
	}

}
