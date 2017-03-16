#include<stdio.h>
#include<string.h>

char map[200];

void init()
{
    map['a'] = 'y';
    map['b'] = 'h';
    map['c'] = 'e';
    map['d'] = 's';
    map['e'] = 'o';
    map['f'] = 'c';
    map['g'] = 'v';
    map['h'] = 'x';
    map['i'] = 'd';
    map['j'] = 'u';
    map['k'] = 'i';
    map['l'] = 'g';
    map['m'] = 'l';
    map['n'] = 'b';
    map['o'] = 'k';
    map['p'] = 'r';
    map['q'] = 'z';
    map['r'] = 't';
    map['s'] = 'n';
    map['t'] = 'w';
    map['u'] = 'j';
    map['v'] = 'p';
    map['w'] = 'f';
    map['x'] = 'm';
    map['y'] = 'a';
    map['z'] = 'q';
}

int main()
{
    FILE *in;
    FILE *out;
    int t, len, i, j, k=0;
    char arr[305];
    
    init();
    
    in = fopen("A-small.in", "r");
    out = fopen("A-small.out", "w");
    
    fscanf(in, "%d\n", &t);
    
    while(t--)
    {
        k++;
        fgets(arr, 300, in);
        len = strlen(arr);
        fprintf(out, "Case #%d: ", k);
        for(i=0; i<len; i++)
        {
            if(arr[i]>=97 && arr[i]<=122) fprintf(out, "%c", map[arr[i]]);
            else fprintf(out, "%c", arr[i]);
        }
    }
    
    fclose(in);
    fclose(out);
    scanf("%d", &t);
    return 0;
}
