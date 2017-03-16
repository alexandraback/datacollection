import sys

T = int(sys.stdin.readline())

def conv(K, stud):
    exp = 1
    ans = 0
    for dig in stud:
        ans += exp*dig
        exp*=K
    ans+=1
    return ans

for t in xrange(1, T+1):
    K,C,S = map(int,sys.stdin.readline().split())
    
    if S*C<K:
        print 'Case #'+str(t)+': IMPOSSIBLE'
    else:
        pos = range(K) + [0]*(S*C-K)
        studs = [pos[i*C:(i+1)*C] for i in xrange(S)]
        tiles = list(set([str(conv(K, stud)) for stud in studs]))
        print 'Case #'+str(t)+': '+' '.join(tiles)

        

        