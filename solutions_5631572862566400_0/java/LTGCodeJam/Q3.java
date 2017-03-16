
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;



public class Q3 {

	public static void main(String[] args) {
		try {
			String input="d:\\C-small-attempt3.in";
		    String output="d:\\output.out";
		    
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);
            
            int n = sc.nextInt();
            sc.nextLine();
            
            
            for (int c=0; c<n; c++) {
            	int len = sc.nextInt();
            	sc.nextLine();
                pw.print("Case #" + (c+1) + ": ");
                test(sc, pw, len);
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            
        }

	}

	static int max = 0;
	static Map<Integer, List<Integer>> map = new HashMap<>();
	private static void test(Scanner sc, PrintWriter pw, int len) {
		
		
		String z = sc.nextLine();
		
		String[] all = z.split(" ");
		int[] ff = new int[len+1];
		
		for(int i = 1;i<len+1;i++){
			if(!all[i-1].isEmpty()){
				int x  = Integer.parseInt(all[i-1]);
				ff[i] = x;
				if(!map.containsKey(x)){
					map.put(x, new ArrayList<Integer>());
				}
				map.get(x).add(i);
			}
		}
		for(int i = 0;i<len;i++){
			bfs(ff,i+1);
		}
			
		pw.println(max);
		max = 0;
		map.clear();
		
	}
	
	private static void bfs(int[] ff,int i) {
		Queue<Integer> all = new LinkedList<>();
		
		all.add(i);
		int count = 1;
		boolean[] used= new boolean[ff.length];
		int last = 0;
		int sec = 0;
		while(!all.isEmpty()){
			int a = all.poll();
			sec = last;
			last = a;
			used[a] = true;
			int b = ff[a];
			if(!used[b]){
				all.add(b);
				count++;
			}
		}
		int x = ff[last] == sec ? rbfs(last, used) : 0;
		if((ff[last] == i || x > 0) && count > 1){
			max = Math.max(max, count + x);
		}
		
	}
	
	private static int rbfs(int i, boolean[] used) {
		Queue<Integer> all = new LinkedList<>();
		Queue<Integer> count = new LinkedList<>();
		all.add(i);
		count.add(0);
		int c = 0;
		while(!all.isEmpty()){
			int a = all.poll();
			c = count.poll();
			used[a] = true;
			if(map.containsKey(a)){
				List<Integer> f = map.get(a);
				for(int b : f){
					if(!used[b]){
						all.add(b);
						count.add(c+1);
					}
				}
			}
		}
		return c;
	}
	

}
