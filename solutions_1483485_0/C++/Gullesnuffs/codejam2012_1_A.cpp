#include <stdio.h>

using namespace std;

int main()
{
	char letter[26]={'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	int lineN;
	char G[105], out[2];
	FILE *fin = fopen("input.in", "r");
	FILE *fout = fopen("output.txt", "w");
	fscanf(fin, "%d", &lineN);
	fgets(G, sizeof(G), fin);
	out[1]=0;
	for(int i=0; i < lineN; ++i){
		fgets(G, sizeof(G), fin);
		fprintf(fout, "Case #%d: ", i+1);
		for(int j=0; G[j] != '\n' && G[j]; ++j){
			if(G[j] == ' ')
				out[0]=' ';
			else
				out[0]=letter[G[j]-'a'];
			fprintf(fout, "%s", out);
		}
		fprintf(fout, "\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
	/*char letters[256], out[2];
	bool used[256];
	FILE *fin = fopen("input.txt", "r");
	FILE *fout= fopen("output.txt", "r");
	FILE *fletters=fopen("letters.txt", "w");
	char G[105], E[120];
	int lineN;
	fscanf(fin, "%d", &lineN);
	fgets(G, sizeof(G), fin);
	for(int i=0; i < lineN; ++i){
		fgets(G, sizeof(G), fin);
		fgets(E, sizeof(E), fout);
		for(int j=0; G[j] != '\n' && G[j]; ++j)
			letters[G[j]]=E[j];
	}
	for(int i='a'; i <= 'z'; ++i)
		used[i]=0;
	out[1]=0;
	for(int i='a'; i <= 'z'; ++i){
		used[letters[i]]=1;
		out[0]=letters[i];
		fprintf(fletters, "'%s', ", out);
	}
	for(int i='a'; i <= 'z'; ++i)
		if(!used[i]){
			out[0]=i;
			printf("%s", out);
		}
	fclose(fin);
	fclose(fout);
	fclose(fletters);
	return 0;*/
}

