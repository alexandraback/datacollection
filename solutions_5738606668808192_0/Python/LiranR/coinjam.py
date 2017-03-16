import random

def rand_str(N):
    mid = "".join(random.choice(["0","1"]) for i in xrange(N-2))
    return "1" + mid + "1"
    
def is_coinjam(s, threshold = 1000):
    '''
    checks if there exists "easy" witnesses (less then the threshold)
    to the fact that s is a coinjam
    '''
    witnesses = []
    for base in xrange(2,11):
        num = int(s, base)
        for i in xrange(2,min(threshold, num)):
            if num % i == 0:
                witnesses.append(i)
                break
        else:
            return None
    return witnesses

T = int(raw_input()) #always 1. Ignore
N, J = map(int, raw_input().split())

found = set()

print "Case #1:"
while len(found) < J:
    s = rand_str(N)
    if s in found:
        continue
    wit = is_coinjam(s)
    if not wit:
        continue
    
    found.add(s)
    print s + " " + " ".join(map(str,wit))

