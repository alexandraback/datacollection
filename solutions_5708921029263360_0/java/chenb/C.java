import java.util.*;


public class Main {

    public static void main(String... args) {
        Main a = new Main();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for (int i = 0; i < caseNum; i++) {
            int j= scanner.nextInt();
            int p = scanner.nextInt();
            int s = scanner.nextInt();
            int k = scanner.nextInt();
            a.solve(j,p,s,k, i+1);
        }
    }


    class Solution {
        int j;
        int p;
        int s;

        Solution(int j, int p, int s) {
            this.j = j;
            this.p = p;
            this.s = s;
        }
    }
    public void solve(int j,  int p, int s, int k, int index) {
        int res = Math.min(j*p*s,j*p*k);
        System.out.println(String.format("Case #%d: %d", index, res));
        List<Solution> solutions = new ArrayList<Solution>();
        if(res == j*p*s) {
            for(int i=1; i<=j; i++) {
                for(int j1=1; j1<=p; j1++) {
                    for(int k1=1; k1<=s; k1++)
                        solutions.add(new Solution(i,j1, k1));
                }
            }

        } else {
            int k1=0;
            int z=0;
            for(int w=1; w<=k; w++ ) {
                for(int i=1; i<=j; i++) {
                    for(int j1=1; j1<=p; j1++) {
                        solutions.add(new Solution(i,j1, k1 +1));
                        if(k1+1 %s ==0) {
                            k1 = z;
                            z= (z+1)%s;
                        } else {
                            k1 +=1;
                        }
                    }

                }
            }
        }

        for(Solution solution: solutions) {
            System.out.println(solution.j + " " + solution.p + " " + solution.s);
        }
    }






}