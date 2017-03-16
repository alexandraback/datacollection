#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char array[255];

char *inputs[3] = {
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

char *outputs[3] = {
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"
};

void initialize_array(char *string, char *output){
int i;
int j;

i = strlen(string);
for(j = 0; j < i; j++) {
	array[string[j]] = output[j];
//	array[output[j]] = string[j];
	}
}

char *translate(char *string) 
{
int i;
char *return_value;
int j;

i = strlen(string);
return_value = (char *) malloc(i);

for(j = 0; j < i; j++) {
	return_value[j] = array[string[j]]; 
	}
return return_value;
}

int main()
{
int i;
char *temp;
char *temp2;
char read_words[200];
int T;
size_t linecap = 0;

for(i = 97; i<=122; i++) array[i]= 65;

for(i =0 ; i <3; i++ ) {
 initialize_array(inputs[i],outputs[i]);
}
array[122] = 113;
array[113] = 122;

scanf("%d\n",&T);
for(i = 0; i< T; i++) {
	temp2 = NULL;
	getline(&temp2, &linecap, stdin);
	temp = translate(temp2);
	printf("Case #%d: %s\n",i+1, temp);
	free(temp);
	free(temp2);
	}

//for(i = 97; i<=122; i++) printf("%c : %c \n ",i,array[i]);

return 0;
}
