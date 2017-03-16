#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class st{
	public:
	st(string tmp){
		len=0;
		for(int i=0;i<tmp.size();++i){
			if(tmp[i]=='0')
				++len;
			else
				break;
		}
		if(len==tmp.size()){
			s="0";
			len=1;
			return;
		}
		char c[200];
		for(int i=len;i<tmp.size()-len;++i){
			c[i-len]=tmp[i];
		}
		len=tmp.size()-2*len;
		c[len]=0;
		s=string(c);
		//len=s.size()-2*len;
	}
	string s;
	int len;
	bool operator<(const st x) const{
		if(len!=x.len){
			return len<x.len;
		}
		else{
			return s<x.s;
		}
	}
};
char* p;
int main(){
	//p=new char[200000000];
	//q=new long long int[100000];


	//int dp[5]={1,1};

	//for(int i=2;i<=50;++i){
	//	int tmp[4];
	//	for(int j=0;j<=4;++j)
	//		tmp[j]=dp[j];
	//	dp[0]=tmp[0];
	//	dp[1]=tmp[1]+tmp[0];
	//	dp[2]=tmp[1]+tmp[2];
	//	dp[3]=tmp[2]+tmp[3];
	//	dp[4]=tmp[0]+tmp[3]+tmp[4];
	//}
	//for(int i=0;i<=4;++i){
	//	cout<<dp[i]<<" ";
	//}
	//cout<<endl;
	
	vector<string> dp[5];
	dp[0].push_back("0");
	dp[1].push_back("1");
	dp[4].push_back("2");
	for(int i=2;i<=28;++i){
		for(int j=4;j>=0;--j){
		
			for(int k=0;k<dp[j].size();++k){
				dp[j][k]+="0";
			}
			if(j>0){
				for(int k=0;k<dp[j-1].size();++k){
					dp[j].push_back(dp[j-1][k]+"1");
				}
			}
			if(j==4){
				for(int k=0;k<dp[j-4].size();++k)
					dp[j].push_back(dp[j-4][k]+"2");
			}
		}
	}
	vector<st> q;

	char stmp[200];
	for(int i=1;i<=4;++i){
		for(int j=0;j<dp[i].size();++j){
			for(int k=0;k<dp[i][j].size();++k)
				stmp[k]=dp[i][j][dp[i][j].size()-k-1];
			stmp[dp[i][j].size()]=0;
			q.push_back(dp[i][j]+string(stmp));
		}

		for(int j=0;j<dp[i].size();++j){
			for(int k=0;k<dp[i][j].size();++k)
				stmp[k]=dp[i][j][dp[i][j].size()-k-1];
			stmp[dp[i][j].size()]=0;
			q.push_back(dp[i][j]+"0"+string(stmp));
			q.push_back(dp[i][j]+"1"+string(stmp));
		}
	}
	q.push_back(dp[0][0]+"1"+dp[0][0]);

	for(int i=0;i<=2;++i){
		for(int j=0;j<dp[i].size();++j){
			for(int k=0;k<dp[i][j].size();++k)
				stmp[k]=dp[i][j][dp[i][j].size()-k-1];
			stmp[dp[i][j].size()]=0;
			q.push_back(dp[i][j]+"2"+string(stmp));
		}
	}

	q.push_back(st("3"));
	sort(q.begin(),q.end());

	//for(int i=0;i<q.size();++i){
	//	cout<<q[i].s<<endl;
	//}
	//cout<<q.size();

	vector<st> p;
	for(int i=0;i<q.size();++i){

		string& s=q[i].s;
		int sum;
		for(int j=0;j<s.size()*2-1;++j){
			sum=0;
			for(int k=0;k<s.size();++k){
				if(j-k>=s.size()||j-k<0)
					continue;
				sum+=(s[k]-'0')*(s[j-k]-'0');
			}
			stmp[j]=sum+'0';
		}
		stmp[s.size()*2-1]=0;
		p.push_back(st(stmp));
	}
	//for(int i=0;i<40;++i)
	//	cout<<p[i].s<<endl;


	//for(int i=0;i<=4;++i){
	//	cout<<"=== "<<i<<" ============================\n";
	//	for(int j=0;j<dp[i].size();++j){
	//		cout<<dp[i][j]<<"\n";
	//	}
	//}


	int T;
	cin>>T;

	int count;
	string ain;
	string bin;
	for(int Ti=1;Ti<=T;++Ti){
		cout<<"Case #"<<Ti<<": ";
		count=0;
		cin>>ain;
		cin>>bin;
		st a=ain;
		st b=bin;
		//cout<<a.s<<" "<<b.s;
		
		int an;
		int bn;

		int up=p.size()-1;
		int lo=0;
		int mi;
		st ta=a;
		while(lo<up-1){
			mi=(up+lo)/2;
			if(ta<p[mi]){
				up=mi;
			}
			else{
				lo=mi;
			}
		}
		an=lo;

		up=p.size()-1;
		lo=0;
		ta=b;
		while(lo<up-1){
			mi=(up+lo)/2;
			if(ta<p[mi]){
				up=mi;
			}
			else{
				lo=mi;
			}
		}
		bn=lo;

		if(p[an].s==ain){
			cout<<bn-an+1;
		}
		else{
			cout<<bn-an;
		}
		cout<<"\n";

	}

	return 0;
}
