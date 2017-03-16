#!/usr/bin/python
# -*- coding:utf-8 -*-
import os


# north (increasing y), south (decreasing y), east (increasing x) or west (decreasing x).

def go():
    try:
        fin = open("B-small-attempt0.in", "r")
        fout = open("B-small-attempt0.out", "w")
        t = int(fin.readline())
        for i in range(t):
            x, y = fin.readline().split()
            x = int(x)
            y = int(y)
            fout.write("Case #%d: "%(i+1))
            ss = ""
            if x > 0:
                ss = "WE"
            else:
                ss = "EW"
                x = x *(-1)
            for j in range(x):
                fout.write("%s"%ss)
            if y > 0:
                ss = "SN"
            else:
                ss = "NS"
                y = y *(-1)
            for j in range(y):
                fout.write("%s"%ss)
            fout.write("\n")

        fin.close()
        fout.close()
    except Exception,e:
        pass

if __name__ == "__main__":
    go()