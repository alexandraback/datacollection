#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE* input = fopen("C-large.in", "r");
	FILE* output= fopen("answer.out", "w");
	int T = 0;
	int L = 0;
	int X = 0;
	char* S = (char*)malloc(sizeof(char)*10002);
	int nowstring = 1; //1=1, 2=-1; 3=i, 4=-i, 5=j, 6=-j, 7=k, 8=-k
	char pstring = 'i';
	int lstring= 1;
	int resentloop = 0;
	bool geti;
	bool getj;
	bool getk;
	fscanf(input,"%d", &T);
	for (int i = 0; i < T; i++){
		resentloop = 0;
		nowstring = 1;
		lstring = 1;
		geti = false;
		getj = false;
		getk = false;
		fscanf(input, "%d", &L);
		fscanf(input, "%d", &X);
		fscanf(input, "%s", S);
		//fgets(S, 10002, input);
		for (int k = 0; k < X; k++){
			for (int j = 0; j < L; j++){
				pstring = S[j];
				if (nowstring == 1){
					if (pstring == 'i')
						nowstring = 3;
					if (pstring == 'j')
						nowstring = 5;
					if (pstring == 'k')
						nowstring = 7;
				}
				else if (nowstring == 2){
					if (pstring == 'i')
						nowstring = 4;
					if (pstring == 'j')
						nowstring = 6;
					if (pstring == 'k')
						nowstring = 8;
				}
				else if (nowstring == 3){
					if (pstring == 'i')
						nowstring = 2;
					if (pstring == 'j')
						nowstring = 7;
					if (pstring == 'k')
						nowstring = 6;
				}
				else if (nowstring == 4){
					if (pstring == 'i')
						nowstring = 1;
					if (pstring == 'j')
						nowstring = 8;
					if (pstring == 'k')
						nowstring = 5;
				}
				else if (nowstring == 5){
					if (pstring == 'i')
						nowstring = 8;
					if (pstring == 'j')
						nowstring = 2;
					if (pstring == 'k')
						nowstring = 3;
				}
				else if (nowstring == 6){
					if (pstring == 'i')
						nowstring = 7;
					if (pstring == 'j')
						nowstring = 1;
					if (pstring == 'k')
						nowstring = 4;
				}
				else if (nowstring == 7){
					if (pstring == 'i')
						nowstring = 5;
					if (pstring == 'j')
						nowstring = 4;
					if (pstring == 'k')
						nowstring = 2;
				}
				else if (nowstring == 8){
					if (pstring == 'i')
						nowstring = 6;
					if (pstring == 'j')
						nowstring = 3;
					if (pstring == 'k')
						nowstring = 1;
				}
				if (nowstring == 3 && !geti){
					geti = true;
					nowstring = 1;
					resentloop = k;
				}
				if (nowstring == 5 && !getj && geti){
					getj = true;
					nowstring = 1;
					resentloop = k;
				}
				if (nowstring == 7 && !getk && geti && getj){
					getk = true;
					nowstring = 1;
					resentloop = k;
				}
			}
			if (k - resentloop > 4)
				break;
			if (k == 0){
				if (!geti){
					lstring = nowstring;
				}
				else if (!getj){
					switch (nowstring)
					{
					case 1:{
						lstring = 3;
						break;
					}
					case 2:{
						lstring = 4;
						break;
					}
					case 3:{
						lstring = 2;
						break;
					}
					case 4:{
						lstring = 1;
						break;
					}
					case 5:{
						lstring = 7;
						break;
					}
					case 6:{
						lstring = 8;
						break;
					}
					case 7:{
						lstring = 6;
						break;
					}
					case 8:{
						lstring = 5;
						break;
					}
					default:
						break;
					}
				}
				else if (!getk){
					switch (nowstring)
					{
					case 1:{
						lstring = 7;
						break;
					}
					case 2:{
						lstring = 8;
						break;
					}
					case 3:{
						lstring = 5;
						break;
					}
					case 4:{
						lstring = 6;
						break;
					}
					case 5:{
						lstring = 4;
						break;
					}
					case 6:{
						lstring = 3;
						break;
					}
					case 7:{
						lstring = 2;
						break;
					}
					case 8:{
						lstring = 1;
						break;
					}
					default:
						break;
					}
				}
				else{
					switch (nowstring)
					{
					case 1:{
						lstring = 2;
						break;
					}
					case 2:{
						lstring = 1;
						break;
					}
					case 3:{
						lstring = 4;
						break;
					}
					case 4:{
						lstring = 3;
						break;
					}
					case 5:{
						lstring = 6;
						break;
					}
					case 6:{
						lstring = 5;
						break;
					}
					case 7:{
						lstring = 8;
						break;
					}
					case 8:{
						lstring = 7;
						break;
					}
					default:
						break;
					}
				}
			}
		}
		if (!getk){
			fprintf(output, "Case #%d: NO\n", i + 1);
			continue;
		}
		if ((lstring==2 && X%2==1)||(lstring!=1 && X%4==2)){
			fprintf(output, "Case #%d: YES\n", i + 1);
			continue;
		}
		fprintf(output, "Case #%d: NO\n", i + 1);
	}
	return;
}