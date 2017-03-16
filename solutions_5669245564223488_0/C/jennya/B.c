#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_LIMIT 100
#define STR_LEN_LIMIT 100
void getAbbreviation(char *str, char *abb)
{
    int abbLen = 0;
	
    int idx = 0;
    abb[abbLen++] = str[idx];
    
	for(idx=1; str[idx]!=0; idx++){
        if(str[idx]==str[idx-1])
            continue;
        else{
            abb[abbLen++] = str[idx];
        }
    }
    abb[abbLen]=0;
}

#define TYPE0 0 // 0
#define TYPE1 1 // 1
#define TYPE2 2 // 01
#define TYPE3 3 // 10
#define TYPE4 4 // 010
#define TYPE5 5 // 101, 0101, 1010, etc

int getType(char *str, char c)
{
    int len = strlen(str), i;
    if(len==1){
	    if(str[0]==c) return TYPE1;
		else return TYPE0;
	}else if(len==2){
	    if(str[0]==c) return TYPE3;
		else if(str[1]==c) return TYPE2;
		else return TYPE0;
	}else{
	    int occurence=0, flag;
	    
		if(str[0]==c){ occurence++; flag = TYPE3;}
		if(str[len-1]==c){ occurence++; flag = TYPE2;}
		
		for(i=1;i<len-1;i++)
		    if(str[i]==c){
			    occurence++;
				flag = TYPE4;
			}
		
		if(occurence==0) return TYPE0;
		else if(occurence==1) return flag;
		else return TYPE5;
	}
}
int factorial(int n)
{
    static int f[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	if(n<=10) return f[n];
	else{ printf("JIZZ"); exit(1); }
}
int process()
{
    int N;
    char dict[N_LIMIT+1][STR_LEN_LIMIT+1];
    scanf("%d", &N);
    int i;
	for(i=0; i<N; i++){
        scanf("%s", dict[i]);
	}

    char abb[N_LIMIT+1][STR_LEN_LIMIT+1];
    for(i=0; i<N; i++){
        getAbbreviation(dict[i], abb[i]);
    }
	
	int ans=1, alphabet, j;
	for(alphabet=0; alphabet<26; alphabet++){
#ifdef TEST
	    printf("---%d---\n", ans);
#endif
	    int typeBook[5][N_LIMIT+1], typeBookLen[5]={0};
	    for(i=0; i<N; i++){
		    int type = getType(abb[i], alphabet+'a');
#ifdef TEST
			printf("=%c: %s %d=\n", alphabet+'a', abb[i], type);
#endif
			if(type==TYPE5) return 0;
			if(type!=TYPE0) typeBook[type][typeBookLen[type]++] = i;
		}
		if(typeBookLen[TYPE4]>=1){
		    if(typeBookLen[TYPE1]+typeBookLen[TYPE2]+
			   typeBookLen[TYPE3]+typeBookLen[TYPE4] != 1)
			    return 0;
			else
			    continue;
		} else if(typeBookLen[TYPE2]>1){
		    return 0;
		} else if(typeBookLen[TYPE3]>1){
		    return 0;
		} else if(typeBookLen[TYPE2]==1 && typeBookLen[TYPE3]==1){
		    char mergeStr[STR_LEN_LIMIT+1];
			strcpy(mergeStr, abb[typeBook[TYPE2][0]]);
			strcpy(mergeStr+strlen(mergeStr)-1, abb[typeBook[TYPE3][0]]);
			ans *= factorial(typeBookLen[TYPE1]);
			for(i=1; i<5; i++)
			    for(j=0; j<typeBookLen[i]; j++)
				    abb[typeBook[i][j]][0]=0;
			strcpy(abb[typeBook[TYPE2][0]], mergeStr);
		} else if(typeBookLen[TYPE2]==1 && typeBookLen[TYPE3]==0){
		    ans *= factorial(typeBookLen[TYPE1]);
			for(i=1; i<5; i++){
			    if(i==TYPE2) continue;
			    for(j=0; j<typeBookLen[i]; j++)
				    abb[typeBook[i][j]][0]=0;
			}
		} else if(typeBookLen[TYPE2]==0 && typeBookLen[TYPE3]==1){
		    ans *= factorial(typeBookLen[TYPE1]);
			for(i=1; i<5; i++){
			    if(i==TYPE3) continue;
			    for(j=0; j<typeBookLen[i]; j++)
				    abb[typeBook[i][j]][0]=0;
			}
		} else if(typeBookLen[TYPE2]==0 && typeBookLen[TYPE3]==0){
		    ans *= factorial(typeBookLen[TYPE1]);
			for(j=1; j<typeBookLen[TYPE1]; j++)
				abb[typeBook[TYPE1][j]][0]=0;
		} else{
		    printf("JIZZ");
		    exit(1);
		}
	}
	
	int nonEmptyCnt = 0;
    for(i=0; i<N; i++)
	    if(strlen(abb[i])!=0) nonEmptyCnt++;
#ifdef TEST
	printf("xxx %d xxx\n", nonEmptyCnt);
#endif
	
	return ans*factorial(nonEmptyCnt);
}
int main()
{
    int caseNum;
    scanf("%d", &caseNum);
	int i;
    for(i=1; i<=caseNum; i++){
        int ans = process();
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
