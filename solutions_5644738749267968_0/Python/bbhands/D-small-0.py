#!/usr/bin/python
# -*- coding: utf-8 -*-

if __name__ == "__main__":

    fin = open("D-small-0.in", "r")
    fout = open("D-small-0.out", "w")
    T = int(fin.readline())

    for t in xrange(0, T):
        N = int(fin.readline().strip())
        blocks_naomi = map(float, fin.readline().strip().split(' '))
        blocks_ken = map(float, fin.readline().strip().split(' '))

        answer_2 = 0
        answer_1 = 0

        blocks_naomi.sort()
        blocks_ken.sort()
        i = 0
        j = 0
        while i<=N-1 and j<=N-1:
            while j<=N-1 and blocks_ken[j]<=blocks_naomi[i]:
                j += 1
            if j==N:
                break
            i+=1
            j+=1

        answer_1 = N-i

        i = 0
        j = 0
        while i<=N-1 and j<=N-1:
            while i<=N-1 and blocks_ken[j]>=blocks_naomi[i]:
                i += 1
            if i==N:
                break
            i+=1
            j+=1
        answer_2 = j

        fout.write("Case #%i: %i %i\n" % (t+1, answer_2, answer_1))
    
    fin.close()
    fout.close()

