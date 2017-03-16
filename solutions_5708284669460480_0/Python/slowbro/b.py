from __future__ import division
from collections import defaultdict
import math
import sys

#myin = sys.stdin
myin = open(sys.argv[1], 'rb')

def rstr(): return myin.readline().strip()
def rstrs(): return myin.readline().strip().split()
def rnum():  return int(rstr())
def rnums():  return list(int(x) for x in rstrs())
def window(vec, window_size=2):
    for i in xrange(len(vec)-window_size+1):
        yield vec[i:(i+window_size)]

def solve():
    K,L,S = rnums()
    wordK = rstr()
    wordL = rstr()

    #check if its even possible and if there is common prefix at tail
    prefix_ind = 0
    for (i,c) in enumerate(wordL):
        if c not in wordK:
            return 0.0
        if (i > 0) and c == wordL[prefix_ind]:
            prefix_ind += 1
        else:
            prefix_ind = 0
    tail_prefix_len = prefix_ind

    #create K tables
    K_count_table = defaultdict(lambda:0)
    K_prob_table = {}
    for c in wordK:
        K_count_table[c] += 1
    for (k,v) in K_count_table.items():
        K_prob_table[k] = v/K

    #build graph
    state_graph = [] 
    for i in xrange(L+1):
        transitions = {}
        transitions[L] = 1 - K_prob_table[wordL[0]]
        transitions[0] = K_prob_table[wordL[0]]
        if (i == L-1) and (tail_prefix_len > 0):
            transitions[L] -= K_prob_table[wordL[i-2]]
            transitions[i-2] = K_prob_table[wordL[i-2]]
        elif (i < (L-1)):
            transitions[L] -= K_prob_table[wordL[i+1]]
            transitions[i+1] = K_prob_table[wordL[i+1]]
        state_graph.append(transitions)


    memo = [[-1]*(S+1) for i in xrange(L+1)]
    #import pdb 
    #pdb.set_trace()
    def recur(state, keys_rem):
        if memo[state][keys_rem] != -1:
            return memo[state][keys_rem]
        ans = 0
        if state == (L-1):
            ans += 1
        if state == L:
            suff_len = L
        else:
            suff_len = L  - ((state+1) % L) 
        if keys_rem < suff_len or keys_rem == 0:
            memo[state][keys_rem] = ans
            return ans 
         
        for (next_state, prob) in state_graph[state].items():
            ans += prob*recur(next_state, keys_rem-1)
        memo[state][keys_rem] = ans 
        return ans


#    memo2 = [[-1]*(S+1) for i in xrange(L+1)]
#    def recur2(state, keys_rem):
#        if memo2[state][keys_rem] != -1:
#            return memo2[state][keys_rem]
#        suff_len = L - 1 - (state % L) 
#        if keys_rem < suff_len:
#            memo2[state][keys_rem] = 0
#            return 0 
#       
#        ans = 0
#        if state == (L-1):
#            ans += 1
#        for (next_state, prob) in state_graph[state].items():
#            ans += recur2(next_state, keys_rem-1)
#        memo2[state][keys_rem] = ans 
#        return ans

    for i in xrange(S+1):
        recur(L, i)
        #recur2(L, i)

    num_bananas = S // (L - tail_prefix_len) - tail_prefix_len

    return num_bananas - memo[L][S] 

def main():
    T = rnum()
    for ti in xrange(1,T+1):
        ret = solve()
        print "Case #%i: %.7f"%(ti, ret%1000000007)
    return

if __name__ == '__main__':
    main()
