import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class Omino_CrazyDumb{
	static PrintWriter out;
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(System.in);
		out = new PrintWriter(new File("d.out"));
		
		int times = reader.nextInt();
		reader.nextLine();
		
		ArrayList<String> q = new ArrayList<String>();
		for(int i = 0; i < times; i++)
			q.add(reader.nextLine());
		
		HashMap<String, Boolean> map = new HashMap<String, Boolean>();
		
		for(int t = 1; t <= times; t++){
			Scanner in = new Scanner(q.get(t-1));
			int x = in.nextInt();
			int r = in.nextInt();
			int c = in.nextInt();
			
			if(r > c){r ^= c; c ^= r; r ^= c;}
			
			if(x == 1){
				print(t, true);
			}else if(x == 2){
				print(t, (r*c)%2 == 0);
			}else if(x == 3){
				print(t, (r*c) % 3 == 0 && r > 1);
			}else{
				if((r * c) % 4 != 0 || r <= 2)
					print(t, false);
				else{
					String key = x + " " + r + " " + c;
					if(!map.containsKey(key)){
						System.out.println("Query: " + key);
						map.put(key, reader.next().charAt(0) == 'y');
					}
					print(t, map.get(key));
				}
			}
		}
		
		out.close();
	}
	
	public static void print(int t, boolean good){
		System.out.println("Case #"+t+": "+(good?"GABRIEL":"RICHARD"));
		out.println("Case #"+t+": "+(good?"GABRIEL":"RICHARD"));
	}
}
