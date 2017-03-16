import java.util.Scanner;

public class MainB {

    private static void update(char[] c, int l) {
        int a=0, b=l-1;
        while(a<b) {
            char t= c[a];
            c[a] = c[b];
            c[b] = t;
            if(c[a]=='+') c[a] = '-';
            else c[a] = '+';
            if(c[b]=='-') c[b] = '+';
            else c[b] = '-';
            a++;
            b--;
        }
        if(a==b) {
            if(c[a]=='+') c[a] = '-';
            else c[a] = '+';
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        for (int t = 1; t <= T; t++) {
            String str=sc.nextLine();
            char S[] = str.toCharArray();
            int L = S.length;
            long c = 0;
            while(L>0 && S[L-1]=='+') L--;
            while(L>0) {
                if(S[0]=='-') {
                    update(S, L);
                    while(L>0 && S[L-1]=='+') L--;
                } else {
                    for(int i=0;S[i]=='+';i++) {
                        S[i]='-';
                    }
                }
                c++;
            }
            System.out.println("Case #" + t + ": " + c);
        }
    }
}
