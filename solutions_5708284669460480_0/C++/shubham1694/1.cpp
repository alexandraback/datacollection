#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define inf 1000000000
#define maxn 1000000

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define sin scanint
#define bitcount(x) __builtin_popcount(x)
#define fill(s, p) memset(s, p, sizeof(s));
#define gc getchar

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void computeLPSArray(string pat, int M, int *lps);
 
int KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
 	int ret = 0;
    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        //printf("Found pattern at index %d \n", i-j);
        ret++;
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
    return ret;
}
 
void computeLPSArray(string pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

string s1;
vector<string> v;

void sol(int l, string r)
{
	int i;
	string ret = r;;
	if(l==1){
		for(i=0; i<s1.size(); i++){
			ret = r+s1[i];
			v.pb(ret); 
		}
		return;
	}
	for(i=0; i<s1.size(); i++){
		ret = r+s1[i];
		sol(l-1, ret);
	}
}

int main()
{
	#ifndef ONLINE_JUDJE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int ca=1, i, j, t, k, l, s, occ, tb, socc;
	double ans, x, y, bl;
	string s2, pat;
	sin(t);
	while(t--){
		v.clear();
		sin(k);
		sin(l);
		sin(s);
		cin >> s1 >> pat;
		s2 = "";
		sol(s, s2);
		tb = socc = 0;
		for(i=0; i<v.size(); i++){
			occ = KMPSearch(pat, v[i]);
			//cout << occ << " " << v[i] << endl;
			socc+=occ;
			tb = max(tb, occ);
		}
		y=v.size();
		x = (double)socc/(double)y;
		//cout << x << " " << y << " " << socc << " " << endl;
		ans = (double)tb - x;
		//cout << tb << endl;
		printf("Case #%d: %.8lf\n", ca++, ans);
	}
	return 0;
}