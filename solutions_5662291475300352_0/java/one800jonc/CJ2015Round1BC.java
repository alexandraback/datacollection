import java.io.*;
import java.util.*;


public class CJ2015Round1BC {
	public static class Hiker {
		double pos;
		double speed;
		public Hiker(double pos, double speed){
			this.pos=pos;
			this.speed=speed;
		}
		
		public Hiker clone(){
			return new Hiker(this.pos,this.speed);
		}
	}
	
	public static class HikerComparator implements Comparator<Hiker> {
		double curpos;
		public HikerComparator(double curpos){
			this.curpos = curpos;
		}
		@Override
		public int compare(Hiker a, Hiker b) {
			int c = (int) ((a.pos-curpos)%360 - (b.pos-curpos)%360);
			if (c!=0){
				return c;
			}
			else {return (int) (a.speed-b.speed);}
		}
	}
	
	public static double nextHit(List<Hiker> hikers){
		Hiker first = hikers.get(0);
		List<Double> times = new ArrayList<Double>();
		for(int i = 1; i<hikers.size();i++){
			Hiker now = hikers.get(i);
			if(first.speed!=now.speed){
				double speeddiff = Math.abs(first.speed-now.speed);
				if (first.speed>now.speed){
					double locdiff = (now.pos-first.pos)%360;
					if(locdiff==0)locdiff=360;
					times.add(locdiff/speeddiff);
				} else {
					double locdiff = (first.pos-now.pos)%360;
					if(locdiff==0)locdiff=360;
					times.add(locdiff/speeddiff);
				}
			}
		}
		if (times.isEmpty()){return 0;}
		return Collections.min(times);
	}
	
	public static void updateHikers(List<Hiker> hikers, double time){
		for (Hiker h : hikers){
			h.pos+=time*h.speed;
			h.pos%=360;
		}
	}
	
	public static int findCol(List<Hiker> hikers,double curpos){
		Collections.sort(hikers, new HikerComparator(curpos));
		double newpos = hikers.get(0).pos;
		if (newpos<curpos) return 0;
		double time = nextHit(hikers);
		if (time == 0) return 0;
		if (hikers.get(0).speed*time+hikers.get(0).pos >360){return 0;}
		updateHikers(hikers,time);
		Collections.sort(hikers, new HikerComparator(newpos));
		List<Hiker> newhikers= new ArrayList<Hiker>();
		for(Hiker h : hikers) {
		    newhikers.add(h.clone());
		}
		if (newhikers.size()==2){return 1;}
		return 1 + Math.min(findCol(hikers,newpos),findCol(newhikers,newhikers.get(2).pos));
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("C-small-1-attempt1.in"));
		//BufferedReader in = new BufferedReader(new FileReader("temp.txt"));
		PrintWriter out  = new PrintWriter(new File("2015Round1BCout.txt"));
		int T = Integer.parseInt(in.readLine());
		for(int a = 1; a < T+1; a++){
			int N = Integer.parseInt(in.readLine());
			List<Hiker> hikers = new ArrayList<Hiker>();
			for(int b = 0; b < N; b++){
				String[] ayo = in.readLine().split(" ");
				int D = Integer.parseInt(ayo[0]);
				int H = Integer.parseInt(ayo[1]);
				int M = Integer.parseInt(ayo[2]);
				for(int i = 0; i < H; i++){
					hikers.add(new Hiker(D,M+i));
				}
			}
			int ret = findCol(hikers,0);
			System.out.println("Case #"+a+": "+ret);
			out.println("Case #"+a+": "+ret);
		}
		in.close();
		out.close();
	}
}
