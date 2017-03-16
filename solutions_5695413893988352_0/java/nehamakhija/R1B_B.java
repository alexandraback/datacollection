import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class R1B_B {
	
	public static void main(String[] args)throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int t=Integer.parseInt(br.readLine());
		
		for(int z=1; z<=t; z++){
			String scores[]=br.readLine().split(" ");
			//scores[0] is c s[1] is j
			int l=scores[0].length();
			String cf="";
			String jf="";
			long cs=0; long js=0;
			for(int i=0; i<l; i++){
				char cch=scores[0].charAt(i);
				char jch=scores[1].charAt(i);
				if(cch=='?' && jch=='?'){
					if(cs==js){
						cs*=10;
						js*=10;
						cf=cf+"0";
						jf=jf+"0";
					}
					else if(cs>js){
						cs*=10;
						js=(js*10)+9;
						cf=cf+"0";
						jf=jf+"9";
					}
					else{

						js*=10;
						cs=(cs*10)+9;
						jf=jf+"0";
						cf=cf+"9";
					}
				}
				else if(cch=='?'){
					if(cs==js){
						cs=(cs*10)+jch-'0';
						cf=cf+jch;
					}
					else if(cs>js){
						cs*=10;
						cf=cf+"0";
					}
					else{
						cs=(cs*10)+9;
						cf=cf+"9";
					}
					js=(js*10)+jch-'0';
					jf=jf+jch;
				}
				else if(jch=='?'){

					if(cs==js){
						js=(js*10)+cch-'0';
						jf=jf+cch;
					}
					else if(cs>js){
						js=(js*10)+9;
						jf=jf+"9";
					}
					else{

						js*=10;
						jf=jf+"0";
					}
					cs=(cs*10)+cch-'0';
					cf=cf+cch;
				}
				else{
					cs=(cs*10)+cch-'0';
					js=(js*10)+jch-'0';
					cf=cf+cch;
					jf=jf+jch;
				}

				//System.out.println("Case #"+z+": "+cf+" "+jf);
			}
			System.out.println("Case #"+z+": "+cf+" "+jf);
		}
	}
}
