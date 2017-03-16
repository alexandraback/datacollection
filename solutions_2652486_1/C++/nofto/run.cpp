#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


int main()
{
	int T;
	scanf("%d\n",&T);  
	for(int t=1; t<=T; t++)
	{
		int R,N,M,K;
     	int sucin;
     	int vyskyt[9];
     	int vyskyt2[9];
     	int vyskyt3[9];
		scanf("%d %d %d %d\n",&R,&N,&M,&K);  
        printf("Case #%d:\n",t);
	    for(int i=0; i<R; i++){
	    	for(int c=2;c<=M;c++) vyskyt[c]=0;
	    	for(int c=2;c<=M;c++) vyskyt2[c]=0;
	    	for(int c=2;c<=M;c++) vyskyt3[c]=0;
	        for(int j=0; j<K; j++){
	    	    scanf("%d",&sucin);
	    	    for(int c=2;c<=M;c++){
	    	    	if(sucin%c==0 && sucin%(c*c)!=0) vyskyt[c]++;
	    	    	if(sucin%(c*c)==0 && sucin%(c*c*c)!=0) vyskyt2[c]++;
	    	    	if(sucin%(c*c*c)==0) vyskyt3[c]++;
	    	    }
	        }
	        int rv=0;
	        int zap=0;
			for(int c=2;c<=M;c++){
	          if(vyskyt[c]>0) rv++;
			}
			if(rv==N){
			    for(int c=2;c<=M;c++){
	                if(vyskyt[c]>0){printf("%d",c);zap++;}
			    }
			}
			if(rv<N){
     		    for(int c=2;c<=M;c++){
	                if(vyskyt[c]>0){printf("%d",c);zap++;}
			    }
			}
			if(zap<N){
     		    for(int c=2;c<=M;c++){
	                if(vyskyt2[c]>0 && zap<N){printf("%d",c);zap++;}
			    }
			}
			if(zap<N){
     		    for(int c=2;c<=M;c++){
	                if(vyskyt3[c]>0 && zap<N){printf("%d",c);zap++;}
			    }
			}
			bool nasiel=false;
			while(zap<N){
				for(int c=2;c<=M;c++){
					if(vyskyt2[c]>0 && zap<N){printf("%d",c);zap++;nasiel=true;}
				}
				if(!nasiel) vyskyt2[2]=1;
			}
	        printf("\n");
		}
	}

  
  return 0;
}
