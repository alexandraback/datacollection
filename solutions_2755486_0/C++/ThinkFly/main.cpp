#include <stdio.h>

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include "assert.h"
#include <set>
#include <vector>
#include <xutility>
using namespace std;

class wall
{
public:
    wall()
    {
        memset(arr, 0, sizeof(arr));
        shift = 200;
    }
    int lookup_min(int left, int right)
    {
        left += shift;
        right += shift;
        left *= 10;
        right *= 10;
        int val = arr[left];
        for (int i=left; i<= right; i++)
            val = min(arr[i], val);
        return val;
    }
    void add_height(int left,int right, int val)
    {
        left += shift;
        right += shift;
        left *= 10;
        right *= 10;
        for (int i=left; i<= right; i++)
            arr[i] = max(arr[i], val);
    }
private:
    int shift;
    int arr[30000];
};
class nomadic
{
public:
    friend class war;
    nomadic(){}
    nomadic(int x)
    {
        scanf(" %d %d %d %d %d %d %d %d", &d,&n_attack,&w,&e,&s,&det_d,&det_pos,&det_s);
    }
    void attack()
    {
        d += det_d;
        n_attack --;
        w += det_pos;
        e += det_pos;
        s += det_s;
    }
    friend bool operator< (const nomadic& a, const nomadic& b);
private:
    int d,n_attack,w,e,s,det_d,det_pos,det_s;
};
class war
{
public:
    war(int N) : count(0)
    {
        for (int i=0; i<N; i++)
        {
            nomadic tmp(1);
            attack.insert(tmp);
        }
    }
    int fire()
    {
        while (attack.size() > 0)
        {
            int day;
            do 
            {
                nomadic one_fire = *(attack.begin());
                resolve.insert(one_fire);
                day = one_fire.d;
                {
                    // ÅÐ¶Ï¹¥»÷ÊÇ·ñ³É¹¦
                    if (w.lookup_min(one_fire.w, one_fire.e) < one_fire.s)
                        count ++;
                }
                attack.erase(attack.begin());
                one_fire.attack();
                if (one_fire.n_attack >= 1)
                    attack.insert(one_fire);
            } while (attack.size() > 0 && day == attack.begin()->d);
            while (resolve.size() > 0)
            {
                nomadic one_res = *(resolve.begin());
                resolve.erase(resolve.begin());
                w.add_height(one_res.w, one_res.e, one_res.s);
            }
        }
        return count;
    }
public:
    set<nomadic> attack;
    set<nomadic> resolve;
    wall w;
    int count;
};


int solve_one()
{
    int N;
    scanf("%d", &N);
    war w(N);
    return w.fire();
}
int main(int argc, char**argv)
{
    freopen("D:\\3.in", "r+", stdin);
    freopen("D:\\out.txt", "w+", stdout);
    int T;
    scanf("%d", &T);
    for (int i=1; i<=T; i++)
    {
        printf("Case #%d: %d\n", i, solve_one());
    }
    return 0;
}

bool operator< (const nomadic& a, const nomadic& b)
{
    if (a.d != b.d)
        return a.d < b.d ;
    if (a.s != b.s)
        return a.s < b.s;
    if (a.n_attack != b.n_attack)
        return a.n_attack < b.n_attack;
    if (a.det_d != b.det_d)
        return a.det_d < b.det_d;
    if (a.det_pos != b.det_pos)
        return a.det_pos < b.det_pos;
    if (a.det_s != b.det_s)
        return a.det_s < b.det_s;
    return a.e < b.e;
}