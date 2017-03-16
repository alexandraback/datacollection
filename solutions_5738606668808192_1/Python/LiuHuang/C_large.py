p = [[] for i in range(20)];
for B in range(2,11):
    for i in range(0,33):
        p[B].append(B**i); 
        
N = 32;
J = 500;
cnt = 0;
for a in range(0,2**(N-2)):
    bit = [0 for i in range(N)];
    n = a * 2 + 1 + 2**(N-1);
    for i in range(N):
        bit[i] = n % 2;
        n /= 2;
    ans = [0 for i in range(11)];
    ok = True;
    for B in range(2,11):
        s = 0;
        for i in range(N):
            s += bit[i] * (B ** i);
        pr = -1;
        for x in range(3, 55, 2):
            if (s % x == 0):
                pr = x;
                break;
        ans[B] = pr;
        if (pr == -1):
            ok = False;
            break;
    if (ok):
        for i in range(N-1,-1,-1):
            print("%d"%bit[i], end='')
        for i in range(2,11):
            print(' %d'%ans[i], end='')
        print();
        cnt = cnt + 1;
        if (cnt == J):
            break;

            
