import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Locale;
import java.util.Scanner;


public class PbD {
	
	public int n_to_empty = 0;
	public static int R;
	public static int C;
	public int[][] grid;
	
	public PbD(int[][] grid,int n){
		this.grid = myClone(grid);
		R = grid.length;
		C = grid[0].length;
		n_to_empty = n;
	}
	
	public void setValue(int[][] map, int x,int y,int value){
		int X = map.length;
		int Y = map[0].length;
		
		if(x>=0 && x<X && y>=0 && y<Y){
			if(map[x][y]==-1){
				map[x][y]=value;
				n_to_empty--;
			}
		}
	}
	
	public static void main(String[] args) {
		
		FileReader fr = null ;
    	Scanner sc = null;
    	int n_cases = 0;
    	
    	Locale.setDefault(Locale.US);
    	
    
    	try{
    		fr = new FileReader(args[0]);
    		sc = new Scanner(fr);
    		
    		if (sc.hasNextInt()) n_cases = sc.nextInt();
    		
    		for (int i=0;i<n_cases;i++){
    			
    			R = sc.nextInt();
    			C = sc.nextInt();
    			int M = sc.nextInt();
    			
    			int[][] grid_init = new int[R][C];
    			for (int x=0;x<R;x++)
    				for (int y=0;y<C;y++)
    					grid_init[x][y] = -1;
    			
    			computeCase(grid_init,i,M);
    			
    		}
    		
    	} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
    	finally{
    		if(sc != null) sc.close();
    		if(fr != null)	try {fr.close();} catch (Exception e) {}
    	}

	}

	private static void computeCase(int[][] grid_init,int i,int M) {
		for (int x=0;x<R;x++){
			for (int y=0;y<C;y++){
				int[][] grid = myClone(grid_init);
				int n = R*C-M-1;
				grid[x][y] = 2;
				
				int[][] res;
				if(n>0){
					PbD pbd = new PbD(grid,n);
					res= pbd.tryClick(x,y);
				}else
					res = grid;
				
				if(res!=null){
					System.out.println("Case #"+(i+1)+":");
					printGrid(res);
					return;
				}
			}
		}	
		System.out.println("Case #"+(i+1)+":");
		System.out.println("Impossible");
		
	}

	private static void printGrid(int[][] res) {
		for (int a=0;a<R;a++){
			for (int b=0;b<C;b++){
				int k = res[a][b];
				if (k==-1)
					System.out.print('*');
				else if (k==0 || k==1)
					System.out.print('.');
				else
					System.out.print('c');
			}
			System.out.println();
		}
	}

	private int[][] tryClick(int x, int y) {
		
		if(grid[x][y]==0)
			grid[x][y]=1;
		
		setValue(grid,x-1,y,0);
		setValue(grid,x-1,y-1,0);
		setValue(grid,x,y-1,0);
		setValue(grid,x+1,y-1,0);
		setValue(grid,x+1,y,0);
		setValue(grid,x+1,y+1,0);
		setValue(grid,x,y+1,0);
		setValue(grid,x-1,y+1,0);
		
		if(n_to_empty == 0)
			return grid;
		else if(n_to_empty <0)
			return null;
		else{ 
			for (int i=0;i<R;i++){
				for (int j=0;j<C;j++){
					if (grid[i][j] == 0){
						//System.out.println("Check : "+i+","+j+" : "+n_to_empty);
						//printGrid(grid);
						PbD pb = new PbD(grid,n_to_empty);
						int[][] res = pb.tryClick(i, j);
						if(res!=null){
							return res;
						}
					}
				}
			}
			return null;
		}
	}
	
	public static int[][] myClone(int[][] array) {
	    int rows=array.length ;

	    //clone the 'shallow' structure of array
	    int[][] newArray =(int[][]) array.clone();
	    //clone the 'deep' structure of array
	    for(int row=0;row<rows;row++){
	        newArray[row]=(int[]) array[row].clone();
	    }

	    return newArray;
	}

}
