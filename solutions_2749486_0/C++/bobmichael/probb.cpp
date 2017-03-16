//#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <map> 
#include <cstdlib>
using namespace std;

ifstream cin("B-small-attempt0 (1).in");
ofstream cout("out2.txt");

int X,Y;
map< pair<int,int>, int > mp;
map< pair<int,int>, pair<int,int> > p;

void getAdjacent(pair<int,int> newv, vector < pair<int,int> > &vi){
	int dst=mp[newv]+1;
	int i=newv.first,j=newv.second;
	//cout<<"FROM: "<<i<<","<<j<<"\n";
	for(int k=-dst;k<=dst;k+=dst)
		for(int l=-dst;l<=dst;l+=dst){
			if(abs(k+l)==dst)
				vi.push_back(make_pair(i+k,j+l));
			//cout<<i+k<<","<<j+l<<endl;
		}
}
void BFS(pair<int,int> source){
	mp.clear();
	mp[(source)] = 0;
	queue < pair<int,int> > Q;
	Q.push(source);		
	while(Q.size()!=0){	
		pair<int,int> newv = Q.front();	
		if(newv.first==X && newv.second==Y) return;
		Q.pop();
		vector < pair<int,int> > vvi;
		getAdjacent(newv,vvi);
		for(int i=0;i<vvi.size();i++){			
			if(mp.count((vvi[i]))==0){
				mp[(vvi[i])]=mp[newv]+1;
				p[vvi[i]]=newv;
				Q.push(vvi[i]);					
			}
		}
	}
}
deque<char> s;
deque<char> debug;
void getpath(){
	s.clear();
	pair<int,int> curr = make_pair(X,Y),prev;
	while(curr!=make_pair(0,0)){
		prev=p[curr];
		if(curr.first>prev.first) s.push_front('E');
		if(curr.first<prev.first) s.push_front('W');
		if(curr.second>prev.second) s.push_front('N');
		if(curr.second<prev.second) s.push_front('S');
		curr=prev;
	}
}

int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>X>>Y;
		BFS(make_pair(0,0));
		getpath();
		cout<<"Case #"<<t<<": ";
		for(int i=0;i<s.size();i++) cout<<s[i]; cout<<endl;
	}
}