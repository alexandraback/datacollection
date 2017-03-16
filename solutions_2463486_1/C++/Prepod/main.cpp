#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream inp("C-large-1.in");
	cin.rdbuf(inp.rdbuf());
	ofstream out("output.txt");
	cout.rdbuf(out.rdbuf());
	int t; cin>>t;
	__int64 ms[]={1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001L,
102030201L,
104060401L,
121242121L,
123454321L,
125686521L,
400080004L,
404090404L,
10000200001L,
10221412201L,
12102420121L,
12345654321L,
40000800004L,
1000002000001L,
1002003002001L,
1004006004001L,
1020304030201L,
1022325232201L,
1024348434201L,
1210024200121L,
1212225222121L,
1214428244121L,
1232346432321L,
1234567654321L,
4000008000004L,
4004009004004L};
	int len=39;
	for(int i=1;i<=t;i++){
		__int64 a,b; cin>>a>>b;
		int c=0;
		for(int j=0;j<len;j++){
			if (ms[j]>=a && ms[j]<=b) c++;
		}
		cout<<"Case #"<<i<<": "<<c<<endl;
	}
	return 0;
}