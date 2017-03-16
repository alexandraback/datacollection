#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>


using namespace std;

bool myfunction (int i,int j) { return (i<j); }

class Akt{ 
public: 
  int v;
  int por;
  bool operator<(const Akt& other) const { 
    return v > other.v || (v==other.v && por<other.por);
  }
};

int main()
{
	int T;
	scanf("%d\n",&T);  
	for(int t=1; t<=T; t++)
	{
		int A,N;
		scanf("%d %d\n",&A,&N);
		vector<int> s;
		int velkost;
		s.clear();  
        for(int i=0; i<N; i++){
		    scanf("%d",&velkost);
		    s.push_back(velkost);
		}
		sort(s.begin(),s.end());
		int answer=0;
		int index=0;
		int bestanswer=N;
		while(index<N){
			if(s[index]<A){
			    A+=s[index];
			    index++;
			}
			else{
				if(A==1){
					answer=N-index;
					index=N;
				}
				else{
					bestanswer=min(bestanswer,answer+N-index);
					int kolko=0;
					while(A<=s[index]){
						A+=A-1;
						kolko++;
					}
					answer+=kolko;
					A+=s[index];
					index++;
				}
			}
		}
		answer=min(answer,bestanswer);
		printf("Case #%d: %d\n",t,answer);		
	}

  
  return 0;
}
