from sys import stdin

f = open("primes","r");

primes = [int(x) for x in f.readlines()]



def test(q):
    jc = (q, [])
    bits = []
    while(q):
        bits.append(q%2)
        q/=2
    bits = [x for x in reversed(bits)]
    for b in xrange(2,11):
        nb = 0
        #print(bits)
        for bit in bits:
            nb *= b
            nb += bit
            #print(nb)
        found = False
        for p in primes:
            #print(nb, p)
            #h=input()
            if((nb != p) and (nb%p==0)):
                jc[1].append(p)
                found = True
                break
        if(not found):
            return None
    return jc

t=int(input())
n=int(input())
j=int(input())

jamcoins = [];

k = 2**(n-1)

i=0
print "Case #1:"
while(len(jamcoins) < j):
    q = k+(2*i)+1;
    jc = test(q);
    if(not (jc is None)):
        jamcoins.append(jc)
    i+=1

for jc in jamcoins:
    q = jc[0]
    bits = []
    while (q):
        bits.append(q%2)
        q/=2
    bits = reversed(bits)
    bits = "".join([str(x) for x in bits])
    print "%s %s" % (bits, " ".join([str(x) for x in jc[1]]))
