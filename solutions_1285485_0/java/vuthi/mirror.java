import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;


public class mirror {

	/**
	 * @param args
	 */
	
	public static int count(int h, int w, int d, char [][]map) {
		int count = 0;

		// find "X"
		int r = 0, c = 0;
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				if(map[i][j] == 'X') {
					r = i;
					c = j;
					break;
				}
			}
		}

		System.err.println("Found X at "+r+","+c);
		
		int fromR = r-d;
		int toR = r+d;
		int fromC = c-d;
		int toC = c+d;
		
		int curR=fromR;
		while(curR <= toR) {
			int curC=fromC;
			while(curC<=toC) {
				int dist2 = (curR-r)*(curR-r) + (curC-c)*(curC-c);
				if(dist2 <= d*d) {
					int mapR = mapRow(curR, h);
					int mapC = mapCol(curC, w);
					
					System.err.println("cur "+curR+","+curC+" use "+mapR+","+mapC);
					if(map[mapR][mapC]=='X' && 
							(!(curR==r && curC==c)) &&
							linkOk(curR,curC,r,c,h,w,map))
						count++;
				}
				curC++;
			}
			curR++;
		}
		
		return count;
	}
	
	static boolean linkOk(int fR, int fC, int tR, int tC, int h, int w, char [][]map) {
		int difR = Math.abs(tR-fR);
		int difC = Math.abs(tC-fC);

		if(difR==0) {
			fC += (tC>fC)?1:-1;
			while(fC!=tC) {
				if(map[mapRow(fR, h)][mapCol(fC,w)]=='X')
					return false;
				fC += (tC>fC)?1:-1;
			}
		}
		else if(difC==0) {
			fR += (tR>fR)?1:-1;
			while(fR!=tR) {
				if(map[mapRow(fR, h)][mapCol(fC,w)]=='X')
					return false;
				fR += (tR>fR)?1:-1;
			}
		}
		else {
			int dby = hrm(difR,difC);
			if(dby!=1) {
				difR /= dby;
				difC /= dby;
				fR += (tR>fR)?difR:-difR;
				fC += (tC>fC)?difC:-difC;
				while(fR!=tR && fC!=tC) {
					if(map[mapRow(fR, h)][mapCol(fC,w)]=='X') {
						System.err.println("DBY "+difR+","+difC);
						return false;
					}
					fR += (tR>fR)?difR:-difR;
					fC += (tC>fC)?difC:-difC;
				}				
				
			}
		}
		return true;
	}
	
	static int hrm(int a, int b) {
		int c;
		while((c=a%b)!=0) {
			a=b;
			b=c;
		}
		
		return b;
	}
	
	static int mapRow(int curR, int h) {
		if(curR<0)
			curR=-curR-1;
		
		int blockR = curR / h;
		int modR = Math.abs(curR % h);
		int mapR = (blockR%2==0) ? modR:(h-modR-1);
		return mapR;
	}

	static int mapCol(int curC, int w) {
		if(curC<0)
			curC = -curC-1;
		
		int blockC = curC / w;
		int modC = Math.abs(curC % w);
		int mapC = (blockC%2==0) ? modC:(w-modC-1);
		return mapC;
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		try {
			FileReader fr = new FileReader(args[0]);
			BufferedReader br = new BufferedReader(fr);
			String line = br.readLine();
			
			int cCount = Integer.parseInt(line);
			System.err.println("Cases "+cCount);

			for(int i=0;i<cCount;i++) {
				line = br.readLine();
				String [] cols = line.split(" ");
				int h = Integer.parseInt(cols[0]);
				int w = Integer.parseInt(cols[1]);
				int d = Integer.parseInt(cols[2]);
				
				System.err.println("h w d "+h+","+w+","+d);

				
				char map[][] = new char[h-2][w-2];
				line = br.readLine();
				for(int j=0;j<h-2;j++) {
					line = br.readLine();
					for(int k=0;k<w-2;k++) {
						map[j][k] = line.charAt(k+1); 
					}
				}
				line = br.readLine();
				
				int result = count(h-2, w-2, d, map);
				System.out.println("Case #"+(i+1)+": "+result);
			}
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
	}

}
