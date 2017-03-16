/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package greatwall;

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 *
 * @author rickyjeremiah
 */
public class GreatWall {

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		try{

			
			//System.out.println(dcs);
			
			Scanner sc = new Scanner(new File("input.txt"));
			FileWriter fw = new FileWriter("output.txt");

			int t = sc.nextInt();
			
			long res = 0;
			int n;
			int[] d,at,w,e,s,dd,dp,ds;
			int[] wall;
			
			PriorityQueue<Item> pq = new PriorityQueue<Item>();
			ArrayList<Item> upd = new ArrayList<Item>();
			
			for(int tc = 1; tc<=t ; tc++){
				res = 0;
				wall = new int[800];
				
				n = sc.nextInt();
				
				d = new int[n];
				at = new int[n];
				w = new int[n];
				e = new int[n];
				s = new int[n];
				dd = new int[n];
				dp = new int[n];
				ds = new int[n];
				
				
				for(int i=0;i<n;i++){
					d[i] = sc.nextInt();
					at[i] = sc.nextInt()-1;
					w[i] = sc.nextInt()+400;
					e[i] = sc.nextInt()+400;
					s[i] = sc.nextInt();
					dd[i] = sc.nextInt();
					dp[i] = sc.nextInt();
					ds[i] = sc.nextInt();
					
					pq.add(new Item(i,-d[i]));
				}
				
				upd.clear();
				
				Item cur;
				for(int time=0;time<70000000;time++){
					
					if(pq.isEmpty()) break;
					cur = pq.peek();
						
					while(cur.getDay()==-time){
						int id = cur.getId();
						
						boolean succ = false;
						for(int x=w[id];x<e[id];x++){
							if(wall[x]<s[id]){
								succ = true;
								res++;
								break;
							}
						}
						
						upd.add(cur);
						
						
						cur = pq.poll();
						
						if(pq.isEmpty()) break;
						cur = pq.peek();
					}
					
					if(!upd.isEmpty()){
						for(Item itm:upd){
							int id = itm.getId();
							
							for(int x=w[id];x<e[id];x++){
								if(wall[x]<s[id]){
									wall[x] = s[id];
								}
							}
							
							if(at[id]>0){
								at[id]--;
								d[id]+=dd[id];
								w[id]+=dp[id];
								e[id]+=dp[id];
								s[id]+=ds[id];
								pq.add(new Item(id,-d[id]));
							}
						}
						upd.clear();
					}
				}
				
				
				System.out.println("Case #"+tc+": "+res);
				fw.write("Case #"+tc+": "+res+"\n");
			}
			
			fw.close();

		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
	}
}


class Item implements Comparable<Item> {
	private Integer id;
	private Integer day;
	
	public Item(Integer id, Integer day){
		this.id = id;
		this.day = day;
	}
	
	@Override
	public int compareTo(Item item){
		if(this.day!=item.day){
			return item.day.compareTo(this.day);
		}
		return this.id.compareTo(item.id);
	}
	
	@Override
	public String toString(){
		return id+":"+day;
	}

	public Integer getDay() {
		return day;
	}

	public void setDay(Integer day) {
		this.day = day;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}
}
