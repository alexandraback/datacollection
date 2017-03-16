#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
using namespace std;


int C,D,V;
int covered[233], minted[233];
int** searchstack;
int prev_opt;//min
int search(int pos,int lvl)
{
	//cerr<<"searching:"<<pos<<":"<<lvl<<" currst:"<<searchstack[lvl][pos]<<endl;
	if(pos>V)
	{
		//cerr<<"reached max pos:"<<pos<<endl;
		if(lvl<prev_opt)prev_opt=lvl;//lvl is minted new coin
		return 0;
	}
	if(searchstack[lvl][pos]==1)
	{
		int newpos=pos;while(newpos<=V && searchstack[lvl][newpos])newpos++;
		return search(newpos,lvl);
	}
	
	//curr pos is unsatisfied, need to mint new coin
	int minreq=2*V;
	//if(lvl>prev_opt)return 2*V;//this level is already suboptimal
	
	//for(int i=0;i<=pos;i++)
	for(int i=pos;i>=0;i--)
	if(searchstack[lvl][i]==1)
	if(!minted[pos-i])
		{//purpose: mint (pos-i)
			int newmint=pos-i;
			//for(int ii=0;ii<lvl;ii++)cerr<<"--";
			//cerr<<"try minting:"<<newmint<<endl;
			
			//memcpy(searchstack[lvl],searchstack[lvl+1],sizeof(searchstack[lvl+1]));
			for(int i=0;i<=V;i++)searchstack[lvl+1][i]=searchstack[lvl][i];
			
			for(int ci=0;ci<C;ci++)
			for(int v=V+1;v>=newmint;v--)//v==pos, v-newmint=i
			{
				if(searchstack[lvl+1][v-newmint])searchstack[lvl+1][v]=1;
			}
			//filled
			minted[newmint]=1;
			int ret=search(pos+1,lvl+1);
			if(ret<minreq)minreq=ret;
			minted[newmint]=0;
			
			//for(int ii=0;ii<lvl;ii++)cerr<<"--";
			//cerr<<" outcome:"<<ret<<endl;
		}
	return 1+minreq;
}
int calc()
{
	int ds[101];
	cin>>C>>D>>V;
	//assume C=1 for now
	for(int i=0;i<D;i++)
		cin>>ds[i];
	//memset(minted,0,sizeof(minted));
	for(int i=0;i<=V+1;i++)minted[i]=0;
	for(int i=0;i<=V+1;i++)covered[i]=0;
	for(int i=0;i<D;i++)minted[ds[i]]=1;
	
	covered[0]=1;
	for(int ci=0;ci<C;ci++)
	for(int i=0;i<D;i++)
	for(int v=V+1;v>=ds[i];v--)
	{
		if(covered[v-ds[i]])covered[v]=1;
	}
	
	int nc=0;
	for(int i=0;i<=V;i++)
		if(!covered[i]){nc++;}//cerr<<"not covered"<<i<<endl;}
	
	//memcpy(searchstack[0],covered,sizeof(searchstack[0]));
	for(int i=0;i<=V;i++)searchstack[0][i]=covered[i];
	
	prev_opt=V;//minimum possible routes
	int ret=search(0,0);
	if(nc==0 && ret!=0 || ret>nc)cerr<<"strange outcome:nc"<<nc<<" ret"<<ret;
	if(ret!=prev_opt)cerr<<"prev opt mismatch? prevopt="<<prev_opt<<endl;
	return ret;
}

int main()
{
	searchstack=new int*[233];
	for(int i=0;i<233;i++)searchstack[i]=new int[233];
	
	
	//cout<<calc();return 0;
	int N;cin>>N;
	for(int i=0;i<N;i++)
		cout<<"Case #"<<(i+1)<<": "<<calc()<<endl;
	return 0;
}