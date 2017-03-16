#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector< pair<int, int> > vii;


int mx = -1;
int tot = 0;

int num =0;

int w;
int k;
int s;

string ks;
string wos;


void perm(char a[], int cur){



	if(cur == s){


		/*for(int i=0;i<s;i++){
			cout << a[i];
		}

		cout << endl;*/
		num++;
		int cnt = 0;

		for(int i=0; i <= s - w; i++){

			int chk = 0;
			for(int j=i; j< i+w; j++){

				if(wos[j-i] != a[j]){
					chk =1;
					break;
				}
			}

			if(chk == 1)
				continue;

			cnt++; 
		}

		if(cnt > mx)
			mx = cnt;

		tot += cnt;
	}
	else{

		for(int i=0;i<k;i++){
			a[cur] = ks[i];
			perm(a, cur+1);
		}
	}

}

int main(){

	int t;

	cin >> t;

	for(int tt=1;tt<=t;tt++){

		cin >> k >> w >> s;
		cin >> ks >> wos;

		char a[100];


		tot = 0;
		num = 0;
		mx  =-1;
		perm(a,0);

		//cout << tot << " " << mx << " "<<num;

		double ans = 0.0;
		 ans = mx  - (1.0*tot)/num; 
		//cout << "Case #" << tt << ": " <<   ans <<endl;

		printf("Case #%d: %.8f\n", tt, ans);
	}
}