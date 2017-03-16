#include<stdio.h>
#include<stdlib.h>
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		int aa[34],bb[34],kk[34],ca=0,cb=0,ck=0;
		while(a!=0){
			aa[ca++]=a%2;
			a/=2;
		}
		while(b!=0){
			bb[cb++]=b%2;
			b/=2;
		}
		while(k!=0){
			kk[ck++]=k%2;
			k/=2;
		}
		int i,j,l,;
		int aaa[34][34],bbb[34][34],kkk[34][34],cnta=0,cntb=0,cntk=0;
		for(i=ck-1;i>=0;i--){
			for(j=32;j>=ck;j--) kkk[cntk][j]=0;
			for(j=ck-1;j>i;j--) kkk[cntk][j]=kk[j];
			if(kk[i]==1){
				kkk[cntk][i]=0;
				for(j=i-1;j>=0;j--) kkk[cntk][j]=-1;
				cntk++;
			}
		}
		for(i=ca-1;i>=0;i--){
			for(j=32;j>=ca;j--) aaa[cnta][j]=0;
			for(j=ca-1;j>i;j--) aaa[cnta][j]=aa[j];
			if(aa[i]==1){
				aaa[cnta][i]=0;
				for(j=i-1;j>=0;j--) aaa[cnta][j]=-1;
				cnta++;
			}
		}
		for(i=cb-1;i>=0;i--){
			for(j=32;j>=cb;j--) bbb[cntb][j]=0;
			for(j=cb-1;j>i;j--) bbb[cntb][j]=bb[j];
			if(bb[i]==1){
				bbb[cntb][i]=0;
				for(j=i-1;j>=0;j--) bbb[cntb][j]=-1;
				cntb++;
			}
		}
	/*	for(i=0;i<cntk;i++){
		  for(j=32;j>=0;j--)
		    printf("%d ",kkk[i][j]);
		  printf("\n");
		}  */
		int e;
		long long int ans=0;
		for(i=0;i<cntk;i++)
		  for(j=0;j<cnta;j++)
		    for(l=0;l<cntb;l++){
		    	long long int w=1;
		    	for(e=32;e>=0;e--)
		    	{
		    		int eee=0;
		    		if((kkk[i][e]==-1||kkk[i][e]==0)&&(aaa[j][e]==-1||aaa[j][e]==0)&&(bbb[l][e]==-1||bbb[l][e]==0)) eee++;
					if((kkk[i][e]==-1||kkk[i][e]==0)&&(aaa[j][e]==-1||aaa[j][e]==1)&&(bbb[l][e]==-1||bbb[l][e]==0)) eee++;
		    		if((kkk[i][e]==-1||kkk[i][e]==0)&&(aaa[j][e]==-1||aaa[j][e]==0)&&(bbb[l][e]==1||bbb[l][e]==-1)) eee++;
		    		if((kkk[i][e]==1||kkk[i][e]==-1)&&(aaa[j][e]==1||aaa[j][e]==-1)&&(bbb[l][e]==1||bbb[l][e]==-1)) eee++;
					w*=eee;
		    	}
		    	ans+=w;
		    }
		printf("Case #%d: %lld\n",hh,ans);
	/*	for(i=0;i<cntk;i++){
		  for(j=ck-1;j>=0;j--)
		    printf("%d ",kkk[i][j]);
		  printf("\n");
		}   */
	}
	return 0;
}
