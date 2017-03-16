#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>   
#include<deque>
using namespace std;


int main(){
	ifstream cin;
	cin.open("A-large.in");
	ofstream cout;
	//	dic.open("garbled_email_dictionary.txt");
	cout.open("out.txt");




	int T;
	cin>>T;
	for(int k=0;k<T;k++){
		deque<pair<int,int> > p;
		string s;
		int n;
		cin>>s;
		cin>>n;
//------------------------------------------------------------------
		for(int i=0;i<s.length();i++){

			int start=i;
			int end=i;

			while( i<s.length() && s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
				end=i;
				i++;
			}
			
			if(end-start+1>=n){	p.push_back(make_pair(start,end));}
				
		}
		//for(int i=0;i<p.size();i++) cout<<p[i].first<<" "<<p[i].second<<endl;
//-----------------------------got-p---------------------------------
		long long fcount=0;
		for(int i=0;!p.empty() && i<s.size();i++){
			int w=p[0].second-p[0].first +1;
			int extra=w-n;					//cout<<extra<<endl;
			int add=s.size()-1-p[0].second;			 //cout<<add<<endl;

			if(i<p[0].first){
				fcount += 1+ add + extra;
				if(p[0].second-i+1 == n) p.pop_front();

			}
			

			else{

				if(p[0].second-i+1>=n) fcount += 1 +  add + extra + (p[0].first-i);
				if(p[0].second-i+1==n) p.pop_front();

			}

		


		}






	
	
	cout<<"Case #"<<k+1<<": "<<fcount<<endl;

	}


	


	return 0;






}





