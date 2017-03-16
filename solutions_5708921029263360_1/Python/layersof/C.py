DEBUG=1

def main():
    T = input()
    for i in range(T):
        J, P, S, K = map(int, raw_input().split())
        print 'Case #%d: %s' % (i+1, '\n'.join(solve(J, P, S, K)))

def check(db, K):
    from collections import Counter
    c1 = Counter()
    c2 = Counter()
    c3 = Counter()

    for j, p, s in db:
        c1[(p, s)] += 1
        c2[(j, s)] += 1
        c3[(j, p)] += 1
    if not (c1.most_common(1)[0][1] <= K and
            c2.most_common(1)[0][1] <= K and
            c3.most_common(1)[0][1] <= K):
        print db, K
        print (c1.most_common(1)[0][1] <= K,
               c2.most_common(1)[0][1] <= K,
               c3.most_common(1)[0][1] <= K)
        return False

    return True
        

def solve(J, P, S, K):
    results = []
    db = []
    A, B, C, alpha = J*P*K, P*S*K, J*S*K, J*P*S
    count = min(A, B, C, alpha)
    results.append(str(count))
    if alpha == count:
        for i in range(J):
            for j in range(P):
                for k in range(S):
                    db.append((i+1, j+1, k+1))
                    results.append('%d %d %d' % (i+1, j+1, k+1))

    elif A == count:
        k = 0
        d = 0
        for i in range(J):
            for j in range(P):
                for _ in range(K):
                    db.append((i+1, j+1, (k+d)%S+1))
                    results.append('%d %d %d' % (i+1, j+1, ((k+d)%S)+1))
                    k = (k + 1) % S
                    if S == J or S == P:
                        if k == 0:
                            d += 1
                            # print 'hoge'
        
    elif B == count:
        i = 0
        d = 0
        for _ in range(K):
            for j in range(P):
                for k in range(S):
                    db.append(((i+d)%J+1, j+1, k+1))
                    results.append('%d %d %d' % ((i+d)%J+1, j+1, k+1))
                    i = (i + 1) % J
                    if S == J or J == P:
                        if i == 0: d += 1
        
    elif C == count:
        j = 0
        d = 0
        for i in range(J):
            for _ in range(K):
                for k in range(S):
                    db.append((i+1, (j+d)%P+1, k+1))
                    results.append('%d %d %d' % (i+1, (j+d)%P+1, k+1))
                    j = (j + 1) % P
                    if P == J or P == S:
                        if j == 0: d += 1

    assert check(db, K)

    return results

if __name__ == '__main__':
    main()
