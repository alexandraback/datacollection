#include <bits/stdc++.h>
using namespace std;
int L[360],N,*H,*sH,nH;
void sort()
{
	int tI,temp;
	for(int i=0;i<nH;i++)
	{
		tI=i;
		for(int j=i+1;j<nH;j++)
			if(H[j]<H[tI]) tI=j;
		temp=H[i];
		H[i]=H[tI];
		H[tI]=temp;
		temp=sH[i];
		sH[i]=sH[tI];
		sH[tI]=temp;
	}
}
void solve()
{
	for(int i=0;i<360;i++)L[i]=0;
	cin>>N;
	nH=0;
	H=(int *)malloc(sizeof(int));
	sH=(int *)malloc(sizeof(int));

	for(int i=0;i<N;i++)
	{
		int D;
		cin>>D;
		int a,s;
		cin>>a>>s;

		H=(int *)realloc(H,sizeof(int)*(nH+a));
		sH=(int *)realloc(sH,sizeof(int)*(nH+a));

		for(int i=0;i<a;i++)
		{
			H[i+nH]=D;
			sH[i+nH]=s+i;
		}
		nH+=a;
	}
	sort();
	double oT,mT;
	int c,Imin=INT_MAX,mS=1;
	for(int cHD=0;cHD<nH;cHD++)
	{

		
		c=0;
		mS=sH[cHD];
		int l=H[cHD]-1;
		int oS,oL;
		for(int i=1;i<=l;i++)
		{
			for(int j=0;j<nH;j++)
				if(H[j]==i) {c++;break;}
		}
		//int myDis=dis(360-l);
		for(int other=0;other<nH;other++)
		{
			oS=sH[other];
			oL=H[other];
			if(oL==l && oS==mS) {c=INT_MAX;break;}
			else if(oL!=l && oS==mS) ;
			else if(oL>l && oS<mS)
			{
			oT=(double)((360-oL))/oS;
			mT=(double)((360-l))/mS;
			//cout<<"oL="<<oL<<" MT = "<<mT<<" oT= "<<oT<<';';
				if(mT<=oT) c++;
			}
			else if(oL>l && oS>mS)
			{
			oT=(double)((360+l-oL))/(oS-mS);
			mT=(double)((360-l))/mS;
			//cout<<"oL="<<oL<<" MT = "<<mT<<" oT= "<<oT<<';';
				if(mT>=oT) c++;
			}
			else if(oL<l && oS>mS)
			{
			oT=(double)((l-oL))/(oS-mS);
			mT=(double)((360-l))/mS;
				if(mT>=oT) c++;
			}
			else if(oL<l && oS<mS)
			{;
			}


		}
		if(c<Imin) Imin=c;

		//cout<<"BEFORE "<<cHD<<"MSPEED="<<mS<<" loc="<<l<<" : c="<<c<<endl;
	}

	cout<<Imin;
}
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i );
		solve();
		printf("\n");
	}
	return 0;
}