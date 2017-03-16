package gcj2013;

public class B_lawn {
	int     row,col;
	int[][] lawn;
	int[]   maxr,maxc;
	
	public B_lawn(int row, int col) {
		int i,j;
		
		this.row  = row;
		this.col  = col;
		this.lawn = new int[row][col];
		this.maxr = new int[row];
		this.maxc = new int[col];
		
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				lawn[i][j] = 0;
			}
			maxr[i] = 0;
		}
		for(j=0; j<col; j++){
			maxc[j] = 0;
		}
	}
	
	public void set(int x, int y, int v){
		lawn[x][y] = v;
		
		if(maxr[x]<v){ maxr[x] = v; }
		if(maxc[y]<v){ maxc[y] = v; }
	}

	public Boolean chk(){
		int i,j;
		Boolean[][] able = new Boolean[row][col];
		Boolean     yes  = true;
		
		//check Row & Column Line
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				if(lawn[i][j]==maxr[i] || lawn[i][j]==maxc[j]){
					able[i][j] = true;
				}
				else
					able[i][j] = false;
			}
		}		
		
		//check AbleFlag
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				yes = yes & able[i][j];
			}
		}		

		return yes;
	}
}
