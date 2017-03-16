import java.io.*;
import java.util.Scanner;


public class C {
	
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		C main = new C();
		main.answer();
	}
	
	
	public void answer()throws FileNotFoundException, UnsupportedEncodingException{
		Scanner scan = new Scanner(new File("C-small-attempt2.in"));
		//Scanner scan = new Scanner(System.in);
		int T = Integer.parseInt(scan.nextLine()); 
		PrintWriter writer = new PrintWriter("Csmall.out", "UTF-8");
		for(int cas=1; cas<=T; cas++){
			String[] lx = scan.nextLine().split(" ");
			int l = Integer.parseInt(lx[0]);
			Long x = Long.parseLong(lx[1]);
			String line = scan.nextLine();
			//System.out.println(l+" "+x);
			String s = new String(line);
			//if(s.length()<100)
			//	System.out.println(s);
			
			boolean positive = true;
			for(int i=0; s.length()>1; i++){
				char s1 = s.charAt(0);
				char s2 = s.charAt(1);
				String rest = "";
				if(s.length()>2){
					rest = s.substring(2);
				}
				if(s1==s2){
					positive = !positive;
					s = rest;
				}else if(s1=='i'){
					if(s2=='j'){
						s = "k"+rest;
					}else{
						s = "j"+rest;
						positive=!positive;
					}
				}else if(s1=='j'){
					if(s2=='k'){
						s = "i"+rest;
					}else{
						s = "k"+rest;
						positive=!positive;
					}
				}else if(s1=='k'){
					if(s2=='i'){
						s = "j"+rest;
					}else{
						s = "i"+rest;
						positive=!positive;
					}
				}
			}
			boolean isijk = false;
			int order = 0;
			if(s.equals("")){
				if(!positive){
					isijk = (x%2!=0);
					order = 2;
				}else{
					isijk = false;
					order = 1;
				}
			}else{
				isijk = (x%4==2);
				order = 4;
			}
			boolean isSol = false;
			positive = true;
			s = "";
			for(int i=0; i<Math.min(x,2*order); i++){
				s +=line;
			}
			if(isijk && line.charAt(0)=='i' && line.charAt(l-1)=='k'){
				isSol=true;
			}else if(isijk && s.length()>3){
				int i=0;
				for(i=0; !(s.charAt(0)=='i'&&positive)&&s.length()>3&&i<l*order; i++){
					char s1 = s.charAt(0);
					char s2 = s.charAt(1);
					String rest = "";
					if(s.length()>2){
						rest = s.substring(2);
					}
					if(s1==s2){
						positive = !positive;
						s = rest;
					}else if(s1=='i'){
						if(s2=='j'){
							s = "k"+rest;
						}else{
							s = "j"+rest;
							positive=!positive;
						}
					}else if(s1=='j'){
						if(s2=='k'){
							s = "i"+rest;
						}else{
							s = "k"+rest;
							positive=!positive;
						}
					}else if(s1=='k'){
						if(s2=='i'){
							s = "j"+rest;
						}else{
							s = "i"+rest;
							positive=!positive;
						}
					}
				}
				if((s.charAt(0)=='i'&&positive)&&s.length()>2){
					s=s.substring(i+1);
						while(!(s.charAt(0)=='j'&&positive)&&s.length()>2){
							char s1 = s.charAt(0);
							char s2 = s.charAt(1);
							String rest = "";
							if(s.length()>2){
								rest = s.substring(2);
							}
							if(s1==s2){
								positive = !positive;
								s = rest;
							}else if(s1=='i'){
								if(s2=='j'){
									s = "k"+rest;
								}else{
									s = "j"+rest;
									positive=!positive;
								}
							}else if(s1=='j'){
								if(s2=='k'){
									s = "i"+rest;
								}else{
									s = "k"+rest;
									positive=!positive;
								}
							}else if(s1=='k'){
								if(s2=='i'){
									s = "j"+rest;
								}else{
									s = "i"+rest;
									positive=!positive;
								}
							}
						}
					if(s.charAt(0)=='j'&&positive&&s.length()>1){
						isSol = true;
					}
				}
			}else if(isijk && s.length()==3){
				isSol = s.equals("ijk");
			}
			if(isSol){
				writer.println("Case #"+cas+": "+"YES");
				System.out.println("Case #"+cas+": "+"YES");
			}else{
				writer.println("Case #"+cas+": "+"NO");
				System.out.println("Case #"+cas+": "+"NO");
			}
				
		}		
		writer.close();
	}
	
	public String reduce(String s){
		boolean positive = true;
		for(int i=0; s.length()>1; i++){
			String s1 = s.substring(0,1);
			String s2 = s.substring(1,2);
			String rest = "";
			if(s.length()>2){
				rest = s.substring(2);
			}
			if(s1.equals(s2)){
				positive = !positive;
				s = s.substring(2);
			}else if(s1.equals("i")){
				if(s2.equals("j")){
					s = "k"+rest;
				}else{
					s = "j"+rest;
					positive=!positive;
				}
			}else if(s1.equals("j")){
				if(s2.equals("k")){
					s = "i"+rest;
				}else{
					s = "k"+rest;
					positive=!positive;
				}
			}else if(s1.equals("k")){
				if(s2.equals("i")){
					s = "j"+rest;
				}else{
					s = "i"+rest;
					positive=!positive;
				}
			}
		}
		if(positive){
			return s;
		}else{
			return "-"+s;
		}
	}
	
	
	
}
