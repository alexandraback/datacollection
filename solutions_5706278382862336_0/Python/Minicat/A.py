f_in = open("A-small-attempt0 (2).in", 'r')
f_out = open("A-small.out", 'w')


def get_int():
    return int(f_in.readline().rstrip())

pows = [pow(2, i) for i in range(0, 39)]

def gens(P, Q):
    # Could a parent be 1/1?
    if 2 * P - Q >= 0:
        return 1
    # Otherwise, if P = 1, theres only one way
    if P == 1:
        return pows.index(Q)
    else:
        # Try to find smallest 1/2, 1/4 etc that makes it positive
        # Then return gens of that
        x = 2
        #print P * 2 - Q / x
        while P * 2 - Q / x < 0:
            x *= 2
        #print x
        return 1 + gens(1, x)
        

T = get_int()

for i in range(1, T + 1):

    P, Q = [int(x) for x in f_in.readline().rstrip().split('/')]

    gen = "Meow"
    if Q not in pows:
        gen = "impossible"
    else:
        gen = gens(P, Q)

    print "Case #{1}: {0}".format(gen, i)
    f_out.write("Case #{1}: {0}\n".format(gen, i))











f_in.close()
f_out.close()
