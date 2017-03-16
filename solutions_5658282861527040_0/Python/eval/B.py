

if __name__ == '__main__': 
    T = input() 
    for t in range(1, T+1): 
        A, B, K = map(int, raw_input().split()) 
        cnt = 0 
        for i in range(A): 
            for j in range(B): 
                if (i & j) < K: 
                    cnt += 1 

        print 'Case #%d: %d' %(t, cnt)
