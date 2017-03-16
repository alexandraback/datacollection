str = "B-large.in";
fo = open(str,"r");
T = int(fo.readline());
for m in range(T):
    x = fo.readline().strip().split(" ");
    A = int(x[0]);
    B = int(x[1]);
    K = int(x[2]);
    if A < B:
        temp = B;
        B = A;
        A = temp;
    if K <= B:
        count = K * (A + B - K);
        for i in range(K,A):
            for j in range(K,B):
                re = i & j;
                if re < K:
                    count += 1;
    else:
        count = A * B;
    print "Case #%d:" % (m+1), count;
