import java.util.*;


public class Jamthree {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		
		
		for(int i=0;i<t;i++) {
			int h[]=new int[800];
			//h at -200 is h[0], h at 200 is h[800]
			int n=sc.nextInt();
			ArrayList<Attack> list=new ArrayList<Attack>();
			for(int j=0;j<n;j++) {
				int dj=sc.nextInt();
				int nj=sc.nextInt();
				int wj=sc.nextInt();
				int ej=sc.nextInt();
				int sj=sc.nextInt();
				int ddj=sc.nextInt();
				int dpj=sc.nextInt();
				int dsj=sc.nextInt();
				
				for(int k=0;k<nj;k++) {
					list.add(new Attack(wj,ej,dj,sj));
					dj+=ddj;
					wj+=dpj;
					ej+=dpj;
					sj+=dsj;
				}
			}
			
			Collections.sort(list,new Mycomparator());
			
			int m=list.size();
			int current=0;
			int next[]=new int[800];
			int ans=0;
			for(int j=0;j<m;j++) {
				boolean success=false;
				if(current<list.get(j).date) {
					for(int k=0;k<800;k++) {
						h[k]=next[k];
					}
		//		System.out.println("rebuild");
				}
				current=list.get(j).date;
				for(int k=list.get(j).left*2+400; k<=list.get(j).right*2+400;k++) {
					if(list.get(j).strength>h[k]) {
						success=true;
						next[k]=Math.max(next[k],list.get(j).strength);
					}
				}
				if(success) ans++;
		//		System.out.println(list.get(j).left+" "+list.get(j).right+" "+list.get(j).date+" "+list.get(j).strength+" "+success);
			}
			System.out.println("Case #"+(i+1)+": "+ans);
		}
		
		
		
	} 

}
class Attack{
	int left;
	int right;
	int date;
	int strength;
	Attack(int l, int r, int d, int s) {
		left=l;
		right=r;
		date=d;
		strength=s;
	}
	
}

class Mycomparator implements Comparator<Attack> {
	public int compare(Attack a, Attack b) {
		return a.date-b.date;
	}
}
