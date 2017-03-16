#include <bits/stdc++.h>

#define REP(i, b) for (int i = 0; i < int(b); i++) 
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
  
#define pb push_back
#define mp make_pair
#define fi first
#define se second
           
#define INF 2000000000

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair< int, ii> ipii;
typedef vector<ii> vii;
typedef set<int> si;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int t,k,l,s;
string board, word;
int udela, poc;

int KMP(string S, string K)
{
    vector<int> T(K.size() + 1, -1);
	vector<int> matches;
 
        if(K.size() == 0)
        {
            REP(i,S.size()+1)
            	matches.push_back(i);
            return matches.size();
        }
	for(int i = 1; i <= K.size(); i++)
	{
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}
 
	int sp = 0;
	int kp = 0;
	while(sp < S.size())
	{
		while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
		kp++;
		sp++;
		if(kp == K.size()) matches.push_back(sp - K.size());
	}
 
	return matches.size();
}

void rek(string str){
	if(str.size()==s){
		udela+=KMP(str,word);
		poc++;
		//cout<<str<<endl;
	}
	else{
		REP(i,board.size()){
			string str2=str;
			str2+=board[i];
			rek(str2);
		}
	}
}

int main(){
	scanf("%d", &t);
	REP(tt, t){
		udela=0;
		poc=0;
		int maxcnt;
		scanf("%d%d%d", &k, &l, &s);
		
		cin>>board>>word;
		//cout<<board<<" "<<word<<endl;
	    vector<int> T(word.size() + 1, -1);
		for(int i = 1; i <= word.size(); i++)
		{
			int pos = T[i - 1];
			while(pos != -1 && word[pos] != word[i - 1]) pos = T[pos];
			T[i] = pos + 1;
		}		
		/*REP(i,T.size()){
			cout<<T[i]<<" ";
		}
		cout<<endl;*/
		maxcnt=(s-T[T.size()-1])/(l-T[T.size()-1]);
		
		REP(i,word.size()){
			bool ok=0;
			REP(j,board.size()){
				if(word[i]==board[j])
					ok=1;
			}
			if(ok==0){
				maxcnt=0;
			}
		}
		//cout<<maxcnt<<endl;
		string emp="";
		rek(emp);
		//cout<<udela<<" "<<poc<<endl;
		printf("Case #%d: %.8f\n", tt+1, (double)maxcnt-(double)udela/poc);
	}

 
}