#include <stdio.h>
#include <algorithm>
#define EPS (1e-20)

struct hiker{
	int t;
	double p;
};

bool operator <(hiker a, hiker b) {
	if(a.p==b.p)return a.t>b.t;
	return a.p<b.p;
}

hiker h[10000];

double mod(double x){
	while(x<0)x+=360;
	while(x>=360)x-=360;
	return x;
}

double abs(double x){
	return x>0?x:-x;
}

double cruzamento(int a, int b) {
	return abs(h[a].t*h[b].t*mod(h[a].p-h[b].p)/(h[a].t-h[b].t));
}

int main(){
	
	int testes;
	scanf("%d",&testes);
	for(int xxx=0;xxx<testes;xxx++){
		int n;
		scanf("%d",&n);
		int at=0;
		for(int i=0;i<n;i++){
			int start,number,ti;
			scanf("%d %d %d",&start, &number, &ti);
			for(int j=0;j<number;j++){
				h[at].t=ti+j;
				h[at].p=start;
				at++;
			}
		}
		printf("Case #%d: ", xxx+1);
		if(at==1 || h[0].t==h[1].t){
			printf("0\n");
			continue;

		}
		if(h[0].t>h[1].t){
			hiker aux=h[0];
			h[0]=h[1];
			h[1]=aux;
		}

		double dist = mod(h[1].p-h[0].p);
		double tempolento = h[1].t*(360-h[1].p)/360;
		double tempocruzamento = dist*h[0].t*h[1].t/(360*(h[1].t-h[0].t));
		if(h[0].p<h[1].p)tempocruzamento+=(h[0].t*h[1].t/((h[1].t-h[0].t)));
		if(tempolento>=tempocruzamento || abs(tempolento- tempocruzamento)<EPS)printf("1\n");
		else printf("0\n");

		continue;
		double pos=0;
		int count=0;
		while(true){
			std::sort(h,h+at);
			int proximo=-1;
			for(int i=0;i<at;i++){
				if(h[i].p>pos){
					proximo=i;
					break;
				}
			}
			double tempominimo=1e10;
			for(int i=0;i<at;i++){
				if(proximo==i)continue;
				double tempocruzamento = cruzamento(i,proximo);
				if(tempocruzamento<tempominimo){
					tempominimo=tempocruzamento;
				}
			}
			if(h[proximo].p*h[proximo].t+360*tempominimo>360*h[proximo].t){
				break;
			}
			int rapidos=0,lentos=0;
			for(int i=0;i<at;i++){
				h[i].p=h[i].p+360*tempominimo/h[i].t;
				while(h[i].p>360)h[i].p-=360;
				if(h[i].p-h[proximo].p<EPS){
					if(i==proximo)continue;
					if(h[i].t<h[proximo].t)rapidos++;
					else lentos++;
				}
			}

			if(rapidos>0){
				count+=lentos+1;
				pos=h[proximo].p+EPS;
			}else {
				pos=h[proximo].p-EPS;
			}

		}
		printf("%d\n", count);



	}
}