import java.io.*;
import java.util.*;
import java.math.*;

public class C {
    public static void main(String[] args) { 
        PrintWriter out = new PrintWriter(System.out);

        Application application = new Application();
        application.solve(System.in, out);

        out.close();
    }
}

class Element {
    public int value = 1;
    public int sign = 1;
    public static int MUL[][] = new int[][] {
            new int[] { 0, 0,  0,  0,  0},
            new int[] { 0, 1,  2,  3,  4},
            new int[] { 0, 2, -1,  4, -3},
            new int[] { 0, 3, -4, -1,  2},
            new int[] { 0, 4,  3, -2, -1}
        };

    public Element(char c) {
        if (c == 'i') { this.value = 2; }
        else if (c == 'j') { this.value = 3; }
        else { this.value = 4; }
        this.sign = 1;
    }

    public Element() {
        this.value = 1;
        this.sign = 1;
    }
    public Element(Element e) {
        this.value = e.value;
        this.sign = e.sign;
    }

    public void mul(Element b) {
        int v = MUL[this.value][b.value];
        if (v < 0) {
            this.value = -v;
            this.sign *= -b.sign;
        }
        else {
            this.value = v;
            this.sign *= b.sign;
        }
    }
    public static Element MUL(Element a, Element b) {
        Element c = new Element();

        int v = MUL[a.value][b.value];
        if (v < 0) {
            c.value = -v;
            c.sign = -a.sign*b.sign;
        }
        else {
            c.value = v;
            c.sign = a.sign*b.sign;
        }
        return c;
    }
    public String toString() {
        char c[] = new char[] {'?', '1', 'i', 'j', 'k'};
        return (this.sign < 0 ? '-' :  ' ') + "" + c[this.value];
    }
}

class Application {
    public void solve(InputStream in, PrintWriter out) {
        Scanner scanner = new Scanner(in);

        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++) {
            int L = scanner.nextInt();
            int X = scanner.nextInt();
            scanner.nextLine();
            String line = scanner.nextLine();


            Element A[] = new Element[L*X];
            for (int i = 0; i < L; i++) {
                A[i] = new Element(line.charAt(i));
            }
            for (int x = 1; x < X; x++) {
                for (int i = 0; i < L; i++) {
                    A[x*L+i] = new Element(A[i]);
                }
            }
            L = L * X;

            Element S[] = new Element[L];
            Element P[] = new Element[L];
            S[0] = new Element(A[0]);
            for (int i = 1; i < L; i++) {
                S[i] = Element.MUL(S[i-1], A[i]);        
            }

            P[L-1] = new Element(A[L-1]);
            for (int i = L-2; i >= 0; i--) {
                P[i] = Element.MUL(A[i], P[i+1]);
            }

            /*
            for (int i = 0; i < L; i++) {
                System.out.print(S[i] + " ");
            }
            System.out.println();
            for (int i = 0; i < L; i++) {
                System.out.print(P[i] + " ");
            }
            System.out.println();*/
            boolean found = false;
            for (int i = 0; i < L; i++) {
                if (S[i].value == 2 && S[i].sign == 1) {
                    for (int j = i+1; j < L; j++) {
                        if (S[j].value == 4 && S[j].sign == 1) {
                            if (j < L-1) {
                                if (P[j+1].value == 4 && P[j+1].sign == 1) {
                                    found = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            System.out.println("Case #" + t + ": " + (found ? "YES" : "NO"));
        }
    }
}
