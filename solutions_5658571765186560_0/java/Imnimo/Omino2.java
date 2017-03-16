import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class Omino2 {
	public static void main(String[] args) throws Exception {
		generatePieces(4);
		/*for(int size = 1;size<=4;size++) {
			for(Piece p : allPieces.get(size)) {
				System.out.println(size + " " + p);
			}
		}*/
		
		Scanner s = new Scanner(new File("D-small-attempt0.in"));
		
		int numCases = Integer.parseInt(s.nextLine());
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			String line = s.nextLine();
			String[] lineArr = line.split("\\s+");
			int x = Integer.parseInt(lineArr[0]);
			int r = Integer.parseInt(lineArr[1]);
			int c = Integer.parseInt(lineArr[2]);
			
			
			boolean richardWins = false;
			for(Piece p : allPieces.get(x)) {
				//System.out.println("Checking " + p);
				if(!canSolveWithRotRef(r,c,p,new ArrayList<Piece>(allPieces.get(x)))) {
					//System.out.println("Richard wins by picking " + p);
					richardWins = true;
				}
			}
			
			System.out.print("Case #" + currentCase + ": ");
			if(richardWins) {
				System.out.println("RICHARD");
			} else {
				System.out.println("GABRIEL");
			}
			
		}
		/*
		for(Piece p : allPieces.get(4)) {
			System.out.println(p);
			System.out.println(canSolveWithRotRef(4,3,p,new ArrayList<Piece>(allPieces.get(4))));
		}
		*/
	}
	
	public static boolean canSolveWithRotRef(int r, int c, Piece p, ArrayList<Piece> otherPieces) {
		Piece rot = p;
		for(int deg = 0;deg<360;deg+=90) {
			rot = rot.rotate();
			//System.out.println("ROT: " + rot);
			if(canSolve(r,c,rot,otherPieces)) {
				return true;
			}
		}
		Piece refX = p.reflectX();
		rot = refX;
		for(int deg = 0;deg<360;deg+=90) {
			 rot = rot.rotate();
			if(canSolve(r,c,rot,otherPieces)) {
				return true;
			}
		}
		Piece refY = p.reflectY();
		rot = refY;
		for(int deg = 0;deg<360;deg+=90) {
			rot = rot.rotate();
			if(canSolve(r,c,rot,otherPieces)) {
				return true;
			}
		}
		return false;
	}
	
	public static boolean canSolve(int r, int c, Piece p, ArrayList<Piece> otherPieces) {
		boolean[][] blank = new boolean[r][c];
		for(int x = 0;x<r;x++) {
			for(int y = 0;y<c;y++) {
				
				if(fits(blank,p,x,y)) {
					boolean[][] start = addPiece(blank,p,x,y);
					if(canFill(start,otherPieces,0)) {
						return true;
					}
				}
			}
		}
		return false;
	}
	
	public static boolean canFill(boolean[][] rect,ArrayList<Piece> pieces, int index) {
		
		//System.out.println("Working on: ");
		//printArr(rect);
		
		boolean allFilled = true;
		for(int x = 0;x<rect.length && allFilled;x++) {
			for(int y = 0;y<rect[0].length && allFilled;y++) {
				if(!rect[x][y]) {
					allFilled = false;
				}
			}
		}
		if(allFilled)  {
			//System.out.println("FILLED!");
			return true;
		
		
		}
		
		for(int i = index;i<pieces.size();i++) {
			for(int x = 0;x<rect.length;x++) {
				for(int y = 0;y<rect[0].length;y++) {
					if(fits(rect,pieces.get(i),x,y)) {
						//System.out.println("Adding " + pieces.get(i) + " at " + x + "," + y + " to ");
					//	printArr(rect);
						
						boolean[][] added = addPiece(rect,pieces.get(i),x,y);
						//System.out.println("Result is ");
						//printArr(added);
						
						boolean result = canFill(added,pieces,i);
						if(result) return true;
					}
				}
			}
		}
		return false;
	}
	
	public static void printArr(boolean[][] rect) {
		for(int x = 0;x<rect.length;x++) {
			for(int y = 0;y<rect[0].length;y++) {
				if(!rect[x][y]) {
					System.out.print(".");
				} else {
					System.out.print("X");
				}
			}
			System.out.println();
		}
	}
	
	public static boolean[][] addPiece(boolean[][] base, Piece p, int x, int y) {
		boolean[][] result = new boolean[base.length][base[0].length];
		for(int i = 0;i<base.length;i++) {
			System.arraycopy(base[i], 0, result[i], 0, base[i].length);
		}
		for(Coord c : p.coords) {
			result[x + c.x][y + c.y] = true;
		}
		return result;
		
	}
	public static boolean fits(boolean[][] base, Piece p, int x, int y) {
		for(Coord c : p.coords) {
			if(x + c.x >= base.length || x + c.x < 0) return false;
			if(y + c.y >= base[0].length || y + c.y < 0) return false;
			if(base[x + c.x][y + c.y]) {
				return false;
			}
		}
		return true;
	}
	
	static HashMap<Integer,HashSet<Piece>> allPieces = new HashMap<Integer,HashSet<Piece>>();
	
	public static void generatePieces(int maxSize) {
		
		
		for(int i = 1;i<=maxSize;i++) {
			allPieces.put(i,new HashSet<Piece>());
		}
		
		Coord origin = new Coord(0,0);
		HashSet<Coord> temp = new HashSet<Coord>();
		temp.add(origin);
		Piece unomino = new Piece(temp);
		allPieces.get(1).add(unomino);
		
		for(int size = 2;size<=maxSize;size++) {
			for(Piece p : allPieces.get(size-1)) {
				
				for(Coord c : p.coords) {
					for(int xOffset = -1;xOffset<=1;xOffset++) {
						for(int yOffset = -1;yOffset<=1;yOffset++) {
							if(xOffset==0 && yOffset==0) continue;
							if(xOffset!=0 && yOffset!=0) continue;
							
							Coord newCoord = new Coord(c.x + xOffset,c.y + yOffset);
							
							if(!p.containsCoord(newCoord)) {
								Piece next = p.addCoord(newCoord);
								allPieces.get(size).add(next);
							}
							
						}
					}
				}
				
			}
		}
		
	}
	
}

