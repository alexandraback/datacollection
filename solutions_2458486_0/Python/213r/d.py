import sys
import copy
import numpy as np

def read():
    return sys.stdin.readline()

def format(tup):
    return 'Case #%d: %s'%tup

def do(have_key,chest,opened):
    if len(opened) == len(chest):
        return opened
    else:
        if have_key == []:
            return ""
    c = [] 
    for j in xrange(len(chest)):
        for i in xrange(len(have_key)):
            now_key = copy.copy(have_key)
            if j in opened: continue
            if now_key[i] == chest[j][0]:
                now_key.pop(i)
                now_key += chest[j][1]
                #c.append(do(now_key, chest, opened + [j]))
                a = do(now_key, chest, opened + [j])
                if a != '':
                    return a

for i in xrange(int(read())):
    n_key_stat, n_chest = map(int,read().split()) 
    list_key_stat = map(int,read().split()) 
    list_chest = []
    for j in xrange(n_chest):
        l = map(int,read().split()) 
        list_chest.append([l[0],l[2:]])
    x = do(list_key_stat,list_chest,[])
    #print list_key_stat
    #print list_chest
    #print x 
    if x != None:
        print format((i+1,' '.join(map(str,[i + 1 for i in x]))))
    else:
        print format((i+1,"IMPOSSIBLE")) 

