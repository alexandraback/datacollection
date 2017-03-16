str = "B-small-attempt0.in";
fo = open(str,"r");
T = int(fo.readline());
for m in range(T):
    x = fo.readline().strip().split(" ");
    A = int(x[0]);
    B = int(x[1]);
    K = int(x[2]);
    count = 0;
    for i in range(A):
        for j in range(B):
            re = i & j;
            if re < K:
                count += 1;
    print "Case #%d:" % (m+1), count;
