#include <bits/stdc++.h>

#define li long int
#define lli long long int
#define loop(i, a, b) for(i=a; i<b; i++)
#define loope(i, a, b) for(i=a; i<=b; i++)
#define loopr(i, a, b) for(i=a; i>b; i--)
#define loopre(i, a, b) for(i=a; i>=b; i--)
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define MOD 1000000007
#define vi vector<int>
#define vpi vector< pair<int, int> >
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int power(int b, int e)
{
	int ans=1;
	while(e--)
	{
		ans=ans*b;
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i, j, p, n, t, k, l, s, cnt, val, maxcnt, prev;
    double prob, ans;
    int alpha[26];
    string key, target;
    set<string> sets;
    cin>>t;
    loope(i, 1, t)
    {
		cin>>k>>l>>s;
		cin>>key;
		cin>>target;
		fill(alpha, 0);
		maxcnt=0; ans=0.0;
		val=0; prev=0;
		sets.clear();
		while(power(k, val)<power(k, s)) val++;
		loop(j, 0, k)
		{
			alpha[key[j]-'A']++;
		}
		loop(j, 0, power(k, s))
		{
			p=j;
			vector<int> v(10, 0);
			v.clear();
			string temp, temp1;
			temp.clear(); temp1.clear();
			n=0; cnt=0;
			
			while(p)
			{
				v[n]=p%k;
				p=p/k;
				n++;
			}
			reverse(v.begin(), v.begin()+val);
			loop(p, 0, val)
			{
				temp=temp+key[v[p]];
			}
			//cout<<"***"<<temp<<endl;
			sets.insert(temp);
			if(sets.size()!=prev)
			{
			loop(p, 0, val)
			{
				if(p==0) prob=((double)(alpha[temp[p]-'A'])/k);
				else prob=prob*((double)(alpha[temp[p]-'A'])/k);
				if(p<=val-l)
				{
					temp1.assign(temp.begin()+p, temp.begin()+p+l);
					if(temp1==target) cnt++;
				}
			}
			if(cnt>maxcnt) maxcnt=cnt;
			ans=ans+(prob*cnt);
			//cout<<prob<<" "<<cnt<<endl;
			}
			prev=sets.size();
		}
		ans=(double)(maxcnt)-ans;
		printf("Case #%d: %.6lf\n", i, ans);
	}
	return 0;
}
