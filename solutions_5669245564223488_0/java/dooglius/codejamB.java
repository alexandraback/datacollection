import java.util.*;

public class codejamB{
	static Scanner sin;
	static final long MOD = 1000000007;
	
	public static long factorial(int n){
		long ans = 1;
		for(int i = 2; i <= n; i++){
			ans = (ans*i)%MOD;
		}
		return ans;
	}
	
	static class Node{
		public String s;
		public boolean allsame;
		public long ans;
		public int comb;
		public char first;
		public char last;
		public boolean problem;
		public int counts[];
		public Node(String s){
			this.s=s;
			ans=1;
			first = s.charAt(0);
			last = s.charAt(s.length()-1);
			counts = new int[26];
			problem = false;
			for(int i = 0; i < 26; i++){
				counts[i]=0;
			}
			for(int i = 0; i < s.length(); i++){
				counts[s.charAt(i)-'a']++;
			}
			if(counts[s.charAt(0)-'a'] == s.length()){
				allsame = true;
				comb = 1;
				return;
			} else{
				comb = 0;
			}
			for(int i = 0; i < s.length(); i++){
				int count = counts[s.charAt(i)-'a'];
				char c = s.charAt(i);
				for(int j = 0; j < count-1; j++){
					i++;
					if(s.charAt(i) != c){
						problem = true;
						return;
					}			
				}
			}
		}
		//assumes this.last==other.first
		public boolean append(Node other){
			s = s+other.s;
			ans = (ans*other.ans) % MOD;
			if(other.allsame){
				if(allsame && other.allsame){
					comb += other.comb;
					ans = factorial(comb);
				}
				counts[last-'a'] += other.counts[last-'a'];
				return true;
			}
			int skip = last-'a';
			for(int i = 0; i < 26; i++){
				if(i != skip){
					if(counts[i] > 0 && other.counts[i] > 0){
						//System.out.println("bad string: "+s+" on char "+(char)('a'+i)+ "(skip="+(char)('a'+skip)+")");
						return false;
					}
				}
				counts[i] += other.counts[i];
			}
			last=other.last;
			return true;
		}
	}
	public static long go(){
		int num = sin.nextInt();
		Collection<Node> arr = new ArrayDeque<Node>();
		Node sames[] = new Node[26];
		for(int i = 0; i < 26; i++) sames[i]=null;
		boolean problem = false;
		for(int i = 0; i < num; i++){
			Node n = new Node(sin.next());
			if(n.problem) problem = true;
			if(n.allsame){
				int p = n.s.charAt(0)-'a';
				if(sames[p] == null){
					sames[p] = n;
				} else {
					if(!sames[p].append(n)) problem = true;
				}
			} else {
				arr.add(n);
			}
		}
		if(problem) return 0;
		Node start[] = new Node[26];
		Node end[] = new Node[26];
		for(int i = 0; i < 26; i++){
			start[i] = null;
			end[i] = null;
		}
		for(Node n: arr){
			int s = n.first-'a';
			int e = n.last-'a';
			if(sames[e] != null){
				n.append(sames[e]);
				sames[e] = null;
			}
			if(start[s] != null) return 0;
			if(end[e] != null) return 0;
			start[s] = n;
			end[e] = n;
		}
		for(int i = 0; i < 26; i++){
			if(end[i] != null && start[i] != null){
				Node temp1 = end[i];
				Node temp2 = start[i];
				start[i] = null;
				end[i] = null;
				if(!temp1.append(temp2)) return 0;
				end[temp1.last-'a'] = temp1;
			}
		}
		int remain = 0;
		long ans = 1;
		Node test = null;
		//System.out.println("DEBUG");
		for(int i = 0; i < 26; i++){
			if(start[i] != null){
				if(test == null) test = start[i];
				else if(!test.append(start[i])) return 0;
				remain++;
				ans = (ans*start[i].ans)%MOD;
			}
			if(sames[i] != null){
				if(test == null) test = sames[i];
				else if(!test.append(sames[i])) return 0;
				remain++;
				ans = (ans*sames[i].ans)%MOD;
			}
		}
		return (ans*factorial(remain))%MOD;
	}

	public static void main(String[] args){
		sin = new Scanner(System.in);
		int t;
		t = sin.nextInt();
		int i;
		for(i=1; i<=t; i++){
			long ans = go();
			System.out.print("Case #"+i+": ");
			if(ans == -1){
				System.out.println("impossible");
			} else {
				System.out.println(""+ans);
			}
		}
	}
}