#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main()
{
    #ifndef DEBUG

    ifstream in("b_l.in");
    cin.rdbuf(in.rdbuf());
    ofstream out("b_l.out");
    cout.rdbuf(out.rdbuf());

    #endif

    int T;
    cin>>T;
    cout.precision(10);
    for(int X = 1; X <= T; X++)
    {
        char key[27] = {0};
        int K,L,S,cnt = 0;
        cin>>K>>L>>S;
        string a,b;
        cin>>a>>b;
        bool valid = true;
        for(int i = 0; i < K; i++)
        {
            if(key[a[i] - 'A'] == 0)    cnt++;
            key[a[i] - 'A']++;
        }
        double prob = 1.0;
        for(int i = 0; i < b.length(); i++)
        {
            if(key[b[i] - 'A'] == 0)
            {
                valid = false;
                break;
            }
            else
            {
                prob *= key[b[i] - 'A']/(double)K;
            }
        }
        if(L > S)   valid = false;
        double mx = 0;

        vector<int> p = prefix_function(b);
        string tmp = b;
        for(int i = L-1; i < S;)
        {
            mx += 1.0;
            //cout<<p[L-1]<<endl;
            i += L - p[L-1];
        }
        //cout<<mx<<endl;
        int C = S - L;


        double val = (S-L+1)*prob;
        double ans = mx - val;
        cout<<"Case #"<<X<<": ";
        if(valid)
            cout<<ans<<endl;
        else
            cout<<0.0<<endl;
    }

    return 0;
}
