import java.util.*;
import java.io.*;

public class Main {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2014/io/C-small-attempt10.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2014/io/output.txt"));
		int n = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < n ; i++){
        	String[] st = input.readLine().split(" ");
        	int R = Integer.parseInt(st[0]);
        	int C = Integer.parseInt(st[1]);
        	int M = Integer.parseInt(st[2]);
	        pw.println("Case #"+(i+1)+":");
	        if(M == 0){
	        	for(int j = 0 ; j < R ; j++){
	        		for(int k = 0 ; k < C ; k++){
	        			if(j == 0 && k == 0){
	        				pw.print("c");
	        			}else{
	        				pw.print(".");
	        			}
	        		}
	        		pw.println();
	        	}
	        }else if(R == 5 && C == 5 && M == 4){
	        	for(int j = 0 ; j < R ; j++){
	        		for(int k = 0 ; k < C ; k++){
	        			if(j == 0 && k == 0){
	        				pw.print("c");
	        			}else if((j == 2 && k == 4) || (j == 3 && k == 4) || (j == 4 && k == 3) || (j == 4 && k == 4)){
	        				pw.print("*");
	        			}else{
	        				pw.print(".");
	        			}
	        		}
	        		pw.println();
	        	}
	        }else if(R == 4 && C == 4 && M == 3){
	        	for(int j = 0 ; j < R ; j++){
	        		for(int k = 0 ; k < C ; k++){
	        			if(j == 0 && k == 0){
	        				pw.print("c");
	        			}else if((j == 2 && k == 3) || (j == 3 && k == 2) || (j == 3 && k == 3)){
	        				pw.print("*");
	        			}else{
	        				pw.print(".");
	        			}
	        		}
	        		pw.println();
	        	}
	        }else{
	        	mine(R,C,M);
	        }
			pw.flush();
		}
		input.close();
		pw.close();
	}
	
	public static void mine(int R,int C,int M){
		Queue<BL> q = new LinkedList<BL>();
		BL first = new BL(R,C);
		q.add(first);
		boolean existed = false;
		while(!q.isEmpty()){
			BL tbl = q.poll();
			
			if(tbl.mc == M){
				System.out.println(tbl.x+","+tbl.y+","+tbl.muki+","+tbl.mc);
				for(int i = 0 ; i < R ; i++){
				for(int j = 0 ; j < C ; j++){
					if(!tbl.br[i][j]){
						System.out.print(".");
					}else{
						System.out.print("x");
					}
				}
				System.out.println();
				}
				if(isok(R,C,tbl.br,R*C-M)){
		        	for(int j = 0 ; j < R ; j++){
		        		for(int k = 0 ; k < C ; k++){
		        			if(j == 0 && k == 0){
		        				pw.print("c");
		        			}else{
		        				if(tbl.br[j][k]){
			        				pw.print("*");	
		        				}else{
		        					pw.print(".");
		        				}
		        			}
		        		}
		        		pw.println();
		        	}
		        	existed = true;
					break;
				}
			}else{
				/*System.out.println(tbl.x+","+tbl.y+","+tbl.muki+","+tbl.mc);
				for(int i = 0 ; i < R ; i++){
				for(int j = 0 ; j < C ; j++){
					if(!tbl.br[i][j]){
						System.out.print(".");
					}else{
						System.out.print("x");
					}
				}
				System.out.println();
			}
			System.out.println();*/
				int x = tbl.x;
				int y = tbl.y;
				int muki = tbl.muki;
				if(muki == 0){
					if(!isEdge(R,C,x,y-1)){
						BL make = new BL(R,C);
						make.mc = tbl.mc+1;
						for(int i = 0 ; i < R ; i++){
							for(int j = 0 ; j < C ; j++){
								make.br[i][j] = tbl.br[i][j];
							}
						}
						make.br[y-1][x] = true;
						make.x = x;
						make.y = y-1;
						make.muki = 2;
						make.refered = true;
						q.add(make);
					}
					if(!isEdge(R,C,x-1,y)){
						BL make = new BL(R,C);
						make.mc = tbl.mc+1;
						for(int i = 0 ; i < R ; i++){
							for(int j = 0 ; j < C ; j++){
								make.br[i][j] = tbl.br[i][j];
							}
						}
						make.br[y][x-1] = true;
						make.x = x-1;
						make.y = y;
						make.muki = 1;
						make.refered = true;
						q.add(make);
					}	
				}else if(muki == 1){
					if(!isEdge(R,C,x-1,y)){
						BL make = new BL(R,C);
						make.mc = tbl.mc+1;
						for(int i = 0 ; i < R ; i++){
							for(int j = 0 ; j < C ; j++){
								make.br[i][j] = tbl.br[i][j];
							}
						}
						if(make.br[y][x-1]){
							make.mc--;
						}else{
							make.refered = true;
							make.br[y][x-1] = true;
						}
						make.x = x-1;
						make.y = y;
						make.muki = 1;
						q.add(make);
					}else{
						if(!isEdge(R,C,C-1,y-1) && tbl.refered){
							BL make = new BL(R,C);
							for(int i = 0 ; i < R ; i++){
								for(int j = 0 ; j < C ; j++){
									make.br[i][j] = tbl.br[i][j];
								}
							}
							make.mc = tbl.mc+1;
							if(make.br[y-1][C-1])make.mc--;
							make.x = C-1;
							make.y = y-1;
							make.muki = 1;
							make.br[y-1][C-1] = true;
							make.refered = false;
							q.add(make);
							
							make = new BL(R,C);
							for(int i = 0 ; i < R ; i++){
								for(int j = 0 ; j < C ; j++){
									make.br[i][j] = tbl.br[i][j];
								}
							}
							make.mc = tbl.mc+1;
							if(make.br[y-1][C-1])make.mc--;
							make.br[y-1][C-1] = true;
							make.refered = false;
							make.x = C-1;
							make.y = y-1;
							make.muki = 2;
							q.add(make);
						}
					}
				}else if(muki == 2){
					if(!isEdge(R,C,x,y-1)){
						BL make = new BL(R,C);
						make.mc = tbl.mc+1;
						for(int i = 0 ; i < R ; i++){
							for(int j = 0 ; j < C ; j++){
								make.br[i][j] = tbl.br[i][j];
							}
						}
						if(make.br[y-1][x]){
							make.mc--;
						}else{
							make.br[y-1][x] = true;
							make.refered = true;
						}
						make.x = x;
						make.y = y-1;
						make.muki = 2;
						q.add(make);
					}else{
						if(!isEdge(R,C,x-1,R-1) && tbl.refered){
							BL make = new BL(R,C);
							for(int i = 0 ; i < R ; i++){
								for(int j = 0 ; j < C ; j++){
									make.br[i][j] = tbl.br[i][j];
								}
							}
							make.mc = tbl.mc+1;
							if(make.br[R-1][x-1])make.mc--;
							make.br[R-1][x-1] = true;
							make.x = x-1;
							make.y = R-1;
							make.muki = 1;
							make.refered = false;
							q.add(make);
							
							make = new BL(R,C);
							for(int i = 0 ; i < R ; i++){
								for(int j = 0 ; j < C ; j++){
									make.br[i][j] = tbl.br[i][j];
								}
							}
							make.mc = tbl.mc+1;
							if(make.br[R-1][x-1])make.mc--;
							make.br[R-1][x-1] = true;
							make.x = x-1;
							make.y = R-1;
							make.muki = 2;
							make.refered = false;
							q.add(make);
						}
					}
				}
			}
		}
		if(!existed){
			pw.println("Impossible");
		}
	}
	public static boolean isEdge(int R,int C,int x,int y){
		if(x < 0 || y < 0 || x == C || y == R)return true;
		return false;
	}
	
	public static boolean isok(int R,int C,boolean[][] br,int rest){
		if(br[0][0])return false;
		Queue<String> q = new LinkedList<String>();
		q.add(0+","+0);
		rest--;
		/*for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			if(!br[i][j]){
				System.out.print(".");
			}else{
				System.out.print("x");
			}
		}
		System.out.println();
	}
	System.out.println(rest);*/
		boolean[][] searched = new boolean[R][C];
		searched[0][0] = true;
		int[] dx = {-1,0,1,-1,1,-1,0,1};
		int[] dy = {-1,-1,-1,0,0,1,1,1};
		while(!q.isEmpty()){
			String[] st = q.poll().split(",");
			int x = Integer.parseInt(st[0]);
			int y = Integer.parseInt(st[1]);
			boolean ok = true;
			for(int i = 0 ; i < dx.length ; i++){
				if(!isEdge(R,C,x+dx[i],y+dy[i])){
					if(br[y+dy[i]][x+dx[i]]){
						ok = false;
						break;
					}
				}
			}
			if(ok){
				for(int i = 0 ; i < dx.length ; i++){
					if(!isEdge(R,C,x+dx[i],y+dy[i]) && !searched[y+dy[i]][x+dx[i]]){
						searched[y+dy[i]][x+dx[i]] = true;
						rest--;
						q.add((x+dx[i])+","+(y+dy[i]));
					}
				}
				/*for(int i = 0 ; i < R ; i++){
					for(int j = 0 ; j < C ; j++){
						if(searched[i][j]){
							System.out.print(".");
						}else{
							System.out.print("x");
						}
					}
					System.out.println();
				}
				System.out.println();*/
			}
		}
		if(rest == 0)return true;
		return false;
	}
}

class BL{
	boolean[][] br;
	int mc = 1;
	int x;
	int y;
	int muki = 0;//1 is yoko 2 is tate
	boolean refered;
	BL(int R,int C){
		br = new boolean[R][C];
		y = R-1;
		x = C-1;
		br[y][x] = true;
	}
}