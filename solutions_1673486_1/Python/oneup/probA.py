import sys

def calc_keep_typing(cum_prob, A, B):
    wrong_prob = cum_prob[A]
    return (B-A+1)*(1-wrong_prob) + (B-A+1+B+1)*(wrong_prob)

def calc_x_bs(cum_prob, A, B, x):
    return x+calc_keep_typing(cum_prob,A-x,B)

def calc_enter_now(A,B):
    return 1+B+1

def test(A,B,P):
    cum_prob = [0 for p in P]
    cum_prob.append(0)
    cum_prob[0] = 0
    for i,p in enumerate(P):
        cum_prob[i+1] = cum_prob[i]+p*(1-cum_prob[i])
#    print cum_prob
    poss = [calc_x_bs(cum_prob,A,B,x) for x in xrange(1,A)]
    poss.append(calc_keep_typing(cum_prob,A,B))
    poss.append(calc_enter_now(A,B))
    #print >>sys.stderr, poss
    return '%0.6f' % min(poss)
    
        
    
    

T = int(raw_input())
for t in xrange(T):
    A,B = map(int,raw_input().split())
    P = map(float, raw_input().split())
    P = [1-p for p in P]
    print >>sys.stderr, t
    print "Case #%d:" % (t+1), test(A,B,P)
