T = input()

def print_matrix(matrix):
    for c in matrix:
        print ''.join(map(str, c))

for i in range(1, T+1):
    B, M = map(int, raw_input().split())
    matrix = [[1 if j==k+1 else 0 for j in range(B)] for k in range(B)]
    l = [1] * B
    target = B-1
    current = B-3

    M -= 1
    counter = 0
    while M != l[0]:
        if M in l[2:]:
            if not matrix[0][l[2:].index(M)+2]:
                matrix[0][l[2:].index(M)+2] = 1
                break
        if current >= 0:
            matrix[current][target] = 1
            for j in range(0, current+1):
                l[j] += 1
            current -= 1
        else:
            target -= 1
            current = target-2

            if current < 0:
                break

    print"Case #%d:" % i,
    if M == 0:
        print "POSSIBLE"
        print_matrix(matrix)
    else:
        print "IMPOSSIBLE"
