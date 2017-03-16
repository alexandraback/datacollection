import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemC {
	static HashMap<String, String> table = new HashMap<String, String>();
	static HashMap<String,String> inverse = new HashMap<String, String>();
		
	public static void main(String[] args) throws NumberFormatException, IOException {
		initialize();
		FileWriter writer = new FileWriter("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Qualification Round 2015/src/output.txt");		
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Qualification Round 2015/src/input.txt"));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				Scanner sc = new Scanner(line);
				long l = Long.parseLong(sc.next());
				long copies = Long.parseLong(sc.next());
				if(l*copies < 3L){
					br.readLine();
					printAnswer("NO", caseNum, writer);
					continue;
				} else if(l*copies == 3L){
					line = br.readLine();
					if(line.equals("ijk")){
						printAnswer("YES", caseNum, writer);
					} else {
						printAnswer("NO", caseNum, writer);
					}
					continue;
				} else {
					String value = "1";
					HashMap<String, Long> firstOccur = new HashMap<String, Long>();
					firstOccur.put(value, 0L);
					HashMap<String, Long> fakeLastOccur = new HashMap<String, Long>();
					fakeLastOccur.put(value, 0L);
					for(long i = 0; i < l; i++){
						value = times(value, "" + (char)br.read());
						if(!firstOccur.containsKey(value)){
							firstOccur.put(value, i + 1);
						}
						fakeLastOccur.put(value,  i + 1);
					}
					br.readLine();
					HashMap<String, Long> lastOccur = new HashMap<String, Long>();
					if(value.equals("1")){
						printAnswer("NO", caseNum, writer);
						continue;
					} else if(value.equals("-1") && copies % 2 == 0){
						printAnswer("NO", caseNum, writer);
						continue;
					} else if(!value.equals("1") && !value.equals("-1") && copies % 4 != 2){
						printAnswer("NO", caseNum, writer);
						continue;
					}
					for(String key : fakeLastOccur.keySet()){
						lastOccur.put(times(inverse(key), value), fakeLastOccur.get(key));
					}
					//System.out.println(firstOccur);
					//System.out.println(lastOccur);
					String a = value;
					long n1 = Long.MAX_VALUE;
					long bLength = Long.MAX_VALUE;
					if(firstOccur.containsKey("i")){
						n1 = 0;
						bLength = firstOccur.get("i");
					} else {
						for(String key : firstOccur.keySet()){
							String target = times("i", inverse(key));
							String power = a;
							for(int i = 1; i < 4; i++){
								if(target.equals(power)){
									if(i < n1 || (n1 == i && bLength > firstOccur.get(key))){
										n1 = i;
										bLength = firstOccur.get(key);
									}
								}
								power = times(power, a);
							}
						}
					}
					if(n1 > 5){
						printAnswer("NO", caseNum, writer);
						continue;
					}
					//System.out.println(caseNum + " " + n1 + ":" + bLength);
					//System.out.println(a);
					long n3 = Long.MAX_VALUE;
					long gLength = -1;
					if(lastOccur.containsKey("k")){
						n3 = 0;
						gLength = lastOccur.get("k");
					} else {
						//System.out.println("HERE");
						//System.out.println(lastOccur);
						for(String key : lastOccur.keySet()){
							String target = times(inverse(key), "k");
							String power = a;
							//System.out.println("TARGET" + target);
							for(int i = 1; i < 4; i++){
								//System.out.println(power);
								if(target.equals(power)){
									//System.out.println("HIT");
									if(i < n3 || (n3 == i && gLength < lastOccur.get(key))){
										n3 = i;
										gLength = lastOccur.get(key);
									}
								}
								power = times(power, a);
							}
						}
					}
					if(n3 > 5){
						printAnswer("NO", caseNum, writer);
						continue;
					}
					//System.out.println(caseNum + " " + n1 + ":" + bLength + " " + n3 + ":" + gLength);
					if(bLength < gLength){
						if(n1 + n3 + 1 <= copies){
							printAnswer("YES", caseNum, writer);
							continue;
						} else {
							printAnswer("NO", caseNum, writer);
							continue;
						}
					} else {
						if(n1 + n3 + 2 <= copies){
							printAnswer("YES", caseNum, writer);
							continue;
						} else {
							printAnswer("NO", caseNum, writer);
							continue;
						}
					}
				}
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
	}

	public static void printAnswer(String answer, int caseNumber,
			FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
	
	public static String times(String a, String b){
		return table.get(a + b);
	}
	
	public static String inverse(String a){
		return inverse.get(a);
	}

	public static void initialize(){
		table.put("11", "1");
		table.put("1i", "i");
		table.put("1j", "j");
		table.put("1k", "k");
		table.put("1-1", "-1");
		table.put("1-i", "-i");
		table.put("1-j", "-j");
		table.put("1-k", "-k");
		table.put("-11", "-1");
		table.put("-1i", "-i");
		table.put("-1j", "-j");
		table.put("-1k", "-k");
		table.put("-1-1", "1");
		table.put("-1-i", "i");
		table.put("-1-j", "j");
		table.put("-1-k", "k");
		table.put("i1", "i");
		table.put("ii", "-1");
		table.put("ij", "k");
		table.put("ik", "-j");
		table.put("i-1", "-i");
		table.put("i-i", "1");
		table.put("i-j", "-k");
		table.put("i-k", "j");
		table.put("-i1", "-i");
		table.put("-ii", "1");
		table.put("-ij", "-k");
		table.put("-ik", "j");
		table.put("-i-1", "i");
		table.put("-i-i", "-1");
		table.put("-i-j", "k");
		table.put("-i-k", "-j");
		table.put("j1", "j");
		table.put("ji", "-k");
		table.put("jj", "-1");
		table.put("jk", "i");
		table.put("j-1", "-j");
		table.put("j-i", "k");
		table.put("j-j", "1");
		table.put("j-k", "-i");
		table.put("-j1", "-j");
		table.put("-ji", "k");
		table.put("-jj", "1");
		table.put("-jk", "-i");
		table.put("-j-1", "j");
		table.put("-j-i", "-k");
		table.put("-j-j", "-1");
		table.put("-j-k", "i");
		table.put("k1", "k");
		table.put("ki", "j");
		table.put("kj", "-i");
		table.put("kk", "-1");
		table.put("k-1", "-k");
		table.put("k-i", "-j");
		table.put("k-j", "i");
		table.put("k-k", "1");
		table.put("-k1", "-k");
		table.put("-ki", "-j");
		table.put("-kj", "i");
		table.put("-kk", "1");
		table.put("-k-1", "k");
		table.put("-k-i", "j");
		table.put("-k-j", "-i");
		table.put("-k-k", "-1");
		inverse.put("1", "1");
		inverse.put("-1", "-1");
		inverse.put("i", "-i");
		inverse.put("-i", "i");
		inverse.put("j", "-j");
		inverse.put("-j", "j");
		inverse.put("k", "-k");
		inverse.put("-k", "k");
	
	}
}
