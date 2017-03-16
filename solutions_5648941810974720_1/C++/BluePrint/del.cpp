#include<bits/stdc++.h>
using namespace std;
//#define fin cin
//#define fout cout
int main(){
	ifstream fin;
	ofstream fout;
	fin.open("A-large (1).in");
	fout.open("2.txt");
	int t,qqq=1;
	fin>>t;
	int count[26],ans[10];
	while(t--){
		memset(count,0,sizeof(count));
		memset(ans,0,sizeof(ans));
		string s;
		fin>>s;
		int n=s.length();
		for(int i=0;i<n;i++){
			count[s[i]-'A']++;
		}
		int pq='Z'-'A';
		while(count[pq]--){//0
			ans[0]++;
			count['E'-'A']--;
			count['R'-'A']--;
			count['O'-'A']--;
		}
		pq='W'-'A';
		while(count[pq]--){//2
			ans[2]++;
			count['T'-'A']--;
			count['O'-'A']--;
		}
		pq='U'-'A';
		while(count[pq]--){//4
			ans[4]++;
			count['F'-'A']--;
			count['O'-'A']--;
			count['R'-'A']--;
		}
		pq='X'-'A';
		while(count[pq]--){//6
			ans[6]++;
			count['S'-'A']--;
			count['I'-'A']--;
		}
		pq='G'-'A';
		while(count[pq]--){//8
			ans[8]++;
			count['E'-'A']--;
			count['I'-'A']--;
			count['H'-'A']--;
			count['T'-'A']--;
		}
		pq='O'-'A';
		while(count[pq]--){//1
			ans[1]++;
			count['N'-'A']--;
			count['E'-'A']--;
		}
		pq='R'-'A';
		while(count[pq]--){//3
			ans[3]++;
			count['T'-'A']--;
			count['H'-'A']--;
			count['E'-'A']--;
			count['E'-'A']--;
		}
		pq='F'-'A';
		while(count[pq]--){//5
			ans[5]++;
			count['I'-'A']--;
			count['E'-'A']--;
			count['V'-'A']--;
		}
		pq='V'-'A';
		while(count[pq]--){//7
			ans[7]++;
			count['S'-'A']--;
			count['E'-'A']--;
			count['E'-'A']--;
			count['N'-'A']--;
		}
		ans[9]=count['I'-'A'];
		fout<<"CASE #"<<qqq<<": ";
		for(int i=0;i<10;i++){
			while(ans[i]--){
				fout<<i;
			}
			//cout<<ans[i]<<" ";
			
		}
		fout<<endl;
		qqq++;
	}
	return 0;
}
