
def komb(k,L,M,retL):
    if k>0 and L==[]: return
    if k==0:
        retL.append(M)
        #print retL
        return
    L1 = L[1:]
    M1 = M+[L[0]]
    #bud prvok pridame
    #(ak je povolene opakovanie mozeme ho pridat znova (L sa nemeni))

    komb(k-1,L1,M1,retL)
    #alebo ho nepridame
    komb(k,L1,M,retL)


from itertools import chain, combinations

def powerset(iterable):
  xs = list(iterable)
  # note we return an iterator rather than a list
  return chain.from_iterable( combinations(xs,n) for n in range(len(xs)+1) )

kk = []
for i in range(6):
    LL = []
    komb(i,range(1,31),[],LL)
    kk.append(map(set,LL))

#print kk[3]

T = input()


for t in range(T):
    s = raw_input()
    (C,D,V) = map(int,s.split())
    values = set(map(int,raw_input().split()))
    res = None
    for i in range(6):
        if res is not None: break
        for a in kk[i]:
            if res is not None: break
            if len(a & values) !=0: continue
            n = a | values
            toPay = set(range(1,V+1))
            for ps in list(powerset(n)):
                toPay = toPay - {sum(ps)}
                if len(toPay) == 0:
                    res = i
                    break


    print "Case #%d:"%(t+1,), res
    
