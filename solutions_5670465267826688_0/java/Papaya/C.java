import java.util.Scanner;

public class C {
	
	
	
	public static void main(String[] args){
		

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine(); //remove empty line
		
		String line;
		String[] linesplit;
		int L, X;
		char[] chars;
		String Y = "YES";
		String N = "NO";
		String val;
				
		for (int i=1;i<n+1;i++){
			

			line = in.nextLine();
			linesplit = line.split(" ");
			L = Integer.parseInt(linesplit[0]);
			X = Integer.parseInt(linesplit[1]);
			line = in.nextLine();
			chars = line.toCharArray();
			
			char d;
			char c = '1';
			boolean negative = false;
			boolean foundi = false;
			boolean foundj = false;
			for(int j=0;j<X;j++){
				for(int k=0;k<L;k++){
					d = chars[k];
					switch(d){
						case 'i':
							switch(c){
								case '1':
									c = d;
									break;
								case 'i':
									c = '1';
									negative = !negative;
									break;
								case 'j':
									c = 'k';
									negative = !negative;
									break;
								case 'k':
									c = 'j';
									
									break;
							}
							break;
							
						case 'j':
							switch(c){
							case '1':
								c = d;
								break;
							case 'i':
								c = 'k';
								
								break;
							case 'j':
								c = '1';
								negative = !negative;
								break;
							case 'k':
								c = 'i';
								negative = !negative;
								break;
							}
							break;
							
						case 'k':
							switch(c){
							case '1':
								c = d;
								break;
							case 'i':
								c = 'j';
								negative = !negative;
								break;
							case 'j':
								c = 'i';
								
								break;
							case 'k':
								c = '1';
								negative = !negative;
								break;
							}
							break;
							
					}
					if(c=='i'&&!foundi){
						c='1';
						foundi=true;
					}
					if(c=='j'&&!foundj&&foundi){
						c='1';
						foundj=true;
					}
				}
			}
			
			
			
			val = N;
			if(foundi&&foundj&&c=='k'&&!negative){
				val = Y;
			}
			
			System.out.printf("Case #%d: %s\n",i,val);
		}
		in.close();
		
	}
	
	
}
