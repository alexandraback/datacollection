/****************************************************************
   ▄█    █▄       ▄████████    ▄████████  ▄█  ▀█████████▄
  ███    ███     ███    ███   ███    ███ ███    ███    ███
  ███    ███     ███    ███   ███    █▀  ███   ███    ███
 ▄███▄▄▄▄███▄▄   ███    ███   ███        ███  ▄███▄▄▄██▀
▀▀███▀▀▀▀███▀  ▀███████████ ▀███████████ ███ ▀▀███▀▀▀██▄
  ███    ███     ███    ███          ███ ███    ███    ██▄
  ███    ███     ███    ███    ▄█    ███ ███    ███    ███
  ███    █▀      ███    █▀   ▄████████▀  █▀   ▄█████████▀
****************************************************************/



#include<bits/stdc++.h>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)

#define take(args...) asdf,args
#define dump(x) cerr<<#x<<" = "<<x<<endl
#define debug(args...) cerr,args; cerr<<endl;
using namespace std;


template<typename T>
ostream& operator<<(ostream& output, vector<T>&v)
{
    output<<"[ ";
    if(SZ(v))
    {
        output<<v[0];
    }
    FOR(i, 1, SZ(v))
    {
        output<<", "<<v[i];
    }
    output<<" ]";
    return output;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& output, pair<T1, T2>&p)
{
    output<<"( "<<p.fr<<", "<<p.sc<<" )";
    return output;
}




template<typename T>
ostream& operator,(ostream& output, T x)
{
    output<<x<<" ";
    return output;
}



struct ASDF{
    ASDF& operator,(int &a) {
        sf("%d", &a);
        return *this;
    }
    ASDF& operator,(long int &a){
        sf("%ld", &a);
        return *this;
    }
    ASDF& operator,(long long int &a){
        sf("%lld", &a);
        return *this;
    }
    ASDF& operator,(char &c){
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(double &d){
        sf("%lf", &d);
        return *this;
    }

    template<typename T>
    ASDF& operator,(T &a){
        cin>>a;
        return *this;
    }
}asdf;



//Header ends here

int K, L, S;
string keyboard;
string target;



double solve()
{
	int cnt[27];

	mem(cnt, 0);

	loop(i, SZ(keyboard))
	{
		char ch = keyboard[i] - 'A';

		cnt[ch]++;

	}

	double probability = 1.0;

	loop(i, SZ(target))
	{
		char ch = target[i] - 'A';

		if(cnt[ch] == 0)
		{
			return 0;
		}

		probability = probability * ( (double)cnt[ch] / (double)K);
	}

	probability = probability * ( double(S - L + 1)  );

	//dump(probability);

	




	int small = SZ(target);

	for(int j=1; j<SZ(target); j++)
	{
		int p = j;
		int i = 0;

		while(p < SZ(target))
		{
			if(target[p] != target[i])
			{
				break;
			}

			p++;
			i++;
		}

		if(p == SZ(target))
		{
			small = j;
			break;
		}
	}


	int total = 0;

	total = (S - L)/small;

	total++;

	//dump(total);

	double result = (double)total;

	result = result - probability;


	return result;


	




}



int main()
{
	int kases, kaseno = 0;

	cin>>kases;

	while(kases--)
	{
		cin>>K>>L>>S;
		
		cin>>keyboard;

		cin>>target;


		pf("Case #%d: %.7lf\n", ++kaseno, solve());





	}






}
