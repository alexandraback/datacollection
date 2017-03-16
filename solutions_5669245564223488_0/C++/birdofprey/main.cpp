#include <QFile>
#include <QtGlobal>
#include <QTextStream>

#include <iostream>

/* Switch between console and file output modes. */
//#define STDOUT

QTextStream input;

#ifndef STDOUT
    QTextStream output;
#else
    std::ostream &output = std::cout;
#endif

bool isValid(const QString &train) {
    int count = 0; char c;
    for(int i = 0; i < train.size(); ++i) {
        if((i == 0) || (train[i] != train[i - 1])) {
            if(i > 0) {
                if(train.count(c) > count) return false;
            }
            count = 1;
            c = train[i].toLatin1();
        }
        else ++count;
    }
    if(train.count(c) > count) return false;
    return true;
}

void ConnectNext(QString &train, const std::vector<QString> &carts, int joinN, bool *joined, int &res)
{
    train.append(carts[joinN]);
    joined[joinN] = true;

    if(isValid(train)) {

        bool assembled = true;
        for(int i = 0; i < carts.size(); ++i) {
            if(!joined[i]) {
                assembled = false;
                ConnectNext(train, carts, i, joined, res);
            }
        }

        if(assembled && isValid(train)) ++res;
    }

    train.chop(carts[joinN].size());
    joined[joinN] = false;
}

void Optimize(QString &str)
{
    int i = 0;
    while(i < str.size()) {
        if(str[i] == str[i - 1]) str.remove(i, 1);
        else ++i;
    }
}

void SolveCase()
{
    int N; input >> N;
    std::vector<QString> substr;
    for(int n = 0; n < N; ++n) {
        QString buffer; input >> buffer;
        Optimize(buffer);
        substr.push_back(buffer);
    }

    bool *used = new bool [N];
    memset(used, 0, N * sizeof(bool));

    int res = 0; QString train;
    for(int i = 0; i < N; ++i)
        ConnectNext(train, substr, i, used, res);
    output << res << '\n';

    delete[] used;

}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    QFile infile("input.txt");
    infile.open(QIODevice::ReadOnly);
    input.setDevice(&infile);

#   ifndef STDOUT
        QFile outfile("output.txt");
        outfile.open(QIODevice::WriteOnly);
        output.setDevice(&outfile);
#   endif

    uint T; input >> T;
    for(uint t = 1; t <= T; ++t)
    {
        output << "Case #" << t << ": ";
        SolveCase();
        std::cout << "Case # " << t << " solved\n";
    }

    return 0;
}
