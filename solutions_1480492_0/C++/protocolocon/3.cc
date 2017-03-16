//  -*- mode: c++; coding: utf-8; c-file-style: "stroustrup"; -*-

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits>
#include <set>

using namespace std;

const double eps=1e-12;

struct Car
{
    int speed, pos;
    bool left;
};

struct Collision
{
    int i, j;
    double x;
    Collision(int i, int j, double x): i(i), j(j), x(x) {}
};

double max_time;

bool recur(int n, Car *car, multimap<double, Collision> &collision, multimap<double, Collision>::iterator iter) // ret possible
{
    if(iter==collision.end()) return true;

    double t=iter->first;
    max_time=max(max_time, t);
    Collision &col=iter->second;

    //printf("COLL: %9.3f %d %d\n", t, col.i, col.j);

    double xi=double(car[col.i].pos)+double(car[col.i].speed)*t;
    double xj=double(car[col.j].pos)+double(car[col.j].speed)*t;

    for(int pos=0; pos<2; pos++)
    {
        car[col.i].left=(pos==0);
        car[col.j].left=(pos==1);

        bool not_pos=false;
        for(int j=0; j<n; j++)
        {
            if(j==col.i || j==col.j) continue;
            double x=double(car[j].pos)+double(car[j].speed)*t;
            if(fabs(x-xi)<=5+eps && car[j].left==car[col.i].left) { not_pos=true; break; }
            if(fabs(x-xj)<=5+eps && car[j].left==car[col.j].left) { not_pos=true; break; }
        }
        if(not_pos) continue;

        ++iter;
        if(recur(n, car, collision, iter)) return true;
        --iter;
    }
    return false;
}

int main(int narg, char **arg)
{
    int t;
    cin >> t;
    cout.precision(10);
    for(int it=0; it<t; it++)
    {
        cout << "Case #" << it+1 << ": ";

        int n;
        cin >> n;
        Car car[n];
        char tmp;
        for(int i=0; i<n; i++)
        {
            cin >> tmp >> car[i].speed >> car[i].pos;
            car[i].left=(tmp=='L');
        }

        //printf("\n");//!!!!!
        multimap<double, Collision > collision;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(car[i].speed==car[j].speed)
                {
                    continue;
                }

                double t0=double(car[j].pos+5-car[i].pos)/double(car[i].speed-car[j].speed);
                double t1=double(car[j].pos-5-car[i].pos)/double(car[i].speed-car[j].speed);

                //printf("%d %d %9.3f %9.3f\n", i, j, t0, t1);

                if(t0>=-eps || t1>=-eps)
                {
                    if(t0<t1)
                        collision.insert(make_pair(t0, Collision(j, i, double(car[i].pos)+double(car[i].speed)*t0)));
                    else
                        collision.insert(make_pair(t1, Collision(i, j, double(car[j].pos)+double(car[j].speed)*t1)));
                }
            }
        }

        max_time=0;
        multimap<double, Collision>::iterator iter=collision.begin();
        if(recur(n, car, collision, iter)) cout << "Possible" << endl;
        else cout << max_time << endl;
    }
    return 0;
}
