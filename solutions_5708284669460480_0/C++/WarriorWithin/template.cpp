#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>

#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define vpii vector <pair<int, int> >
#define vpll vector <pair<ll, ll> >
#define pll pair<ll, ll>

#define f first
#define s second

#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)

#define pb push_back
#define pob pop_back

#define max_size 100005
#define max_capacity INT_MAX
#define max_string_size 1000
#define max_node_size 340

using namespace std;

string alphabets, word;

ll occurences[26];

char guesses[15];
vector <pair<ll, ll> > alpha;

ll max_banana, found_instances, total;
double average;

void recurse(ll place, ll k, ll l, ll s)
{
	//cout<<"here: "<<place<<" "<<s<<endl;
	if(place==s)
	{
		guesses[place] = '\0';
		total++;
		ll temp_found = 0;
		for(ll i=0; i<s; i++)
		{
			if(guesses[i]==word[0])
			{
				ll flag = 1;
				ll j, m;
				for(j=i, m=0; j<s && m<l; j++, m++)
				{
					if(guesses[j]!=word[m])
					{
						flag = 0;
						break;
					}
				}

				if(m!=l)
					flag = 0;

				if(flag)
				{
					temp_found++;
				}
			}
		}

		if(temp_found>max_banana)
			max_banana = temp_found;

		double temp_average = 1;
		for(ll i=0; i<s; i++)
			temp_average *= ((double)occurences[guesses[i]-'A'])/k;

		average += temp_average*temp_found;

		found_instances += temp_found;

		//cout<<guesses<<" "<<word<<" "<<max_banana<<" "<<temp_found<<" "<<temp_average<<" "<<average<<endl;
		return;
	}

	for(ll i=0; i<alpha.size(); i++)
	{
		guesses[place] = 'A' + alpha[i].f;
		recurse(place+1, k, l, s);
	}
}

int main()
{
	ll t;
	cin>>t;
	for(ll c=1; c<=t; c++)
	{
		ll k, l, s;
		cin>>k>>l>>s;
		cin>>alphabets;
		cin>>word;

		for(ll i=0; i<26; i++)
			occurences[i] = 0;

		for(ll i=0; i<k; i++)
			occurences[alphabets[i]-'A']++;

		alpha.clear();
		for(ll i=0; i<26; i++)
			if(occurences[i]>0)
				alpha.push_back(make_pair(i, occurences[i]));

		max_banana = 0;
		found_instances = 0;
		total = 0;
		average = 0;

		for(ll i=0; i<alpha.size(); i++)
		{
			guesses[0] = 'A'+alpha[i].f;
			recurse(1, k, l, s);
		}

		double remain = ((double)max_banana)-average;
		printf("Case #%lld: %0.6lf\n", c, remain);
	}

	return 0;
}
