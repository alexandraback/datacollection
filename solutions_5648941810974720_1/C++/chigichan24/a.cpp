#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
const long long LINF = 1e18;
const double EPS = 1e-8;
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
#define MOD 1000000007
typedef pair<int,int> Pii;
typedef pair<int, ll> Pil;
typedef vector<int> vi;
typedef vector<vi> vvi;
string target = "ZOWHRFXSGI";
vi num = {0,2,6,8,3,4,1,5,7,9};
vi tmp;
string deleteStr(int idx,int cnt,string str){
	string s;
	int p=idx;
	if(idx == 0){s = "ZERO";}
	if(idx == 1){s = "ONE";}
	if(idx == 2){s = "TWO";}
	if(idx == 3){s = "THREE";}
	if(idx == 4){s = "FOUR";}
	if(idx == 5){s = "FIVE";}
	if(idx == 6){s = "SIX";}
	if(idx == 7){s = "SEVEN";}
	if(idx == 8){s = "EIGHT";}
	if(idx == 9){s = "NINE";}
	
	bool used[2048]={false};
	int ret = -1;
	rep(i,cnt){
		rep(j,s.size()){
			bool flg = false;
			rep(k,str.size()){
				if(s[j] == str[k] && used[k] == false){
					used[k] = true;
					flg = true;
					break;
				}
			}
			if(!flg){
				rep(k,j){
					rep(l,str.size()){
						if(s[k] == str[l] && used[l] == true){
							used[l] = false;
							break;
						}
					}
				}
				ret = i;
				goto end;
			}
		}
	}
	ret = cnt;
	end:;

	string next="";
	rep(i,str.size()){
		if(used[i] == false){
			next += str[i];
		}
	}
	rep(i,ret){
		tmp.pb(p);
	}

	return next;
}
string solve(string str){
	tmp.clear();
	int len = str.size();
	string ans = "";
	rep(i,num.size()){
		//cout << target[num[i]] << "\n";
		int c = 0;
		rep(j,len){
			if(str[j] == target[num[i]]){
				c++;
			}
		}
		str = deleteStr(num[i],c,str);
		len = str.size();
	}
	sort(tmp.begin(),tmp.end());
	rep(i,tmp.size()){
		ans += tmp[i]+'0';
	}
	return ans;
}
int main(){
	int Q;
	scanf("%d",&Q);
	rep(q,Q){
		string str;
		cin >> str;
		string ans = solve(str);
		printf("Case #%d: %s\n",q+1,ans.c_str());
	}
	return 0;
}
