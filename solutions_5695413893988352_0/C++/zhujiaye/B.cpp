#include<string>
#include<iostream>
#include<vector>
#include<cstdio>
#define UN ('?'-'0')
//#define debug
using namespace std;

int N,Q;
string s1,s2;
int ans1,ans2;
int diff;

void update(int tmp,int x,int y,bool first){
	if (!first)
		swap(x,y);
	if (diff==-1 || tmp<diff || tmp==diff && (x<ans1 || x==ans1 && y<ans2)) {
		diff=tmp;
		ans1=x;
		ans2=y;
	}
}	
void calc(int mask,vector<int> n1,vector<int> n2,bool first){
	int bit,prebit;
	for (int i=0;i<N;i++){
		int bit=mask&(1<<i);
		int x=n1[i];
		int y=n2[i];
		if (i==0 || !prebit){
			if (y==UN){
				if (x!=UN)
					y=n2[i]=x-(bit>0);
				else
					y=n2[i]=0;
				if (y<0)
					return;

			}			
			if (x==UN){
				x=y;
				if (bit){
					x=y+1;
					if (x>9)
						return;
				}
				n1[i]=x;
			}
			if (x-(bit>0)<y)
				return;
		}
		else{
			if (y==UN){
				y=n2[i]=9;
			}
			if (x==UN){
				x=n1[i]=0;
			}
			if (x-(bit>0)>=y)
				return;
		}
		prebit=bit;
	}
	int tmp1,tmp2;
	tmp1=tmp2=0;
	for (int i=0;i<N;i++){
		tmp1=tmp1*10+n1[i];
		tmp2=tmp2*10+n2[i];
	}
#ifdef debug
	cout<<tmp1<<" "<<tmp2<<" "<<mask<<endl;
#endif
	update(tmp1-tmp2,tmp1,tmp2,first);
}
void print(int len,int x){
	vector<int>nums;
	for (;x;x/=10)
		nums.push_back(x%10);
	for (;nums.size()<len;nums.push_back(0));
	for (int i=len-1;i>=0;i--)
		cout<<nums[i];
}
int main(){
	freopen("i.txt","r",stdin);
	cin>>Q;
	for (int testcase=1;Q--;testcase++){
		cout<<"Case #"<<testcase<<": ";
		cin>>s1>>s2;
		diff=-1;
		N=s1.size();
		vector<int>n1,n2;
		for (int i=0;i<N;i++){
			n1.push_back(s1[i]-'0');
			n2.push_back(s2[i]-'0');
		}
		for (int i=0;i<1<<(N-1);i++){
			int diff;
			calc(i,n1,n2,true);
			calc(i,n2,n1,false);
		}
		print(N,ans1);
		cout<<" ";
		print(N,ans2);
		cout<<endl;
	}	
	return 0;
}
