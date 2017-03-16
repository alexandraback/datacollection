import java.util.*;
import java.io.*;

public class B {
	
	static String[] trains;
	static int count;
	static boolean[] visited, soloist;
	static int[] front, back, solo;
	
	public static boolean check2(String cur) {
		HashSet<Character> set = new HashSet<Character>();
		for(int i=0; i<cur.length(); i++)
			set.add(cur.charAt(i));
		return set.size() == cur.length();
	}
	
	public static void backtrack(String cur, int index) {
		if(index == trains.length) {
			if(check2(cur))
				count++;
			return;
		}
		for(int i=0; i<trains.length; i++) {
			if(!visited[i]) {
				visited[i] = true;
				if(cur.charAt(cur.length()-1) == trains[i].charAt(0))
					backtrack(reduce(cur+trains[i]), index+1);
				else if(front[(int)(cur.charAt(cur.length()-1)-'a')] == -1)
					backtrack(reduce(cur+trains[i]), index+1);
				visited[i] = false;
			}
		}
	}

    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("b.in"));
    	PrintWriter p = new PrintWriter(new FileWriter("b.out"));
    	int n = s.nextInt();
    	for(int i=0; i<n; i++) {
    		int m = s.nextInt();
    		trains = new String[m];
    		for(int j=0; j<m; j++)
    			trains[j] = reduce(s.next());
    		boolean check = false;
    		front = new int[26];
    		back = new int[26];
    		solo = new int[26];
    		soloist = new boolean[m];
    		for(int j=0; j<26; j++) {
    			front[j] = -1;
    			back[j] = -1;
    			solo[j] = -1;
    		}
    		for(int j=0; j<m; j++) {
    			if(trains[j].length() > 1) {
    				if(front[(int)(trains[j].charAt(0)-'a')] != -1)
    					check = true;
    				if(back[(int)(trains[j].charAt(trains[j].length()-1)-'a')] != -1)
    					check = true;
    				front[(int)(trains[j].charAt(0)-'a')] = j;
    				back[(int)(trains[j].charAt(trains[j].length()-1)-'a')] = j;
    			}
    			else {
    				solo[(int)(trains[j].charAt(0)-'a')] = j;
    				soloist[j] = true;
    			}
    		}
    		for(int j=0; j<m; j++)
    			if(trains[j].length() > 2)
    				for(int k=1; k<trains[j].length()-1; k++) {
    					if(front[(int)(trains[j].charAt(k)-'a')] != -1)
    						check = true;
    					if(solo[(int)(trains[j].charAt(k)-'a')] != -1)
    						check = true;
    					if(back[(int)(trains[j].charAt(k)-'a')] != -1)
    						check = true;
    				}
    		if(check) {
    			p.println("Case #" + (i+1) + ": 0");
    			continue;
    		}
    		count = 0;
    		visited = new boolean[m];
    		for(int j=0; j<m; j++) {
    			visited[j] = true;
    			if(back[(int)(trains[j].charAt(0)-'a')] == -1)
	    			backtrack(trains[j], 1);
    			visited[j] = false;
    		}
    		p.println("Case #" + (i+1) + ": " + count);
    		System.out.println("Case #" + (i+1) + ": " + count);
    	}
    	p.close();
    }
    
    public static String reduce(String str) {
    	String ret = "";
    	for(int i=0; i<str.length(); i++) {
    		ret += str.charAt(i);
    		char tmp = str.charAt(i);
    		while(tmp == str.charAt(i)) {
    			i++;
    			if(i == str.length())
    				break;
    		}
    		i--;
    	}
    	return ret;
    }
}
