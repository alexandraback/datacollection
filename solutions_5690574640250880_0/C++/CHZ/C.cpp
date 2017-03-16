#include<iostream>
#include<cstdio>

#define N 62

using namespace std;

int first_click = 1;
int search(int map[N][N], int z_map[N][N], int now_i, int now_j, int R, int C, int M, int S) {
    /*
       printf("(%d,%d)=%d\n", now_i, now_j, S);
       for (int i = 1; i <=R; ++i) {
       for (int j = 1; j <=C; ++j) {
       if (map[i][j]==0) cout <<"*";
       else cout <<".";
       }
       cout << endl;
       }
       cout << endl;
       */ 
	int r_flag = 0;
    if ( first_click == 1 ||
	    z_map[now_i-1][now_j-1] == 1 ||
	    z_map[now_i-1][now_j  ] == 1 ||
	    z_map[now_i-1][now_j+1] == 1 ||
	    z_map[now_i  ][now_j-1] == 1   
       ) {
	int first_return = 0;
	if ( first_click == 1) {
	    first_click = 0;
	    first_return = 1;
	}
	z_map[now_i][now_j] = 1;
	int record_i[9], record_j[9], n_change;
	n_change = 0;
	for (int i = now_i-1; i<=now_i+1; ++i) {
	    if (i<=0 || i>=R+1)
		continue;
	    for (int j = now_j-1; j<=now_j+1; ++j) {
		if (j<=0 || j>=C+1)
		    continue;
		if (map[i][j]!=1) {
		    map[i][j] = 1;
		    record_i[n_change] = i;
		    record_j[n_change] = j;
		    n_change++;
		    S--;
		}
	    }
	}
	if (S==0) { // find, output
	    int c_flag = 0;
	    for (int i = 1; i <=R; ++i) {
		for (int j = 1; j <=C; ++j) {
		    if (c_flag == 0 && z_map[i][j] == 1) {
			c_flag = 1;
			cout << "c";
		    }
		    else {
			if (map[i][j] == 1) {
			    cout << ".";
			}
			else {
			    cout << "*";
			}
		    }
		}
		cout << endl;
	    }
	    return 1;
	}
	if (S>0) { // next
	    if (now_j == C) {
		if (now_i==R) {
		    return 0;
		}
		else {
		    r_flag = search(map, z_map, now_i+1, 1, R, C, M, S);
		}
	    }
	    else {
		r_flag = search(map, z_map, now_i, now_j+1, R, C, M, S);
	    }
	}
	if (r_flag == 1)
	    return 1;
	// recorver
	for (int i = 0 ; i < n_change; ++i) {
	    map[record_i[i]][record_j[i]] = 0;
	    S++;
	}
	if (first_return == 1)
	    first_click = 1;
    }
    z_map[now_i][now_j] = 0;
    if (now_j == C) {
	if (now_i==R) {
	    return 0;
	}
	else {
	    r_flag = search(map, z_map, now_i+1, 1, R, C, M, S);
	}
    }
    else {
	r_flag = search(map, z_map, now_i, now_j+1, R, C, M, S);
    }
    return r_flag;
}
int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    int R, C, M;
    int map[N][N];
    int z_map[N][N];
    cin >> TIME;
    for (int t = 0 ; t < TIME; t++) {
	cin >> R >> C >> M;
	int m_num = R*C;
	for (int i = 0 ;i < N; ++i) {
	    for (int j = 0 ;j < N; ++j) {
		map[i][j] = z_map[i][j] = 0;
	    }
	}

	//output
	printf("Case #%d:\n",t+1);
	if (R*C-M==1) {
	    for (int i = 0 ; i < R; ++i) {
		for (int j = 0 ; j < C; ++j) {
		    if (i==0 && j==0) {
			cout <<"c";
		    }
		    else {
			cout << "*";
		    }
		}
		cout << endl;
	    }
	    continue;
	}
	int r_flag = 0;
	first_click = 1;
	r_flag = search(map, z_map, 1, 1, R, C, M, R*C-M);
	if (r_flag == 0) {
	    cout <<"Impossible" << endl;
	}
    }
    return 0;
}
