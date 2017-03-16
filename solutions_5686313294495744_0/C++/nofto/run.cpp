#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;

vector <int> maxMatch(vector <vector <int> > left, int rightSize){
	vector <int> ret;
	ret.clear();
	vector <int> nazad;
	nazad.clear();
	int i;
	for(i=0;i<rightSize;i++) nazad.push_back(-1);
	for(i=0;i<left.size();i++) ret.push_back(-1);
	for(i=0;i<left.size();i++){
		vector <int> zasobnik;
		zasobnik.clear();
		zasobnik.push_back(i);
		bool nasiel=false;
		while(!zasobnik.empty() && !nasiel){
			int vybraty=zasobnik.back();
			zasobnik.pop_back();
			for(int j=0;j<left[vybraty].size();j++){
				if(nazad[left[vybraty][j]]==-1){
					nasiel=true;
					int right=left[vybraty][j];
					int lavy=vybraty;
					nazad[right]=lavy;
					while(lavy!=i){
						int newright=ret[lavy];
						ret[lavy]=right;
						right=newright;
						lavy=-(nazad[right]+2);
						nazad[right]=lavy;
					}
					ret[lavy]=right;
					break;
				}
				else{
					if(nazad[left[vybraty][j]]>=0){
						zasobnik.push_back(nazad[left[vybraty][j]]);
						nazad[left[vybraty][j]]=-vybraty-2;
					}
				}
			}
		}
		for(int j=0;j<rightSize;j++) if(nazad[j]<0) nazad[j]=-1;
		for(int j=0;j<left.size();j++) if(ret[j]>=0) nazad[ret[j]]=j;
	}
	return ret;
}


int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++)
	{		
		int N;
		scanf("%d",&N);
		unordered_map <string,int> w1;
		unordered_map <string,int> w2;
		int N1=0;
		int N2=0;
		vector <vector <int> > left;
		for(int i=0;i<N;i++){
			string s1,s2;
			cin >> s1;
			cin >> s2;
			int i1;
			int i2;
			if(w1.count(s1)>0){
				i1=w1[s1];
			}
			else{
				w1[s1]=N1;
				i1=N1;
				N1++;
			}
			if(w2.count(s2)>0){
				i2=w2[s2];
			}
			else{
				w2[s2]=N2;
				i2=N2;
				N2++;
			}
			if(i1+1>left.size()){
				left.push_back({i2});
			}
			else left[i1].push_back(i2);
		}
		vector <int> match=maxMatch(left,N2);
		printf("Case #%d: %d\n",t,N-match.size());
	}
  return 0;
}
