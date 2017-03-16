import java.util.Scanner;
import java.util.ArrayList;
import java.io.FileNotFoundException;
import java.io.File;

public class B {
int[][] choose = new int[50][50];
public B() {
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



	int C = in.nextInt();
	int D = in.nextInt();
	int V = in.nextInt();

	int[] coins = new int[D];
	int largestPossible = 0;
	int counter = 0;


	int result = 0;

	for (int i = 0; i < D; i++) {
		coins[i] = in.nextInt();
	}
	

	while (largestPossible < V) {
		if (counter == D) {
			largestPossible += (largestPossible+1)*C;
			result++;	
		}
		else if (coins[counter] <= largestPossible+1) {
			largestPossible += coins[counter]*C;
			counter++;
		}
		else {
			largestPossible += (largestPossible+1)*C;
			result++;
		}
	}	





	System.out.println (result);
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
	B test = new B();
	test.doTheStuff("B.in");
}
}

