def check_jam_coin(l,s,proof):
    assert len(s) == l
    assert all(d in '01' for d in s)
    assert s[0] == s[-1] == '1'
    assert len(proof) == 9
    for b, d in zip(xrange(2,11), proof):
        v = int(s,b)
        assert 1 < d < v
        assert v % d == 0


from sys import stderr

check_jam_coin(4,'1001',[3,7,5,6,31,8,27,5,77])
check_jam_coin(6,'100011',[5,13,147,31,43,1121,73,77,629])
check_jam_coin(6,'111111',[21,26,105,1302,217,1032,513,13286,10101])
check_jam_coin(6,'111001',[3,88,5,1938,7,208,3,20,11])

from itertools import count

for cas in xrange(1,1+input()):
    print "Case #%s:" % cas
    n, j = map(int, raw_input().strip().split())
    assert n >= 2

    goods = []
    proofs = {}

    from math import sqrt

    start = int('1' + '0'*(n-2) + '1', 2)
    for value in count(start,2):
        s = bin(value)[2:]
        print >>stderr, 'trying', s
        proof = []
        for b in xrange(2,11):
            v = int(s,b)
            for d in xrange(2,min(1000, int(sqrt(v))+1)):
                if v % d == 0:
                    proof.append(d)
                    break
            else:
                break
        else:
            print >>stderr, 'found!', len(goods), proof
            goods.append(s)
            proofs[s] = proof
            if len(goods) > j:
                break

    for i in xrange(j):
        s = goods[i]
        p = proofs[s]
        check_jam_coin(n,s,p)
        print "%s %s" % (s, ' '.join(map(str, p)))
