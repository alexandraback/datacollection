import java.util.Scanner;

public class QRC {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int r = sc.nextInt();
            int c = sc.nextInt();
            int m = sc.nextInt();
            System.out.println("Case #"+(i+1)+":");
            int e = r*c - m;
            int[][] brd = new int[r][c];
            if(e==0){
                System.out.println("Impossible");
                continue;
            } else if (e>1){
                brd = explore(0,0,brd,e);
            }


            if(brd==null){
                System.out.println("Impossible");
                continue;
            }
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    if(j==0 && k == 0){
                        System.out.print('c');
                    }else if(brd[j][k]==1){
                        System.out.print('.');
                    }else {
                        System.out.print('*');
                    }
                }
                System.out.println();
            }
        }
    }

    private static int[][] explore(int x, int y, int[][] brd, int e){
        e -= markNewZeros(x,y,brd);
        if(e==0){
            return brd;
        }
        for (int i = x-1; i <= x+1 ; i++) {
            for (int j = y-1; j <= y+1; j++) {
                int z = getNewZeros(i,j,brd);
                if(z>0 && e>=z){
                    int[][] newbrd = copy(brd);
                    newbrd = explore(i,j,newbrd,e);
                    if(newbrd!=null){
                        return newbrd;
                    }
                }
            }
        }
        return null;
    }

    private static int getNewZeros(int x, int y, int[][] brd){
        int res = 0;
        if(x<0 || y<0 || x>=brd.length || y >= brd[0].length){
            return 0;
        }
        for (int i = x-1; i <= x+1 ; i++) {
            for (int j = y-1; j <= y+1; j++) {
                if(i>=0 && j>=0 && i<brd.length && j < brd[0].length&&brd[i][j]==0){
                    res++;
                }
            }
        }
        return res;
    }

    private static int markNewZeros(int x, int y, int[][] brd){
        if(x<0 || y<0 || x>=brd.length || y >= brd[0].length){
            return 0;
        }
        int c = 0;
        for (int i = x-1; i <= x+1 ; i++) {
            for (int j = y-1; j <= y+1; j++) {
                if(i>=0 && j>=0 && i<brd.length && j < brd[0].length){
                    if(brd[i][j] == 0){
                        c++;
                        brd[i][j]=1;
                    }
                }
            }
        }
        return c;
    }
    private static int[][] copy(int[][] s){
        int[][] r = new int[s.length][s[0].length];
        for (int i = 0; i < s.length; i++) {
            for (int j = 0; j < s[0].length; j++) {
                r[i][j] = s[i][j];
            }
        }
        return r;
    }
}
