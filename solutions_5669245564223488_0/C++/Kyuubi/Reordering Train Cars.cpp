#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

#define MOD 1000000007
#define SWAP(a,b) {a=(a)^(b);b = (a)^(b);a= (a)^(b);}

using namespace std;
inline long long minOf(long long x, long long y){return (x<y?x:y);}
inline long long maxOf(long long x, long long y){return (x>y?x:y);}
inline long long mabs(long long x){return (x<0?-x:x);}
string ss[11],s[11];
vector<int> vv;
long long ans;
bool done[27];
int inb[27];
int main()
{
	ios_base::sync_with_stdio(false);
	char ch;
	int t,n;
	cin >> t;
	for(int tt = 1 ; tt <= t; tt++){
		cin >> n;
		vv.clear();
		ans = 0;
		memset(inb,0,sizeof(inb));
		for(int i = 0;i<n;i++){
			cin >> s[i];
			ch = s[i][0];
			ss[i] = ch;
			for(int j = 0;j<s[i].length();j++){
				if(ch != s[i][j]){
					ss[i]+= s[i][j];
					ch = s[i][j];
				}
			}
			for(int j = 1; j < ss[i].length()-1; j++)
				inb[int(ss[i][j]-'a')]++;
			vv.push_back(i);
		}
		bool isValid = true;;
		for(int i = 0; i <26 && isValid;i++)
			if(inb[i] > 1)
			{
				cout << "Case #" << tt << ": " << 0 << endl;
				isValid = false;
			}
		if(!isValid)
			continue;
		do{
			memset(done, false, sizeof(done));
			isValid = true;
			int ii = 0;
			int jj = 0;
			ch = ss[vv[0]][0];
			while(ii != n && isValid){
				jj = 0;
				while(jj < ss[vv[ii]].length() && isValid){
					if(ss[vv[ii]][jj] != ch){
						if(done[ch-'a'])
							isValid = false;
						else{
							done[ch-'a'] = true;
							ch =ss[vv[ii]][jj];
						}
					}
					jj++;
				}
				ii++;
			}
			if(done[ch-'a'])
				isValid = false;
			if(isValid){
				ans++;
			}
		}while(next_permutation(vv.begin(), vv.end()));
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}

/*
 100
 10
 abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz
 4
 aa aa bc c
 2
 abc bcd
 
 */