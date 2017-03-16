import itertools

def find(S):
    sums = {}
    for m in xrange(1, len(S)): 
        for i in itertools.combinations(S, m):
            #print i
            s = sum(i)
            if s not in sums:
                sums[s] = [list(i)]
            else:
                s1 = set(i)
                for j in sums[s]:
                    s2 = set(j)
                    if s2.isdisjoint(s1):
                        return (list(j), list(i))
                sums[s].append(list(i))
    

t = int(raw_input())
i = 1
while i <= t:
    s = [int(x) for x in raw_input().split(' ')]
    
    s = s[1:]
    
    res = find(s)
    
    print 'Case #%s:'%i
    if res:
        print ' '.join([str(x) for x in res[0]])
        print ' '.join([str(x) for x in res[1]])
    else:
        print 'Impossible'
    
    
    i += 1

