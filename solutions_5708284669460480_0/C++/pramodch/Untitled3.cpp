#include <bits/stdc++.h>
using namespace std;

int lps[112], cnt[112], k;
bool used[112];
vector<char> v;
double ans = 0.0, rem = 0.0;
string pat;

inline void LPS(string pat)
{
    int len = 0;
    int i;

    lps[0] = 0;
    i = 1;
    while (i < pat.length())
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else
       {
         if (len != 0)
         {
           len = lps[len-1];
         }
         else
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

int search(string txt)
{
    int M = pat.length();
    int N = txt.length();
 
    int j  = 0; 
 	
 	int cnt = 0;
    int i = 0;
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
      	cnt++;
        j = lps[j-1];
      }
 
      else if (i < N && pat[j] != txt[i])
      {
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    return cnt;
}

inline void generate(string s, double pr, int len){
	if(s.length() == len){
		//cout<<s<<" "<<pr<<endl;
		ans += ( (double)( search(s) * 1.0) ) * pr;
		rem = max((double)( search(s) * 1.0), rem);
		return;
	}
	string news;
	double npr;
	for(int i = 0; i < v.size(); i++){
		news = s;
		news += ( v[i] );
		npr = pr * ( (double)( cnt[ v[i] - 'A' ] ) / (double)(k*1.0) );
		generate(news, npr, len);
	}
	return;
}

inline void Solve(){
	
	memset(cnt, 0, sizeof(cnt));
 	memset(lps, 0, sizeof(lps));
    ans = 0.0;
    rem = 0.0;
	int l, s;
	cin>>k>>l>>s;
	string str;
	cin>>str>>pat;
    for(int i = 0; i < str.length(); i++){
    	cnt[ str[i] - 'A' ]++;
	}
	v.clear();
	LPS(pat);
	for(int i = 0; i < 26; i++){
		if(cnt[i] > 0){
			v.push_back( (char)(i + 'A') );
		}
	}
	generate("", 1.0, s);
	printf("%0.7f\n", rem - ans);
	return;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, tt = 0;
	cin>>t;
	while(t--){
		cout<<"Case #"<<++tt<<": ";
		Solve();
	}
	return 0;
}
