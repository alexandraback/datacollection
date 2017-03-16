#!/usr/bin/python
# -*- coding:utf-8 -*-
import os

vowels = ['a', 'e', 'i', 'o', 'u']
def is_consecutive(ss):
    for i in ss:
        if i in vowels:
            return False
    return True

def cal():
    try:
        fin = open("A-small-attempt0.in", "r")
        fout = open("consonants.out", "w")
        t = int(fin.readline())
        for i in range(t):
            string, n = fin.readline().split()
            #print string, n
            n = int(n)
            dic = {}
            length = len(string)
            for index in range(length-n +1):
                #print string[index:index+n]
                if is_consecutive(string[index:index+n]):
                    for jj in range(0, index+1):
                        #print "jj:",jj,
                        for kk in range(index+n-1, length):
                            #print "kk:",kk
                            dic.setdefault("%d:%d"%(jj,kk), 1)
            #print dic
            fout.write("Case #%d: %d\n"%(i+1, len(dic.values())))
        #print t
        fin.close()
        fout.close()
    except Exception,e:
        pass

if __name__ == "__main__":
    cal()