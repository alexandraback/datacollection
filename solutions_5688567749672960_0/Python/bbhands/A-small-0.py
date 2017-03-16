#!/usr/bin/python
# -*- coding: utf-8 -*-

def rev(n):
    return int("".join(list(str(n))[::-1]))

if __name__ == "__main__":

    fin = open("A-small-0.in", "r")
    fout = open("A-small-0.out", "w")
    T = int(fin.readline())

    f = {}
    f[1] = 1
    for i in xrange(2, 10**6+1):
        r_i = rev(i)
        if r_i < i and len(str(i)) == len(str(r_i)):
            f[i] = min(f[i-1], f[r_i]) + 1
        else:
            f[i] = f[i-1] + 1

    #print f

    for t in xrange(0, T):
        N = int(fin.readline().strip())

        answer = f[N]

        fout.write("Case #%i: %s\n" % (t+1, answer))

    fin.close()
    fout.close()