class Piece {
	HashSet<Coord> coords = new HashSet<Coord>();
	public Piece(HashSet<Coord> coords) {
		this.coords = coords;
		translateToOrigin();
	}
	
	public String toString() {
		return coords.toString();
	}
	
	public void translateToOrigin() {
		ArrayList<Coord> temp = new ArrayList<Coord>(coords);
		Collections.sort(temp);
		int xOffset = temp.get(0).x;
		int yOffset = temp.get(0).y;
		
		HashSet<Coord> newCoords = new HashSet<Coord>();
		for(Coord c : coords) {
			newCoords.add(new Coord(c.x - xOffset,c.y - yOffset));
		}
		coords = newCoords;
	}
	
	public Piece rotate() {
		HashSet<Coord> newCoords = new HashSet<Coord>();
		for(Coord c : coords) {
			newCoords.add(new Coord(-c.y,c.x));
		}
		return new Piece(newCoords);
	}
	
	public Piece reflectX() {
		HashSet<Coord> newCoords = new HashSet<Coord>();
		for(Coord c : coords) {
			newCoords.add(new Coord(-c.x,c.y));
		}
		return new Piece(newCoords);
	}
	public Piece reflectY() {
		
		HashSet<Coord> newCoords = new HashSet<Coord>();
		for(Coord c : coords) {
			newCoords.add(new Coord(c.x,-c.y));
		}
		return new Piece(newCoords);
	}
	
	public int size() {
		return coords.size();
	}
	
	public boolean equals(Object o) {
		if(o instanceof Piece) {
			Piece p = (Piece)o;
			if(p.size()!=size()) return false;
			for(Coord c : coords) {
				if(!p.containsCoord(c)) {
					return false;
				}
			}
			return true;
		} 
		return false;
	}
	
	
	public boolean containsCoord(Coord c) {
		return coords.contains(c);
	}
	
	
	
	public int hashCode() {
		int result = 1;
		for(Coord c : coords) {
			result *= c.hashCode();
		}
		return result;
	}
	
	public Piece addCoord(Coord c) {
		HashSet<Coord> newCoords = new HashSet<Coord>(coords);
		newCoords.add(c);
		return new Piece(newCoords);
	}
}

class Coord implements Comparable<Coord> {
	int x,y;
	public Coord(int x, int y) {
		this.x = x;
		this.y = y;
	}
	@Override
	public int compareTo(Coord o) {
		if(x<o.x) return -1;
		if(x>o.x) return 1;
		if(y<o.y) return -1;
		if(y>o.y) return 1;
		return 0;
	}
	public boolean equals(Object o) {
		if(o instanceof Coord) {
			Coord other = (Coord)o;
			return other.x == x && other.y==y;
		}
		return false;
	}
	public int hashCode() {
		return x + 500*y;
	}
	public String toString() {
		return "(" + x + "," + y + ")";
	}
}