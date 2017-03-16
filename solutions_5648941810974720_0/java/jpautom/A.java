import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;


public class A {
	static void solveCase() {
		String s = sc.nextLine();
        
		String[] numbers = new String[]{
			"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
		};
		int[][] freqN = new int[10][26];
		for (int i=0; i<10; i++) {
			String number = numbers[i];
			for (char c : number.toCharArray()) {
				freqN[i][c-'A']++;
			}
		}

		int[] freq = new int[26];
		for (char c : s.toCharArray()) {
			freq[c-'A']++;
		}


        Map<Character, Integer> m1 = new HashMap<>();
		m1.put('W', 2);
		m1.put('U', 4);
		m1.put('X', 6);
		m1.put('G', 8);
		m1.put('Z', 0);
		Map<Character, Integer> m2 = new HashMap<>();
		m2.put('R', 3);
		m2.put('F', 5);
		m2.put('V', 7);
		m2.put('I', 9);
        
        int[] res = new int[10];
        for (char c : m1.keySet()) {
            int ic = m1.get(c);
            int n = freq[c-'A'];
            res[ic] += n;
            for (int i = 0; i < 26; i++) {
                freq[i] -= n * freqN[ic][i];
            }
        }
        for (char c : m2.keySet()) {
            int ic = m2.get(c);
            int n = freq[c-'A'];
            res[ic] += n;
            for (int i = 0; i < 26; i++) {
                freq[i] -= n * freqN[ic][i];
            }
        }
        res[1] += freq['O'-'A'];
		
        for (int i=0; i<10; i++) {
            for (int j=0; j<res[i]; j++) {
                printf("%s", i);
            }
        }
        printf("\n");

	}
	
	
	static void printf(String f, Object... args) {
		System.out.printf(f, args);
	}
	
	static void p(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	
	static Scanner sc;
	public static void main(String[] args) throws FileNotFoundException {
		sc = new Scanner(args.length > 0 ? new FileInputStream(args[0]) : System.in);
		int numCases = sc.nextInt();
        sc.nextLine();
		for (int nCase=1; nCase<=numCases; nCase++) {
			printf("Case #%d: ", nCase);
			solveCase();
		}
		sc.close();
	}

}