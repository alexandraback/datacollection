#include <iostream>
#include <stdlib.h>
#include <vector>
#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QTextStream>
#include "../../ZKR4X/lib/zstring.h"

class GString : public QString
{
    public:
        GString(QString _str) : QString(_str)
        {
            _str.replace(" ", "\n");
            strList = _str.split("\n");

           /* strList.removeAll("\n");
            strList.removeAll("\r");
            strList.removeAll("\r\n");
            strList.removeAll(" ");
            strList.removeAll("");*/
        }


        GString& operator>>(QString& _str)
        {
            if(strList.size()) {
                _str = strList[0];
                strList.removeFirst();
            }

            return *this;
        }

        GString& operator>>(ZInt& _str)
        {
            if(strList.size()) {
                _str = strList[0];
                strList.removeFirst();
            }

            return *this;
        }

        GString& operator>>(int& _str)
        {
            if(strList.size()) {
                _str = strList[0].toInt();
                strList.removeFirst();
            }

            return *this;
        }

        QStringList strList;
};

void permute(QList<int> &_list, int a, int b)
{
    int c = _list[a];
    _list[a] = _list[b];
    _list[b] = c;
}

void sort(QList<int> &_list, bool _sens = true)
{
    bool bKeep = true;
    while(bKeep) {
        bKeep = false;
        for(int i = 1; i < _list.size(); i++)
        {
            if(_sens && _list[i-1] > _list[i] || ! _sens && _list[i-1] < _list[i])
            {
                permute(_list, i-1, i);
                bKeep = true;
            }
        }
    }
}

/**
 Functions
**/

QList<char> vowels;
int T;

QList<int> locateSubStr(QString _str, int _n)
{
    QList<int> subIds;
    int count = 0;
    for(int i = 0; i < _str.size(); i++) {
        if(vowels.contains(_str[i].toAscii()))
            count = 0;
        else count++;
        if(count >= _n) {
            subIds.append(i-_n+1);
        }
    }

    return subIds;
}

int nbTotal(QString _str, int _n)
{
    int nb = 0;
    QList<int> subIds = locateSubStr(_str, _n);

    if(!subIds.isEmpty()) {
        nb++;

    nb+=_str.size()-subIds.last()-_n;
    }

    for(int i = 0; i < subIds.size(); i++)
    {
        nb--;
        int next = (i < subIds.size()-1) ? i+1 : i;
        nb -= _str.size()-subIds[next]-_n;
       // if(next != _str.size()-_n) nb++;
        for(int k = 0; k <= _str.size()-subIds[i]-_n; k++) {
            std::cout << k << " ";
            QString substr = _str;
            substr.remove(_str.size()-k, k);
         //   std::cout << substr.size() << " " << subIds[i] << "\n";
           /* for(int j = 0; j < subIds[i]; j++) {
              //  if(j < subIds[i] || j > subIds[i] + _n-1) {
                    substr.remove(j);
                    nb++;
               // }
            }*/

            nb += subIds[i]+1;
            std::cout << nb << " ";
           // if(subIds[i]== 0) nb++;
        }
    }std::cout << "\n";

    return nb;
}

int k = 1, a = 0, b = 0;

void moveY(QString &_str, int _sens)
{
    if(_sens == 1)
        _str += "N";
    else if(_sens == -1)
            _str += "S";

    b+=k*_sens;
    k++;
}

void moveX(QString &_str, int _sens)
{
    if(_sens == 1)
            _str += "E";
    else if(_sens == -1)
            _str += "W";

    a+=k*_sens;
    k++;
}

QString path(const int x, const int y)
{
    QString str;

    k = 1, a = 0, b = 0;

    int goX = (x == 0) ? 0 : abs(x)/x;
    int goY = (y == 0) ? 0 : abs(y)/y;

    while(goX != 0 && abs(a + k*goX) <= abs(x))
        moveX(str, goX);

    while(goY != 0 && abs(b + k*goY) <= abs(y))
        moveY(str, goY);
std::cout << x << " " << y << " " << a << " " << b << "\n";
    while(a != x) {
        moveX(str, -goX);
        moveX(str, goX);
    }

    while(b != y) {
        moveY(str, -goY);
        moveY(str, goY);
        std::cout << a << " " << b << "\n";

    }

    return str;
}


int main(int argc, char** argv)
{

    vowels.append('a');
    vowels.append('e');
    vowels.append('o');
    vowels.append('i');
    vowels.append('u');

    QFile *file = new QFile("in.txt");
    if(!file->open(QIODevice::ReadOnly)) return 1;

    GString in = QString(file->readAll());
    file->close();

    file = new QFile("out.txt");
    if(!file->open(QIODevice::WriteOnly | QIODevice::Truncate)) return 2;
    QTextStream out(file);

    in >> T;
    for(int i = 1; i <= T; i++) {
        int x, y;
        //in >> str >> nb;
        in >> x >> y;

        /**
            Code
        **/
std::cout << "a" << x << " " << y << " " << i << "\n";
       // out << "Case #" << i << ": " << nbTotal(str, nb) << "\r\n";
        out << "Case #" << i << ": " << path(x, y) << "\r\n";
      //  out << "Case #" << i << ": " << nbTotal().getStr() << "\r\n";

    }

    file->close();

    system("out.txt");
}
