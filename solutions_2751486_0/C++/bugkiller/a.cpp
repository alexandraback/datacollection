#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<climits>
#include<vector>
#include<iterator>
#include<set>

#define fr(i,a,b) for(int i=a; i<b; i++)
#define s(a) scanf("%d", &a)
#define p(a) printf("%d\n", a)
#define w(t) while(t--)
#define pb push_back
#define CLR(a) memset(a, 0, sizeof(a))

using namespace std;

typedef long long int lli;
typedef vector<int> VI;
typedef vector<string> VS;

int main() {
	int test;
	scanf("%d\n", &test);
	fr(t, 1, test+1) {
		string s;
		cin>>s;
		int n;
		cin>>n;
		int len = s.length();
		int c, ans = 0;
		for(int i=0;i<len;i++)
            for(int j=i+n;j<=len;j++){
                c=0;
                for(int k=i;k<j;k++){
                    if(s[k]=='a' || s[k]=='e' || s[k]=='i'|| s[k]=='o' || s[k]=='u')
                        c=0;
                    else
                        c++;
                    if(c>=n){
                        ans++;
                        break;
                    }
                }
            }
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
