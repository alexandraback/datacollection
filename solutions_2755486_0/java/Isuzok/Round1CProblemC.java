import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.math.*;


public class Round1CProblemC {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Round1CProblemC hi = new Round1CProblemC();
	}
	
	public Round1CProblemC(){
		parser();
	}

	public void parser(){
		try{
			FileInputStream fstream = new FileInputStream("C-small-attempt0.in");
			//FileInputStream fstream = new FileInputStream("textfile.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			FileWriter outstream = new FileWriter("output.txt");
			BufferedWriter out = new BufferedWriter(outstream);
			
			int length = Integer.parseInt(br.readLine());
			String split[];
			for(int i = 0; i < length; ++i){
				int numberOfTribes = Integer.parseInt(br.readLine());
				
				ArrayList<Tribe> tribes = new ArrayList<Tribe>();
				HashMap<Float, Integer> wallHeight = new HashMap<>();
				
				for(int j = 0; j < numberOfTribes; ++j){
					split = br.readLine().split(" ");
					tribes.add(new Tribe(Integer.parseInt(split[0]), Integer.parseInt(split[1]), Integer.parseInt(split[2]), Integer.parseInt(split[3]), Integer.parseInt(split[4]), Integer.parseInt(split[5]), Integer.parseInt(split[6]), Integer.parseInt(split[7])));
				}
				
				int succesfulAttacks = 0;
				boolean hasMoreAttacks = true;
				while(hasMoreAttacks){
					//Get attack day
					int attackDay = 10000000;
					hasMoreAttacks = false;
					for(int j = 0; j < tribes.size(); ++j){
						if(tribes.get(j).d < attackDay && tribes.get(j).n > 0){
							attackDay = tribes.get(j).d;
							hasMoreAttacks = true;
						}
					}
					//Check if successful
					for(int j = 0; j < tribes.size(); ++j){
						if(tribes.get(j).d == attackDay && tribes.get(j).n > 0){
							for(double p = tribes.get(j).w; p <= tribes.get(j).e; p+=0.5){
								Float point = new Float(p);
//								if(attackDay == 10){
//									System.out.println(p);
//									System.out.println(wallHeight.containsKey(point));
//								}
								if(wallHeight.containsKey(point)){
									if(wallHeight.get(point) < tribes.get(j).s){
										succesfulAttacks++;
										break;
									}
								} else{
									succesfulAttacks++;
									break;
								}
							}
						}
					}
					
					//Update wall height
					for(int j = 0; j < tribes.size(); ++j){
						if(tribes.get(j).d == attackDay && tribes.get(j).n > 0){
							for(double p = tribes.get(j).w; p <= tribes.get(j).e; p+=0.5){
								Float point = new Float(p);
								if(wallHeight.containsKey(point)){
									if(wallHeight.get(point) < tribes.get(j).s){
										wallHeight.put(point, tribes.get(j).s);
									}
								} else{
									wallHeight.put(point, tribes.get(j).s);
								}
							}
							tribes.get(j).doAttack();
						}
					}
				}
				
				
				System.out.println("Case #" + (i+1) + ": " + succesfulAttacks);
				out.write("Case #" + (i+1) + ": " + succesfulAttacks);
				out.newLine();
				out.flush();
				
			}
		}
		catch(Exception e){
			System.err.println("Error: " + e.getMessage());
			System.out.println("Bah!");
			e.printStackTrace();
		}
	}
	
	private int stepsLeft(int goal, int pos){
		if(goal < 0){
			if(pos <= goal){
				return (goal-pos);
			}
			else{
				return (goal-pos)*-1;
			}
		} else {
			if(pos <= goal){
				return (goal-pos);
			}
			else{
				return (goal-pos)*-1;
			}
		}
	}
	
	private class Tribe{
		public int d;
		public int n;
		public int w;
		public int e;
		public int s;
		public int delta_d;
		public int delta_p;
		public int delta_s;
		
		public Tribe(int d, int n, int w, int e, int s, int delta_d, int delta_p, int delta_s){
			this.d = d;
			this.n = n;
			this.w = w;
			this.e = e;
			this.s = s;
			this.delta_d = delta_d;
			this.delta_p = delta_p;
			this.delta_s = delta_s;
		}
		
		public void doAttack(){
			n--;
			d += delta_d;
			w += delta_p;
			e += delta_p;
			s += delta_s;
		}
		
	}
}
