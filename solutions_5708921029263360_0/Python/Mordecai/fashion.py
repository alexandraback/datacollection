def combos(P, S):
    already = set()
    p, s = 1,1
    while True:
        yield (p, s)
        already.add((p,s))
        p = p%P + 1
        s = s%S + 1
        if (p,s) in already: s = s%S+1

def fashion(J, P, S, K):
    x = min(J*P*S, K*J*P)
    el = [str(x)]
    if x == J*P*S:
        for j in range(1,J+1):
            for p in range(1,P+1):
                for s in range(1,S+1):
                    el.append(' '.join(map(str, (j,p,s))))
    else:
        duples = combos(P, S)
        for j in range(1,J+1):
            for i in range(K*P):
                p, s = duples.next()
                el.append(' '.join(map(str, (j,p,s))))
    return '\n'.join(el)

def main():
    cases = int(raw_input())
    for case in range(1, cases+1):
        J, P, S, K = map(int, raw_input().split())
        print "Case #%i:" %case, fashion(J, P, S, K)

if __name__ == '__main__':
    main()
