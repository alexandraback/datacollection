#include<stdio.h>
#include "stdafx.h"
#include<algorithm>
using namespace std;
int main()
{
	FILE *fr=fopen("d-large.in","r");
	FILE *fw=fopen("outl.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		int x,r,c;
		fscanf(fr,"%d%d%d",&x,&r,&c);
		if(r>c)swap(r,c);
		if(x>=7)goto f;
		if((r*c)%x!=0)goto f;
		if(c<x)goto f;
		if(x==1)goto t;
		if(x==2)goto t;
		if(x==3)
		{
			if(r==1)goto f;
			else goto t;
		}
		if(x==4)
		{
			if(r==1||r==2)goto f;
			else goto t;
		}
		if(x==5)
		{
			if(r==1||r==2)goto f;
			else if(r==3&&c==5)goto f;
			else goto t;
		}
		if(x==6)
		{
			if(r==1||r==2||r==3)goto f;
			else goto t;
		}
		if(false)
		{
f:;
			fprintf(fw,"Case #%d: RICHARD\n",p+1);
		}
		if(false)
		{
t:;
			fprintf(fw,"Case #%d: GABRIEL\n",p+1);
		}
	}
}