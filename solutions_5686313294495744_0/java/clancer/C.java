import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

public class C {
	public static void main(String args[]) {
		try (BufferedReader reader = new BufferedReader(new FileReader("C-small-attempt0(1).in"))) {
			
		    int T = Integer.parseInt(reader.readLine());
		    String s;
		    for (int t = 1; t <= T; t++) {
		    	ArrayList<topic> topics = new ArrayList<topic>();
		    	int N = Integer.parseInt(reader.readLine());
		    	for (int i = 0; i < N; i++) {
		    		String[] words = reader.readLine().split(" ");
		    		topic temp = new topic(words[0], words[1]);
		    		topics.add(temp);
		    	}
		    	for (int i = 0; i < N; i++) {
		    		for (int j = 0; j < N; j++) {
		    			if (i != j) {
		    				if (topics.get(i).first.equals(topics.get(j).first) || topics.get(i).second.equals(topics.get(j).second)) {
		    					topics.get(i).c.add(j);
		    					topics.get(i).count++;
		    				}
		    			}
		    		}
		    	}
		    	int count = 0;
		    	while (!unique(topics)) {
		    		int max = Integer.MIN_VALUE;
		    		int maxi = 0;
		    		for (int i = 0; i < N; i++) {
		    			//System.out.println(i + " : " + topics.get(i).count);
		    			if (topics.get(i).count > max) {
		    				maxi = i;
		    				max = topics.get(i).count;
		    			}
		    		}
		    		//System.out.println(max + " " + topics.get(maxi).first + " " + topics.get(maxi).second);
		    		count++;
		    		topics.get(maxi).first = "";
		    		topics.get(maxi).second = "";
		    		topics.get(maxi).c.clear();
		    		topics.get(maxi).count = 0;
		    		for (int i = 0; i < N; i++) {
		    			int indexOf = topics.get(i).c.indexOf(maxi);
		    			if (indexOf != -1) {
		    				//topics.get(i).c.remove(indexOf);
		    				topics.get(i).count--;
		    			}
		    		}
		    		if (count > 6) {
		    			break;
		    		}
		    	}
		    	
		    	System.out.println("Case #"+t+": "+count);
		    }
		} catch (Exception e) {
		}
		
	}
	public static boolean unique(ArrayList<topic> topics) {
    	for (int i = 0; i < topics.size(); i++) {
    		if (topics.get(i).first.isEmpty()) {
    			continue;
    		}
    		boolean first_unique = true;
    		boolean second_unique = true;
    		for (int j = 0; j <  topics.size(); j++) {
        		if (topics.get(j).first.isEmpty()) {
        			continue;
        		}
    			if (i != j) {
    				first_unique = first_unique && !(topics.get(i).first.equals(topics.get(j).first));
    				//System.out.println(topics.get(i).first + " != " + topics.get(j).first + " " + first_unique);
    				second_unique = second_unique && !(topics.get(i).second.equals(topics.get(j).second));
    				//System.out.println(topics.get(i).second + " != " + topics.get(j).second);
    			}
    		}
    		//System.out.println(topics.get(i).first + " " + topics.get(i).second);
    		//System.out.println(first_unique + " " + second_unique);
    		if (!(first_unique || second_unique)) {
    			return false;
    		}
    	}
    		
		return true;
	}
}
class topic {
	public String first = "";
	public String second = "";
	public ArrayList<Integer> c = new ArrayList<Integer>();
	public int count = 0;
	
	public topic (String f, String s) {
		first = f;
		second = s;
	}
}
