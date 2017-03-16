#include <cstring>
#include <cstdio>

const char* table = "yhesocvxduiglbkrztnwjpfmaq";
int main()
{
    int T = 0;

    char T_buf[4096];
    gets(T_buf);
    sscanf(T_buf, "%d", &T);

    for (int i = 0; i < T; ++i)
    {
        char buf[256] = {0};
        char res[256] = {0};

        gets(buf);

        size_t len = strlen(buf);
        for (int k = 0; k < len; ++k)
        {
            if ( buf[k] >= 'a' && buf[k] <= 'z' )
                res[k] = table [ buf[k] - 'a' ];
            else
                res[k] = buf[k];
        }

        printf("Case #%d: %s\n", i+1, res);
    }

    return 0;
}
