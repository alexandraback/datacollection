import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Hashtable;


public class SpeakinginTongues {
	Hashtable<String,String> mapping = new Hashtable<>();
	String[] trainingGs = new String[]{"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"}; 
	String[] trainingSs = new String[]{"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"}; 
	ArrayList<String> result = new ArrayList<>();

	public void train(){
		for(int i=0;i<trainingGs.length;i++){
			String gString = trainingGs[i];
			String sString = trainingSs[i];
			for(int j=0;j<gString.length();j++){
				char gc = gString.charAt(j);
				char sc = sString.charAt(j);
				mapping.put(""+gc, ""+sc);
			}
		}
		mapping.put("q", "z");
		mapping.put("z", "q");
	}
	
	public void solve(ArrayList<String> sentences){
		for(int i=0;i<sentences.size();i++){
			String s = sentences.get(i);
			StringBuffer sb = new StringBuffer();
			for(int j=0;j<s.length();j++){
				char c = s.charAt(j);
				sb.append(mapping.get(""+c));
			}
			result.add(sb.toString());
		}
	}
	
	public void saveResults(String file){
		try {
			FileWriter fstream = new FileWriter(file);
			BufferedWriter out = new BufferedWriter(fstream);
			int count = 1;
			for(int i=0;i<result.size();i++){
				String s = "Case #" + count++ + ": " + result.get(i) + "\n";
				out.write(s);
			}

			out.close();			
		} catch (Exception e) {
			// TODO: handle exception
		}
	}
	
	public static void main(String[] args) {
		String file = args[0];
		ArrayList<String> Gs = new ArrayList<>();
		try{
			BufferedReader br = new BufferedReader(new FileReader(new File(file)));
			String line = br.readLine();
			int numRows = Integer.parseInt(line);
			while((line=br.readLine())!=null){
				Gs.add(line);
			}
		}catch (Exception e) {
			System.out.println(e.getMessage());
		}
		SpeakinginTongues sit = new SpeakinginTongues();
		sit.train();
		sit.solve(Gs);
		sit.saveResults(args[1]);
	}

}
