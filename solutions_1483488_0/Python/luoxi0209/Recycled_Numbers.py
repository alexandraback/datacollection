import sys

test_num = int(raw_input())

for i in range(test_num):
    A,B = raw_input().split(" ")
    A = int(A)
    B = int(B)
    ma = set()
    for j in range(A, B):
        str_j = str(j)
        for num in range(1,len(str_j)):
            str_k = str_j[num:] + str_j[:num]
            k = int(str_k)
            if (j < k <= B):
                ma.add((j,k))
    sys.stdout.write("Case #%d: %d\n" %(i+1, len(ma),))

