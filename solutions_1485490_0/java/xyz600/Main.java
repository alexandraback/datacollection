import java.util.*;

class Main {

    public static void main(String[] args){

	Scanner stdin = new Scanner(System.in);

	int times = stdin.nextInt();
	for (int t = 1; t <= times; t++){

	    int N = stdin.nextInt();
	    int M = stdin.nextInt();

	    long a[] = new long[N];
	    long A[] = new long[N];
	    for (int i = 0; i < N; i++){
		a[i] = stdin.nextLong();
		A[i] = stdin.nextLong();
	    }
	    long b[] = new long[M];
	    long B[] = new long[M];
	    for (int i = 0; i < M; i++){
		b[i] = stdin.nextLong();
		B[i] = stdin.nextLong();
	    }

	    System.out.println("Case #" + t + ": " + solve(a, A, b, B));
	}
    }
    
    static long solve(long[] a, long[] A, long b[], long B[]){
	int N = a.length;
	int M = b.length;
	long[][] cache = new long[N][M];
	for (int i = 0; i < N; i++){
	    for (int j = 0; j < M; j++){
		cache[i][j] = -1;
	    }
	}

	return DP(a, A, b, B, cache, N - 1, M - 1);
    }

    static long DP(long[] a, long[] A, long b[], long B[],
		   long[][] cache, int aIndex, int bIndex){

	//if (cache[aIndex][bIndex] >= 0){
	//return cache[aIndex][bIndex];
	//} else if (aIndex == 0){
	if (aIndex == 0){
	    long sum = 0;
	    for(int i = 0; i <= bIndex; i++){
		if (A[aIndex] == B[i]){
		    sum += b[i];
		}
	    }
	    //cache[aIndex][bIndex] = Math.min(a[aIndex], sum);
	    return Math.min(a[aIndex], sum);
	} else if (bIndex == 0){
	    long sum = 0;
	    for(int i = 0; i <= aIndex; i++){
		if (A[i] == B[bIndex]){
		    sum += a[i];
		}
	    }
	    //cache[aIndex][bIndex] = Math.min(b[bIndex], sum);
	    return Math.min(b[bIndex], sum);			      
	} else {
	    if (A[aIndex] == B[bIndex]){
		long reduceNum = Math.min(a[aIndex], b[bIndex]);
		a[aIndex] -= reduceNum;
		b[bIndex] -= reduceNum;
		long ans = -1;
		if (a[aIndex] == b[bIndex]){
		    //cache[aIndex][bIndex] = reduceNum + DP(a, A, b, B, cache, aIndex - 1, bIndex - 1);
		    ans = reduceNum + DP(a, A, b, B, cache, aIndex - 1, bIndex - 1);
		} else if (a[aIndex] > b[bIndex]){
		    //cache[aIndex][bIndex] = reduceNum + DP(a, A, b, B, cache, aIndex, bIndex - 1);
		    ans = reduceNum + DP(a, A, b, B, cache, aIndex, bIndex - 1);
		} else {
		    //cache[aIndex][bIndex] = reduceNum + DP(a, A, b, B, cache, aIndex - 1, bIndex);
		    ans = reduceNum + DP(a, A, b, B, cache, aIndex - 1, bIndex);
		}
		a[aIndex] += reduceNum;
		b[bIndex] += reduceNum;
		return ans;
	    } else {
		//cache[aIndex][bIndex - 1] = DP(a, A, b, B, cache, aIndex, bIndex - 1);
		//cache[aIndex - 1][bIndex] = DP(a, A, b, B, cache, aIndex - 1, bIndex);
		//cache[aIndex][bIndex] = Math.max(cache[aIndex][bIndex - 1], cache[aIndex - 1][bIndex]);
		return Math.max(DP(a, A, b, B, cache, aIndex, bIndex - 1), DP(a, A, b, B, cache, aIndex - 1, bIndex));
	    }
	}
	//return cache[aIndex][bIndex];
    }
}