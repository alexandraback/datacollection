import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class RanknFile {

	public String lostFile(int n, List<String> l) {
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		for(String s: l) {
			String[] arr = s.split(" ");
			for(String a:arr) {
				if(map.get(a)==null) 
					map.put(a, 1);
				else
					map.put(a, map.get(a)^1);
			}
		}
		List<Integer> re = new ArrayList<Integer>();
		for(String key: map.keySet()) {
			if(map.get(key)==1)
				re.add(Integer.parseInt(key));
		}
		Collections.sort(re);
		String res="";
		for(Integer s:re) {
			res+=s+" ";
		}
		return res;
	}
	public static void main(String[] args) {
		RanknFile tlw =new RanknFile();
		String fname="B-Small-attempt1";
		File file = new File("C:\\Users\\guanziwen\\Downloads\\"+fname+".in");
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(file));
		    int t = Integer.parseInt(br.readLine());
		    Writer writer = null;
		    try {
		        writer = new BufferedWriter(new OutputStreamWriter(
		              new FileOutputStream("C:\\Users\\guanziwen\\Downloads\\"+fname+".out"), "utf-8"));
		        for (int i = 1; i <= t; ++i) {
		        	int n = Integer.parseInt(br.readLine());
		    		List<String> l = new ArrayList<String>();
		        	for(int j=0;j<2*n-1;j++) {
		        		l.add(br.readLine());
		        	}
		        	writer.write("Case #" + i + ": " + tlw.lostFile(n, l)+"\n");
		        }
		    } catch (IOException ex) {
		    } finally {
		    	if(writer!=null)
		       try {writer.close();} catch (Exception ex) {}
		    }
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			if(br!=null)
				try {
					br.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
		}
		System.out.println("Done");
	}

}
