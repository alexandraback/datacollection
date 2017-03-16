import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Match {
	public static void main(String[] args){
		new Match().run();
	}
	
	
	public void run(){
		Scanner sc = new Scanner(System.in);
		Integer t = Integer.parseInt(sc.nextLine());
		for(int i = 0; i<t; i++){
			ArrayList<Integer> coders = new ArrayList<Integer>();
			ArrayList<Integer> jammers = new ArrayList<Integer>();
			String[] foo = sc.nextLine().split(" ");
			
			String c = foo[0];
			String j = foo[1];
			
			c=c.replaceAll("\\?", "~");
			j=j.replaceAll("\\?", "~");
			
			List<String> cl = removeQ(c);
			List<String> jl = removeQ(j);
			
			
			Collections.sort(cl);
			Collections.sort(jl);
			
			int closest = Integer.MAX_VALUE;
			int latest = Integer.MAX_VALUE;
			String cC = "";
			String jC = "";
			
			outer : for(int p = 0; p<cl.size(); p++){
				latest = Integer.MAX_VALUE;
				inner : for(int q=0;q<jl.size(); q++){
					int diff = Math.abs(Integer.parseInt(cl.get(p)) - Integer.parseInt(jl.get(q)));
					if(diff<closest){
						closest = diff;
						cC = cl.get(p);
						jC = jl.get(q);
					}
					if(diff == 0){
						break outer;
					}
					if(diff > latest){
						continue outer;
					}
					latest = diff;
				}
			}
			
			
			
			
			
			System.out.println("Case #" +(i+1) + ": " + cC + " " + jC);
		}
	}
	
	private List<String> removeQ(String s){
		List<String> res = new ArrayList<String>();
		if(!s.contains("~")){
			res.add(s);
			return res;
		}
		
		String s0 = s.replaceFirst("~", "0");
		String s1 = s.replaceFirst("~", "1");
		String s2 = s.replaceFirst("~", "2");
		String s3 = s.replaceFirst("~", "3");
		String s4 = s.replaceFirst("~", "4");
		String s5 = s.replaceFirst("~", "5");
		String s6 = s.replaceFirst("~", "6");
		String s7 = s.replaceFirst("~", "7");
		String s8 = s.replaceFirst("~", "8");
		String s9 = s.replaceFirst("~", "9");
		
		res.addAll(removeQ(s0));
		res.addAll(removeQ(s1));
		res.addAll(removeQ(s2));
		res.addAll(removeQ(s3));
		res.addAll(removeQ(s4));
		res.addAll(removeQ(s5));
		res.addAll(removeQ(s6));
		res.addAll(removeQ(s7));
		res.addAll(removeQ(s8));
		res.addAll(removeQ(s9));
		
		return res;
		
		
	}
}
