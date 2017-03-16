#include <bits/stdc++.h> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

template<class T> inline T maxm(T& a, T b){return a = a < b ? b : a;}
template<class T> inline T minm(T& a, T b){return a = a > b ? b : a;}

int main(){

    int T;
    cin >> T;

    for(int i = 0; i < T; ++i){
    
	string s1, s2;
	cin >> s1 >> s2;
	int N = s1.size();

	string s1o = s1;
	string s2o = s2;
	bool diff = 0;
	bool gr = 0;
	for(int j = 0; j < N; ++j){
	
	    if(!diff){
		if(s1[j] == s2[j] && s1[j] == '?'){
		    s1[j] = s2[j] = '0';
		}
		if(s1[j] == '?'){
		    s1[j] = s2[j];
		}
		if(s2[j] == '?'){
		    s2[j] = s1[j];
		}

		if(s1[j] > s2[j]){
		    diff = 1;
		    gr = 1;
		    if(j && s1[j] - s2[j] >= 5){
			if(s2o[j - 1] == '?') {
			    if(s2[j - 1] != '9'){
				s2[j - 1]++;
				gr = 0;
			    }else{
				int j1 = j - 1;
				while(j1 >= 0 && s2[j1] == '9') --j1;
				if(j1 >= 0 && s2o[j1] == '?'){
				    s2[j1]++;

				    ++j1;

				    for(;j1 <= j - 1; ++j1)
					s2[j1] = '0';
				}
			    }
			}
			if(s1o[j - 1] == '?'){
			    if(s1[j - 1] != '0'){
				s1[j - 1]--;
				gr = 0;
			    }
			}
		    }else{
			gr = 1;
		    }
		}else if(s1[j] < s2[j]){
		    diff = 1;
		    if(j && s2[j] - s1[j] >= 5){
		    
			if(s1o[j - 1] == '?'){
			    if(s1[j - 1] != '9'){
				s1[j - 1]++;
				gr = 1;
			    }else{
				int j1 = j - 1;
				while(j1 >= 0 && s1[j1] == '9') --j1;
				if(j1 >= 0 && s1o[j1] == '?'){
				    s1[j1]++;

				    ++j1;

				    for(;j1 <= j - 1; ++j1)
					s1[j1] = '0';
				}
			    }
			}
			if(s2o[j - 1] == '?'){
			    if(s2[j - 1] != '0'){
				--s2[j - 1];
				gr = 1;
			    }
			}
		    }
		}
	    }else{
		if(s1[j] == '?') s1[j] = gr ? '0' : '9';
		if(s2[j] == '?') s2[j] = gr ? '9' : '0';
	    }
	}

	cout << "Case #" << i + 1 << ": " << s1 << ' ' << s2 << '\n';
    }

    return 0;

}
