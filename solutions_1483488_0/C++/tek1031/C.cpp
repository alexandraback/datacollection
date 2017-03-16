#include<iostream>
#include<sstream>
#include<set>

using namespace std;

int pow(int a,int n){
	int res=1;
	for(int i=0;i<n;i++){
		res*=a;
	}
	return res;
}


int main()
{
	int N;
	cin>>N;
	for(int n=1;n<=N;n++){

		std::ostringstream os;
		int a,b;
		cin>>a>>b;
		os<<a;
		int max_digit=os.str().size();

		int ans=0;
		set<pair<int,int> > S;
		for(int now=a;now<=b;now++){
			for(int k=1;k<=max_digit-1;k++){
				int next=(now%pow(10,k))*pow(10,max_digit-k);
				next+=now/pow(10,k);
//				cout<<now<<" "<<k<<" "<<next<<endl;
				if(next>now && next<=b && !S.count(make_pair(now,next))){
//					cout<<now<<" "<<next<<endl;
					ans++;
					S.insert(make_pair(now,next));
				}
			}
		}
		cout<<"Case #"<<n<<": "<<ans<<endl;

	}
}