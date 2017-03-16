from Queue import deque
# 0.1         0.5     -0.9
#     -0.3 0.4     0.6

def play_fairly(nl, kl):
    nl.sort()
    kl.sort()
    nl = deque(nl)
    kl = deque(kl)
    score = 0
    while nl:
        if nl[-1] > kl[-1]:
           nl.pop()
           kl.popleft()
           score += 1
        else:
           nl.pop()
           kl.pop()
    return score

#  0.186,          0.3,       0.389,               0.557,            0.832, 0.899,  0.907,     0.959,  0.992
#     0.215,  0.271,  0.341,       0.458, 0.52, 0.521,    0.7, 0.728,                      0.916

def play_cheat(nl, kl):
    nl.sort()
    kl.sort()
    nl = deque(nl)
    kl = deque(kl)
    score = 0
    while nl:
        if nl[0] < kl[0]:
            a = nl.popleft()
            b = kl.pop()
            #print '>>', a, b, 'c'
        else:
            a = nl.popleft()
            b = kl.popleft()
            #print '>>', a, b, a>b
            if a > b:
                score += 1
    return score

cases = int(raw_input())
for cas in xrange(1, cases+1):
    n = raw_input()
    nl = map(float, raw_input().split())
    kl = map(float, raw_input().split())
    print 'Case #{}: {} {}'.format(cas, play_cheat(nl, kl), play_fairly(nl, kl))
