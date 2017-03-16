import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("C-small-attempt2.in"));
		PrintWriter out = new PrintWriter("C:\\Users\\JiaKY\\Desktop\\out.txt");
		//Scanner in = new Scanner(System.in);
		
		int n = Integer.valueOf(in.nextLine());
		for(int i=0;i<n;i++){
			String line = in.nextLine();
			String[] data = line.split(" ");
			int start = Integer.valueOf(data[0]);
			int end = Integer.valueOf(data[1]);
			
			Set<Record> set = new TreeSet<Record>();
			for(int s = start;s <= end;s++){
				String ori = String.valueOf(s);
				for(int j=1;j<ori.length();j++){
					String trans = ori.substring(j).concat(ori.substring(0, j));
					int tmp = Integer.valueOf(trans);
					if(tmp <= end && tmp >= start && tmp != s){
						if(tmp > s)
							set.add(new Record(s, tmp));
						else
							set.add(new Record(tmp, s));
					}
				}
			}
			//System.out.println(set);
			out.printf("Case #%d: %d",i+1,set.size());
			out.println();
			out.flush();
		}
		
	}

}
class Record implements Comparable<Record>{
	int a;
	int b;
	public Record(int i,int j) {
		// TODO Auto-generated constructor stub
		a = i;
		b = j;
	}
	@Override
	public int compareTo(Record o) {
		// TODO Auto-generated method stub
		if(o.a != a)
			return a - o.a;
		else
			return b-o.b;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return a+" "+b;
	}
	
}
