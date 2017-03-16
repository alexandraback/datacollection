#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <gmp.h>
#include <gmpxx.h>

#define PI 3.14159265358979323846
using namespace std;

mpq_t choose[2000][2000];

int main(){

	for(int i=0;i<2000;i++)
		for(int j=0;j<2000;j++){
			mpq_init(choose[i][j]);
			mpq_set_ui(choose[i][j],0,1);
		}
	for(int i=0;i<2000;i++){
		mpq_set_ui(choose[i][0],1,1);
	}
	for(int i=1;i<2000;i++){
		for(int j=1;j<2000;j++){
			mpq_add(choose[i][j],choose[i-1][j],choose[i-1][j-1]);
		}
	}

	int T;
	cin >> T;
	for(int z=1;z<=T;z++){
		int N,X,Y;
		cin >> N >> X >> Y;

		if(X<0) X = -X;
		if(Y<0) Y = -Y;

		int layer = (X + Y)/2+1;
		int mountain = layer*(2*layer-1);

		mpq_t ans;
		mpq_init(ans);
		if(N>=mountain){
			mpq_set_ui(ans,1,1);
		} else {
			int innermountain = (layer-1)*(2*(layer-1)-1);
			if(N<=innermountain){
				mpq_set_ui(ans,0,1);
				goto end;
			}
			int sliding = N - innermountain;
			int height = Y+1;
			if(height>sliding){
				mpq_set_ui(ans,0,1);
				goto end;
			}
			if(sliding>=height+(mountain-innermountain)/2){
				mpq_set_ui(ans,1,1);
				goto end;
			}
			if(height-1==(layer-1)*2&&sliding<mountain-innermountain){
				mpq_set_ui(ans,0,1);
				goto end;
			}

			mpq_set_ui(ans,0,1);
			for(int i=height;i <= sliding;i++){
				mpq_add(ans,ans,choose[sliding][i]);
			}
			mpq_div_2exp(ans,ans,sliding);
		}

		end:
		mpf_t flans;
		mpf_init(flans);
		mpf_set_q(flans,ans);
		gmp_printf("Case #%d: %.10Ff\n",z,flans);
	}
}