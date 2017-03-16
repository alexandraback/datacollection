#include<iostream>
#include<cstdio>

using namespace std;

int wall[401];
int wall_between[401];
int new_wall[401];
int new_wall_between[401];
int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    cin >> TIME;
    long long int N;
    long long int d[10], n[10], w[10], e[10], s[10], delta_d[10], delta_p[10], delta_s[10];
    int attack_s;
    int total_attack = 0;
    for (int t = 0 ; t < TIME; t++) {
	answer = 0;
	cin >> N;
	for (int i = 0 ; i < N; ++i) {
	    cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
	    total_attack += n[i];
	}
	for (int i = 0 ; i < 401; ++i) {
	    wall[i] = 0;
	    new_wall[i] = 0;
	    wall_between[i] = 0;
	    new_wall_between[i] = 0;
	}
	for (int tt = 0; tt <= 676060; ++tt) {
	    for (int i = 0 ;i < N; ++i) {
		attack_s = 0;
		if (d[i] <= tt && ((tt-d[i] ) % delta_d[i] == 0) && (tt-d[i])/delta_d[i] < n[i]) { // attack day! 
		    total_attack--;
		    for (int j = (w[i] + delta_p[i] * (tt-d[i] )/ delta_d[i])*2; j <= (e[i] + delta_p[i] * (tt-d[i])/ delta_d[i])*2; ++j) {
			if (wall[j+200] < s[i] + delta_s[i] * (tt- d[i] )/ delta_d[i]) {
			    attack_s = 1;
			    if ( s[i] + delta_s[i] * (tt-d[i])/ delta_d[i] > new_wall[j+200]) {
				new_wall[j+200] = s[i] + delta_s[i] * (tt-d[i] )/ delta_d[i];
			    }
			}
		    }
		    answer += attack_s;
//		    cout << tt << " " << i <<" "<< attack_s << endl;
		}
	    }
	    for (int i = 0 ; i < 401; ++i) {
		wall[i] = new_wall[i];
	    }
	    if ( total_attack == 0)
		break;
	}

	//output
	printf("Case #%d: %d\n",t+1, answer);
    }
    return 0;
}
