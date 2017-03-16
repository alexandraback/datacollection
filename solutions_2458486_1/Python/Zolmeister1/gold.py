import sys
sys.setrecursionlimit(10000)
from copy import copy
import time
fin = open('gold.in')
fout = open('gold.out','w')
cases = int(fin.readline())
startTime = 0
endTime = 0
def keysReq(chests, keys):
    req = {}
    chestKeys = []
    for chest in chests:
        if not chest:
            continue
        ch = chest
        if ch['open'] in req:
            req[ch['open']] +=1
        else:
            req[ch['open']] =1
        chestKeys+=ch['keys']
        
    tar = chestKeys+keys
    for key in req:
        if tar.count(key) < req[key]:
            return False
    for chest in chests:
        if not chest:
            continue
        ch = chest
        if ch['open'] not in keys:
            chestEx = copy(chestKeys)
            for key in ch['keys']:
                chestEx.remove(key)
            if ch['open'] not in chestEx:
                return False
    return True
    
def openChest(chest, keys, chests, log):
    if time.time() > endTime:
        return None
    keys.remove(chest['open'])
    keys += chest['keys']
    log.append(chests.index(chest))
    chests[chests.index(chest)] = None
    
    for i in chests:
        if i:
            break
    else:
        return log
    
    if not keysReq(chests, keys):
        return None
    
    for chest in chests:#chest is chest index in chests
        if not chest:
            continue
        if chest['open'] in keys:
            #if cnt==3:
            #    print chest
            cc = openChest(chest, copy(keys), copy(chests), copy(log))
            if cc:
                return cc
            #if cnt==3:
                #print log
                #print keys
                #print chests
            #print log
            #print keys
            #print chests
    return None
           
def pp(s):#print end case
    print 'Case #%d: ' % (cnt) +s
    fout.write('Case #%d: ' % (cnt) +s+'\n')
    
cnt=0
nan = 30
for case in xrange(cases):
    #print cnt
    cnt+=1
    startTime = time.time()
    endTime = startTime + nan
    K, N = map(int, fin.readline().split(' '))
    keys = map(int, fin.readline().split(' '))
    chests = []
    chestKeys = []
    for chest in xrange(N):
        c = map(int, fin.readline().split(' '))
        chests.append({
            'keys':c[2:],
            'open': c[0]
        })
        chestKeys+=c[2:]
    """
    if cnt==3:
        print keys
        vv=0
        for chest in chests:
            vv+=1
            print chest['open'], chest['keys']
    """
    if not keysReq(chests, keys):
        pp("IMPOSSIBLE")
        continue
    
    for chest in chests:#chest is chest index in chests
        if chest['open'] in keys:
            cc = openChest(chest, copy(keys), copy(chests), [])
            if cc:
                pp(' '.join([str(x+1) for x in cc]))
                break
        startTime = time.time()
        endTime = startTime + nan
    else:
        pp("IMPOSSIBLE")
        
fout.close()