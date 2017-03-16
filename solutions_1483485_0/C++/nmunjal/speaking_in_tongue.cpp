#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

FILE *in = stdin;
FILE *out = stdout;
void initialize(char **map)
{
    int i;
    for (i = 0; i < 26; i++)
    {
        map[0][i] = 'a' + i;
        map[1][i] = 0;
    }
}

void learn_helper(char **map, char *l, char *s)
{
    int i;
    for (i = 0; i < strlen(l); i++)
    {
        if (l[i] != ' ')
        if (map[1][l[i] - 'a'] == 0)
        {
            map[1][l[i] - 'a'] = s[i];
        }
        else
        {
#if 0
            cout << "repeat char = " << l[i] << ", old value = " << map[1][l[i] - 'a'] << " and new value = " << s[i] << "\n";
            if (s[i] != map[1][l[i] - 'a'])
                cout << "error" << "\n";
#endif
        }
    }
}

void learn(char **map)
{
    char *l = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    char *s = "our language is impossible to understand";
    learn_helper(map, l, s);

    l = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    s = "there are twenty six factorial possibilities";
    learn_helper(map, l, s);
    
    l = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    s = "so it is okay if you want to just give up";
    learn_helper(map, l, s);
}

void problem(char **map)
{
    int i;
    map[1]['z' - 'a'] = 'q';
    map[1]['q' - 'a'] = 'z';
    for (i = 0; i < strlen(map[0]); i++)
    {
        if (map[1][i] == 0)
            cout << "no value for " << map[0][i] << "\n";
    }
}

void getSoln(char **map, int T, char *line)
{
    int i;
    char sol[105];
    char final[130];
    for (i = 0; i < strlen(line); i++)
    {
        if (line[i] == ' ')
            sol[i] = ' ';
        else
            sol[i] = map[1][line[i] - 'a'];
    }
    sol[i] = '\0';
    sprintf(final, "Case #%d: ", T);
    strcat(final, sol);
    strcat(final, "\n");
    fputs(final, out);
    // cout << "Case #" << T << ": " << sol << "\n";
}

int main(int argc, char **argv)
{
    char **map;
    int T, i;
    char line[105];
    in = fopen("A-small-attempt0.in", "r");
    out = fopen("Result.in", "w+");
    map = (char **) malloc(2*sizeof(char *));
    map[0] = (char *) malloc(26*sizeof(char));
    map[1] = (char *) malloc(26*sizeof(char));
    initialize(map);
    learn(map);
    problem(map);
    fscanf(in, "%d", &T);
    fgets(line, 104, in);
    for (i = 1; i <= T; i++)
    {
        fgets(line, 104, in);
        getSoln(map, i, line);
    }

    free(map[0]);
    free(map[1]);
    free(map);
    return 0;
}
