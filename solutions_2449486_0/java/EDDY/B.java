
public class B {
	public static void main(String[]args) throws Exception {
		java.io.File file = new java.io.File(args[0]);
		java.io.FileInputStream finput = new java.io.FileInputStream(file);
		java.io.DataInputStream dinput = new java.io.DataInputStream(finput);
		java.io.BufferedReader breader = new java.io.BufferedReader(new java.io.InputStreamReader(dinput));
		
		java.io.File result_file = new java.io.File(args[0]+"_result.txt");
		java.io.FileOutputStream foutput = new java.io.FileOutputStream(result_file);
		java.io.DataOutputStream doutput = new java.io.DataOutputStream(foutput);
		java.io.BufferedWriter bwriter = new java.io.BufferedWriter(new java.io.OutputStreamWriter(doutput));
		
		String line;
		
		line = breader.readLine();
		int times=Integer.parseInt(line);
		int n, m;
		int[][] src;
		String[] strInt;
		
		int[]maxdx;
		int[]maxdy;
		
		int work;
		int dxwork, dywork;
		
		int max_h;
		int[]h_list = new int[101];
		
		for ( int i=1; i<=times; i++){
			line = breader.readLine();
			strInt = line.split(" ");
			n = Integer.parseInt(strInt[0]);
			m = Integer.parseInt(strInt[1]);
			src = new int[n][m];
			maxdx = new int[n];
			maxdy = new int[m];
			work = 1;
			max_h = 0;
			for(int dx=0; dx<=100; dx++){
				h_list[dx] = 0;
			}
			
			for(int dx = 0; dx < n; dx++){
				line = breader.readLine();
				strInt = line.split(" ");
				for(int dy = 0; dy < strInt.length; dy++){
					src[dx][dy] = Integer.parseInt(strInt[dy]);
					h_list[src[dx][dy]] = 1;
					if (src[dx][dy] > max_h) {
						max_h = src[dx][dy];
					}
				}
			}
			
			for(int dx = 0; dx < n; dx++){
				maxdx[dx] = 0;
			}
			for(int dy = 0; dy < m; dy++){
				maxdy[dy] = 0;
			}
			
			for(int h = 100; h >=1; h--){
				if(h_list[h] == 0) continue;
				for(int dx = 0; dx < n; dx++){
					for(int dy = 0; dy < m; dy++){
						if (src[dx][dy] == h){
							// checking part
							dxwork = 1;
							dywork = 1;
							
							if (maxdx[dx] == 0 || src[dx][dy] == maxdx[dx]){
								maxdx[dx] = h;
							}else{
								dxwork = 0;
							}
							if (maxdy[dy] == 0 || src[dx][dy] == maxdy[dy]){
								maxdy[dy] = h;
							}else{
								dywork = 0;
							}
							
							if (dxwork == 0 && dywork ==0){
								work = 0;
								break;
							}
						}
					}
					if (work == 0){
						break;
					}
				}
				if (work ==0){
					break;
				}
			}
			
			
			if (work == 1){
				bwriter.write("Case #"+i+": YES");
			}else{
				bwriter.write("Case #"+i+": NO");
			}
			if ( i != times) {
				bwriter.newLine();
			}
			bwriter.flush();
		}
		doutput.close();
		dinput.close();
	}
}
