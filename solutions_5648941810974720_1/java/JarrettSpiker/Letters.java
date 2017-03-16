import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Letters {
	public static void main(String[] args){
		new Letters().run();
	}
	
	
	public void run(){
		Scanner sc = new Scanner(System.in);
		Integer t = Integer.parseInt(sc.nextLine());
		for(int i = 0; i<t; i++){
			String s = sc.nextLine();
			ArrayList<Integer> nums = new ArrayList<Integer>();
			
			
			//0
			while(s.contains("Z")){
				s = remove0(s);
				nums.add(0);
			}
			
			//2
			while(s.contains("W")){
				s = remove2(s);
				nums.add(2);
			}
			
			//4
			while(s.contains("U")){
				s = remove4(s);
				nums.add(4);
			}
			//5
			while(s.contains("F")){
				s = remove5(s);
				nums.add(5);
			}
			
			//6
			while(s.contains("X")){
				s = remove6(s);
				nums.add(6);
			}
			
			//8
			while(s.contains("G")){
				s = remove8(s);
				nums.add(8);
			}
			
			//7
			while(s.contains("V")){
				s = remove7(s);
				nums.add(7);
			}
			
			//3
			while(s.contains("R")){
				s = remove3(s);
				nums.add(3);
			}
			
			//1
			while(s.contains("O")){
				s = remove1(s);
				nums.add(1);
			}
			
			//9
			while(s.contains("I")){
				s = remove9(s);
				nums.add(9);
			}
			
			Collections.sort(nums);
			
			String ans = "";
			for(Integer q : nums){
				ans += q;
			}
			
			System.out.println("Case #" +(i+1) + ": " + ans);
		}
	}
	
	
	
	private String remove0(String s){
		s = s.replaceFirst("Z", "");
		s = s.replaceFirst("E", "");
		s = s.replaceFirst("R", "");
		s = s.replaceFirst("O", "");
		return s;
	}
	private String remove1(String s){
		s = s.replaceFirst("O", "");
		s = s.replaceFirst("N", "");
		s = s.replaceFirst("E", "");
		return s;
	}
	private String remove2(String s){
		s = s.replaceFirst("T", "");
		s = s.replaceFirst("W", "");
		s = s.replaceFirst("O", "");
		
		return s;
	}
	private String remove3(String s){
		s = s.replaceFirst("T", "");
		s = s.replaceFirst("H", "");
		s = s.replaceFirst("R", "");
		s = s.replaceFirst("E", "");
		s = s.replaceFirst("E", "");
		return s;
	}
	private String remove4(String s){
		s = s.replaceFirst("F", "");
		s = s.replaceFirst("O", "");
		s = s.replaceFirst("U", "");
		s = s.replaceFirst("R", "");
		return s;
	}
	private String remove5(String s){
		s = s.replaceFirst("F", "");
		s = s.replaceFirst("I", "");
		s = s.replaceFirst("V", "");
		s = s.replaceFirst("E", "");
		return s;
	}
	private String remove6(String s){
		s = s.replaceFirst("S", "");
		s = s.replaceFirst("I", "");
		s = s.replaceFirst("X", "");
		return s;
	}
	private String remove7(String s){
		s = s.replaceFirst("S", "");
		s = s.replaceFirst("E", "");
		s = s.replaceFirst("V", "");
		s = s.replaceFirst("E", "");
		s = s.replaceFirst("N", "");
		return s;
	}
	private String remove8(String s){
		s = s.replaceFirst("E", "");
		s = s.replaceFirst("I", "");
		s = s.replaceFirst("G", "");
		s = s.replaceFirst("H", "");
		s = s.replaceFirst("T", "");
		return s;
	}
	private String remove9(String s){
		s = s.replaceFirst("N", "");
		s = s.replaceFirst("I", "");
		s = s.replaceFirst("N", "");
		s = s.replaceFirst("E", "");
		return s;
	}
}
