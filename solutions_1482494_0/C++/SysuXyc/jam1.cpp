#include<iostream>
#include<string>
#include<memory.h>
#include<fstream>
#include<cstdio>
#include<queue>
#include<iomanip>
using namespace std;
const int MAXN=1000;
bool lv1[MAXN],lv2[MAXN];
struct pp{
	int first,second;
	pp(int p1,int p2)
		:first(p1),second(p2){}
};
struct cmp{
	bool operator()(pp p1,pp p2){
		return p1.first > p2.first;
	}
};
priority_queue<pp,vector<pp>,cmp> hp1,hp2;
int main(){
	int T;
	ifstream ipt("B-small-attempt1.in");
	ofstream ot("B-small-attempt1.out");
	ipt >> T;
	int c=T;
	while(T--){
		memset(lv1,0,sizeof(lv1));
		memset(lv2,0,sizeof(lv2));
		while(!hp1.empty()) hp1.pop();
		while(!hp2.empty()) hp2.pop();
		int n;
		ipt >> n;
		int i1,i2;
		for(int i=0;i < n;i++){
			ipt >> i1 >> i2;
			hp1.push(pp(i1,i));
			hp2.push(pp(i2,i));
		}
		int curStar=0;
		int counter=0;
		bool flag=false;
		while(!hp2.empty()){
			while(curStar < hp2.top().first){
				if(!hp1.empty() && lv2[hp1.top().second])
					hp1.pop();
				if(hp1.empty() || curStar < hp1.top().first){
					flag=true;
					break;
				}
				else{
					curStar++;
					lv1[hp1.top().second]=true;
					hp1.pop();
					counter++;
				}
			}
			if(flag)
				break;
			if(lv1[hp2.top().second])
				curStar++;
			else
				curStar += 2;
			lv2[hp2.top().second]=true;
			hp2.pop();
			counter++;
		}
		if(!flag){
			ot << "Case #" << c-T << ": " << counter << endl;
		}
		else{
			ot << "Case #" << c-T << ": " << "Too Bad" << endl;
		}
	}
	return 0;
}