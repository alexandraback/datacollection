#include<stdio.h>

int main()
{
    char p[5][5];
    int T,tc,c,d,xWin,oWin,completed,cek;
    scanf("%d",&T);
    for(tc=1;tc<=T;tc++)
    {
        xWin = 0;
        oWin = 0;
        for(c=0;c<4;c++) scanf("%s",p[c]);
        completed = 1;
        for(c=0;c<4;c++) for(d=0;d<4;d++) if(p[c][d]=='.') completed = 0;
        //diagonal
        cek = 1;
        for(c=0;c<4;c++) if(!(p[c][c]=='X'||p[c][c]=='T')) cek = 0;
        if(cek) xWin = 1;
        cek = 1;
        for(c=0;c<4;c++) if(!(p[c][c]=='O'||p[c][c]=='T')) cek = 0;
        if(cek) oWin = 1;
        cek = 1;
        for(c=0;c<4;c++) if(!(p[3-c][c]=='X'||p[3-c][c]=='T')) cek = 0;
        if(cek) xWin = 1;
        cek = 1;
        for(c=0;c<4;c++) if(!(p[3-c][c]=='O'||p[3-c][c]=='T')) cek = 0;
        if(cek) oWin = 1;
        //horizontal
        for(c=0;c<4;c++)
        {
            cek = 1;
            for(d=0;d<4;d++) if(!(p[c][d]=='X'||p[c][d]=='T')) cek = 0;
            if(cek) xWin = 1;
            cek = 1;
            for(d=0;d<4;d++) if(!(p[c][d]=='O'||p[c][d]=='T')) cek = 0;
            if(cek) oWin = 1;
        }
        //vertical
        for(d=0;d<4;d++)
        {
            cek = 1;
            for(c=0;c<4;c++) if(!(p[c][d]=='X'||p[c][d]=='T')) cek = 0;
            if(cek) xWin = 1;
            cek = 1;
            for(c=0;c<4;c++) if(!(p[c][d]=='O'||p[c][d]=='T')) cek = 0;
            if(cek) oWin = 1;
        }
        if(!xWin && !oWin && !completed) printf("Case #%d: Game has not completed\n",tc);
        else if(xWin && !oWin) printf("Case #%d: X won\n",tc);
        else if(!xWin && oWin) printf("Case #%d: O won\n",tc);
        else printf("Case #%d: Draw\n",tc);
    }
    return 0;
}
