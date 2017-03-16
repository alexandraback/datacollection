#include<iostream>
#include<iterator>
#include<vector>
#include<set>
using namespace std;

vector<string> get;
vector<set<int> > muls;
int mark[20];

int main() {
	int t;
	cin>>t;
	int r,n,m,k;
	
	cin>>r>>n>>m>>k;
	for(int i='2';i<='5';i++)
		for(int j='2';j<='5';j++)
			for(int h='2';h<='5';h++) {
				string str="";
				str+=i;
				str+=j;
				str+=h;
				sort(str.begin(),str.end());
				get.push_back(str);
			}
	sort(get.begin(),get.end());
	get.erase(unique(get.begin(),get.end()),get.end());
	for(int i=0;i<get.size();i++) {
		int a = get[i][0]-'0';
		int b = get[i][1]-'0';
		int c = get[i][2]-'0';
		set<int> s;
		s.insert(1);
		s.insert(a);
		s.insert(b);
		s.insert(c);
		s.insert(a*b);
		s.insert(a*c);
		s.insert(b*c);
		s.insert(a*b*c);
		muls.push_back(s);
	}
	/*
	for(int i=0;i<get.size();i++) {
		cerr<<get[i]<<" : ";
		for(set<int>::iterator it = muls[i].begin(); it!=muls[i].end(); it++)
			cout<<*it << ' ';
		cout<<endl;
	}
	*/
	
	cout<<"Case #1:"<<endl;
	for(int i=0;i<r;i++) {
		int x;
		memset(mark,0,sizeof mark);
		for(int h=0;h<k;h++) {
			cin>>x;
			for(int j=0;j<get.size();j++)
				if(muls[j].find(x)==muls[j].end())
					mark[j] = 1;
		}
		for(int j=0;j<muls.size();j++)
			if(!mark[j]) {
				cout<<get[j]<<endl;
				break;
			}
			
	}

}
