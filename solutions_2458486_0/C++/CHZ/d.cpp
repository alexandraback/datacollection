#include<iostream>
#include<cstdio>

using namespace std;

bool hashtable[1048576];
int search(int hashvalue, int num_key, int depth, int keys[200], int N, int chests[200], int chest_keys[200][401], int chests_visit[200], int seq[200]) {
    if (hashtable[hashvalue] == 1) {
	return 0;
    }
    if (num_key == 0) {
	if (depth == N)
	    return 1;
	else return 0;
    }
    if (depth == N) {
	return 1;
    }
    int return_value = 0;
    for (int i = 0 ; i < N; ++i) {
	if (chests_visit[i] == 1)
	    continue;
	if (keys[chests[i]] == 0)
	    continue;
	keys[chests[i]]--;
	num_key--;
	for (int j = 1 ; j <= chest_keys[i][0]; ++j) {
	    keys[chest_keys[i][j]]++;
	}
	num_key += chest_keys[i][0];
	chests_visit[i] = 1;
	seq[depth] = i;
//	cout << i << endl;
	return_value = search(hashvalue|(1<<i), num_key, depth+1, keys, N, chests, chest_keys, chests_visit, seq);
	hashtable[hashvalue|(1<<i)] = 1;
	chests_visit[i] = 0;
	num_key -= chest_keys[i][0];
	for (int j = 1 ; j <= chest_keys[i][0]; ++j) {
	    keys[chest_keys[i][j]]--;
	}
	num_key++;
	keys[chests[i]]++;
	if (return_value == 1)
	    break;
    }
    return return_value;
}


int main(int artc, char* argv[]) {

    int TIME;// number of test
//    int answer;// Final answer
    cin >> TIME;
    int K, N;
    int tmp;
    int keys[200];
    int chests[200];
    int chests_visit[200];
    int chests_keys[200][401];
    int seq[200];
    for (int t = 0 ; t < TIME; t++) {
	cin >> K >> N;
	for (int i = 0 ; i < 200; ++i) keys[i] = 0;
	for (int i = 0 ; i < 1048576; ++i) hashtable[i] = 0;
	for (int key = 0 ; key < K; ++key) {
	    cin >> tmp;
	    keys[tmp]++;
	}
	for (int chest = 0 ; chest < N; chest++) {
	    chests_visit[chest] = 0;
	    cin >> chests[chest] >> chests_keys[chest][0];
	    //cout << chests[chest]<< " " << chests_keys[chest][0];
	    for (int key = 1 ; key <=chests_keys[chest][0]; ++key) {
		cin >> chests_keys[chest][key];
		//cout << " " << chests_keys[chest][key];
	    }
	    //cout << endl;
	}
	//test
/*	
	cout << "Case " << t+1 << endl;
	cout << K << " " << N << endl;
	for (int i = 0 ; i < 200; ++i) {
	    if (keys[i] == 0)
		continue;
	    for (int j = 0 ; j < keys[i]; ++j)
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0 ; i < N; ++i) {
	    cout << chests[i] << " " << chests_keys[i][0] ;
	    for (int j = 1 ; j <=chests_keys[i][0]; ++j) {
		cout << " " << chests_keys[i][j];
	    }
	    cout << endl;
	}*/
	int re_value = 1;
	re_value = search(0, K, 0, keys, N, chests, chests_keys, chests_visit, seq);
	if (re_value == 0) {
	    printf("Case #%d: IMPOSSIBLE\n",t+1);
	}
	else {
	    printf("Case #%d:",t+1);
	    for (int i = 0 ; i < N; ++i) {
		printf(" %d",seq[i]+1);
	    }
	    printf("\n");
	}

	//output
//	printf("Case #%d: %d\n",t+1, answer);
    }
    return 0;
}
