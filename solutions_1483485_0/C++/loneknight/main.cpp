#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const char *input[] = 
{
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv",
};

const char *output[] = 
{
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up",
};

const int BufferSize = 1000;

int table[256] = {0};
char line[BufferSize];

int main(int argc, char *argv[])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; input[i][j]; ++j)
            table[input[i][j]] = output[i][j];
    }

    table['q'] = 'z';
    table['z'] = 'q';

    fgets(line, BufferSize, stdin);
    int t = atoi(line);

    for (int index = 1; index <= t; ++index)
    {
        fgets(line, BufferSize, stdin);
        line[strlen(line)-1] = '\0';

        for (int i = 0; line[i]; ++i)
            line[i] = table[line[i]];

        printf("Case #%d: %s\n", index, line);
    }

//    int flags[26];
//    fill_n(flags, 26, false);
//    for (int i = 'a'; i <= 'z'; ++i)
//    {
//        cout << (char)i << " " << char(table[i]) << " " << table[i] << endl;
//        flags[table[i]-'a'] = true;
//    }
//    for (int i = 0; i < 26; ++i)
//    {
//        if (flags[i] == false)
//            cout << i << " " << char(i + 'a') << endl;
//    }

    return 0;
}

