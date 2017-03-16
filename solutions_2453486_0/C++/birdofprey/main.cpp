#include <iostream>
#include <QtGlobal>
using namespace std;

#include <QFile>
#include <QTextStream>

QTextStream input, output;

enum Result {undefined, win_x, win_o, draw, unfinished};

void UpdateResult(Result &res, char c)
{
    if      (res == undefined)
    {
        if      (c == 'X') res = win_x;
        else if (c == 'O') res = win_o;
        else if (c == '.') res = unfinished;
    }
    else if (res == win_x)
    {
        if      (c == 'O') res = draw;
        else if (c == '.') res = unfinished;
    }
    else if (res == win_o)
    {
        if      (c == 'X') res = draw;
        else if (c == '.') res = unfinished;
    }
    else if ((res == draw) && (c == '.')) res = unfinished;
}

Result TestHLine(const char line[])
{
    Result res = undefined;
    for(uint i = 0; i < 4; ++i)
    {
        UpdateResult(res, line[i]);
        if(res == unfinished) return res;
    }
    return res;
}

Result TestVLine(char **square, uint line)
{
    Result res = undefined;
    for(uint i = 0; i < 4; ++i)
    {
        UpdateResult(res, square[i][line]);
        if(res == unfinished) return res;
    }
    return res;
}

Result TestMainDiag(char **square)
{
    Result res = undefined;
    for(uint i = 0; i < 4; ++i)
    {
        UpdateResult(res, square[i][i]);
        if(res == unfinished) return res;
    }
    return res;
}

Result TestSecondDiag(char **square)
{
    Result res = undefined;
    for(uint i = 0; i < 4; ++i)
    {
        UpdateResult(res, square[3 - i][i]);
        if(res == unfinished) return res;
    }
    return res;
}

void OutputResult(Result res)
{
    if      (res == win_x) output << "X won" << endl;
    else if (res == win_o) output << "O won" << endl;
    else if (res == draw ) output << "Draw"  << endl;
    else if (res == unfinished) output << "Game has not completed" << endl;
    else Q_ASSERT(false);
}

void SolveCase()
{
    char **task = new char* [4];
    for(uint line = 0; line < 4; ++line)
    {
        task[line] = new char [5];
        input >> task[line];
    }
    bool probably_unfinished = false, ready = false;
    Result res;
    for(uint i = 0; i < 4; ++i)
    {
        res = TestHLine(task[i]);
        if((res == win_x) || (res == win_o)){ OutputResult(res); ready = true; break; }
        if(res == unfinished) probably_unfinished = true;
        res = TestVLine(task, i);
        if((res == win_x) || (res == win_o)){ OutputResult(res); ready = true; break; }
        if(res == unfinished) probably_unfinished = true;
    }
    if(!ready)
    {
        res = TestMainDiag(task);
        if((res == win_x) || (res == win_o)){ OutputResult(res); ready = true; }
    }
    if(!ready)
    {
        res = TestSecondDiag(task);
        if((res == win_x) || (res == win_o)){ OutputResult(res); ready = true; }
    }
    if(!ready)
    {
        if(probably_unfinished)
            OutputResult(unfinished);
        else OutputResult(draw);
    }
    for(uint line = 0; line < 4; ++line) delete[] task[line];
    delete[] task;
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    QFile infile("input.txt"), outfile("output.txt");
    infile.open(QIODevice::ReadOnly);
    outfile.open(QIODevice::WriteOnly);
    input.setDevice(&infile);
    output.setDevice(&outfile);

    uint T; input >> T;
    for(uint t = 1; t <= T; ++t)
    {
        output << "Case #" << t << ": ";
        SolveCase();
    }

    return 0;
}
