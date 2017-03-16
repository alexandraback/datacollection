import itertools
def is_prime(n):
    i = 2
    while i<=int(n**0.5):
        if n%i==0:
            return i
        i+=1
    return 0

def rem_base(s, n):
    ret = 0
    j = 0
    for i in s[::-1]:
        ret+=int(i)*(n**j)
        j+=1
    return is_prime(ret)

def jim_jam_jammy(s):
    div = []
    for i in range(2, 11):
        r = rem_base(s, i)
        if r:
            div.append(str(r))
        else:
            return []
    return div

t = int(raw_input())
while t>0:
    n, j = tuple(map(int, raw_input().strip().split()))
    s = '1'*n
    save = []
    print "Case #1:"
    for i in itertools.product(map(str, range(2)), repeat=n-2):
        s = '1'+''.join(i)+'1'
        r = jim_jam_jammy(s)
        if r!=[]:
            print s, " ".join(r)
            j-=1
            save.append(s)
        if not j:
            break
    t-=1
