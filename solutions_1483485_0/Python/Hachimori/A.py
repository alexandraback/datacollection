#!/usr/local/bin/python


def gen():
    pre = []
    pre.append("ejp mysljylc kd kxveddknmc re jsicpdrysi")
    pre.append("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd")
    pre.append("de kr kd eoya kw aej tysr re ujdr lkgc jv")
    pre.append("zq")
               
    nex = []
    nex.append("our language is impossible to understand")
    nex.append("there are twenty six factorial possibilities")
    nex.append("so it is okay if you want to just give up")
    nex.append("qz")

    ret = {}
    for i in range(len(pre)):
        for j in range(len(pre[i])):
            ret[pre[i][j]] = nex[i][j]
    return ret
    

def read():
    return raw_input()


def work(cases,txt,table):
    toPrint = ""
    for i in range(len(txt)):
        toPrint += table[txt[i]]
    print "Case #%d: %s"%(cases,toPrint)


if __name__=="__main__":
    table = gen()
    
    for i in range(int(raw_input())):
        work(i+1,read(),table)
