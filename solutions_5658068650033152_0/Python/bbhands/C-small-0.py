#!/usr/bin/python
# -*- coding: utf-8 -*-

def factors(n):    
    return set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

if __name__ == "__main__":

    fin = open("C-small-0.in", "r")
    fout = open("C-small-0.out", "w")
    T = int(fin.readline())

    for t in xrange(0, T):
        N, M, K = tuple(map(int, fin.readline().strip().split(' ')))
        factors_filtered = [x for x in factors(K+4) if x!=1 and x!= K+4]
        
        l = len(factors_filtered)
        if l == 0: #K+4 prime
            answer = K
        elif N<=2 or M<=2:
            answer = K
        else:
            n_opt = 1
            m_opt = K+4
            for i in xrange(0, l):
                n = factors_filtered[i]
                m = factors_filtered[l-1-i]
                if n<=N and m<=M and (n+m <n_opt+m_opt):
                    n_opt = n
                    m_opt = m
            
            if n_opt == 1:
                min = K
                for i in xrange(3, N):
                    for j in xrange(3, M):
                        n = i-2
                        m = j-2
                        if K-i*j < min:
                            min = K - i*j
                
                n = N-2
                m = M-2
                answer = min
                if (n*m+2*m+2*n - K)%2 == 1:
                    if 2*(m+n)<min:
                        answer = 2*(m+n)
                else:
                    if 2*(m+n)-1 < min: 
                        answer = 2*(m+n) - 1
            else:
                answer = 2*(m_opt+n_opt-4)

        fout.write("Case #%i: %s\n" % (t+1, answer))
    
    fin.close()
    fout.close()

