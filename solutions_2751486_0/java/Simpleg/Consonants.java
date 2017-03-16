import java.util.*;
import java.io.*;
import java.lang.*;

public class Consonants {	
	
    public static void main(String[] args) throws IOException {

        // Scanner in = new Scanner(new File("input.txt"));
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
        // Scanner in = new Scanner(new File("A-large.in"));
		FileWriter fw = new FileWriter("output_small.txt");	
		// FileWriter fw = new FileWriter("output_large.txt");	
		int T = in.nextInt();
		in.nextLine();
		
		for (int cases = 1; cases <= T; cases++){
			// read parameters for this case
			String line = in.nextLine();
			int pos = line.indexOf(' ');
			String name = line.substring(0, pos);
			String numString = line.substring(pos + 1, line.length());
			int num = Integer.parseInt(numString);
			char[] nameC = name.toCharArray();
			int[] store = new int[nameC.length];
			for (int i = 0; i < nameC.length; i++){
				if (nameC[i] == 'a' ||nameC[i] == 'e' ||nameC[i] == 'i' ||nameC[i] == 'o' ||nameC[i] == 'u')
					store[i] = 1;
			}
			int sec0 = 0;
			int[] storeSec = new int[nameC.length];
			for (int i = nameC.length - 1; i >= 0; i--){
				if(store[i] == 0)	sec0++;
				if(store[i] != 0)   sec0 = 0;
				if(sec0 >= num) storeSec[i] = 1;
			}
			
			ArrayList<Integer> storeList = new ArrayList<Integer>();
			for(int i = 0; i < nameC.length; i++)
				if (storeSec[i] == 1)
					storeList.add(i);
			
			int result = 0;
			for(int i = 0; i < nameC.length; i++){
				
				while(!storeList.isEmpty() && storeList.get(0) < i)
					storeList.remove(0);
					
				if(!storeList.isEmpty())	
					if(i <= storeList.get(0)){
						result += nameC.length + 1 - storeList.get(0) - num;
						// System.out.print(result + "  ");
					}
				
			}
			
			
			// System.out.println();
			// for (int i = 0; i < nameC.length; i++){
				// System.out.print(storeSec[i]);
			// }
			// System.out.println(storeList);
			// System.out.println(result);
			// System.out.println();

			

			fw.write("Case #" + cases + ": " + result + "\n");					
		}
		fw.flush();
		fw.close();		
	}
}