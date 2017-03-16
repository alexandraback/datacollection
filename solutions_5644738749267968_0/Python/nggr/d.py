#!/usr/bin/env python
 
from __future__ import print_function
import sys
import random

def read_int():
    return int(input())

def read_float():
    return float(input()) 
 
def read_ls_float():
    s = sys.stdin.readline()
    return [float(x) for x in s.split()]
 

def naomi_choose_naive1(naomi,ken,set_forbid):
    return (naomi[-1], naomi[-1])
def naomi_choose_naive2(naomi,ken,set_forbid):
    return (naomi[0], naomi[0])
def naomi_choose_naive3(naomi,ken,set_forbid):
    k = random.randrange(len(naomi))
    return (naomi[k], naomi[k])

def naomi_choose_deceitful(naomi,ken, set_forbid):
    if naomi[0] < ken[0]:
        # deceitful war:
        # if naomi has a block that is less than ken's least (i.e., guaranteed to lose),
        # then force ken to use his largest block by giving a large but slightly smaller block size
        # and dump her own small block.
        # 
        ntold = ken[-1]
        while ntold in set_forbid:
            ntold -= 0.000001

        nchoice = naomi[0]
    elif ken[0] < naomi[0]:
        # if ken has a block less than naomi's least (i.e., one that ken is guaranteed to lose)
        # tell a block size greater than his greatest, but dump naomi's smallest.
        ntold = ken[-1]
        while ntold in set_forbid:
            ntold += 0.000001

        nchoice = naomi[0]

    return (ntold,nchoice)


# deceitful war
def run_war2(n,naomi,ken, naomifunc, bdebug=False):
    assert(len(naomi) == len(ken)) 
    assert(n == len(naomi))
    naomi.sort()
    ken.sort()
    pointsk = 0
    pointsn = 0
    set_forbid = set(ken)

    for i in range(n):
        (ntold,nchoice) = naomifunc(naomi, ken, set_forbid)
    
        if ntold < ken[-1]:
            # Ken chooses smallest block that will beat Naomi's
            for k in ken:
                if k > ntold:
                    if bdebug == True:
                        print("i={0:2d} [k] k={1:0.5f} n={2:0.5f}".format(i,k,nchoice))
                    ken.remove(k)
                    naomi.remove(nchoice)
                    pointsk += 1
                    break
        else:
            # Ken removes smallest element and naomi removes largest

            # update naomi's knowledge (she knows ken has nothing smaller than what he just played)
            kmin = ken[0]
            if bdebug == True:
                print("i={0:2d} [n] k={1:0.5f} n={2:0.5f}".format(i,ken[0],nchoice))

            del ken[0]
            naomi.remove(nchoice)
            pointsn += 1

    return pointsn

 
def main():

    #list_naomifuncs = (naomi_choose_deceitful,naomi_choose_naive1,naomi_choose_naive2,naomi_choose_naive3)
    list_naomifuncs = (naomi_choose_deceitful,naomi_choose_naive1)

    for i in range(read_int()):
        # input data
        n     = read_int()
        naomi = read_ls_float()
        ken   = read_ls_float()

        results = [run_war2(n, list(naomi), list(ken),naomifunc) for naomifunc in list_naomifuncs ]

        outstr = " ".join([str(x) for x in results])

        # output
        print("Case #%d: %s" % (i + 1, outstr))
 
if __name__ == "__main__":
    #profile.run('main()')
    sys.exit(main())
