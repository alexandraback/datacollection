import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.StringTokenizer;


public class C {
	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer tokenizer;
	
	public static void main(String[]args) throws IOException{
		File inF = new File("/home/taras/workspace/Google_Code_Jam_2014_ Qualification_Round/src/CSmall.txt");
		
		File outF = new File("/home/taras/workspace/Google_Code_Jam_2014_ Qualification_Round/src/CSmall_out.txt");
		FileReader reader = new FileReader(inF);
		FileWriter writer = new FileWriter(outF);
		br = new BufferedReader(reader);
		out = new PrintWriter(writer);
		
		tokenizer = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(tokenizer.nextToken());
		int r,c,m;
		for(int z=0;z<n;z++){
			tokenizer = new StringTokenizer(br.readLine());
			r = Integer.parseInt(tokenizer.nextToken());
			c = Integer.parseInt(tokenizer.nextToken());
			m = Integer.parseInt(tokenizer.nextToken());
			out.append("Case #"+(z+1)+":\n");
			
			char[][] ch = new char[r][c];
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					ch[i][j] = '*';
				}
			}
			int diff = r*c-m;
			
			boolean possible = true;
			
			int minDim = Math.min(r, c);
			if(minDim==1){//if 1
				if(m>0 && diff<1){
					possible = false;
					out.append("Impossible\n");
					//out.append("Impossible !1  r="+r+" c="+c+" diff="+(r*c-m)+"\n");
				}else{
					if(r==1){
						for(int i=0;i<diff;i++){
							ch[0][i] = '.';
						}
					}
					if(c==1){
						for(int i=0;i<diff;i++){
							ch[i][0] = '.';
						}
					}
					
					ch[0][0] = 'c';
					
					for(int i=0;i<r;i++){
						for(int j=0;j<c;j++){
							out.append(ch[i][j]);
						}
						out.append("\n");
					}
				}
			}else if(minDim==2){//if 2
				if((m>0 && (diff<4)) || (diff%2==1)){
					if(diff!=1){
					possible = false;
					out.append("Impossible\n");
					//out.append("Impossible !2  r="+r+" c="+c+" diff="+(r*c-m)+"\n");
					}
				}
				if(possible){
				
					if(r==2){
						for(int i=0;i<diff/2;i++){
							ch[0][i] = '.';
							ch[1][i] = '.';
						}
					}
					if(c==2){
						for(int i=0;i<diff/2;i++){
							ch[i][0] = '.';
							ch[i][1] = '.';
						}
					}
					
					ch[0][0] = 'c';
					
					for(int i=0;i<r;i++){
						for(int j=0;j<c;j++){
							out.append(ch[i][j]);
						}
						out.append("\n");
					}
				}
			} else{
				if((m>0 && diff<4) || (m>0 && diff==5) || (m>0 && diff==7)){
					if(diff!=1){
					possible = false;
					//out.append("Impossible !3  r="+r+" c="+c+" diff="+(r*c-m)+"\n");
					out.append("Impossible\n");
					}
				}
				if(possible){
					if(diff%2==1 && diff>=9){
						diff-=9;
						for(int i=0;i<3;i++){
							for(int j=0;j<3;j++){
								ch[i][j] = '.';
							}
						}
					}else if(diff>=4){
						diff-=4;
						for(int i=0;i<2;i++){
							for(int j=0;j<2;j++){
								ch[i][j] = '.';
							}
						}
					}
					if(diff==1)diff = 0;
					for(int i=2;i<c;i++)if(diff>0)if(ch[0][i]=='*'){
						diff-=2;
						ch[0][i] = '.';
						ch[1][i] = '.';
					}
					
					for(int i=2;i<r;i++)if(diff>0)if(ch[i][0]=='*'){
						diff-=2;
						ch[i][0] = '.';
						ch[i][1] = '.';
					}
					int x = 2;
					int y = 2;
					while(diff>0){
						if(ch[y][x]=='*'){
							diff--;
							ch[y][x] = '.';
						}
						x++;
						if(x==c){
							x = 2;
							y++;
						}
					}
					
					ch[0][0] = 'c';
					
					for(int i=0;i<r;i++){
						for(int j=0;j<c;j++){
							out.append(ch[i][j]);
						}
						out.append("\n");
					}
				}
			}
		}
		out.flush();
		out.close();
	}

	
	/*int res = find(r,c,m);
	if(res!=-1){
		char[][] ch = new char[r][c];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				ch[i][j] = '*';
			}
		}
		int diff = r*c-m;
		int x = 0;int y = 0;
		for(int i=0;i<diff;i++){
			ch[y][x] = '.';
			y++;
			if(y==res){
				y = 0;
				x++;
			}
		}
		
		ch[0][0] = 'c';
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				out.append(ch[i][j]);
			}
			out.append("\n");
		}
	}else out.append("Impossible\n");
	*/
	
	
	/*private static int find(int r, int c, int m) {
		int res = -1;
		int diff = r * c - m;
		
		boolean current = true;
		int parcan = 0,x = 0;
		for(int y=2;y<r;y++){
			current = true;
			x = diff / y;
			parcan = diff % y;
			if(parcan>0)x++;
			if(x==1 && c>1)current = false;
			if(x>c)current = false;
			if(parcan==1)current = false;
			if(current)res = y;
		}
		return res;
	}*/

}
