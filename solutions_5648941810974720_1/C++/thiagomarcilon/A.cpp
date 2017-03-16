#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int t,T;
	FILE *fin = fopen("A.in","r");
	FILE *fout = fopen("A.txt","w");
	char s[2002];
	int ch[26];
	int num[10];
	fscanf(fin,"%d",&t);
	//scanf("%d",&t);
	fgets(s,2002,fin);
	T = t;
	while(t--){		
		fgets(s,2002,fin);
		//fgets(s,2002,stdin);
		memset(ch,0,sizeof(ch));
		memset(num,0,sizeof(num));
		for(int i=0;(s[i] != '\0') && (s[i]!='\n');i++){
			ch[((int)s[i])-65]++;
			//putchar(s[i]);
		}			
		while(ch[25]){
			ch[25]--;
			ch[4]--;
			ch[17]--;
			ch[14]--;
			num[0]++;
		}
		//printf("0 - %d\n",num[0]);
		while(ch[22]){
			ch[19]--;
			ch[22]--;
			ch[14]--;
			num[2]++;
		}
		//printf("2 - %d\n",num[2]);
		while(ch[20]){
			ch[5]--;
			ch[14]--;			
			ch[20]--;
			ch[17]--;
			num[4]++;
		}
		//printf("4 - %d\n",num[4]);
		while(ch[5]){
			ch[5]--;
			ch[8]--;			
			ch[21]--;
			ch[4]--;
			num[5]++;
		}
		//printf("5 - %d\n",num[5]);
		while(ch[23]){
			ch[18]--;
			ch[8]--;			
			ch[23]--;
			num[6]++;
		}
		//printf("6 - %d\n",num[6]);
		while(ch[18]){
			ch[18]--;
			ch[4]--;
			ch[21]--;
			ch[4]--;
			ch[13]--;
			num[7]++;
		}
		//printf("7 - %d\n",num[7]);
		while(ch[14]){
			ch[14]--;
			ch[13]--;			
			ch[4]--;
			num[1]++;
		}
		//printf("1 - %d\n",num[1]);
		while(ch[13]){
			ch[13]--;
			ch[8]--;			
			ch[13]--;
			ch[4]--;
			num[9]++;
		}
		//printf("9 - %d\n",num[9]);
		while(ch[17]){
			ch[19]--;
			ch[7]--;
			ch[17]--;
			ch[4]--;
			ch[4]--;
			num[3]++;
		}
		//printf("3 - %d\n",num[3]);
		while(ch[7]){
			ch[4]--;
			ch[8]--;
			ch[6]--;
			ch[7]--;
			ch[19]--;
			num[8]++;
		}
		//printf("8 - %d\n",num[8]);
		fprintf(fout,"Case #%d: ",T-t);
		while(num[0]--)
			fprintf(fout,"0");
		while(num[1]--)
			fprintf(fout,"1");
		while(num[2]--)
			fprintf(fout,"2");
		while(num[3]--)
			fprintf(fout,"3");
		while(num[4]--)
			fprintf(fout,"4");
		while(num[5]--)
			fprintf(fout,"5");
		while(num[6]--)
			fprintf(fout,"6");
		while(num[7]--)
			fprintf(fout,"7");
		while(num[8]--)
			fprintf(fout,"8");
		while(num[9]--)
			fprintf(fout,"9");
		fprintf(fout,"\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
