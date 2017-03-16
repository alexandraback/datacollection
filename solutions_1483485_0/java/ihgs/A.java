package qualification;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Properties;

import common.FileTranslatorBasis;

public class A {

	public static Map<Character, Character> googlereseMap = new HashMap<Character, Character>();

	private List<Translater> targets = new ArrayList<A.Translater>();

	public A() throws FileNotFoundException, IOException {
		load();
	}
	
	
	public void addTarget(int no, String source){
		targets.add(new Translater(no, source));
	}
	

	public void showTranselate() {
		int size = targets.size(); 
		for (int i = 0; i < size; i++) {
			
				System.out.println(targets.get(i).target);
		}
	}
	
	public void showNotYetTranslate(){
		for(Translater t: targets){
			if(!t.success){
				System.out.println(t.target);
			}
		}
	}
	
	
	boolean allsuccess;
	public boolean translate(){
		allsuccess = true;
		for(Translater t : targets){
			if(!t.success){
				if(!t.translate()){
					allsuccess = false;
				}
			}
		}
		return allsuccess;
	}
	
	public void outputFile(File output) throws FileNotFoundException{
		if(!allsuccess){
			throw new IllegalStateException();
		}
		PrintWriter pw = new PrintWriter(output);
		for(Translater t : targets){
			pw.println(t.toString());
		}
		pw.close();
	}

	public void setInit() {
		String[] sources = new String[] {
				"ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv" };
		String[] targets = new String[] {
				"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up" };

		googlereseMap.put(' ', ' ');

		for (int i = 0; i < sources.length; i++) {
			String s = sources[i];
			String t = targets[i];
			for (int j = 0; j < s.length(); j++) {
				googlereseMap.put(s.charAt(j), t.charAt(j));
			}
		}
	}

	public void load() throws FileNotFoundException, IOException {
		FileInputStream mapFile = new FileInputStream(new File(
				"characterMap.txt"));
		Properties prop = new Properties();

		prop.load(mapFile);
		googlereseMap.clear();

		googlereseMap.put(' ', ' ');
		for (Entry<Object, Object> e : prop.entrySet()) {
			String key = (String) e.getKey();
			String value = (String) e.getValue();
			googlereseMap.put(key.charAt(0), value.charAt(0));
		}
		mapFile.close();
	}

	public static class Translater {
		int no ;
		boolean success;
		String source;
		String target;

		public Translater(int no, String source) {
			this.no = no;
			this.source = source;
		}

		public boolean translate() {
			success = true;
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < source.length(); i++) {
				Character c = googlereseMap.get(source.charAt(i));
				if (c == null) {
					sb.append("[" + source.charAt(i) + "]");
					success = false;
				} else {
					sb.append(c);
				}
			}

			target = sb.toString();
			return success;
		}
		
		@Override
		public String toString() {
			return "Case #"+String.valueOf(no)+": "+ target;
		}

	}

	public void action() throws FileNotFoundException, IOException {
		while (true) {
			System.out.println("[action]reload: r,show: s, show not yet: m, quit: q");

			int input = System.in.read();
			if (input == 'r') {
				load();
				if(translate()){
					System.out.println("All success!!");;
					outputFile(new File("output.txt"));
					break;
				}
				showTranselate();
			} else if (input == 'q') {
				break;
			}else if(input == 's'){
				showTranselate();
			}else if(input == 'm'){
				showNotYetTranslate();
			}
		}
	}

	public void showMap() {
		for (int i = 'a'; i <= 'z'; i++) {
			System.out.println((char) i + "->" + googlereseMap.get((char) i));
		}
	}

	public static void main(String[] args) throws FileNotFoundException,
			IOException {
		A a = new A();
		
//		String fname = "sample.txt";
		String fname = "A-small-attempt1.in.txt";
		
				
		FileTranslatorBasis ftb = FileTranslatorBasis.getInstance(fname);
		
		int num = ftb.getNumOfCase();
		for(int i=0;i<num;i++){
			a.addTarget(i+1, ftb.getStrData());
		}
		a.translate();
		a.showTranselate();
		a.action();
	}

}
