#! /usr/bin/python
import re

def qmul(c1, c2):
    sign = int(bool(re.search('-',c1))) + int(bool(re.search('-',c2)))
    c1 = c1.replace('-','')
    c2 = c2.replace('-','')
    if c1 == '1':
        res = c2
    elif c2 == '1':
        res = c1
    elif c1 == c2:
        res = '1'
        sign += 1
    elif c1 == 'i':
        if c2 == 'j':
            res = 'k'
        else:
            res = 'j'
            sign += 1
    elif c1 == 'j':
        if c2 == 'i':
            res = 'k'
            sign += 1
        else:
            res = 'i'
    else:
        if c2 == 'i':
            res = 'j'
        else:
            res = 'i'
            sign += 1
    sign = '-'*(sign%2)
    return '%s%s'%(sign,res)

def Transform(sent, rep):
    if rep%4 == 0:
        res = 'NO'
    else:
        ans_mul = reduce(lambda x,y:qmul(x,y),ans)
        if reduce(lambda x,y:qmul(x,y),[ans_mul]*(rep%4)) != '-1':
            res = 'NO'
        else:
            i, j, k, pos = False, False, False, 0
            target_sent = sent * min(4,rep)
            c = '1'
            while pos < len(target_sent):
                c = qmul(c, target_sent[pos])
                if c == 'i':
                    i = True
                    break
                else:
                    pos += 1
            if not i:
                res = 'NO'
            else:
                pos += 1
                target_sent = sent*min(int(pos/len(sent))+5,rep)
                c = '1'
                while pos < len(target_sent):
                    c = qmul(c, target_sent[pos])
                    if c == 'j':
                        j = True
                        break
                    else:
                        pos += 1
                if not j:
                    res = 'NO'
                else:
                    pos += 1
                    target_sent = sent*min(int(pos/len(sent))+5,rep)
                    c = '1'
                    while pos < len(target_sent):
                        c = qmul(c, target_sent[pos])
                        if c == 'k':
                            k = True
                            break
                        else:
                            pos += 1
                    if not k:
                        res = 'NO'
                    else:
                        res = 'YES'
    return res

inf = open('input.in')
inp = inf.read().split('\n')
inf.close()

T = int(inp.pop(0))
outf = open('output','w')
for i in range(T):
    L, X = [int(x) for x in inp.pop(0).split(' ')]
    ans = inp.pop(0)
    outf.write('Case #%d: %s\n'%(i+1,Transform(ans,X)))
outf.close()