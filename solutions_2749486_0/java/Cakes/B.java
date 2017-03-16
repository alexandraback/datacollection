import java.io.*;
import java.awt.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class B {
	
	PrintWriter out;
	BufferedReader f;

	public void run()throws Exception{
		f = new BufferedReader(new FileReader("B-small-attempt1.in"));
	    out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
	    int datasets = Integer.parseInt(f.readLine());
	    for(int x = 0; x<datasets; x++){
	    	out.print("Case #"+(x+1)+": ");
	    	//System.out.print("Case #"+(x+1)+": ");
	   		StringTokenizer a = new StringTokenizer(f.readLine());
	   		int X = Integer.parseInt(a.nextToken());
	   		int Y = Integer.parseInt(a.nextToken());
	   		String seq = "";
	   		int tX = 0, tY = 0;
	   		int jump = 1;
	   		while(tX!=X||tY!=Y){
	   			boolean work = false;
	   			if(tX<X){
	   				if(tX+jump<=tX){
	   					work = true;
	   					tX+=jump;
	   					seq+="E";
	   					jump++;
	   				}
	   			}
	   			else if(tX>X){
	   				if(tX-jump>=tX){
	   					work = true;
	   					tX-=jump;
	   					seq+="W";
	   					jump++;
	   				}
	   			}if(tY<Y){
	   				if(tY+jump<=tY){
	   					work = true;
	   					tY+=jump;
	   					seq+="N";
	   					jump++;
	   				}
	   			}
	   			else if(tY>Y){
	   				if(tY-jump>=tY){
	   					work = true;
	   					tY-=jump;
	   					seq+="S";
	   					jump++;
	   				}
	   			}
	   			if(!work){
	   				while(tX!=X){
	   					if(tX<X){
	   						tX++;
	   						seq+="WE";
	   					}
	   					else{
	   						tX--;
	   						seq+="EW";
	   					}
	   				}
	   				while(tY!=Y){
	   					if(tY<Y){
	   						tY++;
	   						seq+="SN";
	   					}
	   					else{
	   						tY--;
	   						seq+="NS";
	   					}
	   				}
	   			}
	   		}
	   		out.println(seq);
	   		//Queue<Object[]> que = new LinkedList<Object[]>();
	   		//que.add(new Object[]{0,0,1,""});
	   		/*while(!que.isEmpty()){
	   			Object[] temp = que.remove();
	   			int tX = (int)temp[0];
	   			int tY = (int)temp[1];
	   			int jump = (int)temp[2];
	   			String cur = (String)temp[3];
	   			if(tX==X&&tY==Y){
	   				//System.out.println(tX+" "+tY);
	   				out.println(cur);
	   				System.out.println(cur);
	   				break;
	   			}
	   			que.add(new Object[]{tX,tY+jump,jump+1,cur+"N"});
	   			que.add(new Object[]{tX,tY-jump,jump+1,cur+"S"});
	   			que.add(new Object[]{tX+jump,tY,jump+1,cur+"E"});
	   			que.add(new Object[]{tX-jump,tY,jump+1,cur+"W"});
	   		}*/
	    }
	    out.close();
	    System.exit(0);
	}

    public static void main (String [] args) throws Exception {
		new B().run();
    }
}
