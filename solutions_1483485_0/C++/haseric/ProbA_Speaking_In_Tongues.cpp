#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

char translate(char x){
    if (x == 'a') return 'y';
    if (x == 'b') return 'h';
    if (x == 'c') return 'e';
    if (x == 'd') return 's';
    if (x == 'e') return 'o';
    if (x == 'f') return 'c';
    if (x == 'g') return 'v';
    if (x == 'h') return 'x';
    if (x == 'i') return 'd';
    if (x == 'j') return 'u';
    if (x == 'k') return 'i';
    if (x == 'l') return 'g';
    if (x == 'm') return 'l';
    if (x == 'n') return 'b';
    if (x == 'o') return 'k';
    if (x == 'p') return 'r';
    if (x == 'q') return 'z'; // return 'k';
    if (x == 'r') return 't';
    if (x == 's') return 'n';
    if (x == 't') return 'w';
    if (x == 'u') return 'j';
    if (x == 'v') return 'p';
    if (x == 'w') return 'f';
    if (x == 'x') return 'm';
    if (x == 'y') return 'a';
    if (x == 'z') return 'q'; // return 'k';
    else return x;
}

char* convert(char* in){
    char* out;
    strcpy(out,in);
    for (int a = 0; a < strlen(out); a++){
        out[a] = translate(out[a]);
    }
    return out;
}

int main(){
    FILE *in = fopen("A-small-attempt0.in","r");
    FILE *out = fopen("output.out","w");
    ofstream save("A-small-attempt0.out");
    int insum = 0;
    fscanf(in,"%d\n",&insum);
    for (int a = 0; a < insum; a++){
        char input[100] = {0};
        char* output;
        strcpy(output,"");
        fscanf(in,"%[^\n]\n",input);
        output = convert(input);
        //fprintf(out,"Case #%d: %s\n",a+1,output);
        save << "Case #" << a+1 << ": " << output << endl;
    }
    fclose(in);
    fclose(out);
    return 0;
}
