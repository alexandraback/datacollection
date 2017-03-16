#include<iostream>
#include<cstdio>
#include<cmath>
#define forloop(i,a,b) for(int i=(a);i<(b);i++)

void solve(){
	long double d,ts[3000],xs[3000],as[300],ti,xo,uo,xm,um,am,tr,del_t;
	int n,a,done;

	scanf("%Lf%d%d",&d,&n,&a);
	forloop(i,0,n){
		scanf("%Lf%Lf",&ts[i],&xs[i]);
	}
	forloop(i,0,a){
		scanf("%Lf",&as[i]);
	}

	forloop(i,0,a){
		am=as[i];
		done=0;
		um=0;
		xm=0;
		tr=0;
		//first done
		if(xs[0] >= d){
			tr=sqrtl((2*d)/am);	
		}
		//else not		
		else{
			for(int j=1;j<n && !done;j++){
				uo=(xs[j]-xs[j-1])/(ts[j]-ts[j-1]);				
				if(xs[j] > d){
					xo=d;	
					ti=ts[j-1]+(d-xs[j-1])/uo;
					done=1;
				}else{
					xo=xs[j];
					ti=ts[j];
				}
				
				del_t=ti-ts[j-1];

				uo=(xs[j]-xs[j-1])/(ts[j]-ts[j-1]);

				xm=um*del_t+0.5*am*del_t*del_t;
				um+=am*del_t;
				tr+=del_t;

							

				if(xm > xo){
					xm=xo;	
					
					if(j < n-1){
						uo=(xs[j+1]-xs[j])/(ts[j+1]-ts[j]);
						if(um > uo){
							um=uo;
						}
					}
				}

				//printf("%Lf %Lf %Lf %Lf %Lf %Lf\n",xm,um,xo,uo,am,tr);	
			}

			if(xm < d){
				//printf("added = %Lf\n",(sqrtl(um*um+2*am*(d-xm)) - um)/am);
				tr+=(sqrtl(um*um+2*am*(d-xm)) - um)/am;
			}

			printf("%Lf\n",tr);
		}
	}
}

main(){
	int testcases;
	scanf("%d",&testcases);
	forloop(i,0,testcases){
		printf("Case #%d:\n",i+1);
		solve();
	}
}
