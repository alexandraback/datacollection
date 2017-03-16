#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;
struct Cell{
	int* next;
	int size;//for next
};
int path;
void nextNode(Cell* node,int node1, int node2){
	for(int i=0;i<node[node1].size;++i){
		if(node[node1].next[i]==node2) {
			++path;
			if(path>=2) return;
		} else {
			nextNode(node, node[node1].next[i],node2);
		}
	}
}

int main(){
	ifstream infile;
	char inname[50];
	cout<<"input input filename: ";
	cin>>inname;	
	infile.open(inname);
	FILE *outfile;
	outfile=fopen("p1Ans.txt","w");
	int T;
	infile>>T;
	string line;
	getline(infile,line);
	int I=1;
	cout<<T<<endl;
	cout<<"end of input T"<<endl;
	while(I<=T){
		cout<<I;//test
		cout<<" start to process case"<<endl;//test
		//input
		int N=-1;
		infile>>N;
		Cell* node=new Cell[N];
		for(int i=0;i<N;++i){
			infile>>node[i].size;
			if(node[i].size>0)	node[i].next=new int[node[i].size];
			for(int j=0;j<node[i].size;++j){
				infile>>node[i].next[j];
				--node[i].next[j];
			}
		}
		//calculate
		bool ans=false;
		for(int node1=0;node1<N;++node1){
			for(int node2=0;node2<N;++node2){
				if(node1==node2) continue;
				path=0;
				nextNode(node,node1,node2);
				//cout<<node1<<" "<<node2<<" "<<path<<endl;//test
				if(path>=2) {
					ans=true;
					break;
				}
			}
		}
		//output	
		fprintf(outfile,"Case #%d:",I);
		if(ans) fprintf(outfile," Yes");
			else fprintf(outfile," No");
		fprintf(outfile,"\n");
		for(int i=0;i<N;++i){
			if(node[i].size>0)
				delete	[]node[i].next;
		}
		delete[]node;
		++I;
	}
	fclose(outfile);
return 0;
}
