//Code by PepeOfMath
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem3a {

    //use a,b,c,d as -(1,i,j,k), respectively
    public static void main(String[] args) throws FileNotFoundException {

        //hard code the file location
        //open file
        //get number of test cases
        File f = new File("C-large.in");
        Scanner s = new Scanner(f);
        String line = s.nextLine();
        int T = Integer.parseInt(line);

        //open output file
        File f2 = new File("bigresult.txt");
        PrintWriter p = new PrintWriter(f2);

        for (int j = 1; j <= T; j++) {
            String[] parts = s.nextLine().split(" ");
            int L = Integer.parseInt(parts[0]);
            long X = Long.parseLong(parts[1]);
            char[] chars = s.nextLine().toCharArray();

            boolean works = hasPartition(chars, X, L);

            //store the result in the output file
            if (works) {
                p.println("Case #" + j + ": YES");
            } else {
                p.println("Case #" + j + ": NO");
            }
        }

        p.close();
        s.close();
    }

    public static boolean hasPartition(char[] arr, long X, int L) {
        long product = X * L;
        char p1 = '1';
        char p3 = '1';
        char[] lpowers = new char[4];

        //calculate the total product
        char temp = '1';
        for (int i = 0; i < L; i++) { //product over 1 cycle
            temp = mult(temp, arr[i]);
        }
        //the four unique powers
        lpowers[0] = '1';
        lpowers[1] = temp;
        lpowers[2] = mult(temp, temp);
        lpowers[3] = mult(lpowers[2], temp);

        char ptotal = '1';
        for (int i = 0; i < (X % 4); i++) { //full product
            ptotal = mult(ptotal, temp);
        }

        if (ptotal != 'a') {
            return false;
        }

        for (int m1 = 0; m1 <= L; m1++) {
            if (m1 != 0) {
                p1 = mult(p1, arr[(m1-1) % L]);
            }

            for (int n1 = 0; n1 < 4; n1++) {
                if (mult(lpowers[n1], p1) == 'i') {
                    p3 = '1';
                    for (int m3 = 2*L; m3 > m1; m3--) {
                        if (m3 != 2*L) {
                            p3 = mult(arr[(int) (m3 % L)], p3);
                        }

                        for (int n3 = 0; n3 < 4; n3++) {
                            if (mult(p3, lpowers[n3]) == 'k') {
                                if ((n1 + n3) * L + m1 + (2*L - m3) < product) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    public static char onediv(char c) {
        switch (c) {
            case '1':
                return '1';
            case 'i':
                return 'b';
            case 'j':
                return 'c';
            case 'k':
                return 'd';
            case 'a':
                return 'a';
            case 'b':
                return 'i';
            case 'c':
                return 'j';
            case 'd':
                return 'k';
        }
        return '1'; //should not happen
    }

    public static char mult(char x, char y) {
        switch (x) {
            case '1':
                return y;
            case 'i':
                switch (y) {
                    case '1':
                        return x;
                    case 'i':
                        return 'a';
                    case 'j':
                        return 'k';
                    case 'k':
                        return 'c';
                    case 'a':
                        return 'b';
                    case 'b':
                        return '1';
                    case 'c':
                        return 'd';
                    case 'd':
                        return 'j';
                }
            case 'j':
                switch (y) {
                    case '1':
                        return x;
                    case 'i':
                        return 'd';
                    case 'j':
                        return 'a';
                    case 'k':
                        return 'i';
                    case 'a':
                        return 'c';
                    case 'b':
                        return 'k';
                    case 'c':
                        return '1';
                    case 'd':
                        return 'b';
                }
            case 'k':
                switch (y) {
                    case '1':
                        return x;
                    case 'i':
                        return 'j';
                    case 'j':
                        return 'b';
                    case 'k':
                        return 'a';
                    case 'a':
                        return 'd';
                    case 'b':
                        return 'c';
                    case 'c':
                        return 'i';
                    case 'd':
                        return '1';
                }
            case 'a':
                switch (y) {
                    case '1':
                        return x;
                    case 'i':
                        return 'b';
                    case 'j':
                        return 'c';
                    case 'k':
                        return 'd';
                    case 'a':
                        return '1';
                    case 'b':
                        return 'i';
                    case 'c':
                        return 'j';
                    case 'd':
                        return 'k';
                }
            case 'b':
                switch (y) {
                    case '1':
                        return x;
                    case 'i':
                        return '1';
                    case 'j':
                        return 'd';
                    case 'k':
                        return 'j';
                    case 'a':
                        return 'i';
                    case 'b':
                        return 'a';
                    case 'c':
                        return 'k';
                    case 'd':
                        return 'c';
                }
            case 'c':
                switch (y) {
                    case '1':
                        return x;
                    case 'i':
                        return 'k';
                    case 'j':
                        return '1';
                    case 'k':
                        return 'b';
                    case 'a':
                        return 'j';
                    case 'b':
                        return 'd';
                    case 'c':
                        return 'a';
                    case 'd':
                        return 'i';
                }
            case 'd':
                switch (y) {
                    case '1':
                        return x;
                    case 'i':
                        return 'c';
                    case 'j':
                        return 'i';
                    case 'k':
                        return '1';
                    case 'a':
                        return 'k';
                    case 'b':
                        return 'j';
                    case 'c':
                        return 'b';
                    case 'd':
                        return 'a';
                }
        }
        return '1'; //should not happen
    }
}

