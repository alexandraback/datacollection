#include "math.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "string"
#include "set"
#include "unordered_set"
#include "algorithm"
#include "map"
#include "sstream"
using namespace std;


int main(){
	int T;
	ifstream in("inputs.txt");
	ofstream out("outputs.txt");
	in>>T;
	for(int i=0;i<T;i++){
		out<<"Case #"<<i+1<<": ";
		int N;
		in>>N;
		vector <int> bff;
		for(int j=0;j<N;j++){
			int tmp;
			in>>tmp;
			bff.push_back(tmp);
		}
		int ct=0;
		map <vector <int> , int > duprec;
		for(int head=0;head<N;head++){
			int leng=0;
			int cttmp=0;
			unordered_set <int> visitedbff;
			int it=head;
			visitedbff.insert(head);
			leng++;
			while(visitedbff.find(bff[it]-1)==visitedbff.end()){
				visitedbff.insert(bff[it]-1);
				leng++;
				int tmpit=it;
				it=bff[it]-1;
				if(bff[it]-1==head){
					cttmp=leng;
				}
				if(bff[it]-1==tmpit){
					vector <int> vectmp;
					vectmp.push_back(tmpit);
					vectmp.push_back(it);
					if(duprec.find(vectmp)==duprec.end()){
						duprec[vectmp]=leng;
					}
					else{
						duprec[vectmp]=max(leng,duprec[vectmp]);
					}
				}	
			}
			ct=max(ct,cttmp);
		}
		for(auto iter=duprec.begin();iter!=duprec.end();iter++){
			vector <int> tails;
			tails=iter->first;
			reverse(tails.begin(),tails.end());
			if(duprec.find(tails)!=duprec.end()){
				ct=max(ct,iter->second+duprec[tails]-2);
			}
		}
		out<<ct<<endl;	
	}
}
