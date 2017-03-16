import java.util.*;
import java.io.*;
public class A{
  public static void main(String[] args) throws Exception{
    BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
    int t = Integer.parseInt(in.readLine()); 
    PrintWriter out = new PrintWriter("output.txt");
    for (int i = 1; i <= t; i++){
	String s = in.readLine();
	String output = calc(s);
	out.println("Case #"+i+": "+output);
    }
    out.close();
    }
    private static String calc(String input){
	int l = input.length();
	if(l<=0)
	    return "";
	String ans = ""+input.charAt(0);
	for(int i = 1;i<l;i++){
	    char fst = ans.charAt(0);
	    char cur = input.charAt(i);
	    if(cur<fst)
		ans+=cur;
	    else{
		ans = cur+ans;
	    }
	}
        return ans;
     }
}
