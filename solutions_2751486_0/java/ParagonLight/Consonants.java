package Round1C;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Consonants {

	/**
	 * @param args
	 */

	public static boolean isVowels(char letter) {
		if (letter == 'a')
			return true;
		else if (letter == 'e')
			return true;
		else if (letter == 'i')
			return true;
		else if (letter == 'o')
			return true;
		else if (letter == 'u')
			return true;
		else
			return false;
	}

	public static ArrayList prepare(ArrayList list, String string, int n) {
		char[] chars = string.toCharArray();
		boolean flag = false;
		int start = 0;
		for (int i = 0; i < chars.length; i++) {
			if (isVowels(chars[i]) || i == chars.length - 1) {
				int length = 0;
				if(i == chars.length - 1){
					if(!isVowels(chars[i]))
						length = i - start + 1;
					else
						length = i - start;	
				}else
					length = i -1 - start + 1;
				
				if (length >= n) {
					int[] element = new int[2];
					element[0] = start;
					if(i == chars.length - 1 && !isVowels(chars[i]))
						element[1] = i;
					else
						element[1] = i - 1;
//					element[2] = element[1] - start + 1;
					list.add(element);					
				}
				start = i + 1;
			}
		}
		return list;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br;
		try {
			int N;
			br = new BufferedReader(new FileReader("A-small-attempt4.in.txt"));
			PrintWriter pw = new PrintWriter(new File("output"));
			String line = br.readLine();
			N = Integer.parseInt(line);
			int count = 1;
			while (count <= N) {
				line = br.readLine();
				String[] strs = line.split(" ");
				String name = strs[0];
				int n = Integer.parseInt(strs[1]);
				int nValue = 0;
				ArrayList list = new ArrayList();
				list = prepare(list, name, n);
				System.out.println(list.size());
				if(list.isEmpty()){
					nValue = 0;
				}else{				
					int i = 0;				
					int position = 0;
					while(i < list.size()){
						int[] element = (int[])list.get(i);
						int startP = element[0];
						int endP = element[1];
//						int length = element[2];
						nValue += (startP - position + 1) * (name.length() - (startP + n) + 1);
						startP += 1;
						while(startP < name.length() && (endP - startP + 1) >= n){
							nValue += (name.length() - (startP + n) + 1);						
							startP += 1;
						}
						i ++;
						position = startP;						
					}
					
					
					
				}
				
				
				
				System.out.println("Case #" + count + ": " + nValue);
				pw.write("Case #" + count + ": " + nValue + "\n");
				pw.flush();
				count++;
			}			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
