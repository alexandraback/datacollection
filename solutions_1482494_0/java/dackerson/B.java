import java.util.*;

public class B{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int numCases = sc.nextInt();
		for(int caseNum = 1; caseNum <= numCases; caseNum++){
			int n = sc.nextInt();
			LinkedList<Pair> list = new LinkedList<Pair>();
			for(int i = 0; i < n; i++){
				list.add(new Pair(sc.nextInt(), sc.nextInt()));
			}
			int stars = 0;
			Comparator sortFirst = new SortByFirst();//, sortSecond = new SortBySecond();
			Collections.sort(list, sortFirst);
			int count = 0;

			loop:
			while(stars < (2 * n)){
				count++;
				for(Pair p : list){
					if(!p.bTaken && p.b <= stars){
						p.bTaken = true;
						if(p.aTaken){
							stars++;
						}
						else{
							stars += 2;
						}
						continue loop;
					}
				}
				for(Pair p : list){
					if(!p.aTaken && p.a <= stars){
						p.aTaken = true;
						stars++;
						continue loop;
					}
				}
				count = -1;
				break;
			}

			String msg = null;
			if(count == -1){
				msg = "Too Bad";
			}
			else{
				msg = "" + count;
			}
			System.out.printf("Case #%d: %s\n", caseNum, msg);
		}
	}
	static class SortByFirst implements Comparator<Pair>{
		public int compare(Pair a, Pair b){
			if(a.a > b.a){
				return 1;
			}
			else if (a.a == b.a){
				if(a.b > b.b){
					return -1;
				}
				else if (a.b == b.b){
					return 0;
				}
				else{
					return 1;
				}
			}
			else{
				return -1;
			}
		}
		public boolean equals(Object a){
			return false;
		}
	}
	static class SortBySecond implements Comparator<Pair>{
		public int compare(Pair a, Pair b){
			if(a.b > b.b){
				return 1;
			}
			else if (a.b == b.b){
				return 0;
			}
			else{
				return -1;
			}
		}
		public boolean equals(Object a){
			return false;
		}
	}
	static class Pair{
		boolean aTaken;
		boolean bTaken;
		int a;
		int b;
		public Pair(int A, int B){
			aTaken = false;
			bTaken = false;
			a = A;
			b = B;
		}
	}
}