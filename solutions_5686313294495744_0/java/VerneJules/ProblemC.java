import java.io.*;
import java.util.*;

public class ProblemC{
	
		
	private static Scanner s = new Scanner(System.in);
	public static void main(String[] args){
		int t = Integer.parseInt(s.nextLine());
		
		for(int i = 0; i < t; i++){
			String testcase = s.nextLine();
			System.out.println("Case #"+(i+1)+": " + solve(testcase));
		}
	}
	
	public static String solve(String testcase){
		String answer = "";
		int n = Integer.parseInt(testcase);
		String[] titles = new String[n];
		List<String> first = new ArrayList<String>();
		List<Integer> frst = new ArrayList<Integer>();
		List<String> second = new ArrayList<String>();
		List<Integer> scnd = new ArrayList<Integer>();
		for(int i = 0; i < n; i++){
			titles[i] = s.nextLine();
			String[] fs = titles[i].split(" ");
			boolean dup = false;
			for(int j = 0; j < first.size(); j++){
				if(first.get(j).equals(fs[0])){
					frst.set(j,frst.get(j)+1);
					dup = true;
					break;
				}
			}
			if(!dup){
				first.add(fs[0]);
				frst.add(1);
			}
			dup = false;
			for(int j = 0; j < second.size(); j++){
				if(second.get(j).equals(fs[1])){
					scnd.set(j, scnd.get(j)+1);
					dup = true;
					break;
				}
			}
			if(!dup){
				second.add(fs[1]);
				scnd.add(1);
			}
		}
		int fakes = 0;
		for(String title:titles){
			String[] fs = title.split(" ");
			boolean f = false, sc = false;
			int index1 = -1, index2 = -1;
			for(int i = 0; i < first.size(); i++){
				if(first.get(i).equals(fs[0]))
					if(frst.get(i)>1){
						f = true;
						index1 = i;
						break;
					}
			}
			for(int i = 0; i < second.size(); i++){
				if(second.get(i).equals(fs[1]))
					if(scnd.get(i)>1){
						sc = true;
						index2 = i;
						break;
					}
			}
			if(f && sc){
				fakes++;
				frst.set(index1, frst.get(index1)-1);
				scnd.set(index2, scnd.get(index2)-1);
			}
		}
		
		answer = String.valueOf(fakes);
		return answer;
	}
	
}