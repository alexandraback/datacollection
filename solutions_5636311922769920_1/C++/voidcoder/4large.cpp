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

string flip(string s){
	reverse(s.begin(),s.end());
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='-')
			s[i]='+';
		else if(s[i]=='+')
			s[i]='-';
	}
	return s;
}



int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int  t=0;//test
	cin >> t;
	int print=1;
	ofstream myfile;
		  myfile.open ("example.txt");
		  ll count=0;
	ll k,c,s;
	while(t>0){
		//for(int i=0;i<10;i++) arr[i]=0;
		count=0;
		cin >> k >> c >> s;
			//val=t;
		if(k==1){
			printf("Case# %d: ",print);
			myfile << "Case #" << print << ": " ;
			for(size_t i=0;i<k;i++)
			{printf("%lu ", i+1 );myfile << i+1 << " ";}
		}
		else if(c==1 && k==s){
			printf("Case# %d: ",print);
			myfile << "Case #" << print << ": " ;
			for(size_t i=0;i<k;i++)
			{printf("%lu ", i+1 );myfile << i+1 << " ";}
		}
		else if(c==1 && s<k){
			printf("Case# %d: IMPOSSIBLE",print);
			myfile << "Case #" << print << ": IMPOSSIBLE" ;
		}
		else if(c>1){
			if(s<k-1){
				printf("Case# %d: IMPOSSIBLE",print);
				myfile << "Case #" << print << ": IMPOSSIBLE" ;
			}
			else{
				printf("Case# %d: ",print);
				myfile << "Case #" << print << ": " ;

				for(size_t i=1;i<k;i++)
				{printf("%lu ", i+1 );myfile << i+1 << " ";}

			}
		}
		// printf("Case#%d: ",print);
		// myfile << "Case #" << print << ": ";
		// for(size_t i=0;i<k;i++)
		// {printf("%lu ", i+1 );myfile << i+1 << " ";}
		printf("\n");
		myfile << endl;
		//myfile << "Case #" << print << ": "<< count << endl; 
		print++;
		
		t--;
	}
	myfile.close();
	
}

