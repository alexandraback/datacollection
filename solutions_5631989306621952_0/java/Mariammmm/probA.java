import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;


public class probA {
	static  String input = "probA.in";
	static  String output = "probA.out";
	public static void main(String[] args) throws IOException{
//		BufferedReader in =new BufferedReader(new InputStreamReader(System.in));
	//	PrintWriter out = new PrintWriter(System.out);
		BufferedReader in =new BufferedReader(new FileReader(input));
	PrintWriter out = new PrintWriter(new FileWriter(output));
		
		int t = Integer.parseInt(in.readLine());
		
		for(int i=1; i<=t; i++){
			out.print("Case #"+i+": ");
			out.println(oneTest(in.readLine()));
		}
		out.flush();
	}
	
	private static String oneTest(String str){
		ArrayList<Character> res = new ArrayList<Character>();
		if(str.length()<=1){
			return str;
		}
		
		res.add(str.charAt(0));
		for(int i=1; i<str.length(); i++){
			if(addLeft(res, str.charAt(i))){
				res.add(0,str.charAt(i));
			}	else {
				res.add(str.charAt(i));
			}
		}
		
		return convert(res);
	}
	
	private static boolean addLeft(ArrayList<Character> list, char ch){
		for(int i = 0; i< list.size(); i++){
			if(ch>list.get(i)){
				return true;
			}
			if(ch<list.get(i)){
				return false;
			}
		}
		
		return false;
	}
	private static String convert(ArrayList<Character> list){
		StringBuilder build = new StringBuilder();
		for(char ch : list){
			build.append(""+ch);
		}
		
		return build.toString();
	}
}
