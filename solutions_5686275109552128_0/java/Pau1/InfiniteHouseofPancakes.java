import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;


public class InfiniteHouseofPancakes {
	
	private void rwFile(String filename){
		try {
			FileReader fr = new FileReader(filename);
			BufferedReader br = new BufferedReader(fr);
			FileWriter fw = new FileWriter(new File("result1.txt"));
			BufferedWriter bw = new BufferedWriter(fw);
			int count = Integer.parseInt(br.readLine());
			for(int i=1; i<=count; i++){
				int num = Integer.parseInt(br.readLine());
				String temp = br.readLine();
				String[] pansStr = temp.split(" ");
				int[] pans = new int[num];
				for(int j=0; j<num; j++){
					pans[j] = Integer.parseInt(pansStr[j]);
				}
				int re = minTime(pans);
				if(i == count){
					bw.write("Case #"+i+": "+re);
				}
				else{
					bw.write("Case #"+i+": "+re+"\n");
				}
//				bw.write(temp+"\n");
			}
			bw.flush();
			bw.close();
			br.close();
			fr.close();
			fw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		catch(IOException e){
			e.printStackTrace();
		}
	}
	
	private int minTime(int[] people){
		Arrays.sort(people);
		int min = people[people.length-1];
		
		int fixSize = 2;
		while(fixSize<min){
			int ans = 0;
			for(int i=0; i<people.length; i++){
				ans += (people[i]-1)/fixSize;
			}
			min = Math.min(ans+fixSize,min);
			fixSize++;
		}
		return min;
	}
	
	public static void main(String[] args){
		InfiniteHouseofPancakes test = new InfiniteHouseofPancakes();
		test.rwFile("B-small-attempt4.in.txt");
//		test.rwFile("test");
	}
}
