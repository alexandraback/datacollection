package com;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class MinesweeperMaster {

    public static void main(String[] args) {
        
        String base="files/";
        String in=base + "C-large.in";
        String out=base + "output1.txt";
        
        
	    try {
	    	BufferedReader br = new BufferedReader(new FileReader(in));
	        
	        StringBuilder sb = new StringBuilder();
	        String line = br.readLine();
	        
	        int tctotal = 0;
	        int tc = 0;
	        int i = -1;
	        
	        while (line != null) {
	        	i++;
	        	
		        if(i == 0){
	        		tctotal = Integer.parseInt(line);
	        		tc = 1;
	        	} else {
	        		String [] parse = line.split(" ");
	        		
	        		int r = Integer.parseInt(parse[0]);
	        		int c = Integer.parseInt(parse[1]);
	        		int m = Integer.parseInt(parse[2]);
	        		
	        		// Generate Minefield with mines
	        		char [][] minefield = new char[r][c];
	        		
	        		for(int a=0; a<r; a++){
	        			for(int b=0; b<c; b++){
	        				minefield[a][b] = '*';
	        			}
	        		}
	        		
	        		// Plot spaces
	        		int sp = r*c - m;
	        		
	        		boolean p = true;
	        		if(sp<0 || c<=0 || r<=0){
	        			// Impossible
	        			p = false;
	        		} else {
	        			// plot
	        			if(sp%2 == 0){
	        				// in a two styled
	        				// if only  columns to be used
	        				if(r==1){
	        					plot(minefield, 0, 1, sp);
	        				} else {
	        					int leftover = sp;
	        					
	        					if(leftover<c*2){
	        						plot(minefield, 0, 2, leftover);
	        						int loner = leftover % 2;
	        						if(loner == 1 && leftover >2){
	        							shiftmine(minefield, 1, leftover/2-1 , 0, leftover/3);
	        						}
	        						leftover = 0;
	        					} else {
	        						plot(minefield, 0, 2, c*2);
	        						leftover = leftover - c * 2;
	        					}
	        					
	        					int a = 2;
	        					
	        					int loner = -1;
		        				int lastrow = a-1;
		        				
	        					while (leftover > c){
	        						plot(minefield, a, 1, c);
	        						
        							leftover = leftover - c;
	        						lastrow = a;
	        						a++;
	        					}
	        					if (leftover >0){
		        					loner = leftover;
		        					plot(minefield, a, 1, leftover);
		        					
		        					if(loner == 1 && r > 1 && c > 1){
		        						try{
		        							shiftmine(minefield, lastrow+1, 1 , lastrow, c-1);
		        						} catch(ArrayIndexOutOfBoundsException e){
		        							System.out.println((lastrow+1) +","+1+","+lastrow+","+(c-1));
		        							System.out.println(tc);
		        							e.printStackTrace();
		        						}
			        				}
	        					}
	        					
	        				}
	        			} else{
	        				// in a three styled
	        				
	        				if(r==1){
	        					plot(minefield, 0, 1, sp);
	        				} else if(r==2){
	        					plot(minefield, 0, 2, sp);	
	        				} else {
	        					
	        					int leftover = sp;
	        					
	        					if(leftover<c*3){
	        						plot(minefield, 0, 3, leftover);
	        						int loner = leftover % 3;
	        						if(loner == 1 && leftover >3){
	        							shiftmine(minefield, 2, leftover/3-1 , 1, leftover/3);
	        						}
	        						leftover = 0;
	        					} else {
	        						plot(minefield, 0, 3, c*3);
	        						leftover = leftover - c * 3;
	        					}
	        					
	        					int a = 3;
	        					int loner = -1;
		        				int lastrow = a-1;
		        				
	        					while (leftover > c){
	        						plot(minefield, a, 1, c);
	        						
        							leftover = leftover - c;
	        						lastrow = a;
	        						a++;
	        					}
	        					if(leftover > 0){
		        					plot(minefield, a, 1, leftover);
		        					loner = leftover;
		        					if(loner == 1 && r > 1 && c > 1){
		        						try{
		        							shiftmine(minefield, lastrow+1, 1 , lastrow, c-1);
		        						} catch(ArrayIndexOutOfBoundsException e){
		        							System.out.println((lastrow+1) +","+1+","+lastrow+","+(c-1));
		        							System.out.println(tc);
		        							e.printStackTrace();
		        						}
			        				}
	        					}
	        				}
	        				
	        				
	        				
	        			}
	        		}
	        		
	        		// set starting point
	        		if(sp!=0){
	        			minefield[0][0] = 'c';
	        		}
	        		
	        		String possible;
	        		if(p == false){
	        			possible = "Impossible";
	        			//possible =  "Impossible\n" + minefieldtostring(minefield);
	        		} else {
	        			possible = checkPossibility(minefield, sp);	
	        		}
	        		sb.append("Case #"+tc+":");
	        		//sb.append(System.lineSeparator());
	        		//sb.append(line);
	        		sb.append(System.lineSeparator());
	        		sb.append(possible);
	        		sb.append(System.lineSeparator());
	        		tc++;
	        	}
		        
	        	line = br.readLine();
	        }
	        
	        String everything = sb.toString();
	        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(
	                new FileOutputStream("files/output.txt"), "utf-8"));
	          writer.write(everything);
	          writer.close();
	    } catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
	    }
    }
    
    public static void plot(char[][] minefield, int currentrow, int style, int num){
    	if(style == 1){
    		for(int i =0; i<num; i++){
    			minefield[currentrow][i] = '.';
    		}
    	} else if (style == 2){
    		for(int i =0; i<num/2; i++){
    			minefield[currentrow][i] = '.';
    			minefield[currentrow+1][i] = '.';
    		}
    		if(num%2 == 1){
    			minefield[currentrow][num/2] = '.';
    		}
    	} else if (style == 3){
    		for(int i =0; i<num/3; i++){
    			minefield[currentrow][i] = '.';
    			minefield[currentrow+1][i] = '.';
    			minefield[currentrow+2][i] = '.';
    		}
    		if(num%3 == 1){
    			minefield[currentrow][num/3] = '.';
    		} else if (num%3 == 2){
    			minefield[currentrow][num/3] = '.';
    			minefield[currentrow+1][num/3] = '.';
    		}
    	}
    }
    
    public static void shiftmine(char[][]minefield, int ar, int ac, int br, int bc){
    	char t1 = minefield[ar][ac];
    	minefield[ar][ac] = minefield[br][bc];
    	minefield[br][bc] = t1;
    }
    private static class Tuple{
    	public int r;
    	public int c;
    	public Tuple(int r,int c){
    		this.r = r;
    		this.c = c;
    	}
    }
    public static String checkPossibility(char[][]minefield, int sp){
    	if(sp<=0){
    		return "Impossible";
    	} else {
    		// traverse
    		checked = new boolean[minefield.length][minefield[0].length];
    		traversed = new boolean[minefield.length][minefield[0].length];
    		
			if(!canExtend(minefield, 0, 0)){
				if(sp!=1){
					//return "Impossible\n" + minefieldtostring(minefield);
					return "Impossible";
				} else {
					return minefieldtostring(minefield);
				}
			} else {
				// BFS
				Tuple tuple = new Tuple(0, 0);
				ArrayList<Tuple> queue = new ArrayList<Tuple>();
				queue.add(tuple);
				
				int c = 1;
				while(!queue.isEmpty()){
					Tuple node = queue.remove(0);
					ArrayList<Tuple> newnodes = traverse(minefield, node.r, node.c);
					queue.addAll(newnodes);
					c = c+ newnodes.size();
				}
				if(c==sp){
					return minefieldtostring(minefield);
				} else {
					//return "Impossible\n" + minefieldtostring(minefield);
					return "Impossible";
				}
				
			}
    	}
    }
    
    public static boolean[][] checked;
    public static boolean[][] traversed;
    public static ArrayList<Tuple> traverse(char[][] minefield, int r, int c){
    	ArrayList<Tuple> nodes = new ArrayList<Tuple>();
    	checked[r][c] = true;
    	traversed[r][c] = true;
    	
    	if(canExtend(minefield, r, c)){
	    	if(c+1 < minefield[0].length){
	    		if(minefield[r][c+1] == '.'){		
	    			checked[r][c+1] = true;
	    		}
	    		if(!traversed[r][c+1]){
	    			nodes.add(new Tuple(r,c+1));
	    			traversed[r][c+1] = true;
	    		}
	    	}
	    	if(r+1 < minefield.length){
	    		if(minefield[r+1][c] == '.'){		
	    			checked[r+1][c] = true;
	    		}
	    		if(!traversed[r+1][c]){
	    			nodes.add(new Tuple(r+1,c));
	    			traversed[r+1][c] = true;
	    		}
	    	}
	    	if(r+1 < minefield.length && c+1 < minefield[0].length){
	    		if(minefield[r+1][c+1] == '.'){		
	    			checked[r+1][c+1] = true;
	    		}
	    		if(!traversed[r+1][c+1]){
	    			nodes.add(new Tuple(r+1,c+1));
	    			traversed[r+1][c+1] = true;
	    		}
	    	}
    	}
    	
    	return nodes;
    	
    }
    public static boolean canExtend(char[][] minefield, int r, int c){
    	
    	if(c+1<minefield[0].length && r+1 < minefield.length ){
    		if(minefield[r+1][c+1] == '*'){
    			return false;
    		}
    	}
    	
    	if(r+1<minefield.length){
    		if(minefield[r+1][c] == '*'){
    			return false;
    		}
    	}
    	
    	if(c+1<minefield[0].length){
    		if(minefield[r][c+1] == '*'){
    			return false;
    		}
    	}
    	
    	return true;
    	
    }
    
    public static String minefieldtostring(char[][] minefield){
    	StringBuilder sb = new StringBuilder();
    	for(int a = 0; a<minefield.length; a++){
    		for(int b=0; b<minefield[a].length; b++){
    			sb.append(minefield[a][b]);
    		}
    		if(a+1 != minefield.length){
    			sb.append(System.lineSeparator());
    		}
    	}
    	
    	
    	return sb.toString();
    }
}

