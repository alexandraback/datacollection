import java.io.*;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.util.*;

//DancingGooglers.java
//Completes the Dancing with Googlers problem for Google Code Jam 2012
//By Jack Thakar
//Coded in Java using Eclipse 3.7
public class KingdomRush {
	public static void main(String[] args){
		String input = readFile("B-small-attempt1.in");
		String[] lines = input.split(System.lineSeparator());
		String output = "";
		int i=1;
		int lineCount=1;
		while(lineCount<lines.length){
			int amountLevels = Integer.parseInt(lines[lineCount]);
			String levels[] = new String[amountLevels];
			for(int j=0;j<levels.length;j++){
				levels[j] = lines[j+lineCount+1];
			}
			Case c = (new KingdomRush()).new Case(levels);
			output+="Case #"+i+": ";
			output+=c.getSolution();
			lineCount+=amountLevels+1;
			if(lineCount<lines.length) output+=System.lineSeparator();
			i++;
		}
		writeFile("B-small-attempt1.out",output);
	}
	class Case{
		private List<Integer> oneStar,twoStar;
		private int stars;
		public Case(String[] lines){
			oneStar=new ArrayList<Integer>();
			twoStar=new ArrayList<Integer>();
			for(String l:lines){
				String[] nums = l.split(" ");
				oneStar.add(Integer.parseInt(nums[0]));
				twoStar.add(Integer.parseInt(nums[1]));
			}
		}
		public String getSolution(){
			int count=0;
			while(twoStar.size()>0){
				int use = getBestLevel();
				if(use==-1) return "Too Bad";
				count++;
				int addStars=0;
				if(stars>=oneStar.get(use).intValue()&&oneStar.get(use).intValue()!=-1){
					addStars++;
					oneStar.set(use, -1);
				}
				if(stars>=twoStar.get(use).intValue()){
					addStars++;
					oneStar.remove(use);
					twoStar.remove(use);
				}
				stars+=addStars;
			}
			return Integer.toString(count);
		}
		
		public int getBestLevel(){
			for(int i=0;i<twoStar.size();i++){
				int s = twoStar.get(i).intValue();
				if(stars>=s){
					return i;
				}
			}
			for(int i=0;i<oneStar.size();i++){
				int s = oneStar.get(i).intValue();
				if(stars>=s&&s!=-1){
					return i;
				}
			}
			return -1;
		}

	}
	
	private static String readFile(String name){
		File file = new File("input"+File.separator+name);
		Charset charset = Charset.forName("ASCII");
		String text = "";
		try (BufferedReader reader = Files.newBufferedReader(file.toPath(), charset)) {
		    String line = null;
		    while ((line = reader.readLine()) != null) {
		        text+=line+System.lineSeparator();
		    }
		} catch (IOException e) {
		}
		return text;
	}
	private static void writeFile(String name, String data){
		File file = new File("output"+File.separator+name);
		Charset charset = Charset.forName("ASCII");
		try (BufferedWriter writer = Files.newBufferedWriter(file.toPath(), charset)) {
		    writer.write(data, 0, data.length());
		} catch (IOException e) {
		}
	}
}
