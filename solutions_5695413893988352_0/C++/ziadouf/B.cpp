#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <string.h>
#include <numeric>
#include <iomanip>
using namespace std;

 typedef vector<int> vi; 
 typedef vector<vi> vvi; 
 typedef pair<int,int> ii; 
 typedef long long ll;
 #define sz(a) int((a).size()) 
 #define pb push_back 
 #define all(c) (c).begin(),(c).end() 
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 

string A,B;
pair <ll,ll> dp[20][5];
bool vis[20][5];

int N;

ll attachToNum (ll dig, ll num, int after)
{
	for (int i=0 ; i<after ; i++) dig *= 10;
	dig += num;
	return dig;
}

bool cmp ( pair <ll,ll> a , pair <ll,ll> b)
{
	if (llabs(a.first-a.second) == llabs(b.first-b.second))
	{
		if (a.first == a.second) return b.first < b.second;
		return a.first < a.second;
	}
	return llabs(a.first-a.second) < llabs(b.first-b.second);
}

pair <ll, ll> solve (int i, int state, ll first, ll second)
{
	if (i == N) return make_pair(first,second);
	if (vis[i][state]) return dp[i][state];
	
	vector < pair<ll,ll> > all_ans;
	
	if (state == 0)
	{
		int digA_toadd, digB_toadd;
		if (A[i] == B[i])
		{
			if (A[i] == '?') digA_toadd = 0, digB_toadd = 0;
			else digA_toadd = digB_toadd = A[i] - '0';
			ll new_first = first * 10 + digA_toadd;
			ll new_second = second * 10 + digB_toadd;
			pair <ll,ll> p = solve(i+1,state, new_first, new_second);
			all_ans.pb(p);
		}
		else if (A[i] == '?' || B[i] == '?')
		{
			if (A[i] == '?') digA_toadd = digB_toadd = B[i] - '0';
			else if (B[i] == '?') digA_toadd = digB_toadd = A[i] - '0';
			ll new_first = first * 10 + digA_toadd;
			ll new_second = second * 10 + digB_toadd;
			pair <ll,ll> p = solve(i+1,state, new_first, new_second);
			all_ans.pb(p);
		}
		else
		{
			digA_toadd = A[i] - '0';
			digB_toadd = B[i] - '0';
			int new_state;
			if (digA_toadd > digB_toadd) new_state = 1;
			else new_state = 2;
			ll new_first = first * 10 + digA_toadd;
			ll new_second = second * 10 + digB_toadd;
			pair <ll,ll> p = solve(i+1,new_state, new_first, new_second);
			all_ans.pb(p);
		}
	}
	else if (state == 1)
	{
		int digA_toadd, digB_toadd;
		if (A[i] == '?') digA_toadd = 0;
		else digA_toadd = A[i] - '0';
		if (B[i] == '?') digB_toadd = 9;
		else digB_toadd = B[i] - '0';
		
		ll new_first = first * 10 + digA_toadd;
		ll new_second = second * 10 + digB_toadd;
		pair <ll,ll> p = solve(i+1,state, new_first, new_second);
		all_ans.pb(p);
	}
	else if (state == 2)
	{	
		int digA_toadd, digB_toadd;
		if (A[i] == '?') digA_toadd = 9;
		else digA_toadd = A[i] - '0';
		if (B[i] == '?') digB_toadd = 0;
		else digB_toadd = B[i] - '0';
		
		ll new_first = first * 10 + digA_toadd;
		ll new_second = second * 10 + digB_toadd;
		pair <ll,ll> p = solve(i+1,state, new_first, new_second);
		all_ans.pb(p);	
	}
	
	sort(all(all_ans),cmp);
	vis[i][state] = 1;
	return dp[i][state] = all_ans[0];
}

vector <ll> As;
vector <ll> Bs;

void getAllA (int i, ll num)
{
	if (i == N)
	{
		As.pb(num);
		return;
	}
	
	if (A[i] != '?') 
		getAllA(i+1, num*10+(A[i]-'0'));
	else
		for (int j=0 ; j<10 ; j++)
			getAllA(i+1, num*10+j);
	
}

void getAllB (int i, ll num)
{
	if (i == N)
	{
		Bs.pb(num);
		return;
	}
	
	if (B[i] != '?') 
		getAllB(i+1, num*10+(B[i]-'0'));
	else
		for (int j=0 ; j<10 ; j++)
			getAllB(i+1, num*10+j);
	
}

pair <ll,ll> brute_force ()
{
	getAllA(0,0);
	getAllB(0,0);
	
	sort(all(A));
	sort(all(B));
	ll best = -1;
	pair <ll,ll> ret;
	
	for (int i=0 ; i<sz(As) ; i++)
		for (int j=0 ; j<sz(Bs) ; j++)
			if (llabs(As[i] - Bs[j]) < best || best == -1)
			{
				best = llabs(As[i]-Bs[j]);
				ret = make_pair(As[i],Bs[j]);
			}
	return ret;
}

int main ()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	int TC;
	 cin >> TC;
	int CC = 1;
	while (TC--)
	{
		printf("Case #%d: ",CC++);
		memset(vis,0,sizeof vis);
		
		cin >> A >> B;
		N = sz(A);
		As.clear();
		Bs.clear();
		
		// pair <ll,ll> p = solve(0,0,0,0);
		pair<ll,ll> p = brute_force();
		cout << setfill('0') << setw(N) << p.first;
		cout << " ";
		cout << setfill('0') << setw(N) << p.second;
		cout << endl;
		
	}
	
}
