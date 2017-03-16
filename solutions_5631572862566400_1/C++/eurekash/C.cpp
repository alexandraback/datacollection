#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int input[1020];
int calc(int N){


	for(int i=1;i<=N;i++){
		cin>>input[i];
	}
	for(int i=1;i<=N;i++){
		//cout<<"\n"<<i<<"->"<<input[i]<<endl;
	}

	//vector<int> loop2_start;

	int reci[1020]={0,};
	int len_to_reci[1020]={0,};
	int reci_chain_max[1020]={0,};
	int is_to_r2[1020]={0,};
	for(int i=1;i<=N;i++){ len_to_reci[i]=0;reci_chain_max[i]=0;
		reci[i]=0;
		if(input[input[i]]==i)
			reci[i]=input[i];
		//cout<<"reci:"<<i<<"->"<<reci[i]<<endl;
	}

	bool really_visited[1020];memset(really_visited,0,sizeof(really_visited));
	int ansmax=0;
	for(int i=1;i<=N;i++)
		{
			//attempt find max ans
			bool visited[1020];memset(visited,0,sizeof(visited));
			int ptr=i;
			while(true){
				visited[ptr]=true;  really_visited[ptr]=true;
				ptr=input[ptr];
				if(visited[ptr]==true)break;
			}
			//ptr is at an edge of cycle??
			int loopsize=0;
			int ptr2=ptr;
			//cout<<"startptr"<<ptr2<<endl;
			while(true)
			{
				ptr2=input[ptr2];
				//cout<<"goto"<<ptr2<<endl;
				loopsize++;
				if(ptr2==ptr)break;
			}
			//cout<<"ans:"<<loopsize<<endl;
			if(loopsize==2){
				is_to_r2[i]=true;
				//cout<<"reci:"<<ptr<<":"<<reci[ptr]<<endl;
				//special remember
				//no need to do, already have reci array
			}

			ansmax=max(ansmax,loopsize);
		}

	//here we have a naive ans: single loop
	//return ansmax;

	//finding advance ans:

	for(int i=1;i<=N;i++)
		if(is_to_r2[i])
		if(reci[i]==0){
			int chain_len=0;
			int ptr=i;
			//cout<<"entering while at:"<<ptr<<endl;
			while(true){
				ptr=input[ptr];
				chain_len++;
				//cout<<"goto:"<<ptr<<endl;
				if(reci[ptr]!=0)break;
			}
			len_to_reci[i]=chain_len;
			reci_chain_max[ptr]=max(reci_chain_max[ptr],chain_len);
		}

	int advans=0;
	for(int i=1;i<=N;i++)
		if(reci[i]>i)
			advans+=(reci_chain_max[i]+reci_chain_max[reci[i]]+2);
	/*
	for(int i=1;i<=N-1;i++)
		if(reci[i]!=0)
	for(int j=i+1;j<=N;j++)
		if(reci[j]!=0)
		if(i!=j){
			//case 1: one chain, two ends
			if(reci[i]==j){
				int onechain=reci_chain_max[i]+reci_chain_max[j];
				//cout<<"one reci chains longest="<<onechain<<":"<<i<<":"<<j<<'(';
				//cout<<reci_chain_max[i]<<":"<<reci_chain_max[j]<<endl;
				advans=max(advans,onechain+2);
			}
			//case 2: two chains
			if(reci[i]!=j){
				int onechain=reci_chain_max[i]+reci_chain_max[j];
				onechain+=reci_chain_max[reci[i]];
				onechain+=reci_chain_max[reci[j]];
				//cout<<"two reci chains longest="<<onechain<<"("<<i<<":"<<j<<'(';
				//cout<<reci_chain_max[i]<<":"<<reci_chain_max[j]<<endl;
				advans=max(advans,onechain+4);
			
			}
		}*/


	return max(ansmax,advans);
}

int main()
{
	int T,N;
	scanf("%d\n",&T);
	char s[200];
	for(int tt=1;tt<=T;tt++)
	{
		printf("Case #%d: ",tt);
		cin>>N;
		cout<<calc(N)<<endl;
		//printf("\n");
	}
}

