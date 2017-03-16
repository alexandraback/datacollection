#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define MAX 10000000

bool isPalin(long long x){
ostringstream os;
if(x%10 ==0) 
return 0;
os << x;
string str=os.str();
int len=str.size();
for(int i=0;i<len/2;i++){
	if(str[i] != str[len-1-i])
		return false;
}

return true;
}

int main()
{
long long i,T,A,B;
int *total=new int[MAX],Cas=1,cnt;
vector<long long> ll;
total[1]=1;
for(i=1;i<MAX;i++){
	if(isPalin(i)){
		if(isPalin(i*i)){
			ll.push_back(i*i);	
		}
	}
}
/*cout<<"input "<<ll.size()<<endl;
for(i=0;i<ll.size();i++)
	cout<<ll[i]<<" ";
	cout<<endl;
*/
cin>>T;
while(T--){
	cin>>A>>B;
	cnt=0;
	for(i=0;i<ll.size();i++){
		if(ll[i]>=A && ll[i]<=B){
			cnt++;
		}
	}
	cout<<"Case #"<<Cas++<<": "<<cnt<<endl;
}

return 0;
}
