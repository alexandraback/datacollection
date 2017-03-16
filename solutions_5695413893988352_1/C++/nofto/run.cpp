#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <set>

using namespace std;

class Score{
	public:
		long long L;
		long long R;
		int g;
		Score(long long l,long long r,int st):L(l),R(r),g(st){
		}
};

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++)
	{		
		string C,J;
		//scanf("%d",&N);
		cin >> C;
		cin >> J;
		vector <vector <Score> > score(C.length()+1);
		score[0].push_back(Score(0,0,0));
		for(int i=0;i<C.length();i++){
			if(C[i]=='?' && J[i]=='?'){
				for(int j=0;j<score[i].size();j++){
					if(score[i][j].g==0){
						score[i+1].push_back(Score(score[i][j].L*10,score[i][j].R*10,0));
						score[i+1].push_back(Score(score[i][j].L*10+1,score[i][j].R*10,-1));
						score[i+1].push_back(Score(score[i][j].L*10,score[i][j].R*10+1,1));
					}
					else if(score[i][j].g==-1){
						score[i+1].push_back(Score(score[i][j].L*10,score[i][j].R*10+9,-1));			
					}
					else score[i+1].push_back(Score(score[i][j].L*10+9,score[i][j].R*10,1));
				}
			}
			if(C[i]=='?' && J[i]!='?'){
				int JV=J[i]-'0';
				for(int j=0;j<score[i].size();j++){
					if(score[i][j].g==0){
						score[i+1].push_back(Score(score[i][j].L*10+JV,score[i][j].R*10+JV,0));
						if(JV!=9) score[i+1].push_back(Score(score[i][j].L*10+JV+1,score[i][j].R*10+JV,-1));
						if(JV!=0) score[i+1].push_back(Score(score[i][j].L*10+JV-1,score[i][j].R*10+JV,1));
					}
					else if(score[i][j].g==-1)	score[i+1].push_back(Score(score[i][j].L*10,score[i][j].R*10+JV,-1));
					else score[i+1].push_back(Score(score[i][j].L*10+9,score[i][j].R*10+JV,1));
				}
			}
			if(C[i]!='?' && J[i]=='?'){
				int JV=C[i]-'0';
				for(int j=0;j<score[i].size();j++){
					if(score[i][j].g==0){
						score[i+1].push_back(Score(score[i][j].L*10+JV,score[i][j].R*10+JV,0));
						if(JV!=9) score[i+1].push_back(Score(score[i][j].L*10+JV,score[i][j].R*10+JV+1,1));
						if(JV!=0) score[i+1].push_back(Score(score[i][j].L*10+JV,score[i][j].R*10+JV-1,-1));
					}
					else if(score[i][j].g==-1)	score[i+1].push_back(Score(score[i][j].L*10+JV,score[i][j].R*10+9,-1));
					else score[i+1].push_back(Score(score[i][j].L*10+JV,score[i][j].R*10+0,1));
				}
			}
			if(C[i]!='?' && J[i]!='?'){
				int JV=J[i]-'0';
				int CV=C[i]-'0';
				for(int j=0;j<score[i].size();j++){
					int g=score[i][j].g;
					if(g==0) g = (CV>JV) ? -1 : (CV==JV ? 0:1);
					score[i+1].push_back(Score(score[i][j].L*10+CV,score[i][j].R*10+JV,g));
				}
			}
		}
		int L=C.length();
		long long minDif=abs(score[L][0].L-score[L][0].R);
		long long minC=score[L][0].L;
		long long minR=score[L][0].R;
		int best=0;
		for(int i=1;i<score[L].size();i++){
			long long dif=abs(score[L][i].L-score[L][i].R);
			if(dif<minDif || (dif==minDif && score[L][i].L<minC) || (dif==minDif && score[L][i].L==minC && score[L][i].R<minR)){
				minDif=dif;
				minC=score[L][i].L;
				minR=score[L][i].R;
			}
		}
		string ansC=to_string(minC);
		string ansR=to_string(minR);
		while(ansC.length()<L){
			ansC="0"+ansC;
		}
		while(ansR.length()<L){
			ansR="0"+ansR;
		}
		
		printf("Case #%d: %s %s\n",t,ansC.c_str(),ansR.c_str());
	}
  return 0;
}
