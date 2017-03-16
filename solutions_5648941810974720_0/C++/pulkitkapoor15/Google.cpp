#include<bits/stdc++.h>

using namespace std;
int counts[26];
int checks()
{
	for(int num1=0;num1<26;num1++)
	{

	if(counts[num1]>=1)
	return 1;
}
	return 0;
}
int main(){
freopen("inputfile.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int n,t,num1,num2,decks[10];string strs;
	cin>>t;
	for(num1=1;num1<=t;num1++)
	{
		for(num2=0;num2<10;num2++)
	   {
	   	decks[num2]=0;
	   }
	   for(num2=0;num2<26;num2++)
	   {
	   	counts[num2]=0;
	   }
		cin>>strs;
		for(num2=0;num2<strs.length();num2++)
		{
		counts[strs[num2]-'A']++;
		}

		if(counts[25]>=1)
		{
			while(counts[25]!=0)
			{
			counts[4]--;
			counts[14]--;
			counts[17]--;
			counts[25]--;
			decks[0]++;
		}
		}
		if(counts[23]>=1)
		{
			while(counts[23]!=0)
			{
			counts[8]--;
			counts[18]--;
			counts[23]--;

			decks[6]++;
		}

		}
		if(counts[20]>=1)
		{
			while(counts[20]!=0)
			{
			counts[17]--;
			counts[14]--;
			counts[5]--;
			counts[20]--;
			decks[4]++;
		}
		}
		if(counts[6]>=1)
		{
		while(counts[6]!=0)
			{
			counts[6]--;
			counts[4]--;
			counts[8]--;
			counts[7]--;
			counts[19]--;
			decks[8]++;
		}
	}
	   if((counts[22]>=1))
	   {
	   	while(counts[22]!=0)
			{
			counts[22]--;
			counts[19]--;
			counts[14]--;

			decks[2]++;
		}
	   }
	   int flss=checks();
	   if(flss==1)
	   while(flss==1)
	   {

	   if(counts[14]>=1&&counts[13]>=1&&counts[4]>=1)
	   {
	   	counts[14]--;
	   	counts[13]--;
	   	counts[4]--;
	   	decks[1]++;
	   }
	   if(counts[19]>=1&&counts[7]>=1&&counts[17]>=1&&counts[4]>=2)
	   {
	   	counts[19]--;
	   	counts[7]--;
	   	counts[17]--;
	   	counts[4]-=2;
	   	decks[3]++;
	   }
	   if(counts[5]>=1&&counts[8]>=1&&counts[21]>=1&&counts[4]>=1)
	   {
	   	counts[5]--;
	   	counts[8]--;
	   	counts[21]--;
	   	counts[4]--;
	   	decks[5]++;
	   }
	   if(counts[18]>=1&&counts[4]>=2&&counts[21]>=1&&counts[13]>=1)
	   {
	   	counts[18]--;
	   	counts[4]-=2;
	   	counts[21]--;
	   	counts[13]--;
	   	decks[7]++;
	   }
	   if(counts[13]>=2&&counts[8]>=1&&counts[4]>=1)
	   {
	   	counts[13]-=2;
	   	counts[8]--;
	   	counts[4]--;
	   	decks[9]++;
	   }
	   flss=checks();
}
cout<<"Case #"<<num1<<": ";
	   for(num2=0;num2<10;num2++)
	   {
	   	if(decks[num2]>=1)
	   	{
	   		while(decks[num2]!=0)
	   		{
	   			cout<<num2;
				   decks[num2]--;
	   		}
	   	}
	   }
	   cout<<endl;
	   }
	   return 0;
	}

