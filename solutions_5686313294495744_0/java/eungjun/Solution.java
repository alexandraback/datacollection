import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Solver solver = new Solver();
        solver.solve();
    }
}

class Solver {
	boolean combination(Pair[]  elements, int K, Set<String> firsts, Set<String> seconds){
		// get the length of the array
		// e.g. for {'A','B','C','D'} => N = 4 
		int N = elements.length;

		if(K > N){
			System.err.println("Invalid input, K > N");
			return false;
		}

		// get the combination by index 
		// e.g. 01 --> AB , 23 --> CD
		int combination[] = new int[K];

		// position of current index
		//  if (r = 1)              r*
		//  index ==>        0   |   1   |   2
		//  element ==>      A   |   B   |   C
		int r = 0;      
		int index = 0;

		while(r >= 0){
			// possible indexes for 1st position "r=0" are "0,1,2" --> "A,B,C"
			// possible indexes for 2nd position "r=1" are "1,2,3" --> "B,C,D"

			// for r = 0 ==> index < (4+ (0 - 2)) = 2
			if(index <= (N + (r - K))){
				combination[r] = index;

				// if we are at the last position print and increase the index
				if(r == K-1){

					//do something with the combination e.g. add to list or print
					//**** DO ****
					if (solve(combination, elements, firsts, seconds)) {
						return true;
					};
					index++;                
				}
				else{
					// select index for next position
					index = combination[r]+1;
					r++;                                        
				}
			}
			else{
				r--;
				if(r > 0)
					index = combination[r]+1;
				else
					index = combination[0]+1;   
			}           
		}

		return false;
	}

    class Pair {
        public String a;
        public String b;
        public String toString() {
            return a + " " + b;
        }
    }

	boolean solve(int[] combination, Pair[] elements, Set<String> firsts, Set<String> seconds) {
        Set<String> fs = new HashSet<>();
        Set<String> ss = new HashSet<>();
        for(int c : combination) {
			fs.add(elements[c].a);
			ss.add(elements[c].b);
        }
		return fs.containsAll(firsts) && ss.containsAll(seconds);
	}

    int solve(List<Pair> pairs) {
        // 최소 real을 찾자
        // set을 만들고 
        // 그 set을 만족하는 최소 단어수
        Set<String> firsts = new HashSet<>();
        Set<String> seconds = new HashSet<>();
        for(Pair p : pairs) {
            firsts.add(p.a);
            seconds.add(p.b);
        }

		Pair[] arr = new Pair[pairs.size()];
		pairs.toArray(arr);
		for(int i = 1; i <= pairs.size(); i++) {
			if (combination(arr, i, firsts, seconds)) {
				return pairs.size() - i;
			}
		}

        return 0;
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int j = 0; j < t; j++) {
            System.err.printf("Case #%d%n", j + 1);
            List<Pair> pairs = new ArrayList<>();
            int ws = sc.nextInt();
            for(int k = 0; k < ws; k++) {
                Pair p = new Pair();
                p.a = sc.next();
                p.b = sc.next();
                pairs.add(p);
            }
            System.out.printf("Case #%d: %d%n", j + 1, solve(pairs));
        }
    }
}
