import java.util.*;
import java.io.*;

public class Test {

	public void doMain() throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
        int n = input.nextInt();
        input.nextLine();
        for(int i = 0 ; i < n ; i++){
            String s = input.nextLine();
            pw.println("Case #"+(i+1)+": "+num(s));
        }
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static String num(String s){
    	StringBuilder sb = new StringBuilder();
    	for(int i = 0 ; i < s.length() ; i++){
    		if(s.charAt(i) == ' '){
    			sb.append(' ');
    		}else if(s.charAt(i) == 'a'){
    			sb.append('y');
    		}else if(s.charAt(i) == 'b'){
    			sb.append('h');
    		}else if(s.charAt(i) == 'c'){
    			sb.append('e');
    		}else if(s.charAt(i) == 'd'){
    			sb.append('s');
    		}else if(s.charAt(i) == 'e'){
    			sb.append('o');
    		}else if(s.charAt(i) == 'f'){
    			sb.append('c');
    		}else if(s.charAt(i) == 'g'){
    			sb.append('v');
    		}else if(s.charAt(i) == 'h'){
    			sb.append('x');
    		}else if(s.charAt(i) == 'i'){
    			sb.append('d');
    		}else if(s.charAt(i) == 'j'){
    			sb.append('u');
    		}else if(s.charAt(i) == 'k'){
    			sb.append('i');
    		}else if(s.charAt(i) == 'l'){
    			sb.append('g');
    		}else if(s.charAt(i) == 'm'){
    			sb.append('l');
    		}else if(s.charAt(i) == 'n'){
    			sb.append('b');
    		}else if(s.charAt(i) == 'o'){
    			sb.append('k');
    		}else if(s.charAt(i) == 'p'){
    			sb.append('r');
    		}else if(s.charAt(i) == 'q'){
    			sb.append('z');
    		}else if(s.charAt(i) == 'r'){
    			sb.append('t');
    		}else if(s.charAt(i) == 's'){
    			sb.append('n');
    		}else if(s.charAt(i) == 't'){
    			sb.append('w');
    		}else if(s.charAt(i) == 'u'){
    			sb.append('j');
    		}else if(s.charAt(i) == 'v'){
    			sb.append('p');
    		}else if(s.charAt(i) == 'w'){
    			sb.append('f');
    		}else if(s.charAt(i) == 'x'){
    			sb.append('m');
    		}else if(s.charAt(i) == 'y'){
    			sb.append('a');
    		}else if(s.charAt(i) == 'z'){
    			sb.append('q');
    		}
    	}
    	return sb.toString();
    }
	
	public static void main(String[] args) throws Exception{
		(new Test()).doMain();
	}	
	
	
}
