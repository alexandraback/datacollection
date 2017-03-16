import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;


public class Main2 {
	private static final String IN_FILE = "in.txt";
	private static final String OUT_FILE = "out.txt";
	
	
	
	private static List<Case> parseFile() throws IOException  {
		BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(IN_FILE)));
		
		int count = Integer.parseInt(r.readLine());
		List<Case> res = new ArrayList<Case>();
		for(int i = 0; i < count; i++){
			int c = Integer.parseInt(r.readLine());
			
			Case cas = new Case();
			for (int j = 0; j < c; j++) {
				Level l = new Level();
				String[] ls = r.readLine().split(" ");
				l.one = Integer.parseInt(ls[0]);
				l.two = Integer.parseInt(ls[1]);
				
				cas.levels.add(l);
			}
			
			res.add(cas);
		}
		
		r.close();
		
		return res;
	}
	
	private static List<String> process(List<Case> para){
		List<String> res = new ArrayList<String>();
		
		for(Case c : para){
			int count = 0;
			int stars = 0;
			
			while(c.levels.size() > 0){
				Level next = null;
				for(Level l : c.levels){
					if(l.two <= stars){
						next = l;
						c.levels.remove(l);
						break;
					}
					
					if(l.one <= stars && !l.done){
						if(next == null || next.two < l.two){
							next = l;
						}
					}
				}
				
				if(next != null){
					
					if(next.two <= stars && !next.done){
						stars += 2;
					}else{
						stars++;
					}
					
					count++;
					next.done = true;
				}else{
					count = -1;
					break;
				}
			}
			
			if(count > 0){
				res.add(String.valueOf(count));
			}else{
				res.add("Too Bad");
			}
		}
		
		return res;
	}
	
	private static void writeOutput(List<String> data) throws IOException {
		BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUT_FILE)));
		
		for(int i = 0; i < data.size(); i++){
			if(i > 0){
				w.write("\n");
			}
			
			String s = "Case #" +(i+1) +": " +data.get(i);
			w.write(s);
		}
		w.close();
	}
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		List<Case> l = parseFile();
		List<String> r = process(l);
		writeOutput(r);
		
		System.out.println("Done");
	}
	
	private static class Case {
		List<Level> levels = new ArrayList<Level>();
	}
	
	private static class Level {
		int one;
		int two;
		boolean done = false;
	}
}