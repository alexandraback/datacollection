#include<bits/stdc++.h>
#include<fstream>

using namespace std;

#define ll long long int
#define ull unsigned long long int
#define maxN 1000000
#define maxW 1005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define INF (((ll)1000000000) * ((ll)1000000000))
#define e 2.7182818284590452353602874
#define maxT 100000
#define inf 0x7fffffff
#define inff 100000
#define ff first
#define ss second
#define rep(i,N) for(int i=0;i<N;i++)


int A[100];
ll dp[maxN+5];
ll flip(ll a) {
int i=0;

while(a) {
A[i++]=a%10;
a/=10;
}

ll b=0;
for(int j=0;j<i;j++)
b=b*10+A[j];
return b;
}

int main() {

//cin.sync_with_stdio(0);
//cin.tie(0);

int T;

ifstream infile("thefile.txt");
infile>>T;

ofstream myfile;
myfile.open("output.txt");


//dp[i] denotes minimum flips needed to reach 1
dp[1]=1;
for(int i=2;i<=maxN;i++)
 dp[i]=inf;

for(int i=2;i<=maxN;i++) {
 if(i%10!=0)
  dp[i]=1+min(dp[i-1],dp[flip(i)]);
 else
  dp[i]=dp[i-1]+1;
 }

/*for(int i=1;i<=20;i++)
 cout<<dp[i]<<" ";
cout<<"\n";*/

for(int tc=1;tc<=T;tc++) {
ll N;
infile>>N;

/*
//cout<<N<<"\n";
ll cnt=1;
ll a=1;
while(a!=N) {
 ll k=flip(a);
 cout<<a<<" "<<k<<"\n";
 if( k>a && k<=N) {
  a=k;
 }
 else
  a++;
  cnt++;
}
*/

myfile<<"Case #"<<tc<<": "<<dp[N]<<"\n";
//myfile<<"Case #"<<tc<<": "<<cnt<<"\n";
}
myfile.close();

    return 0;
}
