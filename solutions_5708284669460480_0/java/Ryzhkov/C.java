import java.util.Scanner;
import java.util.ArrayList;
import java.io.FileNotFoundException;
import java.io.File;

public class C {
int[][] choose = new int[50][50];
public C() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++)
			choose[i][j] = -1;
		choose[i][0] = 1;
		choose[i][i] = 1;
	}
}
// Here are some functions that you might need
// This one sorts array from index s to index f in descending order using Quick Sort
public int[] sortInt (int[] array, int s, int f) {
	if (s >= f)
		return array;
	int i = s;
	int j = f;
	int k = array[(i+j)/2];
	while (i < j) {
		while (array[i] <= k && i<j)
			i++;
		while (array[j] > k && j>i)
			j--;
		if (i < j) {
			int t = array[i];
			array[i] = array[j];
			array[j] = t;
			i++;
			j--;
		}
	}
	array = sortInt (array,s,i-1);
	array = sortInt (array,i,f);
	return array;
}
// This one raises integer x to the power of n
public int pow (int x, int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	int t = pow (x, n/2);
	t *= t;
	if (n % 2 == 1)
		t *= x;
	return t;
}
// This one converts your integer to the bitString
public String toBitString (int i) {
	int[] result = new int[64];
	int counter = 0;
	while (i > 0) {
		result[counter] = i % 2;
		i /= 2;
		counter++;
	}
	String answer = "";
	for (int j = 0; j < counter; j++)
		answer += "" +  result[j];
	return answer;	
}
// This one calculates C(n,k)
public int C(int n, int k) {
	if (choose[n][k] != -1)
		return choose[n][k];
	int t = C(n-1,k-1) + C(n-1,k);
	choose[n][k] = t;
	return t;
}
// This one gives the biggest factor of n, not including n
public int factoring(int N) {
	for (int i = N-1; i >= 1; i--)
		if (N % i == 0)
			return i;
	return 1;
}
// Do not change any of the code above
// This is the most where you start working on your code for this problem:
public void solve(Scanner in) {
	int K = in.nextInt();
	int L = in.nextInt();
	int S = in.nextInt();
	
	int[] letters = new int[26];
	
	in.nextLine();

	String keyboard = in.nextLine(), word = in.nextLine();
	char c;
	
	

	for (int i = 0; i < K; i++) {
		c = keyboard.charAt(i);
		letters[c - 'A']++;
	}
	
	double chanceOfWord = 1;

	for (int i = 0; i < L; i++) {
		chanceOfWord *= (letters[word.charAt(i)-'A']+0.0)/(K+0.0);
	}
	
       	if (chanceOfWord == 0 || chanceOfWord == 1){
		System.out.println (0.0);
		return;
	}
	else if (L == S) {
		System.out.println (1.0-chanceOfWord);
		return;
	}	

	max = 0;
	col = 0;
	double result = full (letters,"",word,S);
	System.out.println ((max - (result+0.0)/(col+0.0)));
}

private int max;
private int col;

public int full (int[] letters, String already, String word, int S) {
	int result = 0;
	
	if (already.length() == S) {
		result = count(already,word);
		if (result > max)
			max = result;
		int t = 1;

		for (int i = 0; i < S; i++) {
			t *= letters[already.charAt(i)-'A'];
		}

		col+=t;

		return result;
	}

	for (char c = 'A'; c <= 'Z'; c++) {
		if (letters[c-'A'] != 0) {
			result += letters[c-'A']*full(letters, already+c, word, S);
		}	
	}
	
	return result;	
	
}

public int count (String S, String W) {
	int result = 0;
	int w = W.length();
	int s = S.length();
	for (int i = 0; i <= s-w; i++) {
		if (S.substring(i,i+w).equals(W))
			result++;
	}
	return result;
}

// Do not change anything below this comment
public void doTheStuff (String filename) throws FileNotFoundException {
	Scanner in = new Scanner (new File (filename));
	int numberOfCases = in.nextInt();
	for (int caseNumber = 1; caseNumber <= numberOfCases; caseNumber++) {
		System.out.print ("Case #"+caseNumber+": ");
		solve(in);
	}
}
public static void main (String[] args) throws FileNotFoundException {
	C test = new C();
	test.doTheStuff("C.in");
}
}

