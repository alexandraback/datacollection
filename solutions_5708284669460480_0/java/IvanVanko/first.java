import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class first {

	public static int overlapping(String s){
		int L = s.length();
		for (int i = 1;i< L;++i){
			String begin = s.substring(0, L-i);
			String end = s.substring(i, L);
			if(begin.equals(end)) return L-i;
		}
		return 0;
	}
	
	public static void main(String[] args) {
	/*	int a = "A".charAt(0);
		System.out.println(a);
		int b = "Z".charAt(0);
		System.out.println(b);
		*/
		try (BufferedReader br = new BufferedReader(new FileReader("B-small-attempt4.in")))
		{
			PrintWriter writer = new PrintWriter("solution-B-small.output", "UTF-8");
			
			int T = 0; //number of tests
			
			String sCurrentLine = br.readLine();
			T = Integer.parseInt(sCurrentLine);
			String stringBuffer[] = null;
			Double[] answers = new Double[T];
			for(int testIntance = 1 ; testIntance <= T; ++testIntance){
				sCurrentLine = br.readLine();
				stringBuffer = sCurrentLine.split(" ");
				int K = Integer.parseInt(stringBuffer[0]);
				int L = Integer.parseInt(stringBuffer[1]);
				int S = Integer.parseInt(stringBuffer[2]);
				int alphabet[] = new int[26];
				
				sCurrentLine = br.readLine();
				
				for(int i = 0 ; i < K;++i){
					int pos = sCurrentLine.charAt(i) - 65;
					alphabet[pos]++;
				}
				
				String word = br.readLine();
				boolean containsAll = true;
				for (int i = 0;i< L;++i){
					int pos = word.charAt(i)- 65;
					if(alphabet[pos] < 1)containsAll = false;
				}
				if(!containsAll){
					answers[testIntance-1] = 0.0;
				}else{
					int overlap = overlapping(word);
					double maxBananas = Math.floor((S-L)/(L-overlap)) + 1; 
					double proba = 1.0;
					for (int i = 0;i< L;++i){
						int pos = word.charAt(i)- 65;
						proba = proba*((double)alphabet[pos]/K);
					}
					
					double averageBananas = proba*maxBananas;
					averageBananas =(double) Math.round(averageBananas*1000000) /1000000;
					answers[testIntance-1] = maxBananas - averageBananas;
					
				}
				
				System.out.println("Case #" + testIntance + ": " + answers[testIntance-1]);
			    writer.println("Case #" + testIntance + ": " + answers[testIntance-1]);
		
			}
		
			writer.close();
		
		} catch (IOException e) {
			e.printStackTrace();
		} 
		
	}

}
