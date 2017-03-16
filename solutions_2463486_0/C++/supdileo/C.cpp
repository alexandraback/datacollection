
#include <iostream>
#include <fstream>

using namespace std;
const int maxn=39;
typedef unsigned long long ull;
ull x[maxn]={1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};


int main()
{
	ifstream cin("C-small-attempt1.in");
	ofstream cout("Csmall.out");
	int ncase;
	cin>>ncase;
	for(int icase=1;icase<=ncase;icase++){
		cout<<"Case #"<<icase<<": ";
		ull A,B;
		cin>>A>>B;
		int sum=0;
		for(int i=0;i<maxn;i++){
			if(x[i]>=A &&x[i]<=B) sum++;
		}
		cout<<sum<<endl;
	}
    return 0;
}