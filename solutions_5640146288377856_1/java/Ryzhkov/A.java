import java.util.Scanner;
import java.util.ArrayList;
import java.io.FileNotFoundException;
import java.io.File;

public class A {
int[][] choose = new int[50][50];
public A() {
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
	for (int i =  N - 1; i >= 1; i--)
		if (N % i == 0)
			return i;
	return 1;
}
// Do not change any of the code above
// This is the most where you start working on your code for this problem:
public void solve(Scanner in) {

	int R = in.nextInt();
	int C = in.nextInt();
	int W = in.nextInt();
	int t = C/W;
	int result = R*t + (W);
	
	if (C % W == 0)
		result--;
	

	System.out.println (result);


	//Before you start working on this problem please read carefully through the list that I have made,
	//to be sure that you will not waste your time on the incorrect implementation of this problem.
	//
	// If you have more than 38 points already, congratulations,
	// if you don't, then work harder, please we want to make it to the second round
	//
	// Did you read other problems?
	// If no then read them
	// Don't ignore the last comment, if you hadn't read all of them, read all of them
	// This is really important
	// find the one than is possible to solve in that amount of time
	//
	// please don't waste your time doing this problem
	// by making sure that you already have the algorithm to solve this problem.
	// and please do not guess.
	//
	// if you are going to do this problem first then answer yes to all of the following questions:
	//
	// Do you have the algorithm to find the answer?
	//
	// Are you sure that you can finish it before the time ends?
	//
	// Are you sure that this is correct?
	// Can you prove that that is a correct algorithm?
	// Are you completely sure that it is correct?
	// Please be sure that that is a correct algorithm, because otherwise you will waste a lot of time
	// implementing it.
	//
	// Do you calculate only the things that are required for the output?
	// If no, then probably there is a better way to solve this problem.
	//
	// if you are calcuating the answer for a lot of supbroblems, and a lot of them are the same, do you save the answers?
	// if you are doing simulations, are you sure, that there is no other to find the answer without simulation?
	//
	// Did you solve with this algorithm for the test cases?
	// Were the answers correct?
	// Is the code for this problem going to be less than 100 lines?
	// if not, then your algorithm is not the best way to solve this problem.
	//
	// Is complexity for the big input << 10^9?
	// 
	// If you answered no to at least one of those questions, then your algorithm is not correct, please spend more time on it
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
	A test = new A();
	test.doTheStuff("A.in");
}
}

