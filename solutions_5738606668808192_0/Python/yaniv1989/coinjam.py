import random

def find_factor(n):
    for i in xrange(2, min(1001, n)):
        if n%i == 0:
            return i

def get_in_base(v, b):
    return sum([v[i]*(b**i) for i in xrange(len(v)-1, -1, -1)])

def get_random_bin_vec(N):
    return [1] + [random.randint(0, 1) for i in xrange(N-2)] + [1]

def get_random_bin_vec_div(N):
    while True:
        v = get_random_bin_vec(N)
        if sum(v)%6 == 0:
            if (sum(v[::2])%3) == (sum(v[1::2])%3):                
                return v

N = 16
J = 50

print "Case #1:"

s = []
while len(s) < J:
    while True:
        v = get_random_bin_vec_div(N)

        if v in s:
            continue
        
        x = get_in_base(v, 6)
        f = find_factor(x)

        if f is None:
            continue

        print "".join(map(str, v)),
        for i in xrange(2, 11):
            if i in [3, 5, 7, 9]:
                assert(get_in_base(v, i) % 2 == 0)
                print 2,
            elif i in [2, 4, 8, 10]:
                assert(get_in_base(v, i) % 3 == 0)
                print 3,
            else:
                print f,
        print ""
        s.append(x)
        break
        
