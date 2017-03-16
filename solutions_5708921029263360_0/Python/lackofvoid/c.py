import itertools
import math

def nCr(n,r):
    f = math.factorial
    return int(f(n) / f(r) / f(n-r))

if __name__ == "__main__":
    T = int(input())

    for I in range(1,T+1):
        jpsk = input().split(" ")
        J,P,S,K = [ int(i) for i in jpsk ]
        N = J*P*S
        poss = list(itertools.product(range(1,J+1), range(1,P+1), range(1,S+1) ) )
        res = []
        if N == 1:
            res = [[1,1,1]]
        elif J*P > K and P*S > K and J*S > K:
            res = poss
        else:
            for L in range(len(poss)):
                for per in itertools.permutations(poss,L):
                    # print(per)
                    count = 0
                    jp = dict()
                    ps = dict()
                    js = dict()
                    for j,p,s in per:
                        # print(per)
                        if (j,p) in jp:
                            jp[(j,p)] += 1
                        else:
                            jp[(j,p)] = 1
                        if (p,s) in ps:
                            ps[(p,s)] += 1
                        else:
                            ps[(p,s)] = 1
                        if (j,s) in js:
                            js[(j,s)] += 1
                        else:
                            js[(j,s)] = 1
                        if jp[(j,p)] <= K and ps[(p,s)] <= K and js[(j,s)] <= K:
                            count += 1
                        else:
                            break
                    # print(count)
                    if count > len(res):
                        # print(K)
                        # print(jp)
                        res = per[:count]
                        if count == L:
                            break
                if len(res) < L:
                    break

        s = "%i\n" % len(res)
        s += "\n".join( " ".join( str(el) for el in a ) for a in res )

        print("Case #%i: %s" % (I, s))
