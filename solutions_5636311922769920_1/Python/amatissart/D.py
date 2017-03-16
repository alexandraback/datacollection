# -*- coding: utf-8 -*-

import sys

def oneG(K, pos):
    return [False]*(pos-1)+[True]+[False]*(K-pos)

def get(seq, C, K, pos):
    if C==1:
        return seq[pos-1]
    return get(seq, C-1, K, ((pos-1)//K)+1) or seq[(pos-1) % K]


def solve(K,C,S):
    if S == K:
        return range(1,K+1)
    seqs=dict()
    for i in xrange(1,K+1):
        seqs[i] = oneG(K, i)
    
    length = K**C
    middle = (length+1)//2


    def find_tiles(first):
        res=[]
        next_pos = first
        pos_set = set()
        while len(res) <= S and next_pos[0]>0:
            for i in next_pos:
                res.append(i)
                if(len(res)>S):
                    break
                for j in xrange(1, K+1):
                    if j in pos_set:
                        continue
                    if get(seqs[j], C, K, i):
                        pos_set.add(j)
                if len(pos_set)==K:
                    return res
            if len(next_pos)>1:        
                next_pos = [next_pos[0]-K,next_pos[-1]+K]
            else:
                next_pos = [middle-(K-1)//2-K,middle+(K-1)//2+K]

        return None

    if K%2 == 0:
        next_pos = [length//2-(K-1), (length//2)+K]
        return find_tiles(next_pos)
    else:
        next_pos = [middle]
        temp = find_tiles(next_pos)
        if temp is not None:
            return temp
        return find_tiles([middle-(K-1)//2,middle+(K-1)//2])



filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        K,C,S = map(int,f.readline().split())
        l = solve(K,C,S)
        if l is None:
            res = 'IMPOSSIBLE'
        else:
            res = " ".join(map(str,l))
        print 'Case #{}: {}'.format(i+1,res)
        
