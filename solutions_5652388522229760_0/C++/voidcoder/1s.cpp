#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <string>

#define eps 1e-9
#define bs 1000000007
#define bsize 512
#define loop(i,start,end) for(int i=start;i<end;i++)
#define modulus 10000007
#define MOD 1000000007

using namespace std;
#define ll long long int

ll powerwithmodulus(ll base, ll exponent)
{
    ll result = 1;
    base%=MOD;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % MOD;
        exponent = exponent >> 1;
        base = (base * base) % MOD;
    }
    return result;
}

// int gcd(int a, int b)
// {
//     while(b) b ^= a ^= b ^= a %= b;
//     return a;
// }

bool checkfib(ll n){
	ll a = 5*n*n+4;
	ll b = 5*n*n-4;
	if(pow(int(sqrt(a)),2)==a || pow(int(sqrt(b)),2)==b)
		return true;
	return false;
}

ll min(ll a,ll b){
	return a>b?b:a;
}

int sum1(long long int x){
	int count=0;
	while(x!=0)
		{count+=x%10;x/=10;}
	return count;
}

long long int rec(long long int b){
	if(b/10==0) return b*(b+1)/2;
	else if(b==10) return 46;
	else{
		return (int(b/10)!=1) ? (10*rec(b/10 -1) + (b/10)*46 + (b%10)*sum1(b/10) + rec(b%10)) : (46+(b%10)*sum1(b/10) + rec(b%10)) ;
 	}
}

long long sum(long long N){
    if(N/10==0) return N*(N+1)/2;
    int i=0;
    long long n=N;
    while(n/10!=0){
        i++;
        n/=10;
    }
    int p=pow(10,i);
    return ((n*45*i*p/10)+ n*(n-1)*p/2+ n*(N%p+1) + sum(N%p));
}
	
int primeinfact(int n,int prime){
	int count =0 ;
	//cout << "here" << endl;
	//if(prime>n)return 0;
	while(n!=0){
		n/=prime;
		count +=n;
	}
	//cout << count << " count " <<  prime<< endl;
	return count;
}
int arr[10]={0};

bool covered(string s){
	for(int i=0;i<s.length();i++){
		arr[s[i]-'0']++;
	}
	for(int i=0;i<10;i++){
		if(arr[i]==0)
			return false;
	}
	return true;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int  t;//test
	cin >> t;
	ll val;
	int print=1;
	ofstream myfile;
		  myfile.open ("example.txt");
	while(t>0){
		for(int i=0;i<10;i++) arr[i]=0;
		scanf("%lld",&val);
			//val=t;
		ll i =1;
		ll temp =val;
		while(!covered(to_string(val)) && val>0){
			val=temp*i;i++;
			//cout << val << " val " << endl;
		}
		
		 
		if(val<=0){
			//printf("Case #%d: INSOMNIA\n",print);
			myfile << "Case #" << print << ": INSOMNIA" << endl; 
			print++;
		}
		else {
			//printf("Case #%d: %lld\n",print,val);
			myfile << "Case #" << print << ": " << val << endl; 
			
			print++;
		}

		t--;
	}
	
		  myfile.close();

	
}